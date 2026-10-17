#pragma once

#include <algorithm>
#include <cstdint>
#include <optional>
#include <string>
#include <unordered_map>
#include <utility>
#include <vector>

namespace Echohearts::OnlineBattle {

using SequenceId = std::uint64_t;
using TurnId = std::uint64_t;

struct BattleStats {
    std::int32_t vibrance{0};
    std::int32_t density{0};
    std::int32_t harmony{0};
    std::int32_t purity{0};
};

struct AuthoritativeEcoKinSnapshot {
    std::string ecoKinId;
    std::string ownerPlayerId;
    std::string essenceId;
    BattleStats stats;
    std::int32_t maxHealth{1};
};

enum class CommandCategory : std::uint8_t {
    Move,
    Ability,
    PartnerAction,
    Tactical
};

enum class BattleStatus : std::uint8_t {
    None,
    Static
};

struct ActionDefinition {
    std::string actionId;
    CommandCategory category{CommandCategory::Move};
    std::int32_t basePower{0};
    bool targetsOpponent{true};
    bool appliesStatic{false};
    std::string resonanceTargetEssenceId;
    std::int32_t resonanceBonusBps{0};
};

struct BattleCommand {
    std::string matchId;
    std::string playerId;
    std::string actingEcoKinId;
    std::string targetEcoKinId;
    std::string actionId;
    CommandCategory category{CommandCategory::Move};
    TurnId expectedTurnId{0};
    SequenceId clientSequence{0};
};

enum class CommandValidationCode : std::uint8_t {
    Ok,
    MatchNotActive,
    WrongMatch,
    UnknownPlayer,
    WrongTurn,
    WrongActor,
    DuplicateOrStaleSequence,
    UnknownAction,
    CategoryMismatch,
    IllegalTarget
};

struct CommandValidationResult {
    CommandValidationCode code{CommandValidationCode::Ok};
    std::string reason;
};

enum class BattleEventType : std::uint8_t {
    ActionResolved,
    TurnAdvanced,
    PlayerDisconnected,
    PlayerReconnected,
    MatchCompleted,
    RewardsFinalized
};

struct BattleEvent {
    SequenceId eventSequence{0};
    TurnId turnId{0};
    BattleEventType type{BattleEventType::ActionResolved};
    std::string actorEcoKinId;
    std::string targetEcoKinId;
    std::string actionId;
    std::int32_t damage{0};
    bool resonanceTriggered{false};
    BattleStatus appliedStatus{BattleStatus::None};
    std::string winnerPlayerId;
};

struct RuntimeEcoKinState {
    AuthoritativeEcoKinSnapshot source;
    std::int32_t currentHealth{1};
    BattleStatus status{BattleStatus::None};
    std::int32_t statusTurnsRemaining{0};

    bool IsAlive() const { return currentHealth > 0; }
};

enum class MatchPhase : std::uint8_t {
    Active,
    Completed,
    RewardsFinalized
};

struct ReconnectSnapshot {
    std::string matchId;
    TurnId turnId{0};
    std::string activeEcoKinId;
    MatchPhase phase{MatchPhase::Active};
    std::vector<RuntimeEcoKinState> units;
    SequenceId lastEventSequence{0};
    std::string winnerPlayerId;
};

class AuthoritativeBattleServer {
public:
    AuthoritativeBattleServer(std::string matchId,
                              std::vector<AuthoritativeEcoKinSnapshot> roster,
                              std::vector<ActionDefinition> actions)
        : matchId_(std::move(matchId))
    {
        for (auto& unit : roster) {
            RuntimeEcoKinState runtime;
            runtime.source = std::move(unit);
            runtime.currentHealth = std::max<std::int32_t>(1, runtime.source.maxHealth);
            turnOrder_.push_back(runtime.source.ecoKinId);
            units_.emplace(runtime.source.ecoKinId, std::move(runtime));
        }
        for (auto& action : actions) {
            actions_.emplace(action.actionId, std::move(action));
        }
        AdvancePastDefeatedUnits();
    }

    const std::string& MatchId() const { return matchId_; }
    TurnId CurrentTurnId() const { return turnId_; }
    MatchPhase Phase() const { return phase_; }
    const std::string& WinnerPlayerId() const { return winnerPlayerId_; }

    std::string ActiveEcoKinId() const {
        if (turnOrder_.empty() || activeIndex_ >= turnOrder_.size()) return {};
        return turnOrder_[activeIndex_];
    }

    CommandValidationResult ValidateCommand(const BattleCommand& command) const {
        if (phase_ != MatchPhase::Active) {
            return {CommandValidationCode::MatchNotActive, "match is not accepting commands"};
        }
        if (command.matchId != matchId_) {
            return {CommandValidationCode::WrongMatch, "command match id does not match server match"};
        }
        if (!PlayerExists(command.playerId)) {
            return {CommandValidationCode::UnknownPlayer, "player is not part of this match"};
        }
        if (command.expectedTurnId != turnId_) {
            return {CommandValidationCode::WrongTurn, "command was authored for a stale or future turn"};
        }
        const auto activeId = ActiveEcoKinId();
        if (command.actingEcoKinId != activeId) {
            return {CommandValidationCode::WrongActor, "acting Eco-Kin is not the authoritative active unit"};
        }
        const auto actorIt = units_.find(activeId);
        if (actorIt == units_.end() || actorIt->second.source.ownerPlayerId != command.playerId) {
            return {CommandValidationCode::WrongActor, "player does not own the authoritative active unit"};
        }
        const auto seqIt = lastAcceptedClientSequence_.find(command.playerId);
        if (seqIt != lastAcceptedClientSequence_.end() && command.clientSequence <= seqIt->second) {
            return {CommandValidationCode::DuplicateOrStaleSequence, "client sequence was already accepted or is stale"};
        }
        const auto actionIt = actions_.find(command.actionId);
        if (actionIt == actions_.end()) {
            return {CommandValidationCode::UnknownAction, "action id is not server-authored"};
        }
        const auto& action = actionIt->second;
        if (action.category != command.category) {
            return {CommandValidationCode::CategoryMismatch, "command category does not match server action definition"};
        }
        const auto targetIt = units_.find(command.targetEcoKinId);
        if (targetIt == units_.end() || !targetIt->second.IsAlive()) {
            return {CommandValidationCode::IllegalTarget, "target is missing or defeated"};
        }
        const bool sameOwner = targetIt->second.source.ownerPlayerId == command.playerId;
        if (action.targetsOpponent == sameOwner) {
            return {CommandValidationCode::IllegalTarget, "target does not satisfy action targeting rule"};
        }
        return {};
    }

    CommandValidationResult SubmitCommand(const BattleCommand& command) {
        const auto validation = ValidateCommand(command);
        if (validation.code != CommandValidationCode::Ok) return validation;

        lastAcceptedClientSequence_[command.playerId] = command.clientSequence;
        Resolve(command);
        return {};
    }

    void DisconnectPlayer(const std::string& playerId) {
        if (!PlayerExists(playerId)) return;
        connected_[playerId] = false;
        Emit({0, turnId_, BattleEventType::PlayerDisconnected, {}, {}, {}, 0, false, BattleStatus::None, {}});
    }

    std::optional<ReconnectSnapshot> ReconnectPlayer(const std::string& playerId) {
        if (!PlayerExists(playerId)) return std::nullopt;
        connected_[playerId] = true;
        Emit({0, turnId_, BattleEventType::PlayerReconnected, {}, {}, {}, 0, false, BattleStatus::None, {}});
        return Snapshot();
    }

    ReconnectSnapshot Snapshot() const {
        ReconnectSnapshot snapshot;
        snapshot.matchId = matchId_;
        snapshot.turnId = turnId_;
        snapshot.activeEcoKinId = ActiveEcoKinId();
        snapshot.phase = phase_;
        snapshot.lastEventSequence = nextEventSequence_ - 1;
        snapshot.winnerPlayerId = winnerPlayerId_;
        snapshot.units.reserve(units_.size());
        for (const auto& id : turnOrder_) {
            const auto it = units_.find(id);
            if (it != units_.end()) snapshot.units.push_back(it->second);
        }
        return snapshot;
    }

    std::vector<BattleEvent> EventsAfter(SequenceId eventSequence) const {
        std::vector<BattleEvent> result;
        for (const auto& event : events_) {
            if (event.eventSequence > eventSequence) result.push_back(event);
        }
        return result;
    }

    bool FinalizeRewardsServerSide() {
        if (phase_ != MatchPhase::Completed) return false;
        phase_ = MatchPhase::RewardsFinalized;
        Emit({0, turnId_, BattleEventType::RewardsFinalized, {}, {}, {}, 0, false, BattleStatus::None, winnerPlayerId_});
        return true;
    }

    bool CanReturnToHub() const { return phase_ == MatchPhase::RewardsFinalized; }

private:
    bool PlayerExists(const std::string& playerId) const {
        return std::any_of(units_.begin(), units_.end(), [&](const auto& pair) {
            return pair.second.source.ownerPlayerId == playerId;
        });
    }

    static std::int32_t ClampNonNegative(std::int32_t value) {
        return value < 0 ? 0 : value;
    }

    std::int32_t CalculateDamage(const RuntimeEcoKinState& actor,
                                 const RuntimeEcoKinState& target,
                                 const ActionDefinition& action,
                                 bool& resonanceTriggered) const
    {
        std::int64_t power = static_cast<std::int64_t>(std::max(0, action.basePower)) +
                             static_cast<std::int64_t>(std::max(0, actor.source.stats.vibrance));
        if (actor.status == BattleStatus::Static) {
            power = (power * 8000) / 10000;
        }
        resonanceTriggered = !action.resonanceTargetEssenceId.empty() &&
                             action.resonanceTargetEssenceId == target.source.essenceId &&
                             action.resonanceBonusBps > 0;
        if (resonanceTriggered) {
            power = (power * (10000 + action.resonanceBonusBps)) / 10000;
        }
        const std::int64_t mitigation = std::max<std::int32_t>(0, target.source.stats.density) / 2;
        return std::max<std::int32_t>(1, static_cast<std::int32_t>(std::max<std::int64_t>(1, power - mitigation)));
    }

    void Resolve(const BattleCommand& command) {
        auto actorIt = units_.find(command.actingEcoKinId);
        auto targetIt = units_.find(command.targetEcoKinId);
        const auto actionIt = actions_.find(command.actionId);
        if (actorIt == units_.end() || targetIt == units_.end() || actionIt == actions_.end()) return;

        auto& actor = actorIt->second;
        auto& target = targetIt->second;
        const auto& action = actionIt->second;

        bool resonanceTriggered = false;
        const std::int32_t damage = CalculateDamage(actor, target, action, resonanceTriggered);
        target.currentHealth = ClampNonNegative(target.currentHealth - damage);

        BattleStatus applied = BattleStatus::None;
        if (action.appliesStatic && target.IsAlive()) {
            if (target.source.stats.purity < 80) {
                target.status = BattleStatus::Static;
                target.statusTurnsRemaining = 1;
                applied = BattleStatus::Static;
            }
        }

        Emit({0, turnId_, BattleEventType::ActionResolved,
              actor.source.ecoKinId, target.source.ecoKinId, action.actionId,
              damage, resonanceTriggered, applied, {}});

        if (CheckForWinner()) return;
        ConsumeActorStatus(actor);
        AdvanceTurn();
    }

    static void ConsumeActorStatus(RuntimeEcoKinState& actor) {
        if (actor.statusTurnsRemaining > 0) --actor.statusTurnsRemaining;
        if (actor.statusTurnsRemaining <= 0) actor.status = BattleStatus::None;
    }

    bool CheckForWinner() {
        std::vector<std::string> livingOwners;
        for (const auto& [id, unit] : units_) {
            if (!unit.IsAlive()) continue;
            if (std::find(livingOwners.begin(), livingOwners.end(), unit.source.ownerPlayerId) == livingOwners.end()) {
                livingOwners.push_back(unit.source.ownerPlayerId);
            }
        }
        if (livingOwners.size() == 1) {
            winnerPlayerId_ = livingOwners.front();
            phase_ = MatchPhase::Completed;
            Emit({0, turnId_, BattleEventType::MatchCompleted, {}, {}, {}, 0, false, BattleStatus::None, winnerPlayerId_});
            return true;
        }
        return false;
    }

    void AdvanceTurn() {
        if (turnOrder_.empty()) return;
        activeIndex_ = (activeIndex_ + 1) % turnOrder_.size();
        ++turnId_;
        AdvancePastDefeatedUnits();
        Emit({0, turnId_, BattleEventType::TurnAdvanced, ActiveEcoKinId(), {}, {}, 0, false, BattleStatus::None, {}});
    }

    void AdvancePastDefeatedUnits() {
        if (turnOrder_.empty()) return;
        std::size_t checked = 0;
        while (checked < turnOrder_.size()) {
            const auto it = units_.find(turnOrder_[activeIndex_]);
            if (it != units_.end() && it->second.IsAlive()) return;
            activeIndex_ = (activeIndex_ + 1) % turnOrder_.size();
            ++checked;
        }
    }

    void Emit(BattleEvent event) {
        event.eventSequence = nextEventSequence_++;
        events_.push_back(std::move(event));
    }

    std::string matchId_;
    std::unordered_map<std::string, RuntimeEcoKinState> units_;
    std::vector<std::string> turnOrder_;
    std::unordered_map<std::string, ActionDefinition> actions_;
    std::unordered_map<std::string, SequenceId> lastAcceptedClientSequence_;
    std::unordered_map<std::string, bool> connected_;
    std::vector<BattleEvent> events_;
    std::size_t activeIndex_{0};
    TurnId turnId_{1};
    SequenceId nextEventSequence_{1};
    MatchPhase phase_{MatchPhase::Active};
    std::string winnerPlayerId_;
};

} // namespace Echohearts::OnlineBattle

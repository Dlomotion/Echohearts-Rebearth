#include "EchoheartsOnlineBattleCore.hpp"
#include <algorithm>
#include <cassert>
#include <iostream>

using namespace Echohearts::OnlineBattle;

static AuthoritativeEcoKinSnapshot Unit(const char* id, const char* owner, const char* essence,
                                        int vib, int den, int har, int pur, int hp) {
    return {id, owner, essence, {vib, den, har, pur}, hp};
}

int main() {
    const std::vector<ActionDefinition> actions = {
        {"basic_strike", CommandCategory::Move, 20, true, false, "", 0},
        {"torrent_pulse", CommandCategory::Ability, 24, true, false, "Pyre", 2500},
        {"static_bind", CommandCategory::PartnerAction, 8, true, true, "", 0},
        {"tactical_ping", CommandCategory::Tactical, 1, true, false, "", 0}
    };

    AuthoritativeBattleServer server(
        "match_001",
        {
            Unit("EcoKin_A", "player_a", "Torrent", 30, 10, 50, 70, 100),
            Unit("EcoKin_B", "player_b", "Pyre", 25, 12, 45, 50, 100)
        },
        actions);

    BattleCommand wrongTurn{"match_001", "player_b", "EcoKin_B", "EcoKin_A", "basic_strike",
                            CommandCategory::Move, 1, 1};
    assert(server.ValidateCommand(wrongTurn).code == CommandValidationCode::WrongActor);

    BattleCommand first{"match_001", "player_a", "EcoKin_A", "EcoKin_B", "torrent_pulse",
                        CommandCategory::Ability, 1, 1};
    assert(server.SubmitCommand(first).code == CommandValidationCode::Ok);
    auto events = server.EventsAfter(0);
    assert(!events.empty());
    assert(events.front().type == BattleEventType::ActionResolved);
    assert(events.front().resonanceTriggered);
    const int firstDamage = events.front().damage;
    assert(firstDamage > 0);

    assert(server.SubmitCommand(first).code == CommandValidationCode::WrongTurn);

    BattleCommand second{"match_001", "player_b", "EcoKin_B", "EcoKin_A", "static_bind",
                         CommandCategory::PartnerAction, 2, 1};
    assert(server.SubmitCommand(second).code == CommandValidationCode::Ok);
    auto snap = server.Snapshot();
    auto a = std::find_if(snap.units.begin(), snap.units.end(), [](const RuntimeEcoKinState& u) {
        return u.source.ecoKinId == "EcoKin_A";
    });
    assert(a != snap.units.end());
    assert(a->status == BattleStatus::Static);

    server.DisconnectPlayer("player_a");
    const auto beforeReconnect = server.Snapshot();
    auto reconnect = server.ReconnectPlayer("player_a");
    assert(reconnect.has_value());
    assert(reconnect->turnId == beforeReconnect.turnId);
    assert(reconnect->activeEcoKinId == beforeReconnect.activeEcoKinId);
    assert(reconnect->lastEventSequence > beforeReconnect.lastEventSequence);

    std::uint64_t sequenceA = 2;
    std::uint64_t sequenceB = 2;
    while (server.Phase() == MatchPhase::Active) {
        const auto turn = server.CurrentTurnId();
        const auto active = server.ActiveEcoKinId();
        const bool isA = active == "EcoKin_A";
        BattleCommand cmd{
            "match_001",
            isA ? "player_a" : "player_b",
            active,
            isA ? "EcoKin_B" : "EcoKin_A",
            "basic_strike",
            CommandCategory::Move,
            turn,
            isA ? sequenceA++ : sequenceB++
        };
        assert(server.SubmitCommand(cmd).code == CommandValidationCode::Ok);
    }

    assert(!server.WinnerPlayerId().empty());
    assert(!server.CanReturnToHub());
    assert(server.FinalizeRewardsServerSide());
    assert(server.CanReturnToHub());

    const auto allEvents = server.EventsAfter(0);
    for (std::size_t i = 1; i < allEvents.size(); ++i) {
        assert(allEvents[i].eventSequence > allEvents[i - 1].eventSequence);
    }

    std::cout << "Echohearts online battle logic verification passed; first damage=" << firstDamage
              << ", events=" << allEvents.size() << "\n";
    return 0;
}

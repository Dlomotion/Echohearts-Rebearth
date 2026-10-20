#pragma once

#include <cstdint>
#include <limits>
#include <map>
#include <stdexcept>
#include <string>
#include <utility>

// Offline domain reference only. No UE actors, RPCs, saves or relationship writes.
namespace Echohearts::Reference::Kindling {
inline constexpr std::int64_t MaxRevision = 2147483647;

class Rejected final : public std::runtime_error {
public:
    explicit Rejected(const char* reason) : std::runtime_error(reason) {}
};

inline void Require(bool condition, const char* reason) {
    if (!condition) throw Rejected(reason);
}

inline bool IsIdentity(const std::string& value) {
    if (value.empty() || value.size() > 96) return false;
    for (const unsigned char c : value) {
        if (!((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z') ||
              (c >= '0' && c <= '9') || c == '_' || c == '.' ||
              c == ':' || c == '-')) return false;
    }
    return true;
}

inline bool IsRevision(std::int64_t value) {
    return value >= 0 && value <= MaxRevision;
}

inline std::int64_t NextRevision(std::int64_t value) {
    Require(IsRevision(value), "invalid_revision");
    Require(value < MaxRevision, "revision_exhausted");
    return value + 1;
}

struct Evidence {
    std::string IndividualId;
    std::int64_t Revision = 0;
    bool Observed = false;
    bool Protected = false;
    bool Calm = false;
    bool Consent = false;
    bool Healing = false;
    bool Safe = false;
    bool Eligible = false;
};

struct Ceremony {
    std::string EncounterId;
    std::string OwnerId;
    std::string IndividualId;
    std::string Phase = "encountered";
    std::int64_t Revision = 0;
};

inline bool IsOpenPhase(const std::string& phase) {
    return phase == "encountered" || phase == "observed" || phase == "protected" ||
           phase == "calm" || phase == "invited" || phase == "bond_ready";
}

// Value-in/value-out: rejection leaves the caller's ceremony untouched.
// Evidence must be resolved by the existing host owner, never trusted from RPC flags.
inline Ceremony Transition(const Ceremony& state, const std::string& action,
                           const Evidence& evidence) {
    Require(IsIdentity(state.EncounterId) && IsIdentity(state.OwnerId) &&
            IsIdentity(state.IndividualId), "invalid_identity");
    Require(IsRevision(state.Revision) && IsRevision(evidence.Revision), "invalid_revision");
    Require(evidence.IndividualId == state.IndividualId &&
            evidence.Revision == state.Revision, "stale_evidence");
    Require(action == "observe" || action == "protect" || action == "calm" ||
            action == "invite" || action == "accept" || action == "refuse" ||
            action == "release" || action == "defer" || action == "interrupt", "unknown_action");
    Require(IsOpenPhase(state.Phase), "terminal_or_invalid_phase");
    std::string next;
    if (action == "refuse" || action == "release" || action == "defer" || action == "interrupt") {
        next = action == "refuse" ? "refused" : action == "release" ? "released" : "deferred";
    } else {
        Require(evidence.Safe && !evidence.Healing && evidence.Eligible, "not_safe_to_proceed");
        const bool ordered = (state.Phase == "encountered" && action == "observe") ||
            (state.Phase == "observed" && action == "protect") ||
            (state.Phase == "protected" && action == "calm") ||
            (state.Phase == "calm" && action == "invite") ||
            (state.Phase == "invited" && action == "accept");
        Require(ordered, "wrong_sequence");
        if (action == "observe") Require(evidence.Observed, "observation_missing");
        if (action == "protect") Require(evidence.Observed && evidence.Protected, "protection_missing");
        if (action == "calm" || action == "invite" || action == "accept")
            Require(evidence.Observed && evidence.Protected && evidence.Calm, "calm_evidence_missing");
        if (action == "invite" || action == "accept") Require(evidence.Consent, "consent_required");
        next = action == "observe" ? "observed" : action == "protect" ? "protected" :
            action == "calm" ? "calm" : action == "invite" ? "invited" : "bond_ready";
    }
    const auto revision = NextRevision(state.Revision);
    return {state.EncounterId, state.OwnerId, state.IndividualId, next, revision};
}

// In-memory proposal idempotency only, matching the existing Python oracle.
// A true result proposes a bond review; it does not commit a relationship.
// Single-threaded; the real host must use its existing atomic transaction owner.
class BondReviewLedger final {
public:
    bool Commit(const Ceremony& state, const Evidence& evidence) {
        Require(state.Phase == "bond_ready", "bond_not_ready");
        Require(evidence.IndividualId == state.IndividualId &&
                evidence.Revision == state.Revision, "stale_evidence");
        Require(IsRevision(state.Revision), "invalid_revision");
        Require(IsIdentity(state.OwnerId) && IsIdentity(state.IndividualId) &&
                IsIdentity(state.EncounterId), "invalid_identity");
        Require(evidence.Observed && evidence.Protected && evidence.Calm && evidence.Consent &&
                evidence.Safe && evidence.Eligible && !evidence.Healing, "bond_not_authorized");
        const auto identity = std::make_pair(state.OwnerId, state.EncounterId);
        const auto found = ByIndividual.find(state.IndividualId);
        if (found != ByIndividual.end()) {
            Require(found->second == identity, "individual_already_resolved");
            return false;
        }
        ByIndividual.emplace(state.IndividualId, identity);
        return true;
    }
private:
    std::map<std::string, std::pair<std::string, std::string>> ByIndividual;
};
} // namespace Echohearts::Reference::Kindling

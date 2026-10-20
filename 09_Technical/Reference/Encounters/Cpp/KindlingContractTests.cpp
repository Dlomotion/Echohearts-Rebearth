#include "KindlingContract.hpp"

#include <iostream>
#include <sstream>
#include <vector>

using namespace Echohearts::Reference::Kindling;

static void Check(bool condition, const char* message) {
    if (!condition) throw std::runtime_error(message);
}

template<class F> static void Rejects(F operation, const char* reason) {
    try { operation(); }
    catch (const Rejected& e) { Check(std::string(e.what()) == reason, "wrong rejection"); return; }
    throw std::runtime_error("operation unexpectedly accepted");
}

static Evidence Fresh(std::int64_t revision) {
    return {"individual", revision, true, true, true, true, false, true, true};
}

static void SelfTest() {
    Ceremony state{"encounter", "owner", "individual"};
    for (const auto* action : {"observe", "protect", "calm", "invite", "accept"})
        state = Transition(state, action, Fresh(state.Revision));
    Check(state.Phase == "bond_ready" && state.Revision == 5, "gold path failed");
    BondReviewLedger ledger;
    Check(ledger.Commit(state, Fresh(5)), "first review missing");
    Check(!ledger.Commit(state, Fresh(5)), "duplicate review emitted");
    auto stolen = state;
    stolen.OwnerId = "other";
    Rejects([&]{ ledger.Commit(stolen, Fresh(5)); }, "individual_already_resolved");
    stolen = state;
    stolen.EncounterId = "other";
    Rejects([&]{ ledger.Commit(stolen, Fresh(5)); }, "individual_already_resolved");
    auto revoked = Fresh(5);
    revoked.Consent = false;
    Rejects([&]{ ledger.Commit(state, revoked); }, "bond_not_authorized");
    BondReviewLedger unconsumed;
    Rejects([&]{ unconsumed.Commit(state, revoked); }, "bond_not_authorized");
    Check(unconsumed.Commit(state, Fresh(5)), "rejected review consumed individual");
    Rejects([&]{ ledger.Commit(state, Fresh(4)); }, "stale_evidence");
    auto injured = Fresh(5);
    injured.Healing = true;
    Rejects([&]{ ledger.Commit(state, injured); }, "bond_not_authorized");

    for (const auto* phase : {"encountered", "observed", "protected", "calm", "invited", "bond_ready"}) {
        for (const auto* action : {"refuse", "release", "defer", "interrupt"}) {
            Ceremony open{"encounter", "owner", "individual", phase, 9};
            Evidence unsafe{"individual", 9};
            const auto exited = Transition(open, action, unsafe);
            Check(!IsOpenPhase(exited.Phase) && exited.Revision == 10, "unsafe exit blocked");
            Rejects([&]{ Transition(exited, "observe", Fresh(10)); }, "terminal_or_invalid_phase");
        }
    }
    Ceremony boundary{"encounter", "owner", "individual", "encountered", MaxRevision - 1};
    const auto final = Transition(boundary, "observe", Fresh(MaxRevision - 1));
    Check(final.Revision == MaxRevision, "final revision missing");
    Rejects([&]{ Transition(final, "protect", Fresh(MaxRevision)); }, "revision_exhausted");
    Rejects([&]{ Transition(final, "release", Fresh(MaxRevision)); }, "revision_exhausted");
    Check(final.Phase == "observed" && final.Revision == MaxRevision, "failure mutated source");
    state.Revision = MaxRevision;
    BondReviewLedger finalLedger;
    Check(finalLedger.Commit(state, Fresh(MaxRevision)), "final readable review rejected");
    Check(!finalLedger.Commit(state, Fresh(MaxRevision)), "final review replayed");
    for (const auto revision : {std::int64_t{-1}, MaxRevision + 1, std::numeric_limits<std::int64_t>::max()})
        Rejects([&]{ NextRevision(revision); }, "invalid_revision");
    for (const auto& id : std::vector<std::string>{"", "bad id", "bad/id", std::string(97, 'a'), "\xC3\xA9", std::string("a\0b", 3)}) {
        Ceremony invalid{id, "owner", "individual"};
        Rejects([&]{ Transition(invalid, "observe", Fresh(0)); }, "invalid_identity");
    }
    Ceremony valid{"encounter", "owner", "individual"};
    auto foreign = Fresh(0);
    foreign.IndividualId = "another";
    Rejects([&]{ Transition(valid, "observe", foreign); }, "stale_evidence");
    Check(Transition(valid, "observe", Fresh(0)).Phase == "observed", "failure consumed state");
    std::cout << "Kindling C++ behavioral checks passed (offline reference only)\n";
}

// Test-only stream adapter. IDs are fixtures, not approved roster identities.
static int StreamTransitions() {
    std::string line;
    while (std::getline(std::cin, line)) {
        std::istringstream input(line);
        std::string phase, action, extra;
        std::int64_t revision = 0, evidenceRevision = 0;
        unsigned flags = 0;
        if (!(input >> phase >> action >> revision >> evidenceRevision >> flags) ||
            (input >> extra) || flags > 127) return 2;
        const Ceremony state{"encounter", "owner", "individual", phase, revision};
        const Evidence evidence{"individual", evidenceRevision,
            (flags & 1) != 0, (flags & 2) != 0, (flags & 4) != 0,
            (flags & 8) != 0, (flags & 16) != 0, (flags & 32) != 0, (flags & 64) != 0};
        try {
            const auto next = Transition(state, action, evidence);
            std::cout << "ok " << next.Phase << ' ' << next.Revision << '\n';
        } catch (const Rejected& e) { std::cout << "error " << e.what() << '\n'; }
    }
    return std::cin.bad() ? 2 : 0;
}

int main(int argc, char** argv) {
    try {
        if (argc == 2 && std::string(argv[1]) == "--transitions") return StreamTransitions();
        if (argc != 1) return 2;
        SelfTest();
        return 0;
    } catch (const std::exception& e) {
        std::cerr << e.what() << '\n';
        return 1;
    }
}

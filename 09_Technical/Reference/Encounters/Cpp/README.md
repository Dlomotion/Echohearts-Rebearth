# Kindling C++17 domain reference

Extends the existing encounter oracle and PR #71. This is an offline, compilable
port of the ceremony transition and in-memory bond-review rules, **not code
installed in the game**. BUILD remains the sole Unreal runtime owner. Spawn
fingerprints, weather, Strain, farming and other field-loop rules are not ported
by these files. No new species, attributes, save format or runtime owner exists.

## Build and compare

From `09_Technical/Reference/Encounters` with GCC and Python 3.12:

```sh
g++ -std=c++17 -Wall -Wextra -Wpedantic -Werror -fsanitize=undefined -fno-sanitize-recover=all -g Cpp/KindlingContractTests.cpp -o /tmp/kindling-reference
/tmp/kindling-reference
python3 check_cpp_parity.py /tmp/kindling-reference
g++ -std=c++17 -O2 -DNDEBUG -Wall -Wextra -Wpedantic -Werror -fsanitize=undefined -fno-sanitize-recover=all Cpp/KindlingContractTests.cpp -o /tmp/kindling-reference-release
/tmp/kindling-reference-release
python3 -O check_cpp_parity.py /tmp/kindling-reference-release
```

The existing reference CI runs both builds. These checks stay active with
`NDEBUG`; they do not depend on C `assert`. The test adapter reads fixture lines
over stdin; it is not a gameplay/network protocol. 14,600 differential cases
compare accepted phases/revisions and rejection reasons with Python: all 128
evidence bit combinations, legal/terminal/invalid phases and actions, stale
evidence, final readable revision, exhaustion and invalid revision bounds.
Behavioral checks additionally cover duplicate reviews, competing owners and
encounters, late refusal/injury, failed-review retries, invalid identities,
foreign-individual evidence and source-state immutability after rejection.

## Symbol and ownership handoff

All symbols below are **new reference symbols**, not claims about BUILD classes.

| Reference symbol | Purpose | Required production owner |
| --- | --- | --- |
| `Ceremony`, `Evidence` | Value snapshots; stable IDs and revision | Existing Kindling service and trusted evidence owner |
| `Transition` | Ordered care/invitation intents; refusal/release/defer | Existing server-authoritative Kindling transition |
| `NextRevision` | Checked bounded increment; no wrap/reset | Existing versioned state owner |
| `BondReviewLedger::Commit` | First-review versus duplicate decision | Existing durable relationship transaction owner |

`bond_ready` and a first review never grant a real relationship or mission
reward. This in-memory ledger is single-process/single-threaded and has no
durability. It must not replace an existing save, cloud, roster or transaction
service. Evidence flags are not safe as client-supplied permissions.

This standalone oracle uses STL and exceptions for rejection. Do **not** include
it unchanged in the UE runtime or enable UE exceptions for it. After BUILD source
review, translate the tested rules into existing Unreal owners using their
types/result conventions, authority checks and serialization. Keep existing
Vibrance/Density/Harmony/Purity and Anima-Link owners; this ceremony-only port
does not implement or replace them.

## Known boundary / native acceptance

At revision `2147483647`, read-only bond-review retry remains valid. Every
changing transition, including release/defer, rejects `revision_exhausted`,
matching the current oracle. This is a reference storage bound, not permission
to trap a live player in a ceremony: native welfare/back-away/presentation
cleanup must remain possible outside a failed persisted transition. Do not
reset the counter or claim this edge is production-safe until the existing
native owner has a reviewed recovery path.

The existing [UE integration handoff](../../../ENCOUNTER_TO_KINDLING_UE58_INTEGRATION_HANDOFF_2026-10-17.md)
defines foundation and runtime gates. UHT/UBT, Editor, PIE, persistence,
networking, cook/package and target-hardware performance remain **NOT VERIFIED**.

# Echohearts: Rebearth — Verification Ledger

This ledger records evidence states. It does not promote a feature to VERIFIED unless the required evidence for that exact claim exists.

## 2026-10-06 — Sector iteration and static manifest validation

- **Status:** REPOSITORY/STATIC EVIDENCE ONLY / NOT YET UE5.8 VERIFIED
- **Executable authority:** `Dlomotion/ECHOHEARTS-REBEARTH-BUILD-`.
- **Authority correction:** executable `.uproject`, `Source/`, compiler/build/package tooling, UE CI, and retained runtime evidence belong in BUILD. The canon repository records contracts and evidence only.
- **Default-branch correction:** `EchoheartsRebearth.uproject` is present on BUILD `main` and declares EngineAssociation `5.8`; no executable `.uproject` is present on the canon repository `main`. Do not collapse those two facts into “no .uproject exists.”
- **Static validator on BUILD main:** `BuildScripts/verify_static_contracts.py` is already present and remains the single universe/platform static validator.
- **Sector-loop implementation state:** the bounded C++ sector-loop implementation and its Automation test are candidate changes in BUILD PR #31, which is still open and unmerged. They are not current BUILD-main runtime behavior.
- **Identity correction:** tracking IDs are stable identifiers and are not required to equal array positions.
- **Threading boundary:** PR #31’s candidate loops are synchronous on the calling thread. No background-thread or non-blocking performance claim is made.
- **Ordering boundary:** PR #31’s candidate sector removal preserves the relative order of remaining records instead of using swap-removal.
- **Canonical attributes preserved:** Vibrance, Density, Harmony, Purity.
- **Lua boundary:** Lua remains proposal/reference material because no approved Lua runtime dependency, sandbox/security contract, build integration, or UE5.8 execution evidence is established.
- **Evidence required before VERIFIED:** merge/rebase to the executable authority, UHT, Development Editor/Game compile, actual UE Automation execution, authored runtime use, packaged execution where claimed, and profiling evidence before any performance claim.

## 2026-10-06 — Array identity, compiler resolution, and Sanctuary Growth Box records

- **Status:** BRANCH STATIC CHECK PASSED / NOT MERGED / NOT YET UE5.8 VERIFIED
- **Candidate runtime implementation:** BUILD PR #31, still open and unmerged.
- **BUILD PR #31 hosted evidence:** GitHub Actions run `37525342301` completed successfully on PR #31 head `69f8a23a2b8d0295ada6c92230fa704f90d19184`. The job executed Python syntax, diagnostic tests, PR #31 compiler-resolution tests, the host C++ array smoke, PowerShell syntax, static schema tests, universe/platform static validation, repository contract validation, and dependency-graph generation.
- **Evidence boundary for that run:** the hosted g++ smoke proves only the standalone smoke program on that PR branch. It does not prove UHT, UBT, reflected Unreal C++, editor/runtime behavior, replication, save, packaging, or performance.
- **Array identity:** stable numeric keys such as `0x3000`–`0x3041` are identifiers, not direct array offsets; individual character records use GUID identity.
- **C++ token conversion:** PR #31’s hosted smoke passed a guarded non-empty `std::string::front()` byte extraction. The invalid `char = std::string` pattern is not accepted.
- **Growth Box boundary:** the Sanctuary Growth Box implementation exists only in open BUILD PR #31. It stores roster/progression records, not living Eco-Kin. Permanent Dex IDs remain 1–125 for Eco-Kin species identity.
- **Attribute authority:** the candidate implementation preserves Vibrance, Density, Harmony, Purity as root attributes; Life, Defense, and Anima-Link reserve are derived; ammunition remains equipment state.
- **Server boundary:** PR #31 authors registration, facility progression, assignment changes, and reload transactions as server-authoritative operations, but replication/save behavior has not executed under UE5.8.

## 2026-10-06 — Dedicated compiler resolver PR #32

- **State:** OPEN / NOT YET STATIC-CI CONFIRMED / NOT UE5.8 VERIFIED.
- **Purpose:** BUILD PR #32 isolates strict explicit compiler-path resolution, compiler-family detection, fail-closed behavior, and dedicated regression tests.
- **Duplication warning:** PR #31 and PR #32 both modify compiler-resolution behavior and `.github/workflows/compiler-static.yml`. They must not be merged independently without reconciliation.
- **Current Actions evidence:** PR #32 workflow run `37533642746` concluded `action_required` and produced no job execution. Therefore its 12 test cases are code-reviewed coverage, not executed CI evidence yet.
- **Merge-safe ownership:** PR #32 should own compiler-path resolution. After PR #32 is CI-confirmed and merged, PR #31 should rebase onto BUILD `main` and drop its duplicate resolver/test changes while retaining its distinct host-array smoke, static-schema tests, sector loops, Growth Box code, and Unreal Automation tests.
- **Verification boundary:** even after PR #32 static tests pass, UE5.8 UHT/UBT, editor, PIE, package and runtime remain **NOT VERIFIED — UE BUILD/RUNTIME EVIDENCE REQUIRED**.

## Production-order guard

Do not let the open loop/Growth Box work leapfrog the established runtime order:

`BUILD foundation/tooling → clean clone + LFS → UE5.8 UHT/Development Editor build → editor + minimal authored map + PIE → bounded Automation → Development package + packaged launch → Issue #10 humanoid + Eco-Kin runtime proof → 4–6 Eco-Kin vertical slice → later systems`.

The ledger may record branch/static evidence early, but it must not convert that evidence into runtime VERIFIED status.

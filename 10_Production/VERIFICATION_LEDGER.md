# Echohearts: Rebearth — Verification Ledger

This ledger records evidence states. It does not promote a feature to VERIFIED unless the required evidence for that exact claim exists.

## 2026-10-06 — Sector iteration and static manifest validation

- **Status:** REPOSITORY_CHECKED / NOT YET UE5.8 VERIFIED
- **Runtime authority:** `Dlomotion/ECHOHEARTS-REBEARTH-BUILD-`
- **Scope:** bounded world-sector iteration helpers, universe/platform manifest validation, and regression checks.
- **Canonical attributes preserved:** Vibrance, Density, Harmony, Purity.
- **Implementation correction:** executable code uses `Source/Echohearts/` and `ECHOHEARTS_API`; the superseded `Source/EchoheartsRebearth/` / `ECHOHEARTSREBEARTH_API` contract is not reintroduced.
- **Identity correction:** tracking IDs are stable identifiers and are not required to equal array positions.
- **Threading boundary:** current C++ sector loops are synchronous on the calling thread. No background-thread or non-blocking performance claim is made.
- **Ordering boundary:** sector removal preserves the relative order of remaining records instead of using swap-removal.
- **Python boundary:** the existing `BuildScripts/verify_static_contracts.py` remains the single universe/platform static validator; the submitted alternate schema/path implementation was not duplicated.
- **Lua boundary:** Lua remains proposal/reference material because no approved Lua runtime dependency, sandbox/security contract, build integration, or UE5.8 execution evidence is established.
- **Evidence required before VERIFIED:** UHT, Development Editor/Game compile, actual UE Automation execution for loop tests, authored runtime use, packaged execution where claimed, and profiling evidence before any performance claim.


## 2026-10-06 — Array identity, compiler resolution, and Sanctuary Growth Box records

- **Status:** STATIC CHECK PASSED / NOT YET UE5.8 VERIFIED
- **Runtime implementation:** `Dlomotion/ECHOHEARTS-REBEARTH-BUILD-` PR #31.
- **Array identity:** stable numeric keys such as `0x3000`–`0x3041` are identifiers, not direct array offsets; individual character records use GUID identity.
- **C++ token conversion:** hosted g++ smoke compilation/execution passed using non-empty `std::string::front()` extraction and explicit byte-to-integer conversion. The invalid `char = std::string` pattern is not part of the implementation.
- **Compiler resolution:** Python regression tests pass for supported compiler-family detection and missing/unsupported explicit tool paths.
- **Attribute authority:** runtime root attributes remain Vibrance, Density, Harmony, Purity on the shared 0..100 `FEchoCoreAttributes` contract.
- **Derived state:** Life, Defense, and Anima-Link reserve are derived; ammunition is equipment state.
- **Growth Box boundary:** the Sanctuary Growth Box stores roster/progression records, not living Eco-Kin. Permanent Dex IDs remain 1–125 for Eco-Kin species identity.
- **Server boundary:** registration, facility progression, assignment changes, and reload transactions are authored as server-authoritative operations.
- **Evidence still required:** UE5.8 UHT/UBT, actual Automation execution, replication behavior, save/reload, UI binding, packaged runtime, and performance profiling before any corresponding VERIFIED claim.

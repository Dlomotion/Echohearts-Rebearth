# Eco-Device summoning intake and deadline correction — 2026-10-17

**Status:** original Lua prototype corrected and locally executed; NOT UE5.8 VERIFIED.

## Intake and design supersession
Latest explicit user direction replaces hip/forearm ambiguity and three-active campaign deployment with a hip-mounted Eco-Device running A.E.G.I.S., eight carried bonded links and one active partner. Existing [A.E.G.I.S. contract](../04_Systems/AEGIS_ECO_DEVICE_RECONCILIATION.md) records the supersession. Other files/BUILD need migration review; no claim of universal synchronization.

Only bonded partners may answer. Trust/consent/healing/ceremony checks, charge and distance-dependent Anima-Link strain remain. Recall is free; a failed incoming swap after successful recall leaves nobody active. Fixture costs/thresholds are not approved balance.

Inspected actual local resource package: Summoning.lua, summoning_tests.lua, SUMMONING-MECHANISMS.md, rebuild_scripts.py and README. It is not a git repository; no git init, duplicate repository or runtime tree was created.

## Corrected defect
Complete checked expiry before invoking eligibility/safety callbacks, but those synchronous callbacks may consume time. A call reaching its five-second prototype deadline during arrivalSafe could still spawn and charge afterward.

Added a clock/deadline check immediately after eligibility and before spawn. Expired ticket is already consumed, so it cannot replay; no actor/charge/strain is committed. Invalid monotonic clock fails closed. This does not provide a distributed transaction: host spawn must remain synchronous/non-yielding and clean up partial actors on failure.

New regression: begin at time zero; arrivalSafe moves host time to five; completion must return UNKNOWN_OR_EXPIRED, spawn zero actors, preserve charge/strain and clear reservation. Original code failed at assertion 66; corrected suite passes 68.

## Execution evidence — scoped
Reviewer Codex; date 2026-10-17; local Linux; installed liblua5.4.so.0 through a minimal ctypes test runner. The lua executable is absent; direct lua command returned 127 and is not a passing run.

- Baseline regression: `python3 ../work/run_lua54_checks.py res/lua/LuaScripts/summoning_tests.lua` returned exit 1: `Check 66 failed`.
- Corrected same command: exit 0, `PASS: 68 revised summoning assertions; fixture values, not final balance`.
- Existing Lua suite: exit 0, atomic ecosystem changes/finite deltas/lifecycle/ticks/session-entry checks.
- `python3 rebuild_scripts.py`: rebuilt six Lua source entries.
- `python3 -m unittest discover -s tests -v`: eight loader methods, 0.007s, OK, exit 0.
- `python3 validate_resources.py`: JSON, archive paths/CRC/sizes/hashes/source equality and uncaptured PSO state passed.
- Updated existing source package, not a packaged Unreal game.
- ZIP SHA-256: `cd4214c1624379d1223ece88d51ab6f150a2a68bc7321448f632cf3bc021124f`.
- Summoning.lua SHA-256: `8c0b1bc6362f2bcb3d0443c079e5afc973fdcd5eed76c259fc9c4989795fa5b0`.
- Tests SHA-256: `ddf2bcda8ba33bde9ef9634c4a23c76f632f21136ea94ed985367656300af922`.

No source commit/remote CI exists for this package. Artifact checksums identify the reviewed source. No Lua-to-Unreal bridge, actual game actor or production spawn was exercised.

## Engineering gates before integration
1. Inspect real module/API/Build.cs/targets in BUILD; do not paste Lua into UE without an explicitly chosen bridge/host and rights/dependency audit.
2. Resolve partner/owner/arrival/distance and resource budgets server-side. No client flags/positions/costs or actor IDs are authority.
3. Session-local serial tickets are correlation IDs, not authentication or cross-session replay protection. Persist/reconcile idempotency, budgets and actor ownership; never initialize a second controller from old balances.
4. Atomic spawn/cost and despawn/rest commit, partial actor cleanup, disconnect/travel/reload, consent changes and late-join reconstruction require real runtime tests.
5. Gate ordinary refusal in implementation/server policy; malformed/hostile RPC payload validation may disconnect. Replicated persistent state, not multicast VFX alone, must recover deployment.
6. Audit GC/lifetime, game-thread UObject access, reentrancy/callback side effects, budget contention, packet limits, save migration and accessible feedback.
7. Do not equate one active campaign partner with deleted roster IDs or altered Arena rules. Migrate old three-active assets/UI/save data explicitly and preserve historical provenance.
8. Lua XDF here is a documented ZIP and XDT a JSON hash index; neither reproduces proprietary foreign formats. No binary Vulkan cache or ad SDK is copied.

## Research / provenance checked 2026-10-17
- Epic UE5.8 RPC documentation: <https://dev.epicgames.com/documentation/en-us/unreal-engine/remote-procedure-calls-in-unreal-engine>. Official source for actor ownership, current relevancy and disconnect-on-validation-failure requirements; no implementation copied.
- Official Epic announcements: <https://forums.unrealengine.com/c/general/announcements/49>. No new material engine update established in bounded feed check.
- Lua source is existing original project prototype; deadline correction is original. System liblua is used only as local test tool; it is not packaged as a new game dependency.

## Exact next action
Restore readable BUILD source, compare existing summoning/bond/runtime policy to this latest user direction, then migrate the real device/active-cap/state contracts on its existing feature branch. Prove Windows UE5.8.3 installation/toolchain and UHT/UBT/Automation before actor/replication/save/package promotion.

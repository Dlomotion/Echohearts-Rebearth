# AI feature intake and route-overflow correction — 2026-10-14

**Status:** REPOSITORY CODE CORRECTION + GENERIC C++17 EXECUTION EVIDENCE; NOT UE5.8 VERIFIED

## Ownership and intake
Main canon remains Dlomotion/Echohearts-Rebearth. BUILD remains the executable Unreal target. The user-directed Dlomotion/EcoKin-A.i. repository is an existing AI feature workspace, not a second canon/runtime track. Inspected its README, route planner/tests, CI workflow and Nanonite story at main commit `db4b4d571753144ff267f8dfc6bf40c7ce9d2fa0`.

BUILD and IN2Deep-Studios/EcoKin-patch metadata each returned 404 on October 14. The user's patch integration statement is retained as intake; contents/integration are **NOT YET VERIFIED**. Access failures do not establish deletion. No new repository was created.

## Concrete defect and fix
The planner checks each input is finite, but weighted scoring and path addition can overflow. A finite DBL_MAX exposure produces an infinite Careful score; the original planner then reports a found route with infinite cost.

Feature [draft PR #2](https://github.com/Dlomotion/EcoKin-A.i./pull/2), branch `fix/route-cost-overflow-2026-10-14`, head `38e3819931709b931f19d420f4826e8f3f07bba1`:
- Reject nonfinite weighted score before clamping.
- Reject nonfinite score and accumulated total before updating the queue/predecessor.
- Add regression cases for score overflow, multi-edge accumulated overflow and a finite alternate route.
- Refuse NDEBUG test compilation, preventing assert-based tests from printing a false pass when assertions are removed.

Changed files: `include/EcoKinAIRoutePlanner.hpp`, `tests/EcoKinAIRoutePlannerTests.cpp`. Both exact-commit contents matched the reviewed local source byte-for-byte.

## Retained execution evidence
Reviewer: Codex; date: 2026-10-14; platform: local Linux; compiler: GCC 13.3.0; source: above PR head.
- Baseline plus new regression: compile succeeded, execution failed at overflow assertion, exit 134.
- Corrected source: `g++ -std=c++17 -Wall -Wextra -Werror -pedantic -O2 -fsanitize=undefined -Iwork/ai-audit/include work/ai-audit/tests/EcoKinAIRoutePlannerTests.cpp -o /tmp/eco_ai_regression`; execution exit 0.
- Raw output: `EcoKin AI route planner contract checks passed`.
- NDEBUG negative check: compiler exit 1 with `Contract tests require active assertions; do not build with NDEBUG.`
- Header SHA-256: `d6fe6d83984c3fe54885211825bffde953879977d43bd315afc241b340535a59`.
- Test source SHA-256: `35629779907aaeaae4fe3a10012cefcfe5779c9fe31a33f778b7146655ec3224`.

Hosted exact-head evidence: [PR Actions run 38584196747](https://github.com/Dlomotion/EcoKin-A.i./actions/runs/38584196747) and [push run 38584187403](https://github.com/Dlomotion/EcoKin-A.i./actions/runs/38584187403) both returned completed/success. PR run job `contract` has successful JSON validation, C++17 compile and execution step conclusions. Hosted build lacks UBSan flag; do not extend the local UBSan claim to CI. API job/step evidence is retained via run URLs; full downloadable logs were not retrieved.

**Scope:** generic C++17 reference and hosted contract checks only. No UE module, UHT/UBT, navmesh, World Partition readiness, server revalidation, save/recovery, NPC, boss, packaged game or platform execution is proven.

## Remaining audit gates
- Duplicate SegmentID ambiguity, invalid enum values, graph-size/input-string bounds, explicit compiler/platform tie behavior, near-equal cost policy and authoritative gate snapshots remain review items.
- Planner results are proposals requiring authoritative revalidation. Server must not accept client IDs, positions, costs or readiness flags.
- Snapshot refresh must invalidate stale routes when habitat, portal, story or streamed-cell readiness changes.
- Reference planner accesses only local value data; do not move UObject access onto worker threads during port.
- CI uses hosted ubuntu-24.04 and contents:read. Checkout @v4 is a mutable major tag; dependency pin/governance should be resolved before production hardening. No persistent self-hosted PR runner was introduced.
- AI main branch endpoint reports unprotected; no rule changes were made. Draft review/merge evidence still required.
- Nanonite document contains an 8-roster/3-active statement; this audit does not approve it. Reconcile against current BUILD/canon contracts before treating it as runtime truth.
- Synthetic humanoids are not automatically Eco-Kin. Nanonite reconstruction claims cannot overwrite origins, G.L.Y.T.C.H. autonomy, Nature, ULTRA or established villains/endings.

## Fresh research/provenance
Checked October 14:
- Epic StateTree documentation (UE5.8): <https://dev.epicgames.com/documentation/en-us/unreal-engine/state-tree-in-unreal-engine>. Hierarchical states/transitions are an eventual authored-AI option; existing BUILD architecture must decide the actual integration.
- Epic save/load documentation (UE5.8): <https://dev.epicgames.com/documentation/en-us/unreal-engine/saving-and-loading-your-game-in-unreal-engine>. USaveGame supports authored persistence, but atomicity/migration/recovery must be tested separately.
- cppreference std::isfinite: <https://en.cppreference.com/cpp/numeric/math/isfinite>. Used as reference for rejecting infinity/NaN, no sample copied.
- Existing project source and copyright remain in the user-owned feature repository; no external code or proprietary Epic source copied. No new third-party library/license assumption.

## Next exact action
Review feature PR #2, then restore BUILD/patch access and compare exact heads before integrating. Execute Windows UE5.8 foundation/UHT/UBT/Automation before porting routing. Resolve the macro/Build.cs, snapshot authority, graph bounds and saved route invalidation in existing systems rather than creating competing runtime classes.

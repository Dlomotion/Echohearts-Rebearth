# AI route identity and intent correction — 2026-10-16

**Status:** corrected generic C++17 reference; local and hosted contract evidence; NOT UE5.8 VERIFIED.

## Actual source reviewed
Existing AI feature PR #2 at `38e3819931709b931f19d420f4826e8f3f07bba1`: include/EcoKinAIRoutePlanner.hpp and tests/EcoKinAIRoutePlannerTests.cpp. This workspace supports main canon and BUILD; it does not establish another runtime or canon.

## Defects and bounded correction
1. An out-of-range ERouteIntent passed to the planner bypassed every switch arm and used bare traversal cost. Added explicit intent validation before even the same-POI shortcut; returns `invalid_route_intent`.
2. SegmentIds are returned to identify a route, but duplicate IDs could name different endpoints. Added graph-construction rejection of duplicate nonempty SegmentIDs; returns `duplicate_segment_id`. Includes IDs on gated-off edges, so legality filtering cannot hide ambiguous source identity. Same-POI no-traversal queries retain their existing empty-route shortcut after intent validation.

No new UE classes/API macros or code tree were invented. Existing hard story/habitat/streaming/portal gates and nonfinite-score rejection remain.

## Source, tests and evidence
Existing branch `fix/route-cost-overflow-2026-10-14`, [draft PR #2](https://github.com/Dlomotion/EcoKin-A.i./pull/2); new head `f5d318f801c1a474f27ae73a0a297c6b481eb346`.

- New regression suite against old source failed at invalid-intent assertion; compile succeeded, execution exit 134.
- Corrected command: `g++ -std=c++17 -Wall -Wextra -Werror -pedantic -O2 -fsanitize=undefined -Iwork/ai-oct16/include work/ai-oct16/tests/EcoKinAIRoutePlannerTests.cpp -o /tmp/eco_ai_oct16`, then execution exit 0.
- Raw output: `EcoKin AI route planner contract checks passed`.
- Existing tests plus invalid intent, invalid intent at same destination, duplicate IDs and duplicate/gated-edge cases passed. These are assert-based reference checks, not a count of Unreal tests.
- Header SHA-256: `bcd130c14252cf1bd0991b017eb13b4eac134cb5f767770b06d37f9f077ebbf8`.
- Tests SHA-256: `829f6cc60fa87840fb55ca86604c8b4b42fc2b2971d458ebff86c300bbc194a0`.
- Both files read back from exact head matching reviewed text.
- Hosted exact-head [PR run 38915556108](https://github.com/Dlomotion/EcoKin-A.i./actions/runs/38915556108) and [push run 38915550628](https://github.com/Dlomotion/EcoKin-A.i./actions/runs/38915550628) returned completed/success. Full downloadable hosted logs were not retrieved; local UBSan scope is not extended to hosted CI.
- Reviewer Codex; 2026-10-16; local Linux/GCC 13.3 C++17 environment. No Windows/Unreal execution claim.

## Remaining real-runtime gates
The planner consumes prevalidated value data; it does not authenticate connections, perform navmesh movement, validate actor ownership, stop an in-flight movement task or persist route versions. Server-owned route/context versioning must revalidate when ecology/story/portal/streamed-cell state changes. Never accept a client-supplied cost, segment, actor ownership or readiness Boolean as authority.

Graph/string/allocation bounds, cancellation, tie/near-equal-cost portability, save schema/migration/atomicity, late join/reconnect, game-thread UObject access/GC and performance remain unresolved. This correction does not solve them.

Ordinary gameplay rejection is separate from disconnect-capable RPC validation. Actual serialized intent/schema validation must be implemented in the existing authority path once BUILD is readable. Event-driven abort/revalidation is preferred where actual Behavior Tree/StateTree architecture supports it, not by adding manual every-frame polling loops.

## Research and provenance checked 2026-10-16
- Epic UE5.8 Actor Owner and Owning Connection: <https://dev.epicgames.com/documentation/en-us/unreal-engine/actor-owner-and-owning-connection-in-unreal-engine>. Official reference for server/connection ownership; no implementation copied.
- Epic UE5.8 Behavior Tree Overview: <https://dev.epicgames.com/documentation/en-us/unreal-engine/behavior-tree-in-unreal-engine---overview>. Official reference for event-driven observers/aborts. Applying this to route invalidation is an Echohearts design inference, not executed behavior.
- Existing source is user-owned project reference code. Added standard-library set/enum validation; no borrowed third-party or proprietary Unreal code. No new network service, dependency or credentials.

## Exact next action
Review the same feature PR #2; restore BUILD/patch access and resolve the actual module/API/Build.cs/targets, then execute Windows UE5.8 foundation/UHT/UBT/Automation. Add bounded graph inputs and versioned authority/revalidation in existing runtime architecture before route-following or Nanonite encounter placement.

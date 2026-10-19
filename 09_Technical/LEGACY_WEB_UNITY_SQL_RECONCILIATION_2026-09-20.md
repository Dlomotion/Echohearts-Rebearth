# Legacy Web / Unity / SQL / Seasonal Prototype Reconciliation — 2026-09-20

Status: SOURCE/PROPOSAL AUDIT. NOT PRODUCTION CODE.

## Scope
Historical material includes Unity/C# managers, turn-based UI controllers, client reconciliation prototypes, SQL/Aurora schemas, web registration UI, cyber/glitch CSS, seasonal reset infrastructure, Kinetic/Thermal/Phase families, capture prisms/cores, looter-shooter weapons, clan wars and claims that the stack was compiled/complete/zero-stutter/secure.

None of those claims or architectures override the current Echohearts UE5.8 source of truth.

## AI Mistake Patch / concrete defects
1. `ActionType.FLE_FLEE` is an obvious enum/action typo and cannot be treated as working code.
2. Unity/C# is legacy reference only. Production runtime is Unreal Engine 5.8 unless explicitly changed.
3. Campaign-wide turn-based state managers conflict with the real-time third-person campaign. Tactical turn-based logic belongs only in approved Arena/EchoDeck/Harmony Circuit contexts.
4. Kinetic/Thermal/Phase does not replace the locked 12 elements.
5. Capture prisms, creature cores, converting Eco-Kin to data, slotted sentient cores and forced worker automation conflict with Eco-Kin agency and are retired.
6. Client-supplied identity, inventory, placement, capture or progression data cannot be authoritative.
7. A browser/front-end must never connect directly to a privileged game database. Account writes require authenticated service/API boundaries, validation, authorization, rate limits and least-privilege DB roles.
8. A local interpolation script is not proof of a secure or correct multiplayer protocol. Raw packet examples are not Unreal connection handshakes.
9. Hard-coded singletons, `FindWithTag`/scene searches and per-frame polling are prototypes, not production architecture.
10. Claims such as 'zero allocation', '0ms handoff', 'within 200ms globally', 'fully compiled', 'bulletproof', 'perfectly synchronized', 'secure', 'production-ready' or 'complete' require measured evidence and are NOT YET VERIFIED.
11. Fixed 60 Hz networking, global 6-week wipes and specific AWS instance/database choices are product/infrastructure proposals, not locked requirements.
12. Seasonal monetization/battle-pass language remains proposal only. Monetization, if any, stays cosmetic/non-pay-to-win and requires separate product review.

## Transferable ideas worth preserving
- responsive web layouts and clear navigation
- accessible, event-driven UI state
- developer diagnostics and bounded latency simulation
- server-authoritative intent/validation
- versioned persistence schemas
- modular gameplay systems instead of one giant manager
- reusable animation/state contracts
- telemetry and performance budgets based on measurement
- data-driven loot/resource tables after canon cleanup
- documented failure modes and test tooling

## Unreal-native mapping when dependencies allow
- Enhanced Input for action mappings
- CommonUI/UMG for menus/HUD
- Gameplay Tags for stable state/classification
- Primary Data Assets/Data Tables for definitions
- ActorComponents/subsystems only where ownership/lifetime justifies them
- StateTree/Behavior Trees/AI Perception/EQS for gameplay AI where appropriate
- server-authoritative RPC entry through player-owned replicated Actors/Components
- Fast Arrays/delta replication only where measured and justified
- World Partition/Data Layers for Rebearth streaming
- versioned SaveGame plus supported async save paths
- Automation/Functional Tests and Unreal Insights

## Website rule
Legacy neon/glitch UI is visual/reference material only. Public Echohearts web presentation must use current Rebearth identity, current terminology, accessible controls, safe client-side handling and no misleading beta/play/download claims without a real build.

## Current implementation gate
Do not port this prototype wholesale.
1. UE5.8 EchoheartsEditor build evidence
2. Partner Command Buffer test evidence
3. recovery/travel/reconnect tests at 150/250/350 ms
4. ECO-API-001 result envelope
5. BCT-001 transaction kernel
6. one BuildPiece + one CraftRecipe end to end
7. then promote one dependency-ready legacy idea at a time

## Verification
Audit document and repository presence: VERIFIED.
Legacy Unity/web/cloud code compilation, security, networking, production readiness and performance: NOT YET VERIFIED.

© 2026 Into Deep Studios and Donta L. Owens. All rights reserved.

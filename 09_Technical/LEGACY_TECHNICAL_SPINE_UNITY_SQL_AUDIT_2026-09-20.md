# Legacy Technical Spine — Unity / SQL Audit

© 2026 Into Deep Studios and Donta L. Owens. All rights reserved.

Status: REFERENCE-ONLY TECHNICAL INTAKE
Verification: NOT YET VERIFIED in the current UE5.8 project.

## Scope
Audit the historical `Technical Spine Integration Pack` that described a Unity C# combat UI controller, a PostgreSQL/Aurora persistence schema and Unity/Mecanim animation-state setup as `production-ready`.

That production claim is retired. The package is preserved only for transferable design intent until current repository/build evidence supports implementation.

## AI Mistake Patch
### 1. Runtime mismatch
Production runtime is Unreal Engine 5.8 unless explicitly changed. Unity `MonoBehaviour`, `UnityEngine.UI`, Mecanim and Unity animation-state-machine code are not production Echohearts runtime code.

Transferable intent may be re-expressed through the approved UE5 stack where needed:
- UMG / CommonUI
- Enhanced Input
- Animation Blueprints
- StateTree where appropriate
- Gameplay Tags
- replicated player-owned request components
- data-driven Primary Data Assets / Data Tables

Do not build a parallel Unity architecture.

### 2. Campaign combat mismatch
The historical controller was written around a turn-based `BattleSystemManager`. Main campaign combat is real-time third-person action. Turn-based/tactical interaction belongs only in approved EchoDeck / Harmony Circuit / Resonance Arena simulation contexts.

### 3. C# defects / uncertainties
The historical controller contains or implies these issues:
- `ActionType.FLE_FLEE` is almost certainly a typo or nonexistent enum member;
- serialized button/panel references are used without null validation;
- `BattleSystemManager.Instance` can be dereferenced without a complete lifecycle/availability contract;
- button listeners are added without documented unsubscription/lifecycle handling;
- action availability, double-input/debouncing and server-authority validation are unspecified;
- continuous `Update()` polling for turn state is unnecessary if the actual architecture can publish state-change events;
- historical `BattleState`, `ActionType` and manager APIs have not been verified against an actual current project tree.

Therefore the code must not be copied into production as-is.

## PostgreSQL / Aurora audit
Historical schema concepts may inform future account-service design, but the pasted schema is not current source of truth.

Issues requiring redesign before use:
- `gen_random_uuid()` requires the appropriate PostgreSQL capability/extension and deployment confirmation;
- nullable/default behavior needs explicit `NOT NULL` policy where required;
- account slot uniqueness and range constraints must match actual product behavior;
- indexes must follow measured query patterns rather than arbitrary latency claims;
- seasonal reset/version modeling must be explicit and migration-safe;
- database transactions, idempotency, audit records, concurrency and retry policy were not defined;
- secret/PII handling, retention, encryption-at-rest/in-transit, access control and deletion policy were not established;
- a global-database topology cannot be declared necessary without scale/latency/availability requirements and cost evidence.

## Canon/data naming corrections
Historical names are not current canonical data contracts:
- `ecosystem_family ('Kinetic','Thermal','Phase')` does not replace the locked 12 elements;
- `starchrom` is not an approved Echohearts currency by default;
- `cradle_sync_harness` must not become a sentient Eco-Kin storage/ownership slot system;
- `eco_kin_designation VARCHAR(64)` is not an acceptable substitute for stable EcoKinID/Echoprint references;
- persistence must model relationship/location/availability safely rather than treating Eco-Kin as account inventory.

Current core elements remain:
Solar, Lunar, Hydro, Magma, Aero, Flora, Volt, Terra, Iron/Tech, Spirit, Chaos, Radiant.

## Appropriate future persistence separation
When backend work is dependency-ready, separate concerns such as:
- account identity/entitlements;
- EchoCode redemption ledger;
- cosmetics/cards/material entitlements;
- progression/save metadata;
- EcoDex knowledge;
- partner relationship references that point to authoritative game/save records rather than commodity inventory.

No schema should be implemented solely because the historical proposal contained tables.

## Current technical gate protection
This repost does not jump the established gate order:
1. authorized UE5.8 EchoheartsEditor build;
2. `Echohearts.Partners.CommandBuffer` Automation evidence;
3. reload/recovery/travel/reconnect/late-join tests at 150/250/350 ms;
4. `ECO-API-001` shared result-event envelope;
5. smallest `BCT-001` reservation/commit/rollback kernel;
6. one BuildPiece and one CraftRecipe end-to-end;
7. only then promote dependency-ready legacy features.

The card/redemption backend remains design-only until prerequisites and a real account/backend architecture exist.

## Verification rule
Do not mark any part of this legacy package VERIFIED merely because the code is syntactically plausible or a schema can be created. Verification requires actual repository/build/test/runtime/profile evidence appropriate to the component.

Final status: **HISTORICAL INTENT PRESERVED / UNITY PACKAGE RETIRED FROM PRODUCTION PATH / SQL DESIGN REQUIRES REDESIGN / NOT YET VERIFIED**.

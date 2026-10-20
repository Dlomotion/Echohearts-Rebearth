# UE5.8 Technical Spine — three-system integration gate (2026-10-20)

Status: IMPLEMENTATION TASK / NOT BUILD VERIFIED. This task belongs to the existing daily development workflow; no second canon or runtime.

## 1. Combat UI and Anima-Link
- Implement a UUserWidget or CommonUI view bound by event delegates to a player-owned UActorComponent; use Enhanced Input and Gameplay Tags.
- Main campaign combat is real-time, not turn-based. Server-authorize commands; debounce and validate cooldowns, range and current state.
- Route Eco-Kin damage and combat strain into player stamina/health costs through the bi-directional Anima-Link contract. Map all attribute-dependent calculations to Vibrance, Density, Harmony, Purity.
- Add tests for null binding, duplicate dispatch, disconnect, and invalid commands.

## 2. Secure cloud persistence
- Create a versioned API contract before database implementation. Client never connects directly to PostgreSQL.
- Account identity, entitlements, save metadata, EcoDex discovery and Eco-Kin relationships are distinct data domains; Eco-Kin are not commodity inventory.
- Enforce authentication, least-privilege authorization, idempotent writes, optimistic concurrency, auditability and encryption; define retention/deletion rules.
- Do not import legacy starchrom, cradle harness, Kinetic/Thermal/Phase enum or unverified seasonal wipe rules.
- Gate schema migrations on approved API and recovery/reconnect tests.

## 3. Animation
- Use UE Animation Blueprints with locomotion blend spaces, montage-driven actions, event-driven combat state transitions and gameplay tags.
- No Unity Mecanim controller. Validate interrupt windows, animation-notify authority, replication, and return to exploration.
- Animation never grants damage or immunity without gameplay-side validation.

## Existing production gates (unchanged)
1. Authorized UE5.8 EchoheartsEditor build.
2. Echohearts.Partners.CommandBuffer automation evidence.
3. Reload/recovery/travel/reconnect/late-join tests at 150/250/350 ms.
4. ECO-API-001 result-event envelope.
5. BCT-001 reservation/commit/rollback kernel.
6. One BuildPiece and CraftRecipe end-to-end.

## Acceptance evidence
Record compiler version, engine version, build command, exit code, automation logs, commit SHA and runtime test evidence in the existing verification matrix. No claims of compiled, integrated or 60 FPS verified until evidence exists.

References: 09_Technical/LEGACY_TECHNICAL_SPINE_UNITY_SQL_AUDIT_2026-09-20.md; MASTER_PROJECT_INDEX.md.

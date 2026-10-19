# Legacy Parts 215–255 Code Audit

© 2026 Into Deep Studios and Donta L. Owens. All rights reserved.

Status: SOURCE / PROPOSAL / NOT YET VERIFIED
Runtime target: Unreal Engine 5.8

## Purpose
This file audits the historical Unreal 5.5 code batch covering companion orders, tactical saves, achievements/cloud, dungeons/excavation, swimming/oxygen, altitude, sandbox building, Eco-Kin speed tiers, POIs, fast travel, compass/altimeter/radar UI, and their smoke tests. None of these blocks are considered compiled, verified, production-ready, bulletproof, secure, or final until they exist in the actual Echohearts Unreal project and pass build/test/profile evidence.

## Research basis checked 2026-09-19
Official Epic UE5.8 documentation was used as the primary reference:
- RPCs: https://dev.epicgames.com/documentation/unreal-engine/remote-procedure-calls-in-unreal-engine
- Character Movement networking: https://dev.epicgames.com/documentation/unreal-engine/understanding-networked-movement-in-the-character-movement-component-for-unreal-engine
- World Partition streaming sources: https://dev.epicgames.com/documentation/unreal-engine/world-partition-in-unreal-engine
- Physics Volumes / Fluid Friction: https://dev.epicgames.com/documentation/en-us/unreal-engine/physics-volume-actor-in-unreal-engine
- Async SaveGame: https://dev.epicgames.com/documentation/en-us/unreal-engine/API/Runtime/Engine/UGameplayStatics/AsyncSaveGameToSlot
- GameUserSettings: https://dev.epicgames.com/documentation/unreal-engine/API/Runtime/Engine/UGameUserSettings
- Fast Array replication: https://dev.epicgames.com/documentation/unreal-engine/API/Runtime/NetCore/FFastArraySerializer

## AI Mistake Patch / Continuity QA

### 1. False verification claims
Historical text repeatedly says modules are fully compiled, finalized, hardened, production-ready, secure, or verified. No build logs, UHT output, Automation reports, dedicated-server evidence, profiling traces, packaging logs, or runtime artifacts are attached.

Decision: all such claims are RETIRED. Every module remains NOT YET VERIFIED.

### 2. Wrong production version
The batch targets UE 5.5. Current Echohearts production target is UE 5.8.

Decision: concepts may survive, but APIs/configs must be checked against UE5.8 before implementation.

### 3. POI fast-travel RPC architecture is invalid as written
`UEchoPOIFastTravelManager` is shown as a `UWorldSubsystem` with a `UFUNCTION(Server, Reliable)` request. Epic documents RPCs as functions on replicated Actors or Actor Components, with ownership determining execution.

Correct direction:
`Local Input/UI -> owned PlayerController/Pawn/replicated request component -> server validates stable POI ID -> authoritative POI service/subsystem resolves destination -> preload destination -> safe-arrival validation -> relocation -> replicated travel/discovery result -> local UI event`

The subsystem may own read-only/shared world logic, but it should not be the client RPC endpoint.

### 4. World Partition fast travel cannot use immediate raw TeleportTo only
A destination may be unloaded. Epic documents activating a World Partition Streaming Source at a teleport destination, waiting until streaming completes, then teleporting and disabling the temporary source.

Required travel gates:
- POI discovered/eligible
- quest/boss/Blight gate
- player not in forbidden combat/travel state
- destination streaming loaded
- collision-safe arrival transform
- mount/active Eco-Kin/co-op party handling
- server-authoritative relocation
- persistence/event result

### 5. Client-supplied authority data must be removed
Historical request functions accept values such as `PlayerUID`, `BlockDensity`, `bIsDeepLayer`, tracker pointers, movement components, gear enums, destination coordinates, and reward-context data.

Decision: clients send only bounded intent/stable IDs. Server resolves player identity, owned inventory, capability tags, target block, terrain state, POI definition, restoration state, item/tool entitlement, and reward tables.

### 6. Sandbox grid duplicates BCT-001 and scales poorly as written
A fully replicated `TArray<FEchoSandboxVoxelCellData>` is not the authoritative final building architecture.

Decision:
- Building placement/removal must flow through BCT-001 reservation/validation/commit/rollback.
- Server occupancy should use chunked/spatial integer cells.
- Replicate only relevant deltas, with Fast Array or another proven delta path if the real vertical slice requires it.
- `PlacedByPlayerUID` must be derived from authoritative player identity, not trusted client text.
- Removal requires ownership/permission/ecological rules.

### 7. Companion command terminology conflicts with Eco-Kin agency
`AssaultVortex`, `GatherHarvest`, `IndustrialMining`, genetic-capability language, and passive attack/weight buffs read as forced labor/stat-command systems.

Decision: merge into A.E.G.I.S. partner command language:
- Engage / Protect / Regroup / Assist / Hold / Retreat
- Sanctuary Aptitudes are voluntary capability preferences, not forced worker classes.
- Capability is anatomy/ecology/skill-tag driven, not framed as exploitable genetics.
- Do not introduce Attack/Weight as new public Eco-Kin stats. Public stats remain Vibrance, Density, Harmony, Purity.

### 8. The so-called radial command widget is not radial
The Slate example uses `SVerticalBox` and buttons, while claiming a radial ring. `HoveredSegmentIndex` is not meaningfully updated in the shown code.

Decision: merge into the existing A.E.G.I.S. Quick Wheel / CommonUI plan. Use Enhanced Input, controller/keyboard accessibility, hold/toggle options, readable labels, icon+text, reduced-motion mode, and no duplicate command UI.

### 9. Swimming code has a concrete API error
The historical code writes `MoveComp->FluidFriction`; in UE5.8 Fluid Friction is a property of `APhysicsVolume`, not `UCharacterMovementComponent`.

Correct direction:
- water Physics Volume / water-state authority
- Character Movement `MOVE_Swimming` and swimming speed/buoyancy settings
- server-authoritative submersion/oxygen state
- gear entitlement validated server-side
- environmental survival effects routed through existing player survival/attribute rules

### 10. Altitude must not grant flight by Z coordinate
The old altitude manager automatically switches to `MOVE_Flying` above a hard Z threshold.

Decision: altitude zones describe environmental pressure/weather/biome state only. Flight requires approved anatomy, flying Eco-Kin, player gear, mount state, or explicit movement capability. High Z alone never grants flight.

Also, `PrimaryComponentTick.bCanEverTick = false` means the shown manual `TickSpatialAltitudeEvaluation()` is not an engine tick unless another system calls it.

### 11. Graphics settings should not reinvent GameUserSettings
The custom graphics SaveGame duplicates Unreal's `UGameUserSettings`, which already owns resolution, scalability, frame rate, HDR and related user settings.

Decision: extend/subclass `UGameUserSettings` only when Echohearts-specific options require it. Do not hardcode an 8K texture pool as a universal profile.

### 12. SaveGame async implementation is unsafe/incorrectly layered
The historical graphics code manually launches `AsyncTask` and calls `UGameplayStatics::SaveGameToSlot` from the worker lambda while retaining a UObject pointer.

Epic provides `UGameplayStatics::AsyncSaveGameToSlot`, which serializes appropriately and performs platform-specific write work asynchronously.

Decision: use the engine async SaveGame path for active-play autosaves. Keep synchronous saves only for bounded pause/menu cases when appropriate.

### 13. Cloud/Steam implementation is not cross-platform or proven
The batch directly includes Steam headers, manually calls `SteamAPI_Init()`, writes raw Remote Storage files, uses SteamDevAppId 480 in config, and calls raw byte serialization 'encrypted'. `FMemoryWriter` serialization is not encryption.

Decision:
- Do not call this encrypted.
- Keep platform integration behind one service interface.
- Gameplay authority emits achievement/milestone events; the owning platform/user service performs platform achievement/cloud operations.
- Do not hardwire Steam throughout gameplay code.
- SteamDevAppId 480 is development/test-only, never a production AppID.
- No platform SDK implementation is VERIFIED until SDK/plugin/license/platform tests exist.

### 14. Smoke tests frequently prove almost nothing
Problems include:
- unknown/unproven `UTransientBufferUtil::GetMockWorld()` helper
- returning success when world setup fails
- `Duration > 0.0f` treated as proof of stability
- no expected-state assertions
- no multiplayer ownership/replication proof
- no streaming completion assertion
- no save round-trip assertion
- no cleanup/leak instrumentation
- Server RPC functions called locally rather than through real network conditions

Decision: replace with real Unreal Automation/Functional tests using explicit setup failure, state assertions, authority paths, request retry/idempotency tests, network emulation, load/reload/reconnect, World Partition streaming proof, and Unreal Insights/profile evidence.

### 15. Procedural dungeon stress test would accumulate actors
Repeated authoritative generation spawns rooms with `AlwaysSpawn`, no deterministic seed contract, no teardown between generations, and no collision/layout validation.

Decision: do not implement this as-is. First decide whether Deep Root Tunnels need authored modular rooms, procedural instancing, or hybrid generation. If procedural generation survives design review, require deterministic seed, bounded room graph, overlap checks, teardown/reset, save/reload identity, and reproducible tests.

### 16. Excavation trusts client-derived geology
`BlockDensity` and `bIsDeepLayer` are passed into the server request.

Decision: client sends target/cell ID and tool intent. Server reads authoritative Living Crust stratum/material, ecological veto, reach, tool, stamina/resource cost, and reward table. This must connect to Living Crust and BCT-001 rather than form a parallel digging economy.

### 17. POI/speed data should be data-driven and canon-safe
Hardcoded `Windy City Sanctuary Outpost`, `Abyssal Sewage Tunnels`, raw coordinates, 'legendary apex velocity', and rarity-based speed tiers are implementation placeholders, not canon.

Decision:
- POIs come from approved Rebearth location definitions.
- Use stable IDs, preferably `FName`, Gameplay Tags, or Primary Asset IDs according to the owning data system.
- Locomotion is based on anatomy, species profile, terrain, status and authored movement data, not rarity alone.

### 18. Dedicated server deployment text is only a template
The hardcoded systemd unit (`User=ubuntu`, fixed paths, binary name, `KillMode=process`) is not production deployment proof.

Decision: keep deployment scripts out of the implementation gate until the actual packaged server binary, hosting target, service account, logs, health checks, restart strategy, firewall/ports, secrets, patching and observability are defined.

## Preserve these useful ideas
- Server-authoritative requests
- Stable POI registry concept
- World-state-gated fast travel
- Altitude/pressure region classification
- Underwater oxygen and pressure gameplay
- Integer grid coordinates for build occupancy
- Automated tests as a requirement
- Data-driven loot/POI definitions
- Weak references in UI where appropriate
- Headless/dedicated-server compatibility goals
- Compass/altimeter/radar concepts, after merging them into the current A.E.G.I.S./CommonUI UX architecture

## Required implementation order
Do not jump current project gates.

1. Authorized UE5.8 EchoheartsEditor build.
2. `Echohearts.Partners.CommandBuffer` evidence.
3. 150/250/350 ms reload/recovery/travel/reconnect/late-join tests.
4. ECO-API-001 shared authoritative result-event envelope.
5. BCT-001 smallest reservation/commit/rollback kernel.
6. One BuildPiece + one CraftRecipe end to end.
7. Only then promote one legacy Parts 215–255 feature at a time, starting with POI/Fast-Travel authority and World Partition streaming.

## Verification status
- Code compile: NOT YET VERIFIED
- UHT: NOT YET VERIFIED
- Dedicated server: NOT YET VERIFIED
- Multiplayer ownership/RPC: NOT YET VERIFIED
- World Partition fast travel: NOT YET VERIFIED
- Save/cloud/platform services: NOT YET VERIFIED
- Performance claims: NOT YET VERIFIED
- Security/anti-cheat claims: NOT YET VERIFIED

This audit supersedes all historical claims that Parts 215–255 are already finalized or production-ready.
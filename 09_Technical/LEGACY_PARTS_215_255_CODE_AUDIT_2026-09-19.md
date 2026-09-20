# Legacy Parts 215–255 Code Audit

Status: **SOURCE/PROPOSAL — NOT YET VERIFIED**

This file preserves the historical UE5.5-generated systems while explicitly preventing unsupported production claims from entering the live codebase.

## Included historical areas

- Companion commands and task assignment
- Radial tactical UI
- Tactical saves
- Vendor pricing
- Achievements/cloud synchronization
- Procedural dungeon/excavation
- Swimming/oxygen
- Altitude zones
- Sandbox/voxel construction
- Eco-Kin speed tiers
- POI registry and fast travel
- Compass/altimeter/subterranean radar widgets
- Associated smoke/stress tests

## Required corrections before implementation

1. **RPC authority:** client requests must enter through a replicated player-owned Actor/Component. A `UWorldSubsystem` is not itself the correct client RPC origin.
2. **Server validation:** clients send bounded intent/stable IDs only. Server resolves player identity, inventory ownership, Eco-Kin capability, terrain block, depth/density, POI destination, rewards, and world state.
3. **Fast travel:** do not call `TeleportTo()` into an unloaded World Partition destination. Preload destination cells with a streaming source, validate safe arrival, relocate, then release the temporary source.
4. **Sandbox replication:** do not replicate an unbounded monolithic `TArray` for the entire world. Use authoritative chunk/spatial indexing and relevant delta replication/Fast Array only where justified.
5. **Swimming:** historical code incorrectly treated `FluidFriction` as `UCharacterMovementComponent` state. Fluid friction belongs to the water/physics volume; swimming speed and movement belong to Character Movement.
6. **Altitude:** Z-coordinate alone must never grant `MOVE_Flying`. Flight remains anatomy/equipment/capability driven.
7. **Testing:** tests that return success when no test world exists, call unknown helpers, or only assert `Duration > 0` are not verification. Replace with supported Unreal automation/functional/network fixtures, explicit state assertions, failure-path tests, and Unreal Insights measurements.
8. **Saves/settings:** use supported Unreal SaveGame/async pathways for active-play persistence where appropriate and `UGameUserSettings` for user graphics preferences unless a documented reason requires extension.
9. **Platform services:** achievements/cloud providers must remain behind a platform abstraction. Raw serialization is not encryption.
10. **Canon/data:** hard-coded names such as Windy City, sewage-layer labels, coordinates, or retired geography are placeholders only. Consume approved Rebearth data assets/registries.
11. **Eco-Kin agency:** command/task systems must not turn partners into forced workers or introduce non-canon public stats such as generic Attack/Weight.
12. **Excavation:** merge with Living Crust / Deep Root Tunnels. Geology and rewards are resolved by authoritative world data, not client-supplied `BlockDensity` or `bIsDeepLayer`.

## Promotion gate

No legacy module is promoted until:

`actual repo inspection → UE5.8 API reconciliation → UHT/editor compile → dedicated-server compile if relevant → automated/functional tests → multiplayer/late-join/reconnect tests → save migration tests → Insights/profile evidence → canon/data review`

## Current priority order

1. UE5.8 authorized Editor build
2. `Echohearts.Partners.CommandBuffer` evidence
3. Reload/recovery/travel/reconnect/late-join network tests
4. ECO-API-001 shared result-event envelope
5. BCT-001 reservation/commit/rollback kernel
6. One BuildPiece + one CraftRecipe end-to-end proof
7. POI/Fast-Travel authority + World Partition streaming contract
8. Sandbox replication model
9. Swimming/altitude reconciliation
10. Promote remaining legacy features one at a time

© 2026 Into Deep Studios and Donta L. Owens. All rights reserved.

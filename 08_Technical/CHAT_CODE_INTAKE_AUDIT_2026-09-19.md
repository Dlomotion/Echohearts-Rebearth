# Echohearts Chat Code Intake Audit — 2026-09-19

© 2026 Into Deep Studios and Donta L. Owens. All rights reserved.

**Status:** SOURCE INTAKE / QA
**Runtime target:** Unreal Engine 5.8
**Verification:** NOT YET VERIFIED

## Purpose
This file records which ideas from pasted technical drafts are useful, which are incompatible with Echohearts canon, and which code claims must not enter production without repository/build evidence.

## Production rule
Do not copy outside-game code, terminology, item names, mechanics, or identities. Transfer only general engineering principles that are independently implemented for Echohearts.

## Accepted concepts
The following concepts are useful and may be retained as architecture direction:
- server-authoritative gameplay requests,
- authoritative event IDs and deduplication,
- asynchronous saves for active-play autosaving,
- data-driven asset definitions,
- Gameplay Tags for hierarchical rules,
- replicated movement/state where necessary,
- pooled presentation for repeated UI events such as floating combat text,
- time-of-day and world-threat state as separate systems,
- procedural distribution used as a secondary authored-world tool rather than the sole world generator,
- modular building/crafting transactions,
- separation of gameplay authority from local UI/VFX presentation,
- rollback and recovery for failed transactions.

## Canon-incompatible concepts to retire or redesign
The pasted drafts repeatedly include mechanics that conflict with current Echohearts rules. These remain reference-only and must not enter active runtime:
- capture spheres, capture grenades, capture probability, containment cages, and captured-creature databases,
- forced Eco-Kin work assignments,
- forced evolution/modification,
- body/creature fusion,
- Eco-Kin as inventory objects,
- copied game-specific names and cross-franchise item identities,
- imported weapon catalogs from other games,
- direct campaign/mechanic cloning,
- battle-royale framing as the main game identity,
- generic Sanity/Strength/Agility stat overlays replacing Vibrance, Density, Harmony, Purity,
- claims of "zero rubberbanding," "complete," "secure," or "production-ready" without evidence.

## Technical issues found in pasted code
### Save engine draft
Useful idea: binary serialization and explicit save/load flow.

Issues:
- Writing raw bytes with `FArchive` is not encryption and must not be described as "highly secure encrypted files."
- No schema/version migration contract is shown.
- No integrity/checksum or authenticated encryption is shown.
- No atomic temp-file/replace flow is shown.
- Directory creation/failure handling is incomplete.
- Direct raw-file management bypasses Unreal SaveGame facilities without a demonstrated need.

Production direction: use versioned SaveGame data and asynchronous save/load for normal active-play persistence unless a measured requirement justifies custom binary storage.

### Day/night threat matrix draft
Useful idea: world time can influence threat state.

Issues:
- One directional-light pitch is not a complete atmospheric system.
- The code mixes rendering, time authority, and difficulty scaling in one actor.
- No multiplayer authority/replication policy is defined.
- No seasonal/biome-specific world-state integration is defined.
- A universal 1.0-to-3.5 threat multiplier would flatten authored encounter design.

Production direction: separate authoritative world clock, regional threat model, and local presentation.

### Procedural loot draft
Useful idea: deterministic noise can help cluster world resources.

Issues:
- The sample logs a selection but does not actually spawn or persist a node.
- Z is hard-coded rather than resolved to terrain/world geometry.
- No deterministic seed/version contract is shown.
- No biome, ecology, depletion, respawn, World Partition, save, or multiplayer ownership rules are shown.

Production direction: authored spawn pools + deterministic regional rules + persistent depletion/restoration state.

### Combat processor draft
Useful idea: centralize combat/status resolution.

Issues:
- Generic Kinetic/Fire/Cryo taxonomy does not match the current Echohearts element model.
- A function taking `CurrentTargetHealth` and returning new health bypasses a full authoritative attribute/effect model.
- No resistance, immunity policy, source/target tags, prediction, replication, event ID, or effect duration contract is present.

Production direction: keep Vibrance, Density, Harmony, Purity as public stats and use GAS/Gameplay Tags for authoritative combat effects where appropriate.

### Network character draft
Useful idea: server validation and replicated state.

Issues:
- A distance-only server placement check is insufficient.
- Structure type, inventory cost, ownership, collisions, region permissions, ecological vetoes, replay protection, and world revision are missing.
- "zero rubberbanding" is unsupported until measured dedicated-server tests exist.
- Captured-creature count conflicts with current canon.

Production direction: ECO-API-001 + BCT-001 request/validation/commit flow.

### HUD draft
Useful idea: separate UI presentation from gameplay state.

Issues:
- Generic health/ammo/mold UI does not represent the current Journey Journal/A.E.G.I.S. UX direction.
- UI must not determine gameplay state.
- High-frequency combat text should use pooling/deduplication rather than per-hit widget creation.

Production direction: A.E.G.I.S. Quick Wheel, Journey Journal, clear world-state warnings, pooled transient combat/status presentation.

### Capture component draft
Status: RETIRE / REDESIGN.

Reason:
- capture probability based on lowering health conflicts with current Eco-Kin agency rules,
- spheres/grenades/captured databases conflict with Kindling, Havenlink, Bond Registry, and rescue-first systems,
- base duties framed as forced assignment conflict with Sanctuary-helper rules.

### Quest/dialogue draft
Useful idea: branching dialogue and persistent consequences.

Issues:
- one morality integer is too coarse for Echohearts.
- choices should write explicit world/NPC/Eco-Kin/faction state rather than a single good/bad axis.

Production direction: persistent choice flags + relationship/world-state consequences + D.A.H.L.I.A. World Memory Director validation.

### Weapon matrix draft
Status: REDESIGN.

Reason:
- direct outside-game weapon identities/sources are prohibited,
- the game should use original Keeper tools/Echo weapons,
- weapon data should be Primary Asset/Data Asset driven,
- firearm dominance must not replace rescue/restoration combat identity.

### Building component draft
Useful idea: snap placement, structure types, validation.

Issues:
- `CoreMinimal.PIE.h` is not an appropriate production include.
- raw `FVector` values should not be authoritative grid keys.
- placement ownership, cost reservation, ecological veto, idempotency, replication, persistence, rollback, and streaming recovery are missing.
- a single component should not own every building responsibility.

Production direction: `BCT-001_BUILDING_CRAFTING_TRANSACTION_CONTRACT.md`.

### Character locomotion draft
Useful idea: walk/sprint/slide/vault/glide states.

Issues:
- outside-game naming must be removed.
- direct teleports to vehicle door positions are not a robust traversal/interaction system.
- sprint state must be defined by Echohearts code/input state rather than assuming a stock CharacterMovement `IsSprinting()` API.
- multiplayer prediction/reconciliation and animation authority are not addressed.

Production direction: original Echohearts locomotion spec, then implementation only after the actual character stack is inspected.

### Procedural landscape generator draft
Useful idea: deterministic data can support secondary terrain variation.

Issues:
- one Perlin height field is not an AAA open-world landscape pipeline.
- arbitrary color constants are not a biome/art-direction system.
- copied outside-game biome naming is rejected.
- full procedural voxel generation conflicts with the existing authored-landscape + optional Living Crust layer direction.

Production direction: authored World Partition landscape first; Living Crust/destructible strata only where gameplay requires it.

## Current engine/runtime decision
- Unreal Engine 5.8 is the sole production runtime target.
- Godot/Unity/standalone examples may be studied as reference only, not maintained as parallel implementations.
- Avoid unnecessary C++; prefer data, Blueprint configuration, Gameplay Tags, and UI specs where they solve the problem cleanly.

## Current execution order
1. Build `EchoheartsEditor` under UE 5.8.
2. Run `Echohearts.Partners.CommandBuffer`.
3. Test reload/recovery marker at 150/250/350 ms.
4. Implement `ECO-API-001`.
5. Implement the smallest `BCT-001` reservation/commit/rollback kernel.

## Evidence gate
No pasted code in this audit is considered runtime-verified. Compilation, Automation, dedicated-server replication, persistence, prediction reconciliation, performance, and packaging remain **NOT YET VERIFIED** until evidence is produced from the actual repository/project.

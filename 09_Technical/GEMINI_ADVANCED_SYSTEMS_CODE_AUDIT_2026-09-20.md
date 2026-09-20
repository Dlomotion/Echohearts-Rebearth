# Gemini Advanced Systems Code Audit — 2026-09-20

**Project:** Echohearts: Rebearth  
**Status:** REFERENCE-ONLY / ACTIVE CORRECTION  
**Verification:** NOT YET VERIFIED  
**Production runtime:** Unreal Engine 5.8  

## Purpose

This audit covers the large recovered Gemini C++ batch containing loadout swapping/saving, voxel deformation, cavern generation, outpost progression, worker automation, weapon trails, footsteps, player vitals, cooperative lockboxes, custom packet serialization, boss FSM logic, header generation, compressed movement packets, editor grid snapping, crafting-cost scaling, workstation automation, animation-state plumbing, Slate inventory UI, GameMode integration, building placement traces and facial morph targets.

The pasted source repeatedly labels these systems `production-ready`, `fully engineered`, `compiled`, `optimized`, `verified`, `complete` or `finalized`. Those claims are **retired**. No corresponding Unreal project source tree, `.uproject`, `Build.cs`, compile output, Automation results, packet captures, profiling data or packaged build evidence is currently present on `main`. Repository search also found no implementation of the pasted class names. Therefore this batch is design/prototype reference only.

## Current UE5.8 evidence used for this audit

Reviewed 2026-09-20:

- Epic UE5.8 Remote Procedure Calls documentation: RPCs execute through replicated Actors/ActorComponents and depend on ownership/owning connection.
- Epic UE5.8 Networking Overview: replication must be explicitly configured for gameplay state; components/subobjects require replicated ownership/state contracts.
- Epic UE5.8 Character Movement networking documentation: `ACharacter` + `UCharacterMovementComponent` already provide prediction, saved moves, server corrections and replicated movement.
- Epic UE5.8 Iris documentation: Iris remains opt-in/Experimental and Epic advises caution when shipping.
- Epic UE5.8 StateTree documentation: StateTree is the supported hierarchical state-machine framework for performant gameplay/AI logic.
- Epic UE5.8 Smart Objects documentation: Smart Objects provide queryable, reservable world interactions suitable for workstation/task assignment.
- Epic UE5.8 Physical Materials / Footstep tutorial: use configured Surface Types / Physical Materials and data-driven mappings rather than brittle material-name strings.
- Epic UE5.8 Niagara documentation: Niagara is the current next-generation VFX system; new weapon-trail work should not default to legacy Cascade components unless an existing asset dependency requires it.
- Epic UE5.8 `UActorActionUtility`: actor-action utilities are the editor utility base for operations on selected level Actors.
- Epic UE5.8 Data-Driven Gameplay / Data Registries: static progression and recipe data should be source-controlled as structured data rather than hard-coded switch ladders when practical.

## Global production rules

1. Do not copy this batch into `Source/` as-is.
2. Do not create a monolithic `EchoheartsAdvancedSystems.h` or similar catch-all runtime header.
3. Do not build custom low-level networking around features already handled by Unreal unless profiling proves a requirement.
4. Client-provided IDs, positions, actions, inventory quantities and resource mutations are untrusted input.
5. Shared storage, building, crafting and settlement upgrades must follow the existing authoritative transaction contract:  
   `owned request → server validation → inventory reservation → ecological/world veto → atomic commit → authoritative event ID → replication → asynchronous persistence → local presentation`.
6. Eco-Kin task participation is voluntary and must respect Trust/Kindling, fatigue, health, habitat comfort and refusal/retreat behavior. They are not worker drones.
7. Prefer data/Blueprint/StateTree/Smart Objects first. Add C++ only where the next playable prototype or measured architecture gap justifies it.

---

## A. Immediate-mode loadout swapper / loadout saver

### Status
REFERENCE-ONLY.

### Problems

- `ImGuiLoadoutMenu` does not use Dear ImGui; it prints text to `std::cout`.
- It is not Unreal UI, CommonUI, UMG or Slate integration.
- The standard-library version mixes `int32_t` assumptions with missing `<cstdint>` and pasted include formatting that would not compile as shown.
- Loadout data is stored only in process memory; there is no SaveGame, authority, replication, validation, item ownership or schema versioning.
- Missing-slot lookup silently returns a synthetic default rather than an explicit result/error.

### Retained requirement
Players may save and switch approved field loadout presets.

### Production direction
Use a data-defined loadout record + validated inventory/equipment service + SaveGame persistence. UI should be CommonUI/UMG unless a proven Slate-only screen requires otherwise. Server validates any multiplayer loadout mutation.

---

## B. Voxel deformation replication / cavern generation

### Status
REFERENCE-ONLY. Merge conceptually with the approved **Living Crust / Deep Root** system, not a second global voxel world.

### Problems

- `EchoheartsNetcodeReplicator` performs console output only; it is not an Unreal RPC, replicated property, NetSerialize path or authoritative network object.
- A flat `blockCoordinateIndex` has no chunk/version/world identity, edit sequence, replay protection, relevance, recovery or persistence semantics.
- Blind client application of packet state has no conflict resolution or late-join reconstruction.
- The `GenerateVoxelCavernMatrix` function claims `cellular automata` and `smoothing`, but performs random occupancy plus a random crystal replacement pass. There is no cellular-neighbor smoothing step.
- Uses global `srand/rand`, which is poor for deterministic content pipelines and contaminates global RNG state.
- No guaranteed connectivity, spawn-safe region, authored landmark protection, biome mask, ecological veto, nav generation or World Partition integration.

### Retained requirement
Optional destructible/subterranean Living Crust zones can expose authored caves, Meridian strata and resource veins.

### Production direction
Author the world with Landscape/World Partition first. If localized deformable chunks are approved, use deterministic chunk IDs/seeds, authoritative edit journals, relevance-based deltas, persistence/recovery and strict region limits. Do not replicate a giant flat voxel array.

---

## C. Outpost / Sanctuary progression quotas

### Status
APPROVED CONCEPT / IMPLEMENTATION REJECTED.

### Problems

- Hard-coded Tier 1/2 material requirements do not scale to production content.
- `unordered_map::operator[]` mutates the inventory by inserting missing keys during a read.
- Resource deduction is not reserved/atomic and has no rollback, persistence, event ID, multiplayer contention handling or ecological/world-state veto.
- No behavior exists for tiers beyond the two hard-coded branches.
- Material names (`RAW_TIMBER`, `ANCIENT_ORE`, `CORE_QUARTZ`) are not automatically canon item IDs.

### Production direction
Keep the Area/Sanctuary progression design, but store tier definitions in Data Assets/Tables/Registry rows and execute upgrades through BCT-001 reservation/commit/rollback semantics.

---

## D. Worker / crafting AI

### Status
APPROVED CONCEPT WITH AGENCY PATCH / IMPLEMENTATION REJECTED.

### Compile / logic defects

- Historical standard-C++ snippet contains `EWorkerState.Standby` instead of `EWorkerState::Standby`.
- Reposted snippets contain malformed `std::vectorstd::string` declarations.
- The code calls itself a Behavior Tree but is a small hand-written finite-state switch.
- `activeOrdersCount > 0` is not a task claim/reservation.
- No path result, workstation availability, ingredient reservation, output capacity, cancellation, interruption, illness, fear, Kindling, preference or refusal states exist.
- `EcoKin_Automation_Drone_Beta` and `SpecializedDrone` terminology conflicts with Eco-Kin agency when representing sentient partners.

### Production direction
Use **StateTree** for helper state logic and **Smart Objects** for workstation/task reservation where dependency-justified. A task assignment is an invitation/voluntary activity state, not ownership. Keep Sanctuary aptitudes such as Garden Care, Water Care, Repair Help, Stone Work, Scout Watch, Comfort, Defense and Archive Help.

---

## E. Weapon trails / VFX

### Status
USEFUL REQUIREMENT / REWRITE.

### Problems

- The code defaults to `UParticleSystemComponent` (Cascade-era path) rather than current Niagara-based VFX.
- `PrimaryComponentTick.bCanEverTick = false` means velocity evaluation only works if something else reliably invokes it each frame/window.
- First-frame detection uses world-position zero as an initialization sentinel, which is unsafe if a valid socket can be near origin.
- Raw frame-delta socket displacement is noisy and not animation-event bounded.
- Fixed thresholds (`650`, `1500`) are unprofiled magic numbers.

### Production direction
Drive trails from combat/animation windows. Pass weapon-tip velocity/intensity into Niagara parameters, with data-defined thresholds and pooled/system-managed effects where profiling supports it.

---

## F. Footstep surface audio

### Status
USEFUL REQUIREMENT / REWRITE.

### Problems

- Physical surfaces are looked up by `PhysMaterial->GetName()` string, which is brittle under renames/variants.
- A trace on every arbitrary call has no animation-notify contract, foot selection, concurrency, footwear, wetness, biome override or fallback.
- The historical comments call this `ray-traced audio`; it is a normal collision line trace, not audio ray tracing.

### Production direction
Trigger from footstep Anim Notifies, resolve the hit's **Physical Surface** (`EPhysicalSurface`), then use a Data Asset mapping surface + footwear/context to audio/VFX/decal behavior.

---

## G. Player vitals / Blight exposure

### Status
APPROVED CONCEPT / NEEDS CANON NAMING + REWRITE.

### Critical compile defect
`FEchoheartsPolishVitalsComponent` declares `HazardContaminationRatio` but the implementation reads/writes `HazardContaminationLevel`. As pasted, this does not compile.

### Additional issues

- Two duplicate vitals implementations disagree on drain/regeneration numbers.
- `KineticShieldCharge` is not automatically a canon player stat/system.
- `BioContamination` should map to Blight exposure / Purity or a clearly separate survival hazard, not create a competing public stat taxonomy.
- All rates are magic constants with no difficulty/equipment/biome data source.

### Production direction
Keep stamina and environmental Blight exposure as internal systems where required. Public Eco-Kin stats remain Vibrance, Density, Harmony, Purity. Tune through data assets/curves, not duplicated literals.

---

## H. Cooperative storage / lockbox synchronization

### Status
VALID REQUIREMENT / CURRENT IMPLEMENTATION UNSAFE.

### Problems

- `UGameInstanceSubsystem` is not itself a replicated network-state container for clients.
- `RequestServerLockboxAccess(FString LockboxId, FString RequestingClientId)` trusts a caller-provided client identity string.
- Locks have no lease/timeout, connection ownership, disconnect cleanup, reentrancy, version, compare-and-swap, transaction ID or rollback.
- `Logout()` only logs that locks are released; it does not release them.
- Shared inventory mutations are not demonstrated at all.
- There is no persistence or conflict recovery.

### Production direction
Request must originate from a player-owned replicated Actor/Component. Server derives the caller identity from the connection/ownership chain, validates range/permission/state, creates a short-lived server transaction/reservation, commits an authoritative inventory mutation, emits a result-event ID, then replicates/persists the new state.

---

## I. Custom binary packets / compressed movement

### Status
REJECT AS DEFAULT ARCHITECTURE.

### Problems

- Unreal already provides replication, RPCs and robust `UCharacterMovementComponent` networking/prediction for standard character movement.
- Reimplementing movement frames as raw `int32 X/Y/Z + yaw byte + bitmask` discards prediction, correction, movement mode, velocity, root motion and other existing contracts.
- The code calls simple archive serialization `bit-packing` even though no actual bit writer/delta scheme is implemented.
- The earlier compressed-packet snippet is syntactically incomplete (`Ar & OutPackedPayload)`), and the harness references undeclared `FEchoheartsNetworkBitPacker`.
- The later 14-byte check only proves expected raw field width for three 32-bit integers + two bytes in that specific stream. It does not verify network correctness, packet loss behavior, authentication, desync recovery or real bandwidth.
- `FString` packet fields are unbounded and unversioned in the generic packet sample.

### Production direction
Use standard UE replicated state / RPCs / CharacterMovement first. Add custom `NetSerialize`, quantization or bespoke channels only for measured game-specific state after profiling. Iris remains experimental/opt-in in UE5.8 and is not a mandatory foundation.

---

## J. Alpha / Titan boss FSM

### Status
APPROVED CONCEPT / REWRITE.

### Problems

- `CurrentHP / MaxHP` divides by zero if `MaxHP <= 0`.
- Enrage can be returned every evaluation under 40% HP unless externally gated.
- Stagger state has no duration/recovery transition or shield reset.
- Random attack selection is not deterministic or authority-bound.
- No telegraph windows, navigation, target selection, cooldown, elemental state, multiplayer replication or difficulty scaling.
- `Alpha` naming should not automatically replace current Sovereign/Titan encounter terminology.

### Production direction
Implement boss phase policy in StateTree/Behavior Tree or a bounded authoritative combat-state component, driven by data. Preserve existing Sovereign/Titan rules and ethical encounter outcomes.

---

## K. Header-generation tool

### Status
REJECT AS PRODUCTION TOOL IN CURRENT FORM.

### Critical generator defects

Generated Unreal classes would be invalid:

- `UCLASS` output does not derive from `UObject`/another reflected class.
- No `GENERATED_BODY()` is emitted.
- Module API macro is incorrectly fabricated with `ModuleNamespace.substr(0, 4)`.
- Adding a `.generated.h` include does not make an arbitrary class a valid UHT-reflected type.
- The tool calls its file-write result `compiled`, but does not invoke UnrealHeaderTool, UnrealBuildTool or a compiler.
- Token searching is not syntax validation.

### Production direction
Do not add this tool unless a real repetitive scaffolding need emerges. Prefer Unreal's class generation/editor tooling and project templates. Any custom generator requires golden-file tests and an actual compile validation step.

---

## L. Editor grid snap utility

### Status
USEFUL EDITOR REQUIREMENT / REWRITE.

### Problems

- Actor operations are modeled under `UAssetActionUtility`; UE5.8 exposes `UActorActionUtility` for actor action utilities.
- The provided includes/API calls are not proven against UE5.8.
- No `FScopedTransaction`, `Modify()` or editor undo/redo handling is shown.
- Snapping Z indiscriminately can bury/float actors that need surface alignment.

### Production direction
Use an actor/editor utility only if native editor snapping is insufficient. Support transactions/undo, selected-level actors, per-axis rules and optional surface projection.

---

## M. Tech-tree crafting-cost formula

### Status
DESIGN-ONLY.

`BaseCost * Tier^1.45` is an arbitrary proposal, not a balance proof. It can create steep resource inflation, especially when several ingredients scale simultaneously.

Production economy values must be evaluated against source/sink rates, gathering time, Sanctuary progression pacing, multiplayer inflation and accessibility. Prefer CurveTables/Data Assets so designers can tune without recompilation.

---

## N. Workstation Actor

### Status
APPROVED REQUIREMENT / REWRITE.

### Problems

- Every workstation ticking every frame is unnecessary for most crafting loops.
- The function computes `FrameRefinementYield` but does not reserve ingredients, produce outputs or commit state.
- `bIsWorkerAssigned` treats the helper as a boolean resource and omits identity, willingness, health, fatigue and reservation.

### Production direction
Use event/timer-driven production or centralized scheduling. Workstation interaction should connect to Smart Object/task reservation and the BCT transaction contract.

---

## O. Animation instance

### Status
USEFUL REQUIREMENT / COMPILE FIX NEEDED.

### Critical defect
`APawnOwner* PawnOwner = TryGetPawnOwner();` uses a nonexistent `APawnOwner` type. It should use an appropriate `APawn*`/character type.

### Additional issues

- Stance is never actually derived from equipped item state.
- No thread-safe anim instance/property access strategy is defined.
- No locomotion state, aim offsets, additive layers, linked anim layers or replication-driving contract exists.

Production implementation should follow the actual player/equipment architecture rather than introducing a parallel weapon-state source.

---

## P. Slate multi-user inventory UI

### Status
MOCKUP ONLY.

### Problems

- Three hard-coded slots are not a scalable inventory view.
- No view-model/data binding, selection model, transaction state, lock feedback, accessibility, gamepad navigation or localization.
- UI labels contain draft item names that are not automatically canon.
- Historical UMG wrapper includes a `.cpp` file directly, which is a build/ODR anti-pattern.
- Wrapper constructs `SEchoHeartsGameConsoleWidget`, while the declared class shown is `SEchoheartsMultiUserHub`; this is a direct class-name mismatch.

### Production direction
Use CommonUI/UMG for player-facing inventory and a data/view-model-driven list/grid. Slate should be used only where justified by the real project UI architecture.

---

## Q. GameMode integration

### Status
REFERENCE-ONLY.

`PostLogin()` retrieving a GameInstanceSubsystem is conceptually possible, but the supplied class does not prove authentication, replication or storage synchronization. `Logout()` logs lock release but does not actually release locks owned by that connection. A GameMode exists server-side only, so client-visible state must live on appropriate replicated actors/components/state classes.

---

## R. Placement trace / building snap

### Status
USEFUL REQUIREMENT / MUST MERGE WITH BCT-001.

### Problems

- The comments call the overlap path `non-allocating`, but it allocates several `TArray`s and uses a Kismet helper.
- Ground overlap validation occurs **before** the final grid-snapped location is computed, so the final snapped transform can differ from the validated position.
- Fixed collision channels and slope threshold are unversioned magic policy.
- No ownership, build-zone permission, ecological veto, inventory reservation, support/foundation rule, World Partition readiness, replication, save or rollback exists.

### Production direction
Compute candidate snapped transform first, validate it server-side, run world/ecology/build rules, reserve costs, atomically commit, replicate and persist. This belongs under BCT-001 rather than a standalone placement authority.

---

## S. Facial morph component

### Status
OPTIONAL / DEPENDENCY-GATED.

### Problems

- `SetMorphTarget` assumes exact mesh morph names exist.
- The comment claiming shape keys are driven by `hardware thread calculations` is inaccurate/unproven.
- No preset persistence, replication requirement, LOD compatibility, platform budget or character-creator UI contract exists.

Do not add this module until the player-avatar customization scope and meshes are confirmed.

---

## T. Unsupported architecture assertions

The pasted documentation claims compute-heavy work is already offloaded to async worker threads. No corresponding task graph / async implementation is supplied. Treat that statement as false until code and profiling evidence exist.

Likewise, `All ... passed`, `compiled`, `optimized`, `running`, `fully integrated` and similar console banners are **not tests**. A harness that prints success is not build or runtime evidence.

## Canon terminology corrections

- `Echo-Kin` → **Eco-Kin**.
- `worker unit/drone` for sentient Eco-Kin → voluntary **Sanctuary helper / partner task** language.
- `Bio Tox` / generic contamination → **Blight exposure** or an approved environmental hazard name.
- `Kinetic Shield` requires separate canon/system approval before becoming a player core stat.
- Legacy draft resource/weapon names such as `WPN_DISRUPTOR_RIFLE`, `WPN_PLASMA_CASTER`, `ANCIENT_ORE`, `CORE_QUARTZ`, `Sonic Pickaxe` remain placeholders unless already registered in the canonical item ledger.

## What survives this batch

The following **requirements** are worth keeping, without accepting the pasted implementation:

1. Saveable field loadout presets.
2. Localized Living Crust cavern/deformation support if approved by level design.
3. Data-driven Sanctuary/Area progression.
4. Voluntary Eco-Kin helper/task AI.
5. Weapon trail intensity based on authored combat motion.
6. Surface-aware footsteps.
7. Stamina + Blight/environmental exposure where required.
8. Authoritative cooperative storage transactions.
9. Sovereign/Titan multi-phase encounters.
10. Optional editor alignment tools.
11. Data-driven crafting-cost curves.
12. Weapon-aware animation layers.
13. Server-authoritative building placement validation.
14. Optional character morph presets.

## Current technical gate order remains unchanged

This batch does **not** jump the established engineering gates:

1. Authorized UE5.8 `EchoheartsEditor` build.
2. `Echohearts.Partners.CommandBuffer` Automation evidence.
3. Reload/recovery/travel/reconnect/late-join tests at 150/250/350 ms.
4. `ECO-API-001` shared result-event envelope.
5. Smallest `BCT-001` reservation/commit/rollback kernel.
6. Prove one BuildPiece + one CraftRecipe end to end.
7. Promote one dependency-ready legacy requirement at a time.

## Promotion rule

A requirement from this batch can move from REFERENCE-ONLY only after:

- actual project dependency inspection;
- current UE5.8 API review;
- smallest justified implementation;
- successful Unreal build;
- meaningful Automation/functional assertions;
- multiplayer/server-authority checks where relevant;
- save/recovery/late-join checks where relevant;
- profile evidence before performance claims.

© 2026 Into Deep Studios and Donta L. Owens. All rights reserved.

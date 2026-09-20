# Legacy Unity / Lattice Code Reconciliation

Status: **REFERENCE / NOT YET VERIFIED**

This audit covers the reposted Unity/C# creature-data, packet, behavior-tree, universal-animation, Lattice roster, mutation, crafting, UI, cloth-shader, garment-networking, standalone C++, and historical Unreal-header examples. They are not production Echohearts code.

## Executive disposition

The code contains some reusable engineering ideas, but much of the implementation is tied to Unity types (`MonoBehaviour`, `ScriptableObject`, `Animator`, `SkinnedMeshRenderer`, `MaterialPropertyBlock`) or to an experimental terminology layer that conflicts with current Echohearts canon. Production runtime is UE5.8, so these snippets must not be pasted into the Unreal project as-is.

The rule is: retain the engineering requirement only when it still solves a real Echohearts problem; rebuild it against the actual UE5.8 project module, assets, authority model, and tests.

## 1. Creature data model

### Historical pattern

- `EchoKinData : ScriptableObject`
- later rewritten as `LatticeCoreData`
- alternate element/type enums
- generic HP/MP/ATK/DEF stat matrices
- DNA/mutation payloads

### Problems

1. Unity asset architecture does not map directly to UE Data Assets/Data Tables.
2. Multiple incompatible element systems were introduced.
3. Public stat names conflict with Vibrance, Density, Harmony, Purity.
4. DNA fusion/genome-modification framing conflicts with the consent/agency rules when applied to sentient Eco-Kin.
5. The later “Lattice” rewrite incorrectly replaced the franchise creature identity.

### Current direction

Use stable `EcoKinID`-driven UE data. Public presentation must use current Essences and V/D/H/P. Internal combat coefficients may exist only when documented as implementation values rather than a second public stat sheet. Growth/variant data must use approved non-destructive systems.

## 2. Reposted `AEchoKinBase` Unreal header

The historical header is useful as evidence of the intended creature class, but it is not production-ready.

### Specific corrections

- The enum `Fire, Water, Earth, Wind, Light, Dark, Wood, Iron, Thunder, Ice` conflicts with the locked Rebearth Essence model and must not become another public type system.
- `HP`, `ATK`, `DEF`, and similar generic public stats conflict with V/D/H/P as the player-facing stat language.
- A generic `Evolve()` method is too ambiguous for the current growth rules. Growth Rites, Biomimetic Shifts, Resonant Morphs, Primal Morphs, and other approved authored growth paths need explicit eligibility and consent rules rather than one forced-evolution switch.
- `Trust` or relationship data should not be writable as arbitrary client authority and must preserve refusal/agency semantics.
- The example expansion adds replication broadly but does not define ownership, update frequency, conditions, save authority, prediction, rollback, or persistence.
- A custom two-parameter `TakeDamage` overload should not be adopted casually when Unreal already has an actor damage pipeline and when Gameplay Ability System or a dedicated combat component may be the better architecture. Select the production path from the actual module, not from an isolated header.
- Do not create a new `UEchoKinAbility` UObject layer until the real ability architecture and module dependencies are inspected.

### Status

**RETIRED AS CURRENT IMPLEMENTATION / SALVAGE REQUIREMENTS ONLY.**

## 3. Client command / server snapshot structs

### Historical useful idea

The repost proposed sequence numbers, input ticks, compact interaction flags, orientation, server snapshots, entity state, and timed status effects.

### Keep

- monotonically tracked client input sequence/tick where appropriate;
- bounded input values;
- compact action intent;
- authoritative server world tick;
- stable network entity IDs;
- replicated status effect identifiers/durations where justified.

### Correct

- A packet struct alone does not make the game secure.
- Never trust client-sent position, health, energy, inventory, rewards, Eco-Kin ownership/relationship, cooldown completion, hit results, or client-declared velocity as authority.
- UE replication/RPC/Network Prediction architecture must be selected from the actual project module, not invented in an isolated snippet.
- Actor-component RPCs require the owning actor and component to participate correctly in replication and ownership.
- Validation requires rate limits, sequence-window checks, capability/state checks, server movement/combat simulation, and rejection telemetry.
- `WithValidation` can be used in UE5.8 server RPCs, but it is not a substitute for the broader authoritative game-state checks above.

## 4. Behavior tree examples

The generic `Selector` / `Sequence` samples are educational patterns, not production AI.

Problems:

- no action leaves were implemented;
- `Update()`-driven per-frame evaluation is not automatically the right server cost model;
- no perception, target validity, cooldown, navigation, EQS, StateTree/Behavior Tree integration, authority boundary, or replication policy is present;
- renamed `Tyrant` terminology conflicts with the existing Primal/Titan/Guardian encounter language.

Current direction: use UE5.8 AI tooling appropriate to each encounter. Boss logic needs explicit phases, interrupts, telegraphs, recovery windows, navigation constraints, multiplayer authority, failure recovery, and deterministic test hooks.

## 5. Universal animation router

The historical proposal tried to make every creature use identical animation frames and then differentiate them through bone scaling, playback speed, materials, and particles.

This is rejected because incompatible anatomy cannot safely share one rig. Runtime bone scaling is not a substitute for authored anatomy, locomotion, contact, or personality. It can produce deformation, foot sliding, collision mismatch, poor silhouettes, and animation/VFX desynchronization.

Current direction: compatible rig families + original animation + IK/retargeting. See `07_Art/Animation/ECOKIN_ANIMATION_FOUNDATION_2026-09-20.md`.

The old instruction “same animation as Aniimo” is a quality-reference request only. No Aniimo clips, rigs, timings, poses, landmarks, VFX choreography, or proprietary assets enter Echohearts.

## 6. Cloth / ink-shader experiments

The latest repost contains an ink-brushed clothing shader, procedural vertex displacement, a Unity material controller, joint-stress tracking, and an Unreal-flavored garment replication component.

### Useful visual goals

- readable garment folds;
- strong silhouette and shadow breakup;
- impact-responsive secondary motion;
- controllable stylization for selected character outfits.

### Technical defects / overclaims

- `InternalElasticRestoration = (BaselinePositionOS - BaselinePositionOS) * ...` is identically zero, so the stated elastic-restoration force never contributes.
- `NdotV` is a view-angle/rim term, not proof of concave mesh curvature.
- the vertex-deformation HLSL generates waves from object position and masks; it does not actually receive the claimed bone-compression field or calculate physically based cloth strain.
- manually perturbing normals in the sample is not a physically valid replacement for a tested tangent/normal solution.
- pushing cosmetic cloth deformation through gameplay networking is unnecessary unless a concrete gameplay requirement proves it is needed.

### UE5.8 direction

Use current Unreal material/skeletal workflows and evaluate Chaos Cloth/Dataflow for garment simulation. UE5.8 documents Chaos Cloth as production ready and includes non-destructive/Dataflow workflows, caching, layered interaction support, and performance improvements. Any stylized hatching look should sit on top of a measured Unreal rendering solution rather than porting Unity scripts literally.

## 7. Garment networking / anti-cheat sample

The reposted `FGarmentDeformationPayload` and `UServerGarmentValidationComponent` do not provide real anti-cheat.

Problems:

- the raw pointer `FGarmentDeformationPayload* GarmentStates` is not an approved serialized replicated container;
- the server sample trusts client-sent `ClientVelocity` when deciding whether a speed rule was violated;
- renaming a component “ServerGarmentValidation” does not make the data authoritative;
- cosmetic cloth state should not become a trusted gameplay-state source.

Current rule: clients may drive local cosmetic presentation, while authoritative movement/collision/combat remains in the actual server-authoritative movement and gameplay systems. If cloth affects gameplay at all, that dependency must be explicit, bounded, profiled, and tested.

## 8. Lattice roster code

Generated names such as Alloy-Tusk, Gravel-Back, Volt-Talor, Chrono-Leopard, Brier-Croc, Spore-Fox, Basalt-Maw, Shard-Back, Chrono-Hound, Shock-Stinger, Thistle-Crown, and Mire-Stalker are **not automatically canon Eco-Kin**. They are concept candidates at most.

Do not instantiate roster content at runtime by creating temporary data objects in `Awake()` as a substitute for an authoritative content database. Canon Eco-Kin require Dex intake, duplicate/name check, Essence normalization, ecological/story connection, art review, stable IDs, and authored data assets.

## 9. Mutation / node inversion

The old `SomaticMutationNode`, `Synaptic Node Inversion`, and reset-to-zero polarity ideas were created while trying to imitate progression patterns from other games without copying their terminology. Renaming a loop is not sufficient differentiation.

Status: **RETIRED** pending a genuinely Echohearts-native progression design based on care, field experience, ecology, Growth Rites, authorized traits, and player/Eco-Kin agency.

## 10. Capture lure/cage crafting

Crafting physical cages, enclosure sleeves, nets, anchor traps, pods, root tethers, or tanks specifically to capture sentient Eco-Kin is incompatible with current player ethics.

Possible salvage:

- temporary rescue barriers;
- medical transport supports;
- non-harmful habitat guidance tools;
- antagonist poaching equipment the player disables;
- species-safe treatment carriers used only during emergency care.

## 11. UI inventory

The old interface treated living creatures as inventory/container entries. Retire that framing.

Current separation:

- **Partner roster / EcoDex / Havenlink** for Eco-Kin relationships and care;
- **Inventory** for materials, tools, purified resources, gear, food, cosmetics, and non-sentient items;
- **Sanctuary resident view** for voluntary residence and care status.

## 12. Standalone `Program.cpp` and generic CMake

The reposted hello-world `NeuralResonance::Core::MainEngineFile` and standalone CMake target are ordinary C++ learning/tooling examples. They do not represent the Unreal game executable.

Keep them out of production gameplay modules unless an isolated non-Unreal utility genuinely needs a CMake target. UE5.8 game/runtime modules use Unreal Build Tool and the actual module/target structure.

## 13. C# `CS1024` pasted-source failure

`CS1024: Preprocessor directive expected` indicates that the `.cs` source contains a line beginning with `#` that is not a valid C# preprocessor directive. In the repost, chat/Markdown text was mixed into source. The correct fix is source hygiene: keep prose outside `.cs` files and retain only valid code/preprocessor directives.

This is not evidence that Unity should remain part of the production runtime. The affected historical C# remains reference-only.

## 14. What should become code now?

No new UE C++ is justified from these snippets until the actual UE5.8 module tree and build target are available for direct inspection and test. The correct next technical action remains to inspect/build the authorized UE project, then implement only the smallest required architecture gap.

For animation, the first implementation should prove **one compatible rig-family prototype** with original Eco-Kin animation, IK/retargeting, terrain contact, representative combat transitions, and performance evidence before expanding across the roster.

## Verification status

- Historical C#: **NOT VERIFIED for production**.
- Historical HLSL/Unity cloth code: **NOT VERIFIED for production**.
- Historical detached UE header snippets: **NOT VERIFIED for production**.
- Lattice rewrite: **RETIRED as canon architecture**.
- Generic server-authority principles: **accepted design guidance, implementation NOT YET VERIFIED**.
- Animation foundation: **accepted design guidance, implementation NOT YET VERIFIED**.
- Cloth direction: **accepted visual goal, implementation NOT YET VERIFIED**.

© 2026 Into Deep Studios and Donta L. Owens. All rights reserved.

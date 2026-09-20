# Legacy Unity / Lattice Code Reconciliation

Status: **REFERENCE / NOT YET VERIFIED**

This audit covers the reposted Unity/C# creature-data, packet, behavior-tree, universal-animation, Lattice roster, mutation, crafting, and UI examples. They are not production Echohearts code.

## Executive disposition

The code contains some reusable engineering ideas, but the implementation is tied to Unity types (`MonoBehaviour`, `ScriptableObject`, `Animator`, `SkinnedMeshRenderer`, `MaterialPropertyBlock`) and an experimental terminology layer that conflicts with current Echohearts canon. Production runtime is UE5.8, so these snippets must not be pasted into the Unreal project.

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

## 2. Client command / server snapshot structs

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
- Never trust client-sent position, health, energy, inventory, rewards, Eco-Kin ownership/relationship, cooldown completion, or hit results as authority.
- UE replication/RPC/Network Prediction architecture must be selected from the actual project module, not invented in an isolated snippet.
- Validation requires rate limits, sequence-window checks, capability/state checks, server movement/combat simulation, and rejection telemetry.

## 3. Behavior tree examples

The generic `Selector` / `Sequence` samples are educational patterns, not production AI.

Problems:

- no action leaves were implemented;
- `Update()`-driven per-frame evaluation is not automatically the right server cost model;
- no perception, target validity, cooldown, navigation, EQS, StateTree/Behavior Tree integration, authority boundary, or replication policy is present;
- renamed `Tyrant` terminology conflicts with the existing Primal/Titan/Guardian encounter language.

Current direction: use UE5.8 AI tooling appropriate to each encounter. Boss logic needs explicit phases, interrupts, telegraphs, recovery windows, navigation constraints, multiplayer authority, failure recovery, and deterministic test hooks.

## 4. Universal animation router

The historical proposal tried to make every creature use identical animation frames and then differentiate them through bone scaling, playback speed, materials, and particles.

This is rejected because incompatible anatomy cannot safely share one rig. Runtime bone scaling is not a substitute for authored anatomy, locomotion, contact, or personality. It can produce deformation, foot sliding, collision mismatch, poor silhouettes, and animation/VFX desynchronization.

Current direction: compatible rig families + original animation + IK/retargeting. See `07_Art/Animation/ECOKIN_ANIMATION_FOUNDATION_2026-09-20.md`.

## 5. Lattice roster code

Generated names such as Alloy-Tusk, Gravel-Back, Volt-Talor, Chrono-Leopard, Brier-Croc, Spore-Fox, Basalt-Maw, Shard-Back, Chrono-Hound, Shock-Stinger, Thistle-Crown, and Mire-Stalker are **not automatically canon Eco-Kin**. They are concept candidates at most.

Do not instantiate roster content at runtime by creating temporary data objects in `Awake()` as a substitute for an authoritative content database. Canon Eco-Kin require Dex intake, duplicate/name check, Essence normalization, ecological/story connection, art review, stable IDs, and authored data assets.

## 6. Mutation / node inversion

The old `SomaticMutationNode`, `Synaptic Node Inversion`, and reset-to-zero polarity ideas were created while trying to imitate progression patterns from other games without copying their terminology. Renaming a loop is not sufficient differentiation.

Status: **RETIRED** pending a genuinely Echohearts-native progression design based on care, field experience, ecology, Growth Rites, authorized traits, and player/Eco-Kin agency.

## 7. Capture lure/cage crafting

Crafting physical cages, enclosure sleeves, nets, anchor traps, pods, root tethers, or tanks specifically to capture sentient Eco-Kin is incompatible with current player ethics.

Possible salvage:

- temporary rescue barriers;
- medical transport supports;
- non-harmful habitat guidance tools;
- antagonist poaching equipment the player disables;
- species-safe treatment carriers used only during emergency care.

## 8. UI inventory

The old interface treated living creatures as inventory/container entries. Retire that framing.

Current separation:

- **Partner roster / EcoDex / Havenlink** for Eco-Kin relationships and care;
- **Inventory** for materials, tools, purified resources, gear, food, cosmetics, and non-sentient items;
- **Sanctuary resident view** for voluntary residence and care status.

## 9. What should become code now?

No new UE C++ is justified from these snippets until the actual UE5.8 module tree and build target are available for direct inspection and test. The correct next technical action remains to inspect/build the authorized UE project, then implement only the smallest required architecture gap.

## Verification status

- Historical C#: **NOT VERIFIED for production**.
- Lattice rewrite: **RETIRED as canon architecture**.
- General server-authority principles: **accepted design guidance, implementation NOT YET VERIFIED**.
- Animation foundation: **accepted design guidance, implementation NOT YET VERIFIED**.

© 2026 Into Deep Studios and Donta L. Owens. All rights reserved.

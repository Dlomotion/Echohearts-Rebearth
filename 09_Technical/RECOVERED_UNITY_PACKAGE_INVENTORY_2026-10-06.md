# Recovered Unity Package Inventory — 2026-10-06

**Status:** LEGACY SOURCE RECOVERED / REFERENCE-ONLY / UE5.8 PORT REQUIRED  
**Runtime authority:** `Dlomotion/ECHOHEARTS-REBEARTH-BUILD-`  
**Canon authority:** `Dlomotion/Echohearts-Rebearth`

This inventory records the uploaded historical Unity-era Echohearts packages. It does not promote Unity/C# to production runtime, does not create a second engine lane, and does not override current Echohearts: Rebearth canon.

## Recovered package set

| Package | SHA-256 | Files | Uncompressed bytes | Disposition |
|---|---:|---:|---:|---|
| `Echohearts_Unity_Project (2).zip` | `18bc2fbb2462c7b5852bc59a0831368d4631c3bf549796392a7dc9fa1d8a289e` | 11 | 305 | Mostly placeholders; archive only. |
| `Echohearts_DialogueSystem_Starter (1).zip` | `83249bf022f342d1328ce1b4f93d963b090d8a5378b495f8ae1cc1a57bf9151d` | 6 | 209 | Placeholder dialogue starter; recover intent only. |
| `Echohearts_ProceduralWorld_Unity.unitypackage (1).zip` | `bdb689bb32b9b4d1bbabcc95c039de7ca2b08fd34161abbc1b912a205870d2c7` | 2 | 4,843 | Contains substantive C# reference code; port concepts only. |
| `Echohearts_ProceduralWorld_Unity (1).zip` | `a8910f2ab046fd50fb6bd0775bfef3166b55170a096fb39bc367f13bd3598f53` | 2 | 4,843 | Same logical contents as the unitypackage zip; duplicate source representation. |
| `Echohearts_Unity_Complete_Package.unitypackage (1).zip` | `8739c76e681f900923b900c9df0ef75cf421d39cabb54650c4b9ad19b6a76d85` | 0 | 0 | Empty archive; retire as build input. |
| `Echohearts_Unity_Expanded_Complete (1).zip` | `6ce10ffe74507ad822bc91189efb3eaa6615357722061c3e554d9aa01ec8f964` | 3 | 694 | Minimal sample script/prefab/shader; reference only. |

## Package-level findings

### Echohearts_Unity_Project

The archive contains:

- `BattleSystem.cs`
- `EchoKinData.cs`
- `MoveData.cs`
- `FusionLabManager.cs`
- `AudioManager.cs`
- `UIManager.cs`
- `DialogueManager.cs`
- `DialogueTrigger.cs`
- a Fusion Morph ShaderGraph placeholder
- a Fusion Dissolve VFX placeholder
- a Fusion Lab scene placeholder

All C# files are only placeholder comments rather than implementation.

The Fusion Lab naming must not revive retired player/Eco-Kin fusion or donor-consumption mechanics. Any transferable presentation work must be reconciled into current non-destructive Growth Rites / Resonance Trait Infusion / Bio-Synergy Weaving rules.

### Echohearts_DialogueSystem_Starter

The archive contains placeholder records for:

- DialogueManager
- DialogueTrigger
- DialogueNode
- DialogueUI prefab
- SampleShrineDialogue scene
- SampleDialogueNode asset

No functioning dialogue runtime is present in the uploaded package. The reusable intent is the separation of dialogue node data, trigger logic, manager/presentation, and authored scene content.

A future UE5.8 implementation should use current story/mission/save authority, stable IDs, Blueprint-facing data, UMG presentation, and save-safe branching state rather than copying these placeholders.

### Echohearts_ProceduralWorld_Unity

This is the only uploaded Unity package in this batch with substantial code.

`RegionData.cs` stores:
- region name and description;
- floor prefab;
- obstacle prefab list;
- obstacle density;
- landmark prefab list;
- landmark count;
- fog color;
- ambient light color.

`WorldGenerator.cs`:
- clears generated child objects;
- creates floor cells from a 2D cardinal random walk;
- places landmarks randomly;
- places obstacles using density probability;
- applies fog and ambient light;
- uses a static `SimpleRandomWalk` helper and four cardinal directions.

### Procedural-world correction for UE5.8

Do not port the Unity generator line-for-line.

The current Echohearts large-world architecture remains:

- authored Landscape;
- World Partition;
- PCG for bounded procedural population/scatter/subregions;
- Data Layers and HLOD;
- deterministic seeds where replayable local sites require them;
- server/save authority for any procedural state that affects progression.

Transferable requirements from the recovered Unity code:

- data-driven region descriptors;
- authored obstacle-density parameters;
- authored landmark pools;
- deterministic local-generation seed support;
- region atmosphere metadata;
- bounded local procedural sites;
- explicit regeneration/cleanup lifecycle.

The old implementation uses `Random.Range`, `Random.value`, and `HashSet.ElementAt` selection with no stable seed contract. That is unsuitable for authoritative network/save behavior as written.

### Echohearts_Unity_Expanded_Complete

Recovered:
- `ExampleScript.cs` that only logs that the script loaded;
- `SampleKin.prefab` placeholder;
- `EchoheartsCelShader.shader`, a basic opaque Lambert surface shader exposing one color.

The shader is useful only as historical art-direction evidence for a flat/stylized material test. It is not an Unreal material and should not be copied into UE source.

A future UE5.8 material recreation belongs under the existing art/technical-art pipeline and must be evaluated against current lighting, performance, accessibility, and platform targets.

### Empty complete package

`Echohearts_Unity_Complete_Package.unitypackage (1).zip` is a valid empty ZIP with no entries.

It contains no recoverable source or assets and must not be treated as evidence of a complete Unity package.

## Duplicate and archive handling

The two ProceduralWorld ZIPs contain the same two logical source files and byte-identical extracted content. Preserve one canonical recovery copy in archival storage if needed; do not duplicate both inside production source control.

Historical Unity project/package binaries are not required in the canonical Git repository merely to prove they existed. This inventory and source hashes provide traceability while production behavior is re-authored in UE5.8.

## Current routing

- Story/dialogue intent → `01_Story`, `04_Systems`, `06_UI_UX` as appropriate.
- World-generation intent → `02_World`, `05_Levels`, `09_Technical`.
- Technical-art shader/VFX intent → `07_Art` and `09_Technical`.
- Retired Unity/fusion/placeholder material → `99_Reference_Retired_Needs_Redesign` when a repository copy is actually needed.
- Executable implementation → BUILD repository only.

## Source-control transport

Recommended Windows workflow:

1. **HTTPS + Git Credential Manager** for normal clone/fetch/push authentication.
2. **GitHub CLI (`gh`)** for repository/PR/workflow operations and authentication bootstrap.
3. **SSH** as an optional alternative for users who prefer key-based Git transport.

These are developer transport/authentication methods only. They are not game dependencies and no tokens, credential-cache files, private keys, or machine-local auth state belong in source control.

## Verification status

The uploaded package bytes were inspected and inventoried.

That proves the historical package contents listed here only.

It does **not** prove:

- Unity project compilation;
- UE5.8 UHT/UBT compilation;
- editor launch;
- map load;
- PIE;
- network determinism;
- save/load;
- PCG runtime;
- packaged execution;
- target-hardware behavior.

**NOT VERIFIED — UE BUILD/RUNTIME EVIDENCE REQUIRED**

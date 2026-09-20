# Echohearts: Rebearth — Project Cleanup Lock

Status: **ACTIVE CANON/PRODUCTION RULE**

Purpose: stop chat drift from creating duplicate worlds, systems, creature taxonomies, engines, or terminology. Historical chats remain traceable, but only material reconciled against the current canon may be promoted.

## What this cleanup fixes

The project accumulated several incompatible drafts: Aethelgard versus Rebearth, digital-Grid versus physical world, Echoes versus Eco-Kin, Unity versus Unreal, capture/fusion mechanics versus consent-based bonding, multiple element systems, generic RPG stats versus Echohearts public attributes, and experimental “Lattice” terminology that replaced the franchise identity.

Those contradictions are now resolved by the following source-of-truth order:

1. `00_Canon_Lock/CANON_CORE_RULES.md`
2. `01_Story/ECHOHEARTS_REBEARTH_FINAL_STORY_CONTINUITY_2026-09-20.md`
3. approved Master Game Bible / project index material
4. normalized Eco-Kin Dex entries and intake manifests
5. system/level/art/technical documents that explicitly state their canon status
6. historical chat exports only as reference evidence

When an older conversation conflicts with a higher item, the older version is **retired or rewritten**, not blended back in.

## Locked corrections

### World and story

- **Rebearth** is the physical living planet.
- **Echohearts City** is the main city.
- The current story is not a server simulation and Eco-Kin are not software files.
- Historical Grid/data-collapse drafts are reference material only unless a specific concept has already been intentionally transformed into physical Ancient Tech, Time-Echo, Rift, archive, A.E.G.I.S., or Data Virus fiction.
- The current six-era structure is First Chorus → Meridian Age → War on Humanity → Great Collapse → Rebearth Awakening → Star Rewrite.
- The **Sovereign Heartroot / Tree of Life** restoration spine remains central.

### Eco-Kin identity

- Franchise creature term: **Eco-Kin**.
- Code-safe form: **EcoKin**.
- Singular possessive: **Eco-Kin's**.
- Do not replace the roster with Conductor Lattices, Organic Hardware lifeforms, frames, apps, containers, or manufactured units.
- Eco-Kin are living autonomous beings with memory, preference, refusal, habitat, and ecological consequence.

### Public attributes and Essences

Public attributes remain:

- Vibrance
- Density
- Harmony
- Purity

Official Rebearth Essences remain:

- Flora
- Torrent
- Pyre
- Terra
- Aero
- Glaze
- Voltic
- Aura
- Shade

Sand, Coastal, Guardian, Tracker, Sentinel, Rainwarden, Oracle, Harvester, etc. are role/ecology/family tags, not new Essences.

### Bonding and care

The standard field loop remains:

**Observe → Protect → Calm → Kindle → Bond / Release / Defer**

Retire player-facing systems built around weakening-to-capture, balls, spheres, cages, snares, ownership counts, forced work, unwanted trading, donor sacrifice, or manufactured fusion.

Welfare tools for rescue, treatment, temporary stabilization, transport, and habitat return remain allowed.

### Growth and variants

Approved growth language can include authored species growth, Growth Rites, Biomimetic Shifts, Resonant Morphs, Primal Morphs, Primal Reversion, Bio-Synergy Weaving, and Resonance Trait Infusion where each system's specific rules are approved.

Do not recreate another title's awakening, fusion, polarity-reset, mod-slot, or evolution structure simply by renaming it.

### Animation

The instruction “same animation as Aniimo” is retired. Echohearts will develop original animation while targeting comparable polish and responsiveness. Use `07_Art/Animation/ECOKIN_ANIMATION_FOUNDATION_2026-09-20.md`.

### Engine and code

- Production runtime: **Unreal Engine 5.8** unless explicitly changed later.
- Historical Unity/C# examples are source/reference only.
- Generic networking structs, behavior-tree examples, or data models are not production code merely because they compile in another engine.
- Do not generate replacement C++ just to make the repository look larger. Implement only when there is a real project module, dependency, test path, and current prototype need.
- Server-authoritative principles may be retained: clients send bounded intent; servers validate identity, capability, inventory, destinations, rewards, combat outcomes, and persistent state.

## Material disposition from the latest repost

### RETIRE

- `LatticeCoreData`
- `StructuralResonanceType`
- `LatticeSynapticNodeData`
- `Synaptic Node Inversion`
- `Chromatic Catalyst` reset/polarity loop
- `Neural Resonance` as franchise-wide replacement architecture
- `Organic Hardware` as franchise-wide creature identity
- `Chrono-Packets` as network branding
- universal `Tyrant` boss classification
- `Resonance Enclosure Cages` and capture-lure production
- one identical master animation rig for every creature
- any instruction to copy Aniimo landmarks, animation, rigs, or forms

### SALVAGE AFTER RENAMING/REBUILDING

- server-authoritative input validation
- compact input bitfields where profiling justifies them
- behavior-tree/StateTree-style boss decision logic
- data-driven creature profiles
- shared animation inside compatible anatomy families
- procedural terrain contact/IK corrections
- daily/world events and restoration missions
- player housing, marketplace for non-sentient legal goods, and QoL systems already under separate system review

### KEEP AS STORY/GAME PRINCIPLES

- physical-world ecology
- dynamic world restoration
- persistent consequences
- behavior-driven Eco-Kin personality
- ecological roles
- original rare variants
- player choice between control and stewardship
- Tree of Life restoration
- A.E.G.I.S.-supported field work
- visible before/after world change

## Latest code-repost correction batch

The most recent repost adds several more examples that are now explicitly classified so they cannot drift back into production accidentally.

### Standalone `Program.cpp` / generic CMake bootstrap

- The `NeuralResonance::Core::MainEngineFile` hello-world executable is **REFERENCE-ONLY**.
- It is not an Unreal Engine gameplay module, game target, editor target, subsystem, or production entry point.
- The generic CMake project may be useful for isolated tools/tests, but it does not replace Unreal Build Tool for the UE5.8 game runtime.
- `NeuralResonance` is retired as a replacement project namespace. New production code uses the actual Echohearts module namespace/API once that module exists in the repository.

### Cloth / garment shader experiments

- The Unity Shader Graph/HLSL and C# garment scripts are **REFERENCE-ONLY** visual experiments.
- The old `ComputeStructuralDisplacement` sample contains a real logic defect: `(BaselinePositionOS - BaselinePositionOS)` is always zero, so the stated internal elastic-restoration force never contributes anything.
- The shader examples do not actually calculate mesh curvature merely by using `NdotV`; view-angle/rim response is not the same thing as concavity or wrinkle curvature.
- The geometry-deformer example generates procedural waves, but it does not prove the claimed bone-compression or physically based cloth behavior.
- For UE5.8, garment simulation/rendering must be evaluated through current Unreal material, skeletal, Chaos Cloth/Dataflow, caching, animation, and profiling workflows rather than porting Unity runtime scripts directly.
- Cosmetic cloth strain is presentation. The server should not receive trusted per-vertex or per-joint cosmetic strain just to prove authority. Gameplay collision/movement remains authoritative; cloth presentation can remain client-side unless a concrete gameplay dependency proves otherwise.

### Garment networking examples

- `FGarmentDeformationPayload* GarmentStates` as a raw pointer is not an approved replicated payload design.
- A client-supplied `ClientVelocity` cannot be used as proof against speed manipulation. The server must derive or validate movement from authoritative movement state/input constraints.
- The old garment validation component does not become anti-cheat merely by being named `ServerGarmentValidationComponent`.
- Networked cosmetic effects must not create a second gameplay truth path.

### Reposted `AEchoKinBase` header

The historical header that used `Fire, Water, Earth, Wind, Light, Dark, Wood, Iron, Thunder, Ice` and public `HP/ATK/DEF` is **RETIRED AS CURRENT DESIGN**.

Corrections:

- use the locked Rebearth Essences instead of creating another elemental enum;
- preserve public `Vibrance / Density / Harmony / Purity` instead of exposing a second generic RPG stat sheet;
- do not use a vague forced `Evolve()` contract as the universal growth path;
- relationship state must preserve agency/refusal and cannot be treated as an ownership score;
- abilities, damage, replication, save data, tags, movement and AI architecture must be selected from the actual UE5.8 module and tested there, not invented as a detached header;
- `EcoKin` is correct in identifiers; `Eco-Kin` remains the prose term.

### C# `CS1024` error

The pasted `SummoningSystemBlueprintLogic.cs` error is a source-file hygiene problem, not a reason to preserve the old Unity system. `CS1024` occurs when a line beginning with `#` is not a valid C# preprocessor directive. Markdown headings, copied chat text, code-fence fragments, or malformed directives must never be pasted into `.cs` source files. Historical C# is reference-only because the production game runtime is UE5.8.

### DNA / mutation / synthesis / capture lines

- DNA-fusion or genome-splicing mechanics applied to sentient Eco-Kin remain retired.
- Node-inversion and somatic-mutation trees from the repost do not become canon by renaming them.
- Capture apparatus recipes such as cages, anchor traps, pods, tanks, and root tethers remain retired as player ownership mechanics.
- Rescue/stabilization variants may be redesigned only as welfare tools with clear voluntary/medical use.

### Generated Lattice roster names

`Alloy-Tusk`, `Gravel-Back`, `Volt-Talor`, `Chrono-Leopard`, `Brier-Croc`, `Spore-Fox`, `Basalt-Maw`, `Shard-Back`, `Chrono-Hound`, `Shock-Stinger`, `Thistle-Crown`, and `Mire-Stalker` are not automatically promoted into the Eco-Kin Dex. They remain **REFERENCE / CANDIDATE NAMES** until duplicate, originality, anatomy, Essence, ecology, story, art, and roster reviews pass.

## Weak-line purge rule

The following writing patterns are removed from production-facing Echohearts material unless direct evidence supports them:

- “flawlessly”;
- “100% original” as an unprovable guarantee;
- “high-performance” without profiling;
- “optimized” without benchmark evidence;
- “server-authoritative” when the code still trusts client state;
- “production-ready,” “fully implemented,” “secure,” “complete,” or “verified” without build/test/profile evidence;
- inflated technical wording that makes a simple system harder to understand;
- renaming generic mechanics only to make them sound proprietary.

Prefer plain engineering truth: what the system does, what it depends on, what was tested, what failed, and what remains unknown.

## New intake rule

Every future repost is processed as:

`extract → classify → compare to canon → keep / rewrite / merge / retire → place in correct folder → connect to story/gameplay → mark verification status`

Nothing becomes canon simply because it appeared in an older assistant response.

## Deletion boundary

Historical chat messages themselves cannot be erased from the repository by this document, and this document does not claim to delete ChatGPT conversation history. Instead, conflicting material is made non-authoritative through explicit retirement and replacement in the project source of truth.

© 2026 Into Deep Studios and Donta L. Owens. All rights reserved.

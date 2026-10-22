# Radiant Coast — full design text (verbatim source, 2026-10-14)

> Companion to `region-brief.md` (reconciliation evidence, same date).
> This file is the VERBATIM paste from Tay's 15:50 UTC message — kept whole so
> 01_Story / 02_World / 04_Systems / 09_Technical work can quote it without digging
> through chat history. The brief remains the audit record: names canonized from this
> text are Dex 454–461 (PERMANENT); everything else here is CONCEPT, not locked canon.

## Echohearts: Rebearth — The Radiant Coast

The first coastal concept is created. It transforms the reference photograph into an original Rebearth region with offshore islands, ancient signal towers, cliffside routes, luminous reefs, settlements, and Eco-Kin habitats.

Production status: This is a concept-development asset, not an implemented Unreal level. All newly generated NPC and Eco-Kin names are provisional until reconciled against the existing canon registries. The Blessed Form concept remains a rare ecological discovery, not a guaranteed encounter or purchasable advantage.

I recommend making The Radiant Coast a substantial early-game region where the player learns exploration, A.E.G.I.S. navigation, Eco-Kin bonding, parrying, Anima-Link commands, and environmental restoration through one connected story.

## 1. Playable region layout

Radiant Coast — Proposed vertical slice

UE5.8 target

Schematic only. Coordinates, distances, and traversal times require validation in Unreal.

Main route

Optional discovery route

The six principal locations form a continuous, navigable play space:

* Seabloom Bay: Starting settlement, dialogue tutorials, fishing, restoration supplies, and a safe Eco-Kin encounter.

* Radiant Path: Traversal tutorial, environmental clues, A.E.G.I.S. field scanning, and first cooperative puzzle.

* Cliffwatch Tower: Vertical climbing, navigation reveal, parry training, and a signal relay.

* Tidebreaker Ruins: Structural fracture puzzles, combat encounters, environmental storytelling, and optional passages.

* Dawnspire Lighthouse: Main story culmination with a multi-phase defense and restoration encounter.

* Starcrest Isles: Optional post-quest exploration, rare habitat observations, and possible Blessed Form discovery.

The starting area should be designed around multiple interconnected paths, not a corridor disguised as an open world. Climbing, shoreline traversal, cave passages, and restored bridges create shortcuts that remain unlocked after quests.

## 2. Starting-zone quest campaign

01

A New Shore

Meet the coastal guide, activate A.E.G.I.S., survey the village, and assist an injured Eco-Kin without capturing it.

Validation: Movement, interaction, scanning, dialogue

02

Echoes in the Tower

Reach Cliffwatch, repair a resonance relay, learn the parry timing cue, and direct an Eco-Kin to synchronize with the signal.

Validation: Traversal, parry, Eco-Kin commands

03

Tides of Balance

Investigate a damaged reef, reposition field anchors, and restore its Purity and Vibrance while protecting the worksite.

Validation: Ecosystem simulation, deployables, Anima-Link

04

A Light Again

Navigate Tidebreaker Ruins, recover the lighthouse's missing resonance pattern, and overcome a defensive construct.

Validation: Combat flow, puzzles, checkpoint persistence

05

Beneath the Current

Discover why the coastal signals are failing, resolve the disturbance, and return to Dawnspire to restore the beacon.

Validation: Boss phases, story flags, zone restoration

Each quest must have an authoritative quest-state record, prerequisites, explicit completion conditions, recovery behavior after disconnects, and a persistent environmental consequence. A quest is not complete merely because its final dialogue played.

## 3. Eco-Kin habitats and characters

| Habitat            | Eco-Kin candidates     | Ecological behavior                            |
| ------------------ | ------------------ | ---------------------------------------------- |
| Coastal tide pools | Aqua-Shell, Shorepuff* | Shelter in pools and react to water conditions |
| Reed wetlands      | Reedwing               | Nest building and seasonal migration           |
| Luminous reef      | Coralisk*, Pearlfin*   | Coral cleaning and current-following           |
| Cliff terraces     | Aerinix*               | Wind riding and high-altitude nesting          |
| Submerged passages | Aquavex, Glimmerdrake* | Respond to resonance disturbances              |

\*New concept-board names, pending originality, roster, and canon review. Existing names retain their established identity rather than receiving replacement IDs.

The village NPC cast should include a coastal guide, a watchtower keeper, a restoration engineer, a harbor merchant, and an elder who preserves the region's history through spoken accounts and coastal murals. Their schedules should change when the player repairs infrastructure, rather than remaining static quest dispensers.

Blessed Forms: The concept artwork includes a proposed Dawnblessed Aerinix. Its rare appearance should require an eligible lineage, a restored habitat, a particular environmental condition, and an encounter discovery event. A Blessed Form must remain connected to its base Eco-Kin identity and cannot automatically become a separate permanent Dex entry.

## 4. Combat and gameplay responsiveness

The core combat loop is:

Read the opponent → parry or evade → issue Eco-Kin command → synchronize the Anima-Link → exploit an opening → recover positioning.

For the first playable build, I recommend these provisional tuning targets:

| Mechanic                       | Initial tuning target                      |
| ------------------------------ | ------------------------------------------ |
| Input sampling                 | Every rendered frame                       |
| Parry acceptance window        | 120–180 ms, configurable                   |
| Successful parry presentation  | 100–140 ms of localized cinematic slowdown |
| Eco-Kin command acknowledgment | Within 100 ms locally                      |
| Command buffering              | 150 ms initial test window                 |
| Camera recovery                | Within 250 ms after the parry presentation |
| Combat framerate               | 60 FPS target                              |

These are design hypotheses, not measured results. Multiplayer combat must preserve authoritative server timing; cinematic slowdown must not slow the shared simulation for other players.

Anima-Link consequences should derive from the canonical Vibrance, Density, Harmony, and Purity attributes, with player strain clearly communicated. I would avoid adding independent generic RPG attribute systems.

## 5. Unreal Engine 5.8 implementation blueprint

Proposed level and gameplay architecture

RadiantCoast/ ├── Maps/ │ ├── L_RadiantCoast_Persistent │ ├── L_SeabloomBay │ ├── L_Cliffwatch │ ├── L_TidebreakerRuins │ └── L_Dawnspire ├── Data/ │ ├── DA_RadiantCoastRegion │ ├── DT_CoastalQuestDefinitions │ ├── DT_CoastalHabitatRules │ └── DT_CoastalNPCSchedules ├── Blueprints/ │ ├── BP_AEGISFieldAnchor │ ├── BP_CoastalResonanceRelay │ ├── BP_EcoKinHabitatVolume │ ├── BP_CliffwatchBeacon │ └── BP_CoastalTrainingNode └── UI/ ├── WBP_CoastalRegionMap ├── WBP_QuestTracker └── WBP_AnimaLinkFeedback

The implementation should use World Partition where appropriate, streamed environmental assets, Navigation Mesh Bounds Volumes, Smart Objects for NPC interactions, and server-authoritative gameplay components. The quest and habitat data must reference existing permanent Eco-Kin IDs rather than inventing competing registries.

For the private local-server test, I would build an automated test character that consumes authorized structured game-state telemetry: position, reachable navigation targets, quest objectives, nearby interactions, and server-approved combat commands. It can plan and execute the five starting quests without relying solely on screenshots.

That test must also identify collision and navigation gaps, but report them as defects rather than exploit them to produce misleading quest-completion results.

## 6. Performance and quality gates

60 FPS frame budget

16.67 ms

CPU and GPU profiling target

Quest completion

5 / 5

Required automated scenario coverage

Additional acceptance gates: no reproducible collision bypasses, no quest-state desynchronization, no duplicate completion rewards, reliable navigation around dynamic obstacles, responsive Eco-Kin command feedback, and persistent restoration after saving and reloading.

For GitHub Actions, the reported missing verification script must be checked against the actual repository checkout and case-sensitive file paths. The proposed workflow is a starting template, not proof of a fix. Unreal compilation, UHT validation, packaged builds, and dedicated-server tests also require a properly configured build environment.

## 7. Production handoff

I would route this into the existing Echohearts Daily Game Work process as a proposed Radiant Coast vertical slice, with the following implementation order: first a traversable grey-box coastline, then quest-state persistence, then A.E.G.I.S. and Eco-Kin interactions, then combat and navigation tests, and finally art, animation, audio, and optimization.

The concept image is ready:

View Radiant Coast concept board

Verification boundary: The concept artwork was generated successfully. The UE5.8 map, Blueprints, local server, quest automation, and repository changes are specifications at this stage; they have not been built, committed, or runtime-verified. The generated board's names, elements, and rarity labels are provisional, and any conflicts must be reconciled with the existing Master Project Index and Eco-Kin registry before implementation.

The central creative objective is to make the coast feel alive: villagers responding to restored infrastructure, Eco-Kin changing their behavior as habitats recover, and the player's choices producing visible consequences across Rebearth.

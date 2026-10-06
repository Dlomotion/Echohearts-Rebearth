# Echohearts: Rebearth — Upgrade Highlights & Echo Egg System

Status: **CURRENT DESIGN INTAKE — implementation requires repository/runtime evidence**
Last synchronized: **2026-10-06**

This file records the latest user-requested upgrade package and Echo Egg direction for GitHub Copilot. It extends the existing Echohearts: Rebearth canon and does **not** replace the Master Game Bible, the 125-ID Permanent Dex, or the master inventory/material registry.

## Non-negotiable project rules

- Planet: **Rebearth**.
- Creature class: **Eco-Kin**.
- Player: **Frequency Tamer / Core-Binder**.
- Core attributes: **Vibrance, Density, Harmony, Purity**.
- Preserve **Kindling** and the **Anima-Link** bi-directional strain/damage loop.
- **A.E.G.I.S.** is the player's physical bracer for scanning, field interaction, restoration, bonding support, and combat feedback.
- **Nature** remains a Legendary Humanoid-Kin with conditional Mutations; never call Nature a Legendary Monarch.
- The **125-ID Permanent Dex** remains roster authority.
- Do not introduce generic Strength/Mana/Agility/Speed stats as replacements for the four project attributes.
- Do not import outside game/franchise naming, characters, item designs, UI text, or proprietary code.
- A recovered/legacy item name is not automatically production canon. Preserve its status from the master registry.
- Do not claim VERIFIED without real repository/build/runtime/test evidence.

## Upgrade Highlights

These are the requested Echohearts-native upgrade pillars. Copilot should implement them as incremental, testable features rather than a marketing-only checklist.

### 1. Restored World Visuals
Improve Rebearth's environmental presentation while preserving performance budgets:
- richer authored foliage and restoration-state transitions;
- clearer healthy-versus-Blight environmental storytelling;
- improved water, sky, fog, weather, materials, and dynamic lighting;
- biome-specific restoration VFX driven by actual world state;
- scalable settings and accessibility-safe readability;
- target **60 FPS** where the production performance budget requires it.

### 2. Resonance Combat Flow
Refine real-time player + Eco-Kin combat:
- smoother movement, dodge, guard, light/heavy chaining, ranged aim, and authored recovery windows;
- clearer hit confirmation and exact hit-location feedback where technically valid;
- stronger Anima-Link feedback when Eco-Kin strain transfers tactical cost to the Frequency Tamer;
- readable telegraphs and state changes without hidden generic initiative/speed stats;
- server-authoritative competitive results and inventory/reward changes.

### 3. Resonance Skill Paths
Expand abilities without replacing the four-attribute matrix:
- Vibrance paths emphasize elemental expression and terrain interaction;
- Density paths emphasize defense, anchoring, interruption, and structure;
- Harmony paths emphasize coordinated actions, Kindling, timing, support, and team flow;
- Purity paths emphasize restoration, resistance to corruption, rescue, and cleansing;
- growth must remain bounded by the existing Eco-Kin identity and Forms Registry.

### 4. A.E.G.I.S. Expansion
Add deeper bracer functionality:
- refined scanning and Echoprint reading;
- field restoration diagnostics;
- Resonance Shard/material identification;
- route and anomaly tracking;
- Echo Egg care/scan readouts;
- trap/stabilization controls that never become automatic ownership;
- repairable modules and upgrade slots driven by the inventory registry.

### 5. Sanctuary Building 2.0
Expand the Sanctuary as a living restoration system:
- modular building;
- farming and water restoration;
- fabrication stations;
- power and logistics;
- Eco-Kin care areas;
- nursery/incubation areas for eligible Echo Eggs;
- worker assignments with welfare and rest requirements;
- visual biome recovery tied to real progress;
- multiplayer-safe ownership, placement, collision, permissions, and persistence.

### 6. Echo Egg Incubation & Nursery
Introduce Echo Eggs as a care/progression system, not a loot-box shortcut:
- eggs require incubation, temperature/moisture/frequency care, and Sanctuary support;
- Harmony/Purity and habitat quality can influence safe development conditions;
- lineage and valid Permanent Dex identity determine eligible outcomes;
- no egg may create a brand-new species ID automatically;
- eggs do not bypass Kindling after hatching;
- no Legendary, god/entity, Nature, Event Sovereign, or otherwise breeding-locked record may be produced through ordinary breeding/incubation;
- species with non-egg biological reproduction remain species-appropriate. Do not force every Eco-Kin into an egg lifecycle merely for UI consistency.

### 7. Eco-Kin Animation & Terrain Contact
Improve runtime quality for the vertical slice:
- locomotion;
- slope/terrain contact;
- foot/paw/claw placement where appropriate;
- attack notifies;
- directional hit reactions;
- interaction animations;
- ecology/restoration behaviors;
- no identity-breaking skeleton reuse where anatomy requires a separate rig family.

### 8. Appearance Weave
Create a cosmetic appearance layer that never changes combat identity:
- weapon/vestment appearance overrides;
- device skins;
- Resonance line patterns;
- dye/pigment systems;
- Sanctuary cosmetics;
- anatomy-safe Eco-Kin appearance palettes only where approved;
- no paid appearance may change Vibrance, Density, Harmony, Purity, Kindling, breeding eligibility, or combat power.

### 9. Photo Mode & Echo Archive
Create a dedicated capture/archive experience:
- free camera within authored safety bounds;
- focal length/exposure/depth controls;
- poses that respect rig/anatomy;
- filters and frames;
- biome/restoration stamps;
- Eco-Kin observation cards;
- lore snapshots and location metadata;
- accessibility controls;
- photo mode must not pause/disable authority rules in competitive multiplayer.

### 10. World Pulse / Quest Tracking Overhaul
Improve objectives and world-state communication:
- Sanctuary objectives;
- biome Restoration %;
- Blight pressure;
- boss gates;
- faction consequences;
- active world events;
- material/recipe tracking;
- Echo Egg care tasks;
- clear distinction between story-critical and optional work.

### 11. Inventory, Materials & Marketplace Overhaul
Use the authoritative registry:
- `04_Systems/Inventory/ECHOHEARTS_MASTER_ITEMS_MATERIALS_REGISTRY_2026-10-06.md`
- preserve its categories, descriptions, aliases, and status fields;
- never auto-promote Legacy / Retired / Rename Required entries into public canon;
- keep Legendary/seasonal restricted items out of ordinary player trading;
- cosmetics, approved purchased goods, ordinary materials, and trophies may be tradeable only under the market rules;
- server validates quantity, item identity, tradeability, ownership, capacity, atomic commit, rollback, and replay/duplication protection.

### 12. Performance, Stability, Accessibility & Platform Quality
Treat quality as a production system:
- crash diagnostics;
- save/load integrity;
- async/thread safety;
- bounded replication;
- scalable graphics;
- controller/keyboard accessibility;
- text scaling and readable state cues;
- audio/visual alternatives for important state;
- platform-specific verification before claiming cross-platform support.

## Echo Egg Registry

Echo Eggs are **developmental/incubation items**, not capture devices and not random species generators. Every resulting Eco-Kin must resolve to an eligible existing Permanent Dex identity and valid lineage/growth contract.

### Core variants

| Echo Egg | Resonance identity | Care emphasis | Visual language |
|---|---|---|---|
| **Aero Echo Egg** | Aero | airflow, pressure stability, open canopy | pale sky shell, flowing wind bands |
| **Aura Echo Egg** | Aura | calm, low-noise care, Harmony stability | opalescent shell, soft inner glow |
| **Glaze Echo Egg** | Glaze | cool stable temperature, moisture balance | frosted translucent shell, crystalline rim |
| **Pyre Echo Egg** | Pyre | safe warmth, venting, thermal balance | ember-veined shell, controlled flame halo |
| **Radiant Echo Egg** | Radiant | clean light cycles, high Purity environment | warm white-gold shell, starburst markings |
| **Shade Echo Egg** | Shade | dim shelter, quiet cycles, low disturbance | deep violet shell, soft shadow bands |
| **Terra Echo Egg** | Terra | mineral bed, stable Density, vibration control | layered stone shell, root/mineral seams |
| **Tide Echo Egg** | Torrent/Hydro | humidity, clean water, gentle flow | blue translucent shell, wave spirals |
| **Verdant Echo Egg** | Flora | living soil, leaf cover, clean water | green shell, leaf veins, root cradle |
| **Volt Echo Egg** | Voltic | grounded charge, controlled current | dark shell, gold-blue conductive arcs |

### Advanced variants

| Echo Egg | Purpose | Hard rule |
|---|---|---|
| **Prismatic Echo Egg** | Rare multi-signature shell for an eligible lineage with several compatible Resonance influences. | It does not create a new species; final identity must already exist in the Permanent Dex and valid lineage data. |
| **Ancient Echo Egg** | Dormant naturally preserved egg recovered from an old ecological site or restoration vault. | "Ancient" is provenance, not a promise of Legendary rarity. |
| **Sovereign Echo Egg** | Extremely rare event-grade shell/state connected to difficult world-state conditions. | It must never hatch a breeding-locked Legendary, god/entity, Nature, or Event Sovereign simply because of the shell name. |
| **Sanctuary Echo Egg** | Egg raised under high-quality Sanctuary conditions and careful player stewardship. | It is a care-quality state, not a separate species or paid power tier. |
| **Resonant Echo Egg** | Neutral/default shell showing a strong, stable Resonance signature before element-specific traits are resolved. | Outcome remains lineage/Data Registry driven. |

### Rescue condition: Blight-Stressed Egg
A damaged or contaminated egg may enter a **Blight-Stressed** condition. This is not a collectible rarity tier. It is a rescue state requiring purification, safe incubation, and restoration care. Failing care can pause development or require treatment; do not turn suffering into a power bonus.

## Echo Egg data contract

Prefer a versioned UE5.8 data asset/Data Registry contract. Exact class names should match the actual runtime module after inspection.

Required conceptual fields:
- StableEggDefinitionId
- DisplayName
- ResonanceType / GameplayTags
- EligibleDexIds
- EligibleLineageRules
- BreedingAllowed
- LegendaryOrEntityLocked
- IncubationDuration
- TemperatureRange
- MoistureRange
- FrequencyCareProfile
- MinimumSanctuaryTier
- RequiredCareStations
- PurityRisk
- HarmonyCareModifier
- BiomeAffinity
- WorldStateRequirements
- VariantState
- CosmeticShellProfile
- SaveVersion
- Icon / mesh / material / VFX / SFX references
- LoreEntry
- CanonStatus

Runtime rules:
1. Server validates egg creation/acquisition.
2. Stable ID + save version are serialized; never trust a client-supplied hatch result.
3. Hatch result is resolved server-side from eligible lineage and registry data.
4. Random selection, if used, must be bounded, auditable, and deterministic where replays/recovery require it.
5. Ordinary eggs cannot produce locked records.
6. Duplicate or invalid definitions fail closed and log diagnostics.
7. Inventory consumption and hatch commit must be atomic.
8. A crash/reconnect must not duplicate, delete, or reroll an already committed outcome.
9. Hatching does not overwrite the individual Eco-Kin identity/history after creation.
10. Newly hatched Eco-Kin still requires care, welfare, and eventual Kindling; incubation is not ownership.

## UI presentation for Echo Eggs

Use an original Echohearts visual language:
- living branch/nest geometry;
- bioluminescent flora;
- star-like Resonance motes;
- readable egg silhouette and shell material;
- distinct iconography for each variant;
- no external franchise UI layouts, symbols, names, or copied art;
- accessibility: text label + icon shape/pattern, never color alone.

Suggested screens:
- Echo Egg Collection;
- Incubation Nursery;
- Egg Detail / Care Conditions;
- Lineage Eligibility;
- Sanctuary Nursery Capacity;
- Rescue/Purification Care;
- Archive entry after hatch.

## Repository ownership

- **Dlomotion/Echohearts-Rebearth**: canon/contracts, registry, design-source authority.
- **Dlomotion/ECHOHEARTS-REBEARTH-BUILD-**: executable UE5.8 runtime, build driver, runtime tests/evidence.
- **Dlomotion/Echohearts-Ecokins**: Eco-Kin support metadata and art/archive support; never create a competing Dex.
- **Dlomotion/echohearts-web**: web/presentation surfaces such as inventory, Egg Collection, archive, documentation, and approved support tools.
- **Dlomotion/ECO-KIN-Game**, **Dlomotion/ECHOHEARTS-REBEARTH-**, **Dlomotion/Echohearts**: legacy/prototype support and migration only unless ownership is explicitly reassigned.

## Copilot execution rule

When asked to implement any item, Echo Egg, shop, upgrade, UI, or code fix:
1. search the owning repository first;
2. inspect current branch, modules, data structures, save/network paths, tests, and call sites;
3. read the master item/material registry and this file;
4. preserve Permanent Dex IDs and canon statuses;
5. make the smallest coherent patch;
6. add/update validation/tests;
7. run every available repository check;
8. report exact evidence and label anything requiring Unreal runtime proof as **NOT YET VERIFIED**.

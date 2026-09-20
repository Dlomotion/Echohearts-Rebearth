# ECHOHEARTS: REBEARTH — MASTER PROJECT INDEX

**Purpose:** one clean routing map for the existing Echohearts project.

This file does not invent new canon. It tells every writer, artist, designer, programmer, and production pass which source wins and where work belongs.

© 2026 Into Deep Studios and Donta L. Owens. All rights reserved.

## 1. Source-of-truth precedence

When documents conflict, use this order:

1. `00_Canon_Lock/ECOKIN_NAMING_STANDARD.md` for Eco-Kin naming and display/data conventions.
2. `00_Canon_Lock/CANON_CORE_RULES.md` for protected story, ethics, gameplay, stats, and terminology.
3. `00_Canon_Lock/REBEARTH_ESSENCE_TAMER_VARIANT_CANON_2026-09-20.md` for the active Essence chart, Tamer profession, morphology rules, contracts, and Tree of Life mission.
4. `MASTER_PROJECT_INDEX.md` for routing and production status.
5. Active folder documents that explicitly match the files above.
6. `99_Reference_Retired_Needs_Redesign` and historical chat/source material for reference only.

A newer active canon file does not make old source material disappear; it prevents old terminology from controlling current production.

## 2. Canonical naming

Public-facing creature term:

**Eco-Kin**

Internal code/data identifier form:

**EcoKin**

Singular possessive:

**Eco-Kin's**

Public plural is also **Eco-Kin**.

Do not use `Eco-Kins`, `Echo Kin`, `Echo-Kin`, `Eco Kin`, or `Ecokin` as current production terminology unless quoted in historical source material.

## 3. Active top-level project folders

| Folder | Purpose |
|---|---|
| `00_Canon_Lock` | protected terminology, active canon rules, continuity locks |
| `01_Story` | campaign, characters, NPC arcs, lore, endings |
| `02_World` | regions, cities, biomes, landmarks, world-state changes |
| `03_EcoKin_Dex` | Eco-Kin registry, biology, identities, forms, intake, Dex records |
| `04_Systems` | bonding, combat, Sanctuary, progression, contracts, economy, traversal |
| `05_Levels` | missions, encounters, dungeons, vertical-slice implementation specs |
| `06_UI_UX` | A.E.G.I.S., EcoDex, HUD, menus, accessibility, card interfaces |
| `07_Art` | character/Eco-Kin art, manifests, visual-development intake, anatomy QA |
| `08_Audio` | music, VO, creature audio, environmental and Resonance audio |
| `09_Technical` | Unreal Engine, C++, Blueprint, networking, saves, tests, profiling |
| `10_Production` | backlog, daily assignments, provenance, QA, migration, intake tracking |
| `11_Publication` | approved public-facing story, pitch, marketing, release documentation |
| `99_Reference_Retired_Needs_Redesign` | historical, conflicting, outside-franchise, retired, or redesign-required material |

Do not create a second numbered folder for a function already represented here.

### Duplicate-folder migration rule

- Historical `01_Game_Bible` material must move into the correct active folder or `99_Reference_Retired_Needs_Redesign`.
- Historical `11_Daily_Assignments` material belongs under `10_Production/Daily_Assignments`.
- `11_Publication` remains the only active `11_*` production-stage folder.

## 4. Active canon snapshot

### Project / world

- Game: **Echohearts: Rebearth**
- Planet: **Rebearth**
- Main city: **Echohearts City**
- Living campaign landmark: **Sovereign Heartroot**, commonly called the **Tree of Life**
- Healing the Tree of Life and its root network is a main campaign spine.

### Player role

- Primary profession: **Tamer of Beasts**
- Ethical/restoration discipline: **Veridian Keeper**
- `Frequency Tamer` is legacy terminology, not the primary front-facing profession.

### Eco-Kin relationship rule

Eco-Kin are autonomous sentient partners.

Main field loop:

**Observe → Protect → Calm → Kindle → Bond / Release / Defer**

No normal player progression based on coercive capture, harmful cages, sentient storage-as-items, forced labor, forced evolution, body fusion, ownership trading, or living-resource extraction.

### Public stats

- **Vibrance**
- **Density**
- **Harmony**
- **Purity**

### Active Rebearth Essences

1. **Flora**
2. **Torrent**
3. **Pyre**
4. **Terra**
5. **Aero**
6. **Glaze**
7. **Voltic**
8. **Aura**
9. **Shade**

The former 12-element chart is legacy migration language and must not be presented as the active public type system.

### Harmony / Resonance rule

Harmony is a public stat. Resonance is a broad physical/biological principle. Neither means every Eco-Kin is music-themed. Sonic/music mechanics belong only to species, variants, locations, relics, or story situations that genuinely support them.

## 5. Repost / intake pipeline

Every reposted chat, image, document, code block, Eco-Kin concept, NPC, lore fragment, mechanic, or art reference follows:

`INTAKE → AI MISTAKE PATCH → CONTINUITY CHECK → ORIGINALITY/IP CHECK → NAMING NORMALIZATION → CORRECT FOLDER → STATUS → GAME/STORY LINK → IMPLEMENTATION EVIDENCE`

Do not skip directly from a pasted source to CANON.

## 6. Status vocabulary

- **CANON** — approved source-of-truth fact.
- **APPROVED-PENDING** — accepted direction awaiting implementation/art/data proof.
- **MERGED/RENAMED** — useful material reconciled into an existing identity/system.
- **REFERENCE-ONLY** — historical, comparative, or inspiration material that cannot overwrite canon.
- **RETIRED** — superseded or contradictory material kept for traceability.
- **NOT YET VERIFIED** — technical or production claim without direct evidence.
- **VERIFIED** — supported by direct repository/build/test/profile evidence.

## 7. Eco-Kin Dex rule

Every production-ready Eco-Kin record should resolve, at minimum:

- `EcoKinID`
- public display name
- class/body plan
- biology / creature basis
- primary Essence
- optional secondary Essence
- Vibrance / Density / Harmony / Purity data
- region / biome / habitat
- behavior
- field role
- combat role
- Sanctuary aptitude, if voluntary and species-safe
- Bond / Kindling method
- forms / Biomimetic Shifts / rare morphology
- story connection
- world/ecological effect
- art status
- originality/provenance status
- implementation status

Do not create duplicate identities merely because a historical card, image, variant, or renamed draft exists.

## 8. Art rule

Current art intake belongs in `07_Art` and must point back to the corresponding Eco-Kin identity in `03_EcoKin_Dex`.

- preserve approved silhouette, anatomy, colors, materials, and identity;
- correct errors without redesigning the creature unless redesign is explicitly requested;
- animal Eco-Kin remain true animal-bodied unless intentionally classified otherwise;
- rare variants preserve species identity;
- generated/reference art does not become final canon merely because it exists.

Current manifest anchor: `07_Art/CHARACTER_ECOKIN_ART_INTAKE_MANIFEST.md`.

## 9. Current ecological restoration wave

The 10-creature ecological restoration batch remains routed through:

`03_EcoKin_Dex/Intake/ECOLOGICAL_RESTORATION_WAVE_10_INTAKE_2026-09-20.md`

Those creature concepts are usable, but card text, IDs, Essences, rarity, abilities, forms, biome tags, stats, art status, and story hooks must match the active canon before final lock.

Legacy labels such as Water, Earth, Wind/Air, Nature/Verdant, Ice, Harmony, Coastal, Sand, Guardian, Sentinel, or Tracker must be separated into the correct fields:

- active Essence when appropriate;
- ecology/body/role tag when not an Essence;
- legacy/reference label when retired.

## 10. Story rule

New story material must connect to the existing Rebearth chronology, Tree of Life mission, Blight/Data Virus, cities/regions, factions, and existing named characters before promotion.

A cool isolated idea is not enough. It must connect:

**Rebearth → Eco-Kin → ecosystem → player choice → progression → story consequence**

## 11. Technical rule

Production runtime is Unreal Engine. Legacy Unity/C#, browser prototypes, generic pseudocode, and third-party example architectures are reference-only unless intentionally translated into the current Unreal architecture.

No implementation may be called **VERIFIED**, **compiled**, **production-ready**, **secure**, **optimized**, or **finished** without direct build/test/profile evidence.

Prefer data/Blueprint implementation where appropriate. Add C++ only when it solves an actual production requirement.

## 12. Outside-franchise material

Named characters, creatures, systems, branded terminology, copied move sets, copied evolution structures, copyrighted roster entries, or proprietary formulas from other franchises stay in `99_Reference_Retired_Needs_Redesign` unless transformed into original Echohearts material through documented design work.

Reference study may inform design principles. It does not become Echohearts canon by being pasted into a project document.

## 13. Project-ready acceptance gate

A file is ready for an active production folder only when:

1. Eco-Kin naming follows the naming standard.
2. Active Essences match the nine-Essence canon.
3. Player profession terminology matches current canon.
4. Coercive capture/storage/fusion conflicts are removed or clearly marked antagonist/history/reference.
5. Public stats use Vibrance, Density, Harmony, Purity.
6. Story/world references do not create duplicate geography or characters.
7. Art references have identity/provenance/status.
8. Technical claims have honest evidence state.
9. Outside-franchise source material is not presented as original Echohearts content.
10. The file is routed to exactly one primary folder with cross-links rather than duplicated into multiple competing folders.

This is the active project organization rule going forward.

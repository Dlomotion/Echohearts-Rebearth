# Echohearts: Rebearth

Official development repository for **Echohearts: Rebearth**, **Echohearts: Resonance Arena**, and the **Eco-Kin** creature ecosystem.

This repository uses one source-of-truth workflow. Reposted material is **reconciled, corrected, and routed** into the existing project folders instead of creating duplicate canon, Dexes, GDDs, art pipelines, or code systems.

## Canonical naming

- **Eco-Kin** = public-facing creature name in prose, UI, cards, lore, quests, art, and player-facing documentation.
- **EcoKin** = internal technical/data form only, such as `EcoKinID`, `AEcoKinCharacter`, `UEcoKinDefinition`, and `03_EcoKin_Dex`.
- **Eco-Kin's** = singular possessive only.
- Public plural remains **Eco-Kin**, not `Eco-Kins` or `Eco-Kin's`.
- `Echo Kin`, `Echo-Kin`, `Eco Kin`, and `Ecokin` are retired naming errors unless quoted in historical source material.

See `00_Canon_Lock/ECOKIN_NAMING_STANDARD.md` for the full rule.

## Production folders

- `00_Canon_Lock` — approved canon rules and protected terminology
- `01_Story` — main story, chapters, characters, NPC arcs, lore
- `02_World` — regions, cities, landmarks, habitats, world-state changes
- `03_EcoKin_Dex` — Eco-Kin registry, biology, named Eco-Kin, intake/review
- `04_Systems` — bonding, combat, Sanctuary, progression, economy, traversal
- `05_Levels` — missions, encounters, dungeons, vertical-slice level work
- `06_UI_UX` — A.E.G.I.S., EcoDex, HUD, accessibility, menus
- `07_Art` — character/Eco-Kin art briefs, manifests, visual QA
- `08_Audio` — music, VO, creature audio, Resonance/VFX audio direction
- `09_Technical` — Unreal Engine, C++, Blueprint, networking, saves, testing
- `10_Production` — backlog, QA, provenance, assignments, intake routing
- `11_Publication` — approved public-facing story, pitch, marketing, release docs
- `99_Reference_Retired_Needs_Redesign` — historical drafts, outside-franchise reference material, retired names/systems, and concepts requiring redesign

## Active canon anchors

- `00_Canon_Lock/CANON_CORE_RULES.md`
- `00_Canon_Lock/ECOKIN_NAMING_STANDARD.md`
- `00_Canon_Lock/REBEARTH_ESSENCE_TAMER_VARIANT_CANON_2026-09-20.md`
- `MASTER_PROJECT_INDEX.md`

When an older document conflicts with these files, the older wording is treated as migration/reference material until reconciled.

## Locked development principles

- Eco-Kin are autonomous sentient partners, not inventory objects or forced labor.
- Player profession: **Tamer of Beasts**; **Veridian Keeper** remains the ethical/restoration field tradition.
- Active Rebearth Essences: **Flora, Torrent, Pyre, Terra, Aero, Glaze, Voltic, Aura, Shade**.
- Core public stats: **Vibrance, Density, Harmony, Purity**.
- Main bonding loop: **Observe → Protect → Calm → Kindle → Bond / Release / Defer**.
- Resonance is broader than music; only selected species, locations, relics, or variants should use explicit sonic/music mechanics.
- Main campaign combat is real-time; tactical/turn-based play belongs to approved Arena/EchoDeck simulation modes.
- Incoming art and concepts do not overwrite canon until continuity, originality, anatomy, gameplay, and production review are complete.
- Code is never labeled compiled, verified, production-ready, secure, or optimized without actual repository/build/test/profile evidence.

## Project-ready rule

Do not create new numbered top-level folders for material that already has a destination. Historical duplicate folders are migration targets, not permanent architecture. Daily assignment records belong under `10_Production`, and historical/legacy game-bible material belongs under the appropriate active folder or `99_Reference_Retired_Needs_Redesign`.

© 2026 Into Deep Studios and Donta L. Owens. All rights reserved.

# Echohearts: Rebearth

Official development repository for **Echohearts: Rebearth / Echohearts: Resonance Arena / ECO-KIN’S**.

This repository uses one source-of-truth workflow. Reposted material is **reconciled, corrected, and routed** into the existing project folders instead of creating duplicate canon, Dexes, GDDs, art pipelines, or code systems.

## Production folders

- `00_Canon_Lock` — approved canon rules and protected terminology
- `01_Story` — main story, chapters, characters, NPC arcs, lore
- `02_World` — regions, cities, landmarks, habitats, world-state changes
- `03_EcoKin_Dex` — Eco-Kin registry, biology, named Eco-Kin, intake/review
- `04_Systems` — bonding, combat, Sanctuary, progression, economy, traversal
- `05_Levels` — missions, encounters, dungeons, vertical-slice level work
- `06_UI_UX` — A.E.G.I.S., EcoDex, HUD, accessibility, menus
- `07_Art` — character/Eco-Kin art briefs, manifests, visual QA
- `08_Audio` — music, VO, creature audio, resonance/VFX audio direction
- `09_Technical` — Unreal Engine, C++, Blueprint, networking, saves, testing
- `10_Production` — backlog, QA, provenance, assignments, intake routing
- `11_Publication` — approved public-facing story, pitch, marketing, release docs
- `99_Reference_Retired_Needs_Redesign` — historical drafts, unsafe references, retired names/systems

## Locked development principles

- Eco-Kin are autonomous sentient partners, not inventory objects or forced labor.
- Core public stats: **Vibrance, Density, Harmony, Purity**.
- Main bonding loop: **Observe → Protect → Calm → Kindle → Bond / Release / Defer**.
- Main campaign combat is real-time; tactical/turn-based play belongs to approved Arena/EchoDeck simulation modes.
- Incoming art and concepts do not overwrite canon until continuity, originality, anatomy, gameplay, and production review are complete.
- Code is never labeled compiled, verified, production-ready, secure, or optimized without actual repository/build/test/profile evidence.

© 2026 Into Deep Studios and Donta L. Owens. All rights reserved.


## Repository authority split

This public repository is the authority for **canon, story, world, systems, the 125-ID Permanent Dex, production contracts, publication, and public coordination**.

The executable Unreal Engine 5.8 runtime/build/evidence authority is **`Dlomotion/ECHOHEARTS-REBEARTH-BUILD-`**. Active `.uproject`, `Source/`, compiler/build/package drivers, UE CI, and retained runtime evidence belong there. Historical/bootstrap executable files in this public repository must not become a competing runtime source of truth.

The Echohearts compiler/build driver is maintained in the BUILD repository. Public PR #19 must be split/reconciled before merge so executable implementation is not reintroduced here. PR #20 may carry platform/publication contracts, but runtime claims remain downstream of executed BUILD-repository evidence.

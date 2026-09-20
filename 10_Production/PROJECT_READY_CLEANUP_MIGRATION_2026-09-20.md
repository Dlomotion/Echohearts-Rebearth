# Echohearts: Rebearth — Project-Ready Cleanup Migration

**Date:** 2026-09-20  
**Branch:** `cleanup/project-ready-ecokin-normalization-2026-09-20`  
**Status:** ACTIVE CLEANUP / repository organization verified; gameplay/runtime remains NOT YET VERIFIED unless separately evidenced.

© 2026 Into Deep Studios and Donta L. Owens. All rights reserved.

## AI Mistake Patch / Continuity QA

The project had accumulated multiple generations of terminology and folder structure. The main errors were not isolated spelling mistakes; they were source-of-truth conflicts.

### Corrected in this cleanup

1. Locked public creature spelling to **Eco-Kin**.
2. Locked technical/data identifier form to **EcoKin**.
3. Locked **Eco-Kin's** to singular possessive use only.
4. Retired `Eco-Kins`, `Echo Kin`, `Echo-Kin`, `Eco Kin`, and `Ecokin` as current production terms.
5. Rebuilt the root `MASTER_PROJECT_INDEX.md` as a clean routing document instead of a growing contradictory archive.
6. Updated the root `README.md` with current naming, current nine Essences, current player role, and the canonical folder map.
7. Moved the duplicate historical `01_Game_Bible` document into `99_Reference_Retired_Needs_Redesign` and corrected its current-canon override section.
8. Consolidated the duplicate top-level `11_Daily_Assignments` content into `10_Production/Daily_Assignments`.
9. Corrected stale `twelve-element` references inside migrated daily assignment files to the active nine-Essence system.
10. Corrected migrated mythic-character assignment mappings so old Fire/Light/Nature/Spirit/Moon/Air language no longer masquerades as the current type system.

## Current active naming rule

- **Eco-Kin** — prose, lore, UI, cards, quests, art labels, public documentation.
- **EcoKin** — code, data, schema, IDs, internal folder naming.
- **Eco-Kin's** — singular possessive only.
- Public plural remains **Eco-Kin**.

## Current active canon migration points

Older material must be reconciled to:

- Player profession: **Tamer of Beasts**
- Ethical/restoration discipline: **Veridian Keeper**
- Active Rebearth Essences: **Flora, Torrent, Pyre, Terra, Aero, Glaze, Voltic, Aura, Shade**
- Public stats: **Vibrance, Density, Harmony, Purity**
- Bonding loop: **Observe → Protect → Calm → Kindle → Bond / Release / Defer**
- Eco-Kin agency: no normal coercive capture, sentient item storage, forced labor, forced evolution/fusion, or living-creature trading
- Resonance/Harmony: not a universal music theme
- Production runtime: Unreal Engine; Unity/C#/browser prototypes are historical/reference unless deliberately translated

## Project-ready folder policy

Use only these top-level destinations:

`00_Canon_Lock`
`01_Story`
`02_World`
`03_EcoKin_Dex`
`04_Systems`
`05_Levels`
`06_UI_UX`
`07_Art`
`08_Audio`
`09_Technical`
`10_Production`
`11_Publication`
`99_Reference_Retired_Needs_Redesign`

No second numbered folder should be created for an existing function.

## What NOT to mass-replace blindly

Do not run a global text replacement that changes every `EcoKin` into `Eco-Kin`. Technical symbols such as `EcoKinID`, `AEcoKinCharacter`, `UEcoKinDefinition`, schema fields, filenames, and folder names intentionally use `EcoKin`.

Do not rewrite historical quotations or outside-franchise reference files as if they were active canon. Preserve them in `99_Reference_Retired_Needs_Redesign` and write clean active documents instead.

## Remaining audit queue

The repository still contains many historical reconciliation/intake documents. They should be processed in bounded waves using this order:

1. active canon files;
2. root/project-routing docs;
3. `03_EcoKin_Dex` active named records;
4. `04_Systems` active gameplay docs;
5. `01_Story` and `02_World` continuity docs;
6. `07_Art` active art manifests and labels;
7. `06_UI_UX` player-facing labels;
8. `09_Technical` internal naming and stale design assumptions;
9. `11_Publication` public-facing wording;
10. historical intake/reference files last.

Each migrated file receives one status: CANON, APPROVED-PENDING, MERGED/RENAMED, REFERENCE-ONLY, RETIRED, NOT YET VERIFIED, or VERIFIED.

## Acceptance definition

The project is considered terminology-clean only when active production files contain no accidental public-facing `Echo Kin`, `Echo-Kin`, `Eco Kin`, `Eco-Kins`, or plural `Eco-Kin's`; no active file presents the former 12-element chart as current; and no duplicate top-level workflow folder competes with the canonical folder map.

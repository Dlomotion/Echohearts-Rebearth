# Echohearts: Rebearth — EcoKin Naming Standard

**Status:** CANON LOCK

This file is the single naming rule for the creature brand, prose, UI, data, code, folders, cards, art labels, and production documents.

© 2026 Into Deep Studios and Donta L. Owens. All rights reserved.

## AI Mistake Patch / Continuity QA

Historical project material used multiple conflicting spellings including `Eco Kin`, `Echo Kin`, `Echo-Kin`, `Eco-Kins`, `Ecokin`, `ECO-KIN’S`, and mixed code/prose forms. Those variants created duplicate taxonomy, inconsistent UI labels, and unclear file naming.

The project now uses exactly three approved forms:

1. **Eco-Kin** — public-facing creature name in prose, UI, cards, lore, quests, art briefs, and player-facing documentation.
2. **EcoKin** — internal technical/data identifier form only, such as `EcoKinID`, `EcoKinData`, `AEcoKinCharacter`, `UEcoKinDefinition`, database fields, schemas, code symbols, and folder names such as `03_EcoKin_Dex`.
3. **Eco-Kin's** — singular possessive only, for example: `the Eco-Kin's habitat`, `the Eco-Kin's Trust state`, or `the Eco-Kin's field behavior`.

## Singular and plural rule

Use **Eco-Kin** for both singular and plural public-facing references.

- Correct: `one Eco-Kin`
- Correct: `three Eco-Kin`
- Correct: `the Eco-Kin are migrating`
- Incorrect: `Eco-Kins`
- Incorrect: `Eco-Kin's` when the intent is plural

`Eco-Kin's` is possessive, not plural.

## Approved usage by layer

| Layer | Approved form | Example |
|---|---|---|
| Game title / marketing copy | Eco-Kin | `Discover rare Eco-Kin across Rebearth.` |
| Lore / story / dialogue | Eco-Kin | `The Eco-Kin returned after the storm.` |
| UI / cards / EcoDex | Eco-Kin | `Eco-Kin Profile` |
| Art filenames / production labels | EcoKin or Eco-Kin depending technical/public context | `ECOKIN_PIPLIN_CONCEPT_A.png` |
| C++ / Blueprint / schemas | EcoKin | `EcoKinID`, `AEcoKinCharacter` |
| Repository folder | EcoKin | `03_EcoKin_Dex` |
| Singular possessive | Eco-Kin's | `Eco-Kin's habitat` |

## Forbidden or retired variants

Unless preserved inside a quoted historical source, do not use:

- `Eco Kin`
- `Echo Kin`
- `Echo-Kin`
- `Eco-Kins`
- `Echo-Kins`
- `Ecokin`
- `ECO-KIN’S` as a plural label
- `ECO-KIN'S` as a plural label
- `Kin` as a blanket replacement when the text specifically means the franchise creature class

`Kin` may still appear naturally in dialogue or approved subcategory names where it has a distinct authored meaning, but it does not replace the official creature term.

## File and ID naming

Public display name: `Eco-Kin`

Technical prefix: `EcoKin`

Recommended stable fields:

- `EcoKinID`
- `EcoKinDisplayName`
- `EcoKinClass`
- `EcoKinEssencePrimary`
- `EcoKinEssenceSecondary`
- `EcoKinBiomeTags`
- `EcoKinVariantTags`
- `EcoKinStoryFlags`
- `EcoKinArtStatus`

Do not create parallel IDs such as `EchoKinID`, `Eco_Kin_ID`, or `KinID` for the same entity.

## Current canon compatibility

This naming standard works with the active canon in `CANON_CORE_RULES.md` and `REBEARTH_ESSENCE_TAMER_VARIANT_CANON_2026-09-20.md`:

- Player profession: **Tamer of Beasts**
- Ethical/restoration discipline: **Veridian Keeper**
- Nine active Rebearth Essences: **Flora, Torrent, Pyre, Terra, Aero, Glaze, Voltic, Aura, Shade**
- Public stats: **Vibrance, Density, Harmony, Purity**
- Bonding loop: **Observe → Protect → Calm → Kindle → Bond / Release / Defer**

Historical documents that still use the former 12-element chart, capture ownership, forced fusion, Frequency Tamer as the primary public role, or inconsistent Eco-Kin spelling are migration/reference material until corrected.

## Migration rule

When cleaning an old file:

1. Preserve the original source in `99_Reference_Retired_Needs_Redesign` when traceability matters.
2. Correct public creature naming to **Eco-Kin**.
3. Keep **EcoKin** only for code/data/internal identifiers.
4. Use **Eco-Kin's** only for singular possession.
5. Reconcile element terminology to the nine active Rebearth Essences.
6. Reconcile profession terminology to Tamer of Beasts / Veridian Keeper.
7. Remove or retire coercive capture/storage/fusion language unless it is explicitly antagonist behavior or historical reference.
8. Mark uncertain material `REFERENCE-ONLY`, `APPROVED-PENDING`, or `NOT YET VERIFIED` rather than silently calling it canon.

This file overrides earlier spelling conventions.
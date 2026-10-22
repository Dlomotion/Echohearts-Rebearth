# Echohearts Asset Library — Organization Bible

**Status:** IMPLEMENTED / NOT COMPILED / NOT TESTED / NOT RUNTIME VERIFIED.
This library is an *organizational* layer over the canonical art. Filing art into
folders confers no engine, build, or runtime verification on anything.

## Where everything lives

```
echohearts-asset-library/
├── README.md                  ← you are here
├── file_assets.py             ← the reproducible filing script (run it, don't hand-file)
├── ASSET_MANIFEST.csv         ← every filed asset: path, Dex, kind, status, platforms
├── shared/                    ← platform-agnostic canonical copies
│   ├── ecokin/dex_###_name/   ← one folder per Dex entry; base art + alternate
│   │                             Ecoforms live TOGETHER (forms attach to the base
│   │                             EcoKin per the Forms Registry rule; the `kind`
│   │                             column distinguishes base / form / render)
│   ├── group_art/             ← collages, lineups, multi-creature pieces
│   ├── unsorted/              ← unmapped files + UNSORTED_REPORT.md (Tay rules)
│   ├── ui/                    ← interface art (awaiting population)
│   ├── worlds/                ← region / environment art (awaiting population)
│   └── icons/                 ← app / achievement icons (awaiting population)
├── platform/{windows,mac,linux,android,ios}/
│   ├── PLATFORM_README.md     ← how this platform packages & ships art
│   └── manifest.csv           ← slice of ASSET_MANIFEST.csv (NO image duplication)
├── patches/PATCHES_README.md  ← versioned patch convention (v1, v2, …)
├── data/DATA_README.md        ← data tables live here, separate from art
└── runtime_cache/             ← runtime-generated caches; NEVER committed
    ├── README.md
    └── .gitignore
```

## Provenance rules (do not break these)

1. **Originals are sacred.** The source of truth stays at
   `…/ecohearts-ecokin-catalog/user_uploads/ecokin_art/`. This library holds
   **copies**. `file_assets.py` only ever reads the originals.
2. **Manifest first.** New art gets a row in `ECO_KIN_ART_MANIFEST.csv` and a Dex
   mapping *before* it is filed. Then re-run `file_assets.py`.
3. **Forms attach to base.** An alternate Ecoform never gets its own Dex folder.
4. **Unsorted is a queue, not a graveyard.** Tay rules on naming/placement;
   nothing is deleted.
5. **Original names only.** Folder and bundle names are Echohearts-original.
   We study other games' *organization methods* (separate data from art,
   versioned patches, per-type bundles, runtime caches, per-platform packaging)
   — never their names, content, or proprietary files.

## Naming conventions

- Dex folders: `dex_###_<normalizedname>` — e.g. `dex_497_nyalune`
  (### = zero-padded Dex number, name lowercased, non-alphanumeric stripped).
- Art files keep their canonical catalog names (`EK_ART_<Name>_<kind>_v<N>.<ext>`);
  the library never renames files, it files them.
- Kinds: `base` (primary visual) · `form` (alternate Ecoform) · `render`
  (additional render/alt) · `sidecar` (JSON sidecar) · `group` (multi-creature).

## Adding new art

1. Add the art manifest row (filename → depicted name(s), status).
2. Confirm the Dex mapping in the master registry.
3. Run `python3 file_assets.py` from this directory.
4. Check `shared/UNSORTED_REPORT.md` — new unsorted files mean a mapping gap.

## Evidence tiers

- Filing/organization: IMPLEMENTED.
- Engine import (.uasset), packaging, on-device caches: NOT IMPLEMENTED until
  done in Unreal on a real machine. Nothing here is COMPILED, TESTED, or
  RUNTIME VERIFIED.

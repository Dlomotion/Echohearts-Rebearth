# Platform: Android — Art Packaging Notes

**Status:** CONCEPT / ASPIRATIONAL. Echohearts is a UE5 PC/console-first project;
no mobile build exists, and none is scheduled. This folder reserves the
organization so a future mobile port files cleanly.

## How Echohearts art WOULD ship on Android (plan)

- Source art lives once in `shared/`; `manifest.csv` here is a slice of the
  root `ASSET_MANIFEST.csv`. No per-platform image duplication.
- Mobile packaging principle (studied from shipped mobile titles' *methods*,
  with Echohearts-original names throughout):
  - **Separate data tables from art.** Game data (CSV/JSON) ships in
    `data/`-derived packs; art ships in texture/model packs. Never mixed.
  - **Per-type bundles.** EcoKin art, UI art, and world art cook into separate
    downloadable packs so a balance patch never re-ships gigabytes of textures.
  - **Versioned patches.** Patches are numbered (v1, v2, …) and delta against
    the base install — see `patches/PATCHES_README.md`.
  - **Runtime caches stay out of the repo.** Rendered/cached level data is
    generated on-device, gitignored, and evictable — see `runtime_cache/`.
  - **Texture formats decided at cook time** (ASTC/ETC2), not stored here.
- Install layout would keep the same separation: `packs/` (shipped bundles),
  `patches/`, `cache/` (runtime-generated).

## Honest boundary

Everything above is a plan. No Android build, bundle, or on-device layout has
been produced or verified. Do not present this as shipped.

# Platform: iOS — Art Packaging Notes

**Status:** CONCEPT / ASPIRATIONAL. Echohearts is a UE5 PC/console-first project;
no mobile build exists, and none is scheduled. This folder reserves the
organization so a future mobile port files cleanly.

## How Echohearts art WOULD ship on iOS (plan)

- Source art lives once in `shared/`; `manifest.csv` here is a slice of the
  root `ASSET_MANIFEST.csv`. No per-platform image duplication.
- Same packaging principles as Android (see `platform/android/PLATFORM_README.md`):
  data tables separate from art, per-type bundles, versioned delta patches,
  runtime caches gitignored and evictable, texture formats (ASTC) decided at
  cook time.
- iOS specifics: on-demand resources for world packs, app-thinning via asset
  catalogs — all decided at packaging time in Unreal, not stored here.

## Honest boundary

Everything above is a plan. No iOS build, bundle, or on-device layout has been
produced or verified. Do not present this as shipped.

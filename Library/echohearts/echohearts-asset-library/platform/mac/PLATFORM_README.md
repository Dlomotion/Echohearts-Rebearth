# Platform: macOS — Art Packaging Notes

**Status:** DESIGN / NOT IMPLEMENTED. No packaged macOS build exists yet.

## How Echohearts art ships on macOS

- Source art lives once in `shared/` (this library). It is **never duplicated**
  per platform; `manifest.csv` here is a slice of the root `ASSET_MANIFEST.csv`.
- At build time, Unreal imports source art into `.uasset` files and cooks them
  into `.pak` archives inside the `.app` bundle:
  `EchoheartsRebearth.app/Contents/.../echohearts-ecokin-mac.pak`, etc.
- Textures: ASTC/BC7 per Apple's Metal pipeline at cook time — decided at
  packaging, not stored per platform here.
- Patches layer on top: see `patches/PATCHES_README.md` (v1, v2, …).
- Distribution target: Epic Games Launcher Preview (macOS supported as of
  2026-10-14) once builds exist.

## To add this platform's packaging

Cook via the project's BuildScripts on a macOS runner, verify, and record the
pak list + hashes here. Until then, this file is the plan, not the proof.

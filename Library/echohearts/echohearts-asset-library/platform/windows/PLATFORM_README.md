# Platform: Windows — Art Packaging Notes

**Status:** DESIGN / NOT IMPLEMENTED. No packaged Windows build exists yet.

## How Echohearts art ships on Windows

- Source art lives once in `shared/` (this library). It is **never duplicated**
  per platform; `manifest.csv` here is a slice of the root `ASSET_MANIFEST.csv`.
- At build time, Unreal imports source art into `.uasset` files and cooks them
  into `.pak` archives: one `pak` per content bundle (EcoKin, UI, worlds).
- Bundle layout (planned): `Echohearts/Content/Paks/echohearts-ecokin-windows.pak`,
  `…-ui-windows.pak`, `…-worlds-windows.pak`.
- Patches layer on top: see `patches/PATCHES_README.md` (v1, v2, …).
- Distribution target: Epic Games Launcher (now in Preview on Windows/macOS/Linux
  as of 2026-10-14) once builds exist and anti-cheat requirements are met.

## To add this platform's packaging

Cook via the project's BuildScripts, verify pak integrity (hashes), and record
the pak list + hashes here. Until then, this file is the plan, not the proof.

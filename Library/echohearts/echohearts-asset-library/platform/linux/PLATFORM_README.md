# Platform: Linux — Art Packaging Notes

**Status:** DESIGN / NOT IMPLEMENTED. No packaged Linux build exists yet.

## How Echohearts art ships on Linux

- Source art lives once in `shared/` (this library). It is **never duplicated**
  per platform; `manifest.csv` here is a slice of the root `ASSET_MANIFEST.csv`.
- At build time, Unreal cooks `.pak` archives next to the Linux binary:
  `Staged/Linux/Echohearts/Content/Paks/echohearts-ecokin-linux.pak`, etc.
  (see `BuildScripts/Linux/package-linux.sh` in the BUILD working copy).
- Target distributions: Ubuntu 22.04+, Fedora 43+, Debian 12+ (matching the
  platform support Epic announced for its launcher Preview on 2026-10-14).
- Patches layer on top: see `patches/PATCHES_README.md` (v1, v2, …).
- Distribution target: Epic Games Launcher Preview for Linux once builds exist
  and anti-cheat requirements are met (see `docs/ANTI_CHEAT_LINUX_PLAN.md`).

## To add this platform's packaging

Run the Linux package script on a UE 5.8 Linux toolchain machine, verify pak
hashes, and record them here. Until then, this file is the plan, not the proof.

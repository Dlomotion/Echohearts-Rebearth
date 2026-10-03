# UE5.8 Foundation Verification — 2026-10-03

**Status:** TECHNICAL CONTRACT — NOT YET VERIFIED  
**Branch:** `engine/ue58-foundation-2026-10-03`  
**PR:** https://github.com/Dlomotion/Echohearts-Rebearth/pull/18

## Purpose

Define the evidence gate for the canonical Echohearts: Rebearth Unreal Engine 5.8 project foundation. The presence of a `.uproject`, targets, module rules, and source files is repository evidence only. It is not compile/runtime evidence.

## Required local verification

Run from a clean Windows development machine with Unreal Engine 5.8 installed.

1. Clone the repository.
2. Run `git lfs install`.
3. Run `git lfs pull`.
4. Generate project files for `EchoheartsRebearth.uproject`.
5. Build `EchoheartsRebearthEditor Win64 Development`.
6. Confirm UHT completes without reflection/header errors.
7. Launch the editor with `EchoheartsRebearth.uproject`.
8. Confirm the runtime module loads.
9. Start PIE and keep the session alive for at least 30 seconds.
10. Exit PIE and the editor cleanly.
11. Build/package a Development Win64 client.
12. Launch the packaged client and exit cleanly.
13. Preserve logs and exact engine/toolchain versions.

## Failure policy

Any UHT, UBT, module-load, cook, package, launch, or shutdown error keeps the foundation **NOT YET VERIFIED**.

Warnings must be reviewed rather than automatically ignored.

## Evidence record

Record:

- UE version and build identifier;
- Visual Studio/MSVC toolchain version;
- branch and commit SHA;
- UHT/UBT command;
- compile result;
- editor launch result;
- PIE result;
- packaging result;
- packaged launch result;
- relevant logs/artifacts;
- corrective commit(s), if any.

## Promotion rule

Only after all required checks pass may PR #18 be described as a verified UE5.8 foundation. This does not verify Issue #10, gameplay, save, networking, AI, animation, Anima-Link, Eco-Kin runtime systems, or later production milestones.

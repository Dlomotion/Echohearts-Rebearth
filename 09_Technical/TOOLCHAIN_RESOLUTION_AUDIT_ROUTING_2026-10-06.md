# Toolchain Resolution Audit — Routing Record (2026-10-06)

Status: documentation-only technical routing. Canon, the 125-ID Permanent Dex, Vibrance/Density/Harmony/Purity, Anima-Link and Huma-Link are unchanged.

## Ownership
Executable implementation belongs **only** to `Dlomotion/ECHOHEARTS-REBEARTH-BUILD-` in `BuildScripts/EchoheartsCompiler.py`. This repository must not gain `BuildScripts/`, a second compiler driver, Unreal runtime classes, duplicate verification ledgers, or a competing implementation.

## Audit conclusions for Copilot
1. `shutil.which(explicit) or explicit` is unsafe for an explicit compiler target: missing names and directories pass through unresolved. The BUILD implementation must require a discovered command or a regular executable path, normalize it, and fail closed.
2. Compiler family must derive from a supported resolved executable identity; unknown tools must never silently become GNU.
3. Use argv-based subprocess calls. Filename token blacklists (e.g. 'hack', 'override') are not anti-tamper controls.
4. Reusable helpers raise/return errors; CLI boundaries own exit codes.
5. Do not add the supplied `UEchoStringValidatorLibrary` for compiler-path parsing: this is build tooling, not gameplay/Blueprint runtime.
6. Do not add the supplied array example: `char PrimitiveByteFootprint = CharacterTokenString;` is a compile-time type error, and glyph-to-integer conversion is unrelated.
7. Do not invent tracking indices 0x2C/0x2D as security or registry authority.

## Required BUILD regression coverage
PATH command; explicit executable; blank, missing and directory targets; MSVC; GNU/Clang; unsupported basename; portable path/case behavior.

## Verification wording
Repository/Python checks may be `STATIC CHECK PASSED` only with retained command, SHA, exit code and test evidence. UE5.8 UHT/UBT/editor/PIE/package/runtime remain `NOT VERIFIED — UE BUILD/RUNTIME EVIDENCE REQUIRED` unless matching BUILD evidence exists.

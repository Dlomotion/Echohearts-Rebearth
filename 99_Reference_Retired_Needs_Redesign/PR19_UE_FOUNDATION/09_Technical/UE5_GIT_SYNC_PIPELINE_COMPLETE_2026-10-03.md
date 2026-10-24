# UE 5.8 manual build pipeline — 2026-10-06 correction

Status: **infrastructure candidate / NOT YET VERIFIED**.

## Authoritative roles

- Canon, systems, Dex, production/publication authority: `Dlomotion/Echohearts-Rebearth`.
- Executable implementation/build target: `Dlomotion/ECHOHEARTS-REBEARTH-BUILD-`.
- Public project bootstrap in this PR must use the same Unreal naming contract as the build repository; it is not a competing runtime authority.
- Unreal project: `EchoheartsRebearth.uproject`.
- Game target: `EchoheartsRebearth`.
- Editor target: `EchoheartsRebearthEditor`.
- Primary runtime module: `Echohearts`.
- Export macro contract: `ECHOHEARTS_API`.

Project/target naming and runtime-module naming are deliberately distinct. The descriptor and both TargetRules classes must load the `Echohearts` module.

## Build entry points

- Manual packaging workflow: `.github/workflows/ue5-build.yml`.
- Packaging implementation: `package_unreal.ps1`.
- Repository/static infrastructure checker: `09_Technical/Tools/verify_infrastructure.py`.
- Diagnostic Unreal helper: `09_Technical/Tools/verify_unreal_gate.py`.
- Echohearts compiler/build driver: `09_Technical/Tools/EchoheartsCompiler.py`.

The Echohearts compiler driver does not replace C++ compilation. UnrealBuildTool evaluates the TargetRules/ModuleRules, UnrealHeaderTool processes reflected declarations, and the platform compiler performs native compilation. The driver validates project-specific contracts, invokes those engine tools, records exit results, and preserves the verification boundary.

## Required source foundation

The minimum public bootstrap paths are:

- `EchoheartsRebearth.uproject` with EngineAssociation `5.8` and module `Echohearts`;
- `Source/EchoheartsRebearth.Target.cs`;
- `Source/EchoheartsRebearthEditor.Target.cs`;
- `Source/Echohearts/Echohearts.Build.cs`;
- `Source/Echohearts/Public/Echohearts.h`;
- `Source/Echohearts/Private/EchoheartsModule.cpp`.

The earlier `Source/EchoheartsRebearth/` runtime-module candidate is superseded by the shared `Echohearts` module contract and must not coexist as a second primary game module.

## Runner setup and execution

Provision an authorized Windows x64 runner with labels `self-hosted`, `Windows`, `X64`, `echohearts-ue58`; PowerShell 7; Python; Git LFS; and the UE5.8-supported native compiler toolchain.

The manual packaging workflow must remain reviewed/default-branch-only at this gate. It requires an authored `/Game/...` map; repository documents do not substitute for a `.umap`.

The packaging gate checks:

1. exact UE 5.8 `Build.version`;
2. project/module/target paths;
3. authored map presence;
4. Git LFS integrity;
5. Development Editor build;
6. reviewed Unreal Automation results;
7. Development cook/package;
8. package output/hash and source commit metadata.

A command exit code is interpreted in the context of the tool that returned it. **Exit code 2 is not a universal diagnosis.** The failing command's own log/usage contract remains authoritative.

## Verification boundary

Repository/static checks can establish that files, JSON, names, and contracts are structurally consistent. They do **not** prove UHT, native compilation, editor load, gameplay, save, networking, performance, or package launch.

The current foundation therefore remains **NOT YET VERIFIED** until retained evidence demonstrates the applicable gates:

1. clean checkout + `git lfs pull/fsck`;
2. UHT + Development Editor compile;
3. UE5.8 editor launch;
4. minimal authored map open;
5. PIE smoke test;
6. Development Win64 cook/package;
7. packaged executable launch;
8. Issue #10 runtime/animation proof;
9. save/network/performance evidence only where those claims are made.

The CommandBuffer Automation filter remains blocked until its actual test source/manifest is present and reviewed. Empty test results never pass.

Recovery measurements at 150/250/350 ms remain a separate later gate. Their latency definition, packet-loss profile, acceptance thresholds, and server/client evidence must be specified before ECO-API-001 advances.

## Production order protection

The build pipeline does not authorize later roadmap work out of sequence:

**UE5.8 foundation → Issue #10 humanoid + Eco-Kin body/animation proof → 4–6 Eco-Kin slice → one Growth Rite proof → later save/network/platform expansion.**

Universal platform and ebook contracts may be documented in parallel, but runtime platform claims require the executable evidence ladder and ebook claims require a built publication artifact plus validation/render evidence.

## Recovery

Preserve failed logs, repair the specific prerequisite on a reviewed branch, and rerun from a clean checkout. Do not reuse stale `BuildEvidence` or `PackagedOutput`. Avoid history rewriting for evidence-bearing branches.

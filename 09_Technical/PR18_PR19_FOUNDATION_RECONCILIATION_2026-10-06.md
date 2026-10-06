# PR #18 / PR #19 UE5.8 Foundation Reconciliation

**Date:** 2026-10-06  
**Status:** REPOSITORY REVIEW / NOT YET UE5.8 RUNTIME VERIFIED

## Executive decision

Use **Dlomotion/ECHOHEARTS-REBEARTH-BUILD-** as the single executable UE5.8 authority.

Do **not** merge PR #18 or PR #19 wholesale into `Dlomotion/Echohearts-Rebearth`. Both contain executable-foundation material that would duplicate or conflict with the BUILD repository. Preserve only public canon/verification documentation after reconciliation.

Current BUILD naming contract:

| Contract | Authoritative value |
|---|---|
| Project | `EchoheartsRebearth.uproject` |
| Game target | `EchoheartsRebearth` |
| Editor target | `EchoheartsRebearthEditor` |
| Runtime module | `Echohearts` |
| Export macro | `ECHOHEARTS_API` |
| Engine | UE 5.8 |
| Dex | 125-ID Permanent Dex remains authoritative |

## Current pull-request state

| PR | Current state | Mergeable | Key issue |
|---|---|---:|---|
| #18 | Open, not draft | Yes | Uses runtime module `EchoheartsRebearth` and `ECHOHEARTSREBEARTH_API`, conflicting with current BUILD authority |
| #19 | Open, not draft | No | Uses corrected `Echohearts` module contract, but still carries executable source/tooling that now belongs in BUILD |

PR #19 already documents the repository-role split and explicitly warns against merging its runtime implementation as a second authority.

## File-by-file comparison

| File / area | PR #18 | PR #19 | Reconciliation |
|---|---|---|---|
| `EchoheartsRebearth.uproject` | Adds UE5.8 project with module `EchoheartsRebearth` | Changes descriptor to UE5.8 with module `Echohearts` | **Conflict.** BUILD value is `Echohearts`. Do not add duplicate public runtime descriptor. |
| `Source/EchoheartsRebearth.Target.cs` | Game target loads `EchoheartsRebearth` | Game target loads `Echohearts` | **Conflict.** BUILD uses PR #19-style target contract. Keep executable file only in BUILD. |
| `Source/EchoheartsRebearthEditor.Target.cs` | Editor target loads `EchoheartsRebearth` | Editor target loads `Echohearts` | **Conflict.** BUILD uses PR #19-style target contract. |
| Runtime module directory | `Source/EchoheartsRebearth/` | `Source/Echohearts/` | **Mutually exclusive primary-module layouts.** BUILD uses `Source/Echohearts/`. |
| Build.cs | Includes Core/CoreUObject/Engine/Input/EnhancedInput plus AnimationCore/AnimGraphRuntime/GameplayTasks/UMG | Initial public patch has Core/CoreUObject/Engine/Input/EnhancedInput | BUILD currently owns the broader dependency set. Do not maintain a second public Build.cs. |
| Module entry point/header | `EchoheartsRebearth.cpp/.h` | `EchoheartsModule.cpp`, `Echohearts.h` | **Conflict.** BUILD uses `Echohearts` module implementation. |
| `.github/workflows/ue-foundation-static-check.yml` | Static public foundation check for local `EchoheartsRebearth` module | — | Superseded by BUILD repository static/build verification. Remove from merge-safe public scope. |
| `.github/workflows/infrastructure.yml` | — | Hosted static checks expecting local executable foundation | Must not be merged as-is after repository split; it would validate the wrong repository role. |
| `.github/workflows/ue5-build.yml` | — | Authorized self-hosted Windows UE5.8 package workflow | Executable workflow belongs in BUILD, not canon repository. |
| `09_Technical/Tools/EchoheartsCompiler.py` | — | Project build/evidence driver | BUILD-owned tooling. Do not duplicate. |
| `09_Technical/Tools/verify_unreal_gate.py` | — | UE path/build helper corrections | BUILD-owned tooling. |
| `09_Technical/Tools/verify_infrastructure.py` | — | Checks local project/source paths | Rewrite as cross-repository/public-contract validation or omit; do not require executable files in canon repo. |
| `package_unreal.ps1` | — | Build/Automation/package script | BUILD-owned. Do not merge into canon repo. |
| `Config/DefaultEngine.ini` | Adds redirect to `/Script/EchoheartsRebearth` | — | Do not merge: redirect points at superseded module name and executable config belongs in BUILD. |
| `Config/DefaultGame.ini` | Adds project metadata | — | Project metadata may be mirrored as documentation, but executable config authority belongs in BUILD. |
| `.gitattributes` / `.gitignore` | Adjusts LFS/line-ending/generated-folder policy | — | Evaluate independently from foundation. Current public main already has LFS/ignore policy; do not couple this cleanup to runtime ownership. |
| `09_Technical/UE58_FOUNDATION_VERIFICATION_2026-10-03.md` | Evidence ladder | — | Reusable concept. Update terminology to BUILD ownership and retain as public verification documentation if desired. |
| `09_Technical/UE5_GIT_SYNC_PIPELINE_COMPLETE_2026-10-03.md` | — | Corrected role split and evidence ladder | Keep concept, but rename away from “COMPLETE”; it is a verification contract, not proof of completion. |
| `07_Art/UPLOAD_INTAKE_2026-10-03.md` | — | Art intake manifest | Unrelated to foundation. Split into an independent art/canon PR if still needed. |

## Smallest merge-safe path

1. **PR #18:** do not merge its executable project/module/Config foundation. Close as superseded or reduce it to a documentation-only verification record. Its `EchoheartsRebearth` runtime-module contract is no longer authoritative.
2. **PR #19:** rebase/split. Remove `.uproject`, `Source/`, executable workflows, compiler/build scripts, and packaging script from the public PR.
3. Retain only public-safe contract material that does not duplicate BUILD implementation, especially the repository-role split, verification boundary, evidence ladder, and any unrelated art-intake material moved to its own PR.
4. Keep all executable UE5.8 implementation and retained runtime evidence in `Dlomotion/ECHOHEARTS-REBEARTH-BUILD-`.
5. Update Issue #12 so its “actual .uproject path” points to the BUILD repository rather than requiring a public-repo `.uproject`.

## Evidence-gated checklist: PR #19 + Issue #12

### Repository-checkable now

- [x] Canon repository default branch remains `main`.
- [x] 125-ID Permanent Dex authority is preserved by the reviewed PR contracts.
- [x] BUILD repository exposes `EchoheartsRebearth.uproject` with EngineAssociation `5.8`.
- [x] BUILD repository exposes Game target `EchoheartsRebearth`.
- [x] BUILD repository exposes Editor target `EchoheartsRebearthEditor`.
- [x] BUILD repository exposes runtime module `Echohearts`.
- [x] BUILD repository exposes `Echohearts.Build.cs` and module entry files.
- [x] Hosted static compiler/repository/graph checks have a defined workflow.
- [x] Build evidence retention is defined in the BUILD workflow.
- [ ] Issue #12 text is updated to the repository-role split.
- [ ] PR #18 is closed/split to remove superseded runtime ownership.
- [ ] PR #19 is split/rebased to public-contract-only scope.
- [ ] Actual Automation test source/manifest for the intended filter is present and reviewed.
- [ ] An authored minimal `.umap` exists for packaging/PIE evidence.
- [ ] Protected-branch required-check names are selected only after the checks are reliable.

Repository/static checks may prove paths, names, JSON, source presence, workflow syntax, and contract consistency. They do not prove UE runtime execution.

### Requires authorized UE5.8 Windows runner

- [ ] Runner is online and matches required labels.
- [ ] Exact UE 5.8 `Build.version` is captured.
- [ ] Supported native compiler/toolchain version is captured.
- [ ] Fresh checkout completes.
- [ ] `git lfs pull` / integrity check succeeds.
- [ ] UHT completes successfully.
- [ ] Development Editor Win64 target compiles.
- [ ] Development Game Win64 target compiles.
- [ ] Expected binaries are produced and linked to the `Echohearts` module manifest.
- [ ] UE5.8 editor launches and loads the project/module.
- [ ] Authored minimal map opens.
- [ ] PIE runs at least 30 seconds and exits cleanly.
- [ ] Real non-empty Automation results pass.
- [ ] Development Win64 cook/package succeeds for the authored map.
- [ ] Expected game executable is present and hashed.
- [ ] Packaged executable launches and exits cleanly.
- [ ] Logs, source SHA, tool versions, Automation report, package metadata, and hashes are retained.

### Later evidence — do not block the basic foundation unless claimed

- [ ] Issue #10 body/animation runtime slice.
- [ ] Save/load and migration.
- [ ] Cloud sync.
- [ ] Multiplayer replication/reconnect.
- [ ] Measured latency/recovery at defined profiles.
- [ ] Performance budgets on representative hardware.
- [ ] Accessibility/readability acceptance.
- [ ] Cross-play and target-platform execution.
- [ ] ECO-API-001 only after its prerequisites and measured evidence exist.

## Trustworthy sequence

**Repository-role cleanup → BUILD static checks → authorized UE5.8 runner → clean clone/LFS → exact engine/toolchain preflight → UHT + Game/Editor compile → binary evidence → editor/module launch → authored map + PIE → real Automation → Development package → packaged launch → retained evidence → foundation status decision → Issue #10.**

Nothing in this sequence should be labeled VERIFIED before the evidence for that exact gate exists.

## Canon/reference protection

External game/franchise bestiaries, named creatures, proprietary progression mechanics, and benchmark terminology supplied during research remain reference-only. They must not be copied into the 125-ID Permanent Dex, seasonal rosters, code identifiers, or canon. Any contaminated candidate requires original redesign before promotion.

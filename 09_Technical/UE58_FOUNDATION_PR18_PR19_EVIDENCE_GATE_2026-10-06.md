# UE5.8 Foundation — PR #18 / PR #19 Evidence Gate

**Checked:** 2026-10-06  
**Status:** TECHNICAL CONTRACT / REPOSITORY REVIEW — NOT YET VERIFIED  
**Public contract repository:** `Dlomotion/Echohearts-Rebearth`  
**Executable runtime authority:** `Dlomotion/ECHOHEARTS-REBEARTH-BUILD-`

References:
- PR #18: https://github.com/Dlomotion/Echohearts-Rebearth/pull/18
- PR #19: https://github.com/Dlomotion/Echohearts-Rebearth/pull/19
- Issue #12: https://github.com/Dlomotion/Echohearts-Rebearth/issues/12
- Issue #10: https://github.com/Dlomotion/Echohearts-Rebearth/issues/10
- BUILD repository: https://github.com/Dlomotion/ECHOHEARTS-REBEARTH-BUILD-

## Current repository facts

At this review:
- PR #18 is open, mergeable, 14 commits / 12 changed files.
- PR #19 is open, not mergeable, 30 commits / 14 changed files.
- The repository-authority split established on 2026-10-06 means executable UE5.8 code, build/package tooling, and retained runtime evidence belong in the BUILD repository rather than this public canon/contracts repository.
- The BUILD repository already exposes `EchoheartsRebearth.uproject` with runtime module `Echohearts`, plus `Source/Echohearts/Echohearts.Build.cs` and the Echohearts compiler/build driver. Their presence is repository evidence only; UE5.8 compile/runtime remains NOT YET VERIFIED.

## File-by-file comparison

| File | PR #18 | PR #19 | Decision |
| --- | --- | --- | --- |
| `.gitattributes` | Updates line endings/LFS policy | — | Useful repository policy, but review independently; do not tie it to runtime-module naming. |
| `.gitignore` | Removes blanket `Build/` ignore | — | Good correction in principle. Keep source-controlled Build resources possible; runtime repo already uses scoped Build ignores. |
| `.github/workflows/ue-foundation-static-check.yml` | Static foundation check | — | Do not merge as written: it asserts obsolete `EchoheartsRebearth` runtime-module naming. |
| `09_Technical/UE58_FOUNDATION_VERIFICATION_2026-10-03.md` | Evidence checklist | — | Retain only as contract/history after updating repository ownership and module naming. |
| `Config/DefaultEngine.ini` | Adds redirect to `/Script/EchoheartsRebearth` | — | Do not promote unchanged; current runtime module is `Echohearts`. Runtime config belongs in BUILD. |
| `Config/DefaultGame.ini` | Project metadata | — | Runtime config belongs in BUILD; public repo may retain publication metadata separately. |
| `EchoheartsRebearth.uproject` | Runtime module = `EchoheartsRebearth` | Runtime module = `Echohearts` | Direct conflict. Current authority is `Echohearts`; executable descriptor belongs in BUILD. |
| `Source/EchoheartsRebearth.Target.cs` | `ExtraModuleNames.Add("EchoheartsRebearth")` | `ExtraModuleNames.Add("Echohearts")` | Direct conflict. Current authority is `Echohearts`. |
| `Source/EchoheartsRebearthEditor.Target.cs` | `ExtraModuleNames.Add("EchoheartsRebearth")` | `ExtraModuleNames.Add("Echohearts")` | Direct conflict. Current authority is `Echohearts`. |
| `Source/EchoheartsRebearth/**` | Creates obsolete primary module | — | Do not merge. Superseded by BUILD `Source/Echohearts/**`. |
| `.github/workflows/infrastructure.yml` | — | Hosted static checks | Useful concept, but executable tooling/workflow ownership belongs in BUILD. |
| `.github/workflows/ue5-build.yml` | — | Self-hosted Windows UE5.8 package gate | BUILD-only. Requires authorized runner and direct evidence. |
| `07_Art/UPLOAD_INTAKE_2026-10-03.md` | — | Public intake documentation | Candidate to retain in public repo after canon/provenance review. |
| `09_Technical/Tools/EchoheartsCompiler.py` | — | Build driver | Do not merge here; BUILD owns the executable driver. |
| `09_Technical/Tools/verify_infrastructure.py` | — | Static verifier | Keep executable verifier in BUILD; public repo can document contract requirements. |
| `09_Technical/Tools/verify_unreal_gate.py` | — | UE gate verifier | BUILD-only. |
| `09_Technical/UE5_GIT_SYNC_PIPELINE_COMPLETE_2026-10-03.md` | — | Technical contract | Candidate public documentation after removing any implication that this repo owns executable runtime. |
| `Source/Echohearts/**` | — | Corrected runtime module | Correct naming, but executable source belongs in BUILD. |
| `package_unreal.ps1` | — | Packaging orchestration | BUILD-only. |

## Smallest merge-safe path

1. **Do not merge PR #18's executable module.** Its primary module name and API-macro direction conflict with the current `Echohearts` runtime authority.
2. **Do not merge PR #19 wholesale.** Its own 2026-10-06 correction says executable code/tooling must not create a second runtime authority.
3. Extract only public documentation/intake material that still belongs in this repository into a new documentation-only PR.
4. Treat the BUILD repository as the sole location for `.uproject`, runtime `Source/`, build/package scripts, UE workflows, and runtime evidence.
5. Repoint Issue #12's UE execution prerequisites at the BUILD repository.
6. Keep Issue #10 blocked until real UE5.8 runtime evidence exists.

Closing or superseding PR #18/#19 should happen only after any useful public-contract text has been preserved.

## Repository-checkable corrections now

These can be checked without UE5.8:
- JSON parses and required keys exist.
- Target/module names are internally consistent.
- Public docs use `Echohearts` / `ECHOHEARTS_API` for the runtime module contract.
- The 125-ID Permanent Dex remains authoritative.
- Hosted CI is clearly labeled static/repository-only.
- Build scripts do not claim a generic meaning for exit code 2.
- Required paths, naming rules, LFS policies, and evidence metadata schemas can be validated.
- Public repo does not duplicate executable BUILD ownership.

These checks may be labeled `STATIC CHECK PASSED` or `REPOSITORY CONTRACT PASSED`, never runtime VERIFIED.

## Issue #12 — evidence-gated activation checklist

### Repository / infrastructure gate
- [ ] Public repo documents BUILD as executable authority.
- [ ] BUILD repo contains the intended `.uproject`, targets, module rules, and source paths.
- [ ] Runtime module contract is `Echohearts`; export macro contract is `ECHOHEARTS_API`.
- [ ] Git LFS patterns and ignore rules are reviewed; required project resources are not accidentally ignored.
- [ ] Static Python/JSON checks pass from a clean checkout.
- [ ] Authorized runner labels, artifact retention, secrets boundaries, and environment ownership are documented.

### Real UE5.8 machine / authorized-runner gate
- [ ] Clean checkout + `git lfs pull`.
- [ ] Exact UE5.8 `Build.version` captured.
- [ ] Project files/UHT succeed.
- [ ] `EchoheartsRebearthEditor Win64 Development` compiles.
- [ ] Editor launches the exact source SHA.
- [ ] Authored minimal map opens.
- [ ] PIE runs for the required smoke window and exits cleanly.
- [ ] Bounded Automation tests exist, execute, and produce non-empty reviewed results.
- [ ] Development Win64 cook/package succeeds.
- [ ] Packaged executable launches and exits cleanly.
- [ ] Logs, commands, checksums, toolchain versions, and artifact metadata are retained.

### Feature/runtime gates after the foundation
- [ ] Issue #10 humanoid + Eco-Kin animation/body proof.
- [ ] Save/load/migration/recovery evidence.
- [ ] Dedicated server/client authority and replication evidence.
- [ ] Network reconnect/latency evidence where claimed.
- [ ] Performance and memory capture on representative target hardware.
- [ ] Accessibility/readability verification.
- [ ] Platform-specific SDK/certification checks only on authorized environments.

## Verification rule

A passing repository check proves only that repository contract. A passing UHT/compile proves only that build scope. A successful package command proves only packaging. Runtime, gameplay, save, networking, AI, cross-play, performance, certification, and platform behavior require their own retained evidence.

**Nothing in PR #18, PR #19, or this document is labeled VERIFIED.**

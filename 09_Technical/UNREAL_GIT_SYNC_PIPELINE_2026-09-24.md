# UNREAL ENGINE 5.8 + GITHUB SYNCHRONIZATION PIPELINE — 2026-09-24

**Project:** Echohearts: Rebearth  
**Status:** OPERATIONAL DESIGN / NOT YET VERIFIED AGAINST A LOCAL UE5.8 PROJECT BUILD  
**Repository:** `Dlomotion/Echohearts-Rebearth`  
**Canonical branch:** `main`

## AI Mistake Patch / Continuity QA

This document reconciles the reposted Git/Unreal/AI synchronization blueprint with the current Echohearts repository and production rules.

### Corrections to the repost

1. **Do not run `git init` against the existing official repository checkout.** The GitHub repository already exists. Clone/fetch the canonical repository instead.
2. **Git LFS is recommended for Unreal binary assets, but standard Git does not literally fail merely because a `.uasset` or `.umap` is committed.** The real problems are repository growth, inefficient binary history, merge conflicts and hosting limits.
3. **Unreal binary assets are not normally text-mergeable.** File locking or strict ownership/branch discipline is required for `.uasset` and `.umap` work.
4. **Production runtime is UE5.8, not UE5.7.** Any CI path hard-coded to `UE_5.7` is retired.
5. **Do not create a second `/Docs/AI_Architecture/` source-of-truth tree.** Echohearts already has `MASTER_PROJECT_INDEX.md` and the official `00_Canon_Lock` → `11_Publication` routing structure. AI/technical architecture belongs under `09_Technical` and production workflow material under `10_Production`.
6. **Do not add an Unreal packaging workflow until the repository contains the actual `.uproject`, build targets/modules and an authorized runner/engine path.** No `.uproject` is currently proven on `main`, so a Shipping BuildCookRun workflow would be false automation.
7. **`Build/` ignore rules need exceptions.** Unreal projects may contain project icons or manually maintained packaging resources under `Build`; use a curated Unreal ignore template rather than blindly ignoring everything.
8. **Closing the Editor before every C++ build is not an absolute Unreal requirement, but it is the safer default for branch switches, external file replacement, project-wide refactors and non-Live-Coding rebuilds.** Never switch branches underneath loaded binary assets.
9. **The current branch ruleset is not a full PR protection policy.** `Protect_Main_Branch` currently prevents branch deletion and non-fast-forward updates, but it does not currently prove required pull requests, reviews or status checks.
10. **Do not search/copy arbitrary GitHub code into production.** Search official Epic UE5.8 docs first, then licensed public code only when needed. Record provenance/license and adapt, do not paste blindly.

## 1. Knowledge synchronization

Use the existing source-of-truth chain:

`MASTER_PROJECT_INDEX.md` → `00_Canon_Lock` → `01_Story` → `02_World` → `03_EcoKin_Dex` → `04_Systems` → `05_Levels` → `06_UI_UX` → `07_Art` → `08_Audio` → `09_Technical` → `10_Production` → `11_Publication` → `99_Reference_Retired_Needs_Redesign`

Recovered AI/chat material follows:

`INTAKE → AI MISTAKE PATCH → CONTINUITY CHECK → ORIGINALITY/IP CHECK → CORRECT FOLDER → STATUS → GAME/STORY LINK → IMPLEMENTATION EVIDENCE`

Do not re-seed every new AI session with an uncontrolled giant prompt. Prefer the repository's canonical index plus the smallest relevant source documents for the current task.

## 2. Local repository setup

For a new workstation:

```bash
git clone https://github.com/Dlomotion/Echohearts-Rebearth.git
cd Echohearts-Rebearth
git lfs install
git lfs pull
git fetch --all --prune
```

Before beginning work:

```bash
git switch main
git pull --ff-only origin main
git switch -c <type>/<short-task-name>
```

Recommended branch prefixes:
- `feat/` gameplay/system work
- `fix/` defect correction
- `art/` binary art/animation asset work
- `level/` map/world asset work
- `docs/` documentation/canon routing
- `chore/` build/repository/tooling

Never share a branch for concurrent editing of the same `.uasset`/`.umap` unless the team has an explicit asset-locking workflow.

## 3. Unreal file policy

### Track in Git
- `.uproject`
- `Config/**`
- `Source/**`
- `Plugins/**/Source/**`
- `Content/**` authored project assets
- `Build/**` only where project-owned resources are intentionally required
- project documentation and data dictionaries

### Ignore generated/local output
- `.vs/`
- generated IDE solution/database files
- `Binaries/`
- `DerivedDataCache/`
- `Intermediate/`
- `Saved/`
- plugin-local `Binaries/` and `Intermediate/`

### Git LFS target policy
Minimum Unreal binary patterns:
- `*.uasset`
- `*.umap`

Recommended source-art / DCC patterns once those assets actually live in this repository:
- `*.fbx`
- `*.blend`
- `*.psd`
- `*.tga`
- `*.exr`
- `*.wav`

`*.png` should not automatically be pushed into LFS merely because it is an image. Use LFS for large binary source/production art after checking repository volume and GitHub LFS storage/bandwidth implications. Small documentation/reference PNGs can remain normal Git objects.

## 4. Binary asset safety

`.uasset` and `.umap` files are binary and generally cannot be safely line-merged. For map/content work:

1. sync `main` before starting;
2. create one focused branch;
3. assign ownership of contested binary assets;
4. avoid two people editing the same binary simultaneously;
5. use One File Per Actor / World Partition where applicable to reduce map contention;
6. commit related source + assets together in bounded changes;
7. rebase/update before handoff only when binary ownership is clear;
8. test load the affected map/content after integration.

If the team needs editor-integrated Git locking, evaluate a Git-LFS-capable Unreal workflow such as the current Git source-control integration or a Git-based tool that supports file locks. Do not assume ordinary Git branches solve binary merge contention by themselves.

## 5. C++ / Blueprint correction loop

Use this evidence-driven loop:

`issue/log → reproduce → inspect current UE5.8 docs → smallest fix → compile → automation/unit test → PIE/editor test → latency/reconnect/save tests where relevant → profile → document evidence → PR`

For external branch switches, project-wide code replacement or full rebuilds, close the Editor first. Live Coding can be used only for changes it safely supports; it is not proof that a clean Editor/target build succeeds.

Never use:

```bash
git add . && git commit -m "Fix"
```

as an automatic post-build step. Review the diff and staged assets first:

```bash
git status
git diff
git diff --cached
git add <intentional-files>
git commit -m "<scope>: <specific change>"
```

## 6. Build and CI gate

A UE5.8 packaging workflow is **BLOCKED** until these are proven in the repository/runner:

- actual `.uproject` path;
- UE5.8 installation or source-build path;
- required target names (`Editor`, client/server/game as applicable);
- plugin dependencies;
- platform SDK authorization;
- self-hosted runner labels and permissions;
- Git LFS checkout;
- cache policy;
- Automation Test command set;
- artifact retention policy.

When those exist, CI should stage in this order:

1. checkout + LFS;
2. environment/engine validation;
3. clean Editor target build;
4. required Automation tests;
5. cook/package only for authorized branches/tags;
6. upload build/test logs and artifacts;
7. make required checks eligible for branch protection.

Do not call CI `VERIFIED` merely because YAML parses.

## 7. Current Echohearts technical gate order

Do not let repository/tooling work jump the established gameplay verification gates:

1. authorized UE5.8 `EchoheartsEditor` build;
2. run `Echohearts.Partners.CommandBuffer` Automation evidence;
3. reload/recovery/travel/reconnect/late-join tests at 150/250/350 ms;
4. implement `ECO-API-001` shared result-event envelope;
5. implement the smallest `BCT-001` reservation/commit/rollback kernel;
6. prove one BuildPiece + one CraftRecipe end-to-end;
7. then promote one legacy feature at a time, beginning with POI/Fast-Travel authority + World Partition streaming.

## 8. Branch-management target

Current repository evidence shows an active `Protect_Main_Branch` ruleset that prevents deletion and non-fast-forward operations. That is useful but incomplete.

Target `main` policy when CI exists:
- require pull request before merge;
- require branch to be up to date where appropriate;
- require UE5.8 build/test checks;
- block force pushes;
- block deletion;
- restrict direct pushes except explicit emergency/admin bypass;
- prefer squash or rebase merge for bounded task branches;
- require resolved conversations before merge;
- optional signed commits/tags for release branches once the signing workflow is actually configured.

Do not enable required status checks before the checks reliably exist, or `main` can become unnecessarily blocked.

## 9. GitHub bug-fix research rule

Research order:

1. current official Epic/Unreal Engine 5.8 documentation;
2. current Echohearts repository evidence;
3. Epic issues/forums when needed;
4. vendor/platform documentation;
5. licensed public GitHub repositories and issues;
6. developer-authored talks/postmortems.

Record source, date, license/provenance, exact error/symptom and the reason a proposed fix applies. Never claim a third-party snippet is production-safe until compiled and tested in the actual project.

## 10. Status

### Completed at repository level
- official repository identified;
- `main` confirmed as default branch;
- active branch ruleset confirmed;
- existing workflow directory confirmed;
- no `.uproject` found on current default branch search;
- no root `.gitignore` found before this intake;
- no root `.gitattributes` found before this intake;
- no `ue5-build.yml` found before this intake.

### NOT YET VERIFIED
- local Unreal Engine project checkout;
- UE5.8 compiler/toolchain path;
- actual game module names;
- Git LFS installation on the user's workstation;
- binary asset lock provider;
- clean Editor build;
- cook/package;
- automated gameplay tests;
- self-hosted GitHub runner;
- release artifact pipeline.

© 2026 Into Deep Studios and Donta L. Owens. All rights reserved.

# Echohearts: Rebearth — Unreal / Git / LFS / CI Synchronization Pipeline

Status: **TECHNICAL STANDARD — IMPLEMENTATION PARTIAL / UE BUILD NOT YET VERIFIED**
Date: 2026-09-24
Canonical repository: `Dlomotion/Echohearts-Rebearth`
Production runtime target: **Unreal Engine 5.8**

## Purpose

This document consolidates the project-history / Git / Unreal synchronization proposal into the existing Echohearts source-of-truth structure. It does not create a parallel `Docs/AI_Architecture` hierarchy, second Master Bible, duplicate daily workflow, or alternate canon.

The repository remains the engineering source of truth. Chat exports, AI notes, screenshots, generated concepts, and imported design discussions are **inputs** that must be reconciled into the existing folders and canon/status system before implementation.

## Corrections to the imported blueprint

1. **Do not run `git init` inside the canonical clone.** Clone/fetch the existing repository and work from a feature branch. Re-initializing is unnecessary and can confuse local setup.
2. **Do not blanket-ignore `Build/`.** Unreal projects may keep project packaging resources, icons, and platform-specific source-controlled data there. Review the directory intentionally.
3. **Do not force every PNG into Git LFS.** LFS is appropriate for large/binary source assets, but small UI/reference images can stay in normal Git. Use path-specific LFS rules when source-art directories become large.
4. **Use Git LFS locking for non-mergeable Unreal assets.** `.uasset` and `.umap` are tracked as LFS + `lockable`; compatible DCC binaries may also be locked.
5. **Do not auto-commit immediately after UBT.** Compile/test first, inspect the diff, then commit intentionally. A failed compile must never become a normal "Fix" commit just because a shell chain reached `git add`.
6. **Closing the editor is not a universal rule.** Full editor shutdown is recommended for structural C++/UHT/module changes and any change where Live Coding cannot safely reflect type/layout changes. Simple supported Live Coding iterations may remain in-editor.
7. **The production target is UE5.8, not UE5.7.** CI paths/configuration must not hard-code the older engine version.
8. **Do not expose a self-hosted build runner to untrusted public-PR code.** This repository is public. A workstation runner must be restricted to trusted/manual or trusted-branch execution, with least-privilege tokens and no unreviewed fork code.
9. `UGlobalAudioPoolManager` is not treated as a production dependency unless the actual class exists in source and is benchmarked. Audio pooling remains a technical proposal until implemented/profiled.
10. "Glitched code wireframe" materials are an art-direction proposal, not a global shader requirement. They must pass canon/art/performance review before use.

## Source-of-truth routing

Do not create a separate `/Docs/AI_Architecture/` master hierarchy. Route material into the existing project structure:

- `00_Canon_Lock` — approved terminology/rules only
- `01_Story` / `02_World` — narrative/world continuity
- `03_EcoKin_Dex` — Eco-Kin identity/data
- `04_Systems` — gameplay contracts/mechanics
- `06_UI_UX` — interface standards
- `07_Art` — model sheets, visual QA, animation standards
- `09_Technical` — architecture, Unreal/Git/CI/security/test documentation
- `10_Production` / `11_Daily_Assignments` — execution tracking
- `99_Reference_Retired_Needs_Redesign` — obsolete/conflicting/import-only material

AI/chat material must be classified as `CANON`, `PROPOSAL`, `REFERENCE/RETIRED`, `CONFLICT-NEEDS-DECISION`, or `TECHNICAL-TASK`, and as `VERIFIED` or `NOT YET VERIFIED` where applicable.

## Recommended local Git workflow

```bash
git clone https://github.com/Dlomotion/Echohearts-Rebearth.git
cd Echohearts-Rebearth
git fetch --all --prune
git switch main
git pull --ff-only
git switch -c feature/<work-item>
```

Before asset work:

```bash
git lfs install
git lfs track
```

For `.uasset` / `.umap` collaborative editing, use LFS locks where supported:

```bash
git lfs lock Content/Path/Asset.uasset
# edit asset
git lfs unlock Content/Path/Asset.uasset
```

## Commit / verification loop

Preferred engineering loop:

```text
Edit source/assets
    ↓
For structural C++/UHT changes: close editor
    ↓
Compile / UHT / automated tests
    ↓
Launch UE5.8 editor and run target test
    ↓
Inspect `git status` and `git diff`
    ↓
Commit to feature branch
    ↓
Push branch
    ↓
Open PR
    ↓
CI + review + runtime evidence
    ↓
Merge only when gates are satisfied
```

Never interpret a successful text-only C++ harness as proof that Unreal reflection, replication, packaging, assets, or editor integration work.

## Branch strategy

- `main` — protected integration/source-of-truth branch
- `feature/*` — gameplay/system implementation
- `fix/*` — defect correction
- `design/*` — design/document changes
- `infra/*` — build, source-control, CI, tooling
- `art/*` — source-art/animation integration where appropriate

Avoid long-lived parallel branches that become alternate versions of canon.

## Git LFS baseline

Repository `.gitattributes` should track non-mergeable Unreal binary assets through LFS and mark primary Unreal package/map formats `lockable`.

Core patterns:

```gitattributes
*.uasset filter=lfs diff=lfs merge=lfs -text lockable
*.umap   filter=lfs diff=lfs merge=lfs -text lockable
*.fbx    filter=lfs diff=lfs merge=lfs -text lockable
*.blend  filter=lfs diff=lfs merge=lfs -text lockable
*.psd    filter=lfs diff=lfs merge=lfs -text lockable
```

Do not retroactively migrate large existing history without an explicit migration plan, backup, collaborator coordination, and repository-size review.

## CI architecture

### Current repository state

The repository currently has a lightweight hosted workflow for `09_Technical/MetaSystems`. The actual UE5.8 project skeleton / `.uproject` / `Source/` module tree must exist before a real Unreal package workflow can be verified.

### Safe Unreal build-runner policy

Because the repository is public, do **not** attach the developer workstation as an unrestricted `pull_request` self-hosted runner. A malicious fork PR could execute arbitrary code on the runner.

Preferred choices:

1. trusted/manual `workflow_dispatch` execution on a hardened dedicated runner;
2. trusted `push` execution on a protected integration branch only;
3. isolated/ephemeral build VM/runner with no personal credentials;
4. hosted/managed Unreal build service if later adopted.

The build runner must use least-privilege credentials, avoid persistent personal secrets, and wipe/recreate workspaces between jobs where practical.

## UE5.8 CI template — activate only after the project skeleton exists

Do not place this template into active CI until the actual canonical `.uproject` path and engine installation are verified.

```yaml
name: UE5.8 Build Validation

on:
  workflow_dispatch:
  push:
    branches: [ ue58-integration ]

permissions:
  contents: read

jobs:
  build:
    runs-on: [self-hosted, windows, ue58, trusted]
    steps:
      - name: Checkout
        uses: actions/checkout@v4
        with:
          lfs: true
          persist-credentials: false

      - name: Validate project path
        shell: pwsh
        run: |
          if (-not (Test-Path "$env:GITHUB_WORKSPACE\EchoheartsRebearth.uproject")) {
            throw "Canonical .uproject not found"
          }

      - name: Build / Cook / Package
        shell: pwsh
        run: |
          & "C:\Program Files\Epic Games\UE_5.8\Engine\Build\BatchFiles\RunUAT.bat" `
            BuildCookRun `
            -project="$env:GITHUB_WORKSPACE\EchoheartsRebearth.uproject" `
            -noP4 `
            -platform=Win64 `
            -clientconfig=Development `
            -build -cook -stage -package `
            -utf8output
```

Shipping should not be the first validation configuration. Begin with Development/Test evidence, then add Shipping once packaging and configuration behavior are understood.

## Unreal source-control / binary rules

- Never resolve `.uasset`/`.umap` conflicts by hand-editing binary data.
- Prefer ownership/locking for maps and high-conflict binary assets.
- Keep maps modular to reduce contention.
- Keep generated cache/build output out of Git.
- Verify LFS objects are actually uploaded before deleting local source copies.
- Before large binary migrations, create a recovery tag/backup and validate a fresh clone with `git lfs pull`.

## AI / research synchronization rule

External code/tutorials may be studied for transferable principles only. Do not copy proprietary game rigs, assets, animation timing, shaders, protected source code, UI identity, or confidential implementation.

For each imported technical idea:

1. identify provenance;
2. compare against current Unreal 5.8 documentation;
3. check repository architecture and existing implementation;
4. classify the item;
5. rewrite it in Echohearts-native terms/architecture;
6. test in the actual UE project;
7. document evidence before calling it verified.

## Dependency on Issue #10

The NPC + Eco-Kin 3D body/animation vertical slice remains blocked from genuine UE integration until the project/module skeleton exists. Once available, Issue #10 can implement and verify the canonical character, equipment, damage, hit-reaction, IK/contact, rig-family, and AnimBP slice against the real module/API/packaging environment.

## Verification checklist

Before calling this pipeline production-ready:

- [x] `.gitignore` baseline added on infrastructure branch
- [x] `.gitattributes` LFS/lock policy added on infrastructure branch
- [ ] actual UE5.8 `.uproject` committed/verified
- [ ] actual `Source/` module tree committed/verified
- [ ] fresh clone + `git lfs pull` validated
- [ ] LFS lock/unlock test validated with a real Unreal asset
- [ ] branch protection/ruleset reviewed
- [ ] trusted build-runner security model implemented
- [ ] UE5.8 build workflow activated
- [ ] UHT/compile test passes
- [ ] editor launch passes
- [ ] automated tests pass
- [ ] packaged Development build launches
- [ ] LFS-backed asset loads in fresh clone
- [ ] recovery/rollback procedure tested

Until those unchecked gates have evidence, status remains **NOT YET VERIFIED**.

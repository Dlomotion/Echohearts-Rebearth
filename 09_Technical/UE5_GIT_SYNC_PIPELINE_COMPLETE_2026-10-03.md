# UE 5.8 manual build pipeline — 2026-10-03

Status: infrastructure candidate, not production verified.

## Authoritative paths

- Repository: Dlomotion/Echohearts-Rebearth
- Engine installation: C:\Program Files\Epic Games\UE_5.8 (not the repository root)
- Project: EchoheartsRebearth.uproject at the repository root
- Entry point: .github/workflows/ue5-build.yml
- Packaging implementation: package_unreal.ps1
- Local path checker: 09_Technical/Tools/verify_unreal_gate.py

One manual workflow owns packaging; no duplicate unreal-package.yml is needed.
Push and pull-request packaging triggers are absent. Shipping is intentionally unavailable at this gate.

## Findings against main

The inspected main tree had a root descriptor declaring 5.4, a packaging script looking for UE4Editor.exe, and no Target.cs, Build.cs, or .umap files. This change aligns the descriptor with 5.8 and fixes executable selection; it does not invent missing gameplay, source modules, tests, or map assets.

Required foundation paths are Source/EchoheartsEditor.Target.cs,
Source/EchoheartsRebearth.Target.cs, and
Source/EchoheartsRebearth/EchoheartsRebearth.Build.cs.
Their classes and module declarations must agree with the root descriptor before execution.
Existing foundation work must be reconciled into this layout in a separate reviewed change.

## Runner setup and execution

Provision an authorized Windows x64 runner with labels self-hosted, Windows, X64, echohearts-ue58; PowerShell 7; Git LFS; and the UE 5.8 compiler toolchain.
Configure the unreal-packaging environment to permit reviewed main only.
The workflow additionally rejects non-default branch runs.
After review and merge, use Actions > Echohearts UE 5.8 manual build gate > Run workflow, supplying an authored /Game/... map.

The script checks the engine Build.version, project association, foundation paths and map presence; builds Development Editor; exports and checks nonempty successful CommandBuffer Automation results; then cooks and packages Development.
Each native process exit code is checked. Logs are uploaded on failure; package uploads require success.
Test report schema and PowerShell execution still need validation on the real runner. An exact expected test-name manifest must be established when the missing test sources are integrated; this candidate checks nonempty results, not an exact four-test inventory.

Local path check:
python 09_Technical/Tools/verify_unreal_gate.py preflight --engine-root "C:/Program Files/Epic Games/UE_5.8"

The helper's standalone build/automation/package commands are diagnostic commands, not substitutes for the gated packaging script.

## Evidence and progression

1. Validate engine and real source foundation.
2. Build Editor and pass reviewed Automation tests.
3. Produce and launch a Development package; preserve logs and commit identity.
4. Measure recovery at 150/250/350 ms with documented latency definition, loss conditions, acceptance thresholds, and server/client traces.
5. Advance ECO-API-001 only after reviewed recovery evidence passes.

This workflow does not perform or certify recovery measurements. No push packaging should be enabled until the required Windows gate passes and a separate change is reviewed.

## Repository synchronization

Echohearts-Rebearth remains primary. Echohearts is reference and Echohearts-Ecokins is intake according to project direction; neither repository was modified or consolidated by this change.
Transfer selected, reviewed commits through branches and PRs; do not mirror whole repositories or overwrite canonical art/rosters.
No branch-protection settings or runner installation are claimed complete.

## Recovery

Preserve the failed run logs, repair the reported prerequisite on a new branch, review and merge, then manually retry on a clean checkout.
Do not reuse stale BuildEvidence or PackagedOutput. Revert this PR through GitHub if rollback is required; avoid history rewriting.

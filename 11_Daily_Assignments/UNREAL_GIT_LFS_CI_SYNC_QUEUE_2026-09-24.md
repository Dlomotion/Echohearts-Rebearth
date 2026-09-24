# Unreal / Git / LFS / CI Integration Queue

Status: **TECHNICAL-TASK — NOT YET VERIFIED**
Parent workflow: **Echohearts Daily Game Work**

## Immediate queue

1. Merge/review the corrected `.gitignore` and `.gitattributes` baseline.
2. Confirm final canonical UE5.8 project filename and module name.
3. Commit the real `.uproject` and `Source/` module skeleton on a dedicated implementation branch.
4. Run first UHT/compile test and record exact evidence.
5. Validate fresh clone + `git lfs pull`.
6. Create one test `.uasset` lock/unlock cycle and verify collaborative behavior.
7. Review branch protection/rulesets for `main`.
8. Provision a hardened trusted UE5.8 build runner; do not expose a personal workstation to untrusted public PR execution.
9. Activate the UE5.8 workflow template only after project path/runner verification.
10. Resume Issue #10 NPC + Eco-Kin 3D body/animation implementation against the real Unreal module.

## Daily evidence rule

Do not mark setup complete based on documentation alone. Each checked item needs repository, runner, compile, editor, LFS, workflow, or packaged-build evidence.

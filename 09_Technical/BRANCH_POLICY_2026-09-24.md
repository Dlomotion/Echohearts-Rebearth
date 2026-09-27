# Branch / Pull Request Policy

Status: **TECHNICAL STANDARD — NOT YET FULLY ENFORCED**

## Branch roles
- `main`: protected source-of-truth integration branch
- `feature/*`: gameplay/system work
- `fix/*`: defect correction
- `design/*`: documentation/design changes
- `infra/*`: CI/source-control/tooling
- `art/*`: asset integration when appropriate

## Rules
- Do not commit routine feature work directly to `main`.
- Keep PRs scoped to one coherent work item.
- Do not mix Issue #8 tactical networking work with Issue #10 real-time NPC/Eco-Kin animation work.
- Require evidence appropriate to the change type before calling work VERIFIED.
- Binary Unreal assets should use LFS locking when collaboration risk exists.
- Avoid force-pushing shared branches except for deliberate recovery with explicit coordination.
- Prefer squash or rebase strategies only when they preserve traceability and repository rules permit them.
- Stale or conflicting design branches must not become alternate canon.

# Echohearts Repo Doctor

Read-only TypeScript diagnostics for repository drift and high-risk project mistakes.

## Commands

- `npm install`
- `npm run check` — strict TypeScript compile check.
- `npm run audit` — scans the current repository and returns machine-readable findings.

The doctor does **not** rewrite canon, Unreal assets, C++, or configuration automatically. Findings must be reviewed before repair. UE compile/runtime status still requires real UE5.8 evidence.

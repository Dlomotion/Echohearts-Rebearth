# Linux Launch-Readiness Plan — Echohearts: Rebearth
**Date:** 2026-10-15 · **Scope:** five workstreams only · **No branches created, nothing pushed.** All work below is staged locally, ready to push when you say so.

## Honest state of the five workstreams

| # | Workstream | What's there | State |
|---|---|---|---|
| 1 | Linux build/package scripts + CI | `build-linux.sh`, `package-linux.sh` (syntax-checked), `unreal-linux.yml` CI workflow, cross-platform launcher (compiles; dry-run passed on Linux), platform groundwork doc, UE 5.8.3 target-lock doc | IMPLEMENTED — not compiled, not runtime verified |
| 2 | Anti-cheat session attestation | `AntiCheatTypes.h` (server-authoritative session-check interface) + integration plan for Epic's EAC Linux v2 | IMPLEMENTED — not compiled. Note: this is game-side attestation, not a rebuild of Epic's proprietary EAC |
| 3 | Release-and-harvest code | `ReleaseHarvestTypes.h`, `EcoKinReleaseSubsystem` (.h/.cpp) — willing release yields shed/gifted resources; release is never sacrifice | IMPLEMENTED — not compiled |
| 4 | EcoKin contracts | Core attributes (Vibrance/Density/Harmony/Purity), taxonomy, Kindling, Dex subsystem (.h/.cpp) | IMPLEMENTED — not compiled |
| 5 | Championship TV system | Broadcast types, TV actor, broadcast subsystem (.h/.cpp) | IMPLEMENTED — not compiled |

**The honest gate:** none of this has been through the Unreal compiler. Everything above needs a Windows machine with UE 5.8.3 before any launch claim is real. Scripts and launcher are the only pieces tested (on Linux, dry-run).

## Staged bundles (ready to push)
In `linux-staged-bundles/`, one tarball per workstream, contents verified:
1. `bundle-01-linux-platform.tar.gz` — build/package scripts, Linux CI, launcher, platform docs
2. `bundle-02-anticheat.tar.gz` — attestation header + integration plan
3. `bundle-03-release-harvest.tar.gz` — release subsystem
4. `bundle-04-ecokin-contracts.tar.gz` — attributes, taxonomy, Kindling, Dex subsystem
5. `bundle-05-championship-tv.tar.gz` — broadcast system

## Push sequence (when you approve)
1. Grant the GitHub App access to `IN2Deep-Studios/ECHOHEARTS-REBEARTH-BUILD-` (currently unreachable).
2. Push bundles 01–02 to a `platform/linux-groundwork` branch → draft PR.
3. Push bundles 03–05 to a `systems/` branch → draft PR (or same PR if you prefer one).
4. Compile on the Windows UE 5.8.3 machine; only then mark anything launch-ready.

## Unresolved (blocked on private-repo access)
- Comparison of this local work against the private `IN2Deep-Studios/ECHOHEARTS-REBEARTH-BUILD-` repo: **cannot verify** until access is granted — possible overlap or conflicts unknown.
- Same for `IN2Deep-Studios/ECHOHEARTS-REBEARTH-` (canonical tree).

## Decision list
- [ ] Grant private-repo access so the comparison and push can proceed.
- [ ] Approve the push sequence (one branch per bundle group, or a single branch).
- [ ] Schedule the Windows UE 5.8.3 compile pass — the real readiness gate.

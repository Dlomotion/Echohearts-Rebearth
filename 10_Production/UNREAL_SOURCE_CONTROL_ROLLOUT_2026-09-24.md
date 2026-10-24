# Unreal Source-Control Rollout

Status: **PRODUCTION PLAN — NOT YET VERIFIED**

## Phase 1 — repository hygiene
- `.gitignore` baseline
- `.gitattributes` LFS + lock policy
- branch/PR workflow
- recovery procedure

## Phase 2 — Unreal skeleton
- canonical `.uproject`
- canonical runtime/editor modules
- explicit Build.cs dependencies
- first UHT/compile/editor evidence

## Phase 3 — asset collaboration
- fresh clone test
- LFS pull test
- real `.uasset` lock/unlock test
- map ownership/locking convention

## Phase 4 — CI
- isolated trusted UE5.8 Windows runner
- manual/protected-branch activation first
- Development build/cook/package
- test and artifact retention
- Shipping pipeline only after Development behavior is understood

## Phase 5 — gameplay integration
Resume Issue #10 NPC/Eco-Kin body + animation implementation against the verified UE project. Keep Issue #8 tactical work separate from the real-time character/creature pipeline.

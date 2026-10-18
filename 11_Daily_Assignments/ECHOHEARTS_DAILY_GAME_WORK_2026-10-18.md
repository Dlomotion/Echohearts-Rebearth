# Echohearts daily evidence — 2026-10-18

**Scope:** existing PR #71 encounter/Kindling reference and its existing scene. Canon remains in this repository; executable Unreal implementation/evidence belongs in BUILD. New scene details are **PROPOSAL**. No new workflow, Master Bible, Dex identity or executable foundation.

## REPOSITORY/BUILD STATUS

- Canon main observed at `85f653fb66295371bdce4edc73e71ab10725b96d`.
- PR #71 observed head `a0fe65f57970e683cb544cd1d2bceb6b2f714ade`, branch `feature/encounter-kindling-gap-designs-2026-10-17`, open draft, mergeable. Existing hosted reference run [39050877820](https://github.com/Dlomotion/Echohearts-Rebearth/actions/runs/39050877820) succeeded at that head. Today's correction is prepared on this same branch, with no merge or history rewrite.
- BUILD metadata request again returned GitHub **404**. This proves connection unavailability, not deletion, absence of files, or the reason access fails. Actual current BUILD head, .uproject, module/API macro, targets, engine headers and logs cannot be independently inspected.
- Dlomotion/EcoKin-patch PR #2 head `9c04cd8c6239f60c3d17996791bb7ddd69079283` is readable, open draft and mergeable. Seven-file patch includes original standalone SAT/codec/snap/display references and an include diff. Hosted runs [39049763277](https://github.com/Dlomotion/EcoKin-patch/actions/runs/39049763277) and [39049751565](https://github.com/Dlomotion/EcoKin-patch/actions/runs/39049751565) report success at that exact head. Local GCC 13.3 C++17 build with warnings-as-errors and UBSan reproduced its PASS output. `-DNDEBUG -fsyntax-only` correctly failed with “Regression checks require active assertions”. No changes made to that repair lane today.
- No local git clone or LFS objects were materialized; Git working-tree/index/object/LFS health is **NOT YET VERIFIED**. Remote text was inspected at pinned commits. .gitattributes declares LFS for .uasset/.umap and source binary extensions; this does not prove object availability or conversion. No asset migration occurred.
- .gitignore incorrectly excluded the entire `Build/` tree. Removed that blanket exclusion. The inspected canon tree has no Build resources to justify narrower patterns; classify real BUILD resource/generated files before adding exclusions. Existing generated Binaries/Intermediate/Saved exclusions remain. Binary asset ownership/one-editor-at-a-time and conflict resolution remain required; LFS alone cannot merge assets.
- CI workflow inspected: hosted Ubuntu reference checks with read-only contents permission, no persistent self-hosted execution. Checkout/setup Actions still use major-version references; immutable pin governance remains follow-up, not a claim completed today.

### Smallest correction package

`validate_spawn_commit` accepted a changed species/fingerprint and changed weather, biome or Purity at the same cell revision. This was a reference contract defect; no deployed exploit is claimed.

Require keyword-only host candidates, approved species and seed; recompute the full current proposal and require equality. Preserve capacity/readiness/revision checks and deterministic population-order canonicalization. A fingerprint remains a correlation digest, never a secret or authority token. All inputs must be server-resolved. Native population reservation and commit must still be atomic, durable and replay-safe; this function creates no actor and consumes no token.

Meaningful regression evidence: two new tests produced **five failing subcases before the fix**. Five added methods now cover those cases, changed host registry/seed/candidates, missing trusted inputs and population-order compatibility. Local Python **3.12.14**, Linux, standard-library unittest:
- encounter/field/matrix suite: **70 methods passed**, normal execution;
- same suite under `python3 -O`: **70 passed**;
- existing battle suite: **24 passed**.

Commands: `python3 -m unittest discover -s 09_Technical/Reference/Encounters`; same with `-O`; `python3 -m unittest discover -s 09_Technical/Reference/BattleModes`. All exited 0. Reviewer: Codex, 2026-10-18. Tool-session outputs retained the pre-fix failures and post-fix summaries; hosted CI must retain exact-commit logs after publication.

Artifact scope is source/reference, not a game binary:
- corrected encounter source SHA256: `833249881a947d0a643e0f8fabb42c86905027d0869ebf1fb5c232dbd16d9887`;
- encounter tests SHA256: `fcf0563b5c14d7db44ce32765fab47d5befc42d5dab8714a5577a47f326b94ea`;
- extended scene SHA256: `88a011bac6217449680a77641da5f259e4df56e7f4da0f47c0c1b9faacf0c593`.

UHT/UBT, editor/PIE, cook/package/launch, real network authority/relevancy/reconnect, save migration/rollback, hardware performance and asset validation remain **NOT YET VERIFIED**. The reported two Corruption fixes and eighteen implemented systems remain user-reported; the twenty workstreams are designs, not proven runtime coverage. No new runtime API macro or Build.cs dependency is invented. GC/lifetime, threading, Enhanced Input, native AI, World Partition, shaders/PSO, accessibility and platform gates require the actual owner sources and execution environment.

## Game-creation deliverable

Extended [the existing first encounter slice](../05_Levels/FIRST_PLAYABLE_ENCOUNTER_KINDLING_SLICE_2026-10-17.md#storm-at-the-invitation--scene-extension-2026-10-18) with **Storm at the invitation**: six original presentation/dialogue beats, refusal and Defer handling, caption/mute parity, Training HUD fields, streaming/save/two-player acceptance and requested animation/cue content. No asset, placed map or playable mission is claimed.

Transferable progression principle: an environmental escalation tests demonstrated care, then gives a visible restored channel and later eligible invitation. No borrowed boss/biome/item identity or protected story expression. Numeric fixture limits remain technical bounds, not game balance.

## Story Continuity Status Brief

Observe → Protect → Calm → Kindle → Bond / Release / Defer remains the ethical loop. Weather withdrawal never becomes forced consent. Restoration persists even when a ceremony ends safely. A safe-handling lesson may resolve by Release/Defer; **Training Stage 04 completion still requires a genuine first bond** and cannot grant companion commands early. This resolves a potential ambiguity in the lesson without adding a progression meter.

Training, Tamer of Beasts, Kindling, individual development, Circle Balance and territory progression stay distinct. The scene uses existing D.A.H.L.I.A./mentor roles, with no new character, chapter, origin rewrite or ending unlock. The existing hip Eco-Device/eight carried links/one-active campaign contract is retained as routed; conflicting older title/device text needs owner review rather than automatic global replacement. Four public attributes, nine Essences, 125-ID Dex and historical archive authority remain unchanged. Restoration Crucible remains PROPOSAL and never authorizes casual dissolution of living partners.

## Cartography Status

No region, coordinate, species location or hidden-route lock added. This is an attachment to the existing Field Academy/First Kindling habitat pocket, with approach, shelter and escape connections only. Actual navmesh, collision, cell lifecycle, World Partition/Data Layers and placement must be checked in BUILD. Whispering Glade/Breezy Plains onboarding, existing stencils, Valley of Ruins coordinate registry, pillars and Oasis Sanctuary Gate remain untouched.

## PR #20 delta gate

Head remains `32c7e6df6201f25e96464576ae83ecca0981b609`; open, nondraft, mergeable; zero reviews and the same single comment last updated 2026-10-06. No observed material review/head/comment/mergeability delta from the previous record. These remain repository-checkable contracts only. The authoritative [18-step production order](../11_Publication/PUBLIC_VERIFICATION_STATUS.md) remains controlling, with real foundation and Issue #10 first. No platform, EPUB, accessibility, storefront or cross-play execution outcome is VERIFIED. Windows first; other exact targets remain planned until their own evidence.

## Research / provenance — checked 2026-10-18

- [Epic UE RPC documentation](https://dev.epicgames.com/documentation/en-us/unreal-engine/remote-procedure-calls-in-unreal-engine): owning connection determines RPC routing; validation failure disconnects. Adaptation: host-only trusted inputs; ordinary stale/unsafe spawn denial must not be a disconnect path. Documentation consultation only, no Epic source copied; actual installed 5.8 headers/native behavior still require verification.
- [Epic announcements](https://forums.unrealengine.com/c/general/announcements/49) and [5.8.3 hotfix, published 2026-09-22](https://forums.unrealengine.com/t/5-8-3-hotfix-released/2833315): no new materially actionable engine development identified against the previous successful watch. Announcement activity includes Fab access on October 18; no project engine change follows. Release-notes URL timed out, so exhaustive release-note/API diff coverage is unavailable. No version bump or repository modification was made solely from monitoring.
- [EcoKin-patch PR #2](https://github.com/Dlomotion/EcoKin-patch/pull/2): project repair/public reference, not independent native implementation evidence. Inspected and executed in its original scope; no source transplanted, license grant assumed, or third-party protected code copied.
- Today's reference correction and scene writing are original project work. No new dependency or borrowed implementation requiring license clearance.

## Next exact action

Recheck PR #71 hosted reference CI at the correction commit and retain its job logs. Then obtain readable BUILD owner sources and the actual supported Windows UE5.8 toolchain logs; reproduce the claimed Corruption fixes, validate descriptor/targets/module macro/Build.cs, and execute clean-clone/LFS → UHT/Development Editor → editor/PIE/package launch before Issue #10 and native encounter adapters. Native integration must audit existing spawn/relationship owners and implement one atomic reservation/revalidation transaction; do not install this Python oracle as a second runtime.


## Published correction receipt — 2026-10-18

Source correction commit: `26c52d1a3dd7729e0648f75f77221868f74a198c`, existing draft PR #71, seven intended text files. Exact remote readback matched all seven local reviewed files. Compare against parent `a0fe65f57970e683cb544cd1d2bceb6b2f714ade` showed only those seven files; no binaries or unrelated files changed.

Hosted evidence at that source commit: [PR run 39137552527](https://github.com/Dlomotion/Echohearts-Rebearth/actions/runs/39137552527), [push run 39137548830](https://github.com/Dlomotion/Echohearts-Rebearth/actions/runs/39137548830), both completed SUCCESS. [Job 117705056496 and its log view](https://github.com/Dlomotion/Echohearts-Rebearth/actions/runs/39137552527/job/117705056496) records successful normal encounter, optimized encounter and battle regression steps. Configuration: hosted Ubuntu 24.04, workflow-declared Python 3.12; exact hosted patch/tool metadata belongs to job logs. Result scope: offline source/reference checks only. Reviewer: Codex inspecting GitHub run/job metadata, 2026-10-18; source SHA256 values above identify the tested artifacts. No UE engine/toolchain, device or packaged artifact applies to these tests.

This receipt is a documentation-only follow-up; it does not change tested source or promote the later documentation commit to an independently executed Unreal build. **Next exact action:** obtain readable BUILD owner sources plus the real Windows UE5.8 installation/build logs, then reproduce the Corruption fixes and execute the foundation gate before native encounter integration.

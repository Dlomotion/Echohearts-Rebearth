# Echohearts continuation — 2026-10-19

**Status:** corrected offline engineering reference + PROPOSAL scene extension. Same draft PR #71 and source-of-truth routing; no parallel runtime or canon.

## REPOSITORY/BUILD STATUS

Canon main remains `85f653fb66295371bdce4edc73e71ab10725b96d`. PR #71 starts this pass at `4f0f72b22aa3fadb12ba93617792557723fa1c46`, open draft, mergeable, stacked on existing `feature/echo-duels-modes-servers-2026-10-17`. No base change, merge, force-push or history rewrite.

BUILD metadata again returns **404**. Current descriptor/Source tree, engine patch, API macro, Build.cs/targets and Corruption fixes cannot be inspected. This is an access observation, not proof of missing/deleted code or why the connection fails. The foundation/Windows gate remains the highest-priority native blocker; bounded reference corrections can continue without claiming native implementation.

Inspected pinned encounter/field/battle source/tests, workstream matrix, master index and existing first-playable scene. No AGENTS.md appeared in the complete recursive branch tree. No local git clone, LFS transfer/conversion, binary asset migration or engine execution occurred. Git working-tree/object/LFS health remains untested; the previous Build/ ignore correction remains in place. Existing ownership/one-editor-at-a-time binary workflow is still required before asset edits.

## Concrete engineering correction

The spawn digest used dataclass `repr()`, which gave different fingerprints for equivalent numeric or tag-set inputs. Reproduced **four failing subcases**: int zero versus float zero, int one versus float one, signed zero, and reordered/duplicate membership tags. Because the digest drives weighted selection and commit equality, this can alter reference species selection or deny an otherwise identical restored snapshot.

Replaced it with a domain-separated **v1 canonical ASCII JSON array**, explicit ordered fields, sorted/deduplicated membership tags, sorted population/species and big-endian IEEE binary64 hex for unit numbers. Normalize only int/float equivalents and zero signs; retain distinct valid adjacent binary64 values. Existing invalid-value, identity, duplicate-individual/species, host-input, capacity/revision and consent checks remain.

Compatibility: unversioned fingerprints change intentionally. Reject pending old proposals and regenerate from trusted current host data. No persistent proposal store/save migration exists in this oracle. A native adapter still requires actual owner numeric types and exact vectors on the supported Windows toolchain; Python determinism is not Unreal or cross-platform determinism evidence.

Six new regression methods cover numeric/tag equivalence, fixed seed-7/8 digests, adjacent-value distinction, equivalent commit validation and sixteen seeds with two weighted candidates. Final local Python 3.12.14/Linux results: **76 encounter/field/matrix methods passed normally, 76 under optimization, 24 battle methods passed**. Raw summaries/commands are retained in [local evidence](../09_Technical/Reference/Encounters/evidence/2026-10-19-local.txt). The README specifies the exact v1 preimage and compatibility boundary.

Source SHA256: `533df0f191c28f14dd3f8dea6a45d0b89d57e0e25cca62550828d2dfaf8beb90`.
Test SHA256: `b364cef7d885bebf234a88aa3d745f1d7545455f916759ea8729255afaff74c3`.
Scope: source/reference, no packaged artifact; reviewer Codex; date 2026-10-19. Hosted CI must be assessed at the published source commit and linked in the PR receipt.

Native UHT/UBT, GC/lifetime, threading, authority/RPC/replication/prediction/relevancy/late join, save atomicity/migration, World Partition, input/UI accessibility, GPU/CPU/PSO profiling, editor/PIE/cook/package/launch and target hardware remain **NOT YET VERIFIED**. No sockets, shaders, speculative UE helper or new module was installed. No client-supplied registry/seed/consent may become authority; hashing is not authentication or replay protection. Durable reservation/commit remains the existing host owner's responsibility.

## Concrete game-creation deliverable

Extended [the same encounter scene](../05_Levels/FIRST_PLAYABLE_ENCOUNTER_KINDLING_SLICE_2026-10-17.md) with **Quiet Return**: five original revisit/observation/choice/review beats, conditional mentor/D.A.H.L.I.A. lines, visual/caption/audio handoff and reload acceptance. The restored channel tells the environmental story, but restoration never purchases consent. No asset or map import is claimed. Reuse existing M16/M17 workstreams; no duplicate art pipeline.

## Story Continuity Status Brief

Restore-without-bond persists. Release/Defer resolves safe handling without falsely granting Stage 04 first-bond completion. A revisit requires fresh care/consent evidence; saved willingness is not ongoing agreement. Preserve Observe → Protect → Calm → Kindle → Bond / Release / Defer and existing Anima-Link, device, roster and progression owners. No new species/character/title/chapter/ending, public attribute or Essence was introduced; the 125-ID Dex and historical naming archive remain authoritative.

## Cartography Status

Same Field Academy/First Kindling habitat pocket, cleared channel, shelter and escape route only. No coordinate, hidden-cave route, POI, region or Viewpoint unlock promoted. Actual placement, collision/nav/streaming and world-state persistence await BUILD evidence.

## PR #20 and production order

Head remains `32c7e6df6201f25e96464576ae83ecca0981b609`, open/nondraft/mergeable; zero reviews; same one comment last updated 2026-10-06. No material head/review/comment/mergeability delta. Its platform/ebook documents remain repository contracts only. Preserve [PUBLIC_VERIFICATION_STATUS.md](../11_Publication/PUBLIC_VERIFICATION_STATUS.md)'s full 18-step order, real Windows UE5.8 foundation then Issue #10 before wider slices. No platform, EPUB/storefront/accessibility or cross-play verification follows from these tests.

## Research and license/provenance — checked 2026-10-19

- [Python 3.12 struct documentation](https://docs.python.org/3.12/library/struct.html): explicit endian/standard-size encoding and IEEE binary64 guidance. Adapted as an original project hash encoding; no documentation code copied, no dependency added. Does not establish an Unreal packet format.
- [Epic announcements](https://forums.unrealengine.com/c/general/announcements/49) and [official 5.8 release thread](https://forums.unrealengine.com/t/unreal-engine-5-8-released/2729274): no new materially actionable engine item identified since the previous watch. Visible release activity remains October 3; 5.8.3 hotfix September 22. This pass does not prove an exhaustive API/release-note diff. No monitored change triggered a project/engine update.
- No outside franchise content or third-party implementation was imported. New code, schema explanation and scene lines are original project work; all outputs remain reviewable in the existing PR.

## Next exact action

Retain exact-commit hosted reference CI evidence, then obtain readable BUILD owner sources and Windows UE5.8 installation/build logs. Reproduce the reported Corruption fixes; validate descriptor/targets/module macro/Build.cs and execute clean-clone/LFS → UHT/Development Editor → editor/PIE/package launch. Then Issue #10 and native encounter owner integration, including canonical-state vectors, safe spawn reservation, fresh consent and save/reconnect tests. Do not replace the native implementation with this Python reference.


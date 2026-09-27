# ECHOHEARTS: REBEARTH — FINAL CONSOLIDATION PR + IMPLEMENTATION MAP

**Date:** 2026-09-26  
**Purpose:** connect the current canon, chats/intake, open pull requests, issues, and UE5.8 evidence gates into one production order without merging incompatible work blindly.

## 1. Source order

When two sources conflict, use this priority:

1. `00_Canon_Lock` + approved Master Game Bible decisions.
2. `MASTER_PROJECT_INDEX.md` routing and current Story Continuity Spine.
3. Permanent Eco-Kin Dex / Forms Registry / Data Dictionary.
4. Newest approved production contract and issue acceptance criteria.
5. System/level/art/technical source files.
6. Open PR design/code branches.
7. Historical chat snippets, generated images, copied examples, external game references.

Lower sources cannot silently overwrite higher ones.

## 2. Current repository truth

Canonical repository: `Dlomotion/Echohearts-Rebearth`  
Default branch: `main`  
Engine target in production contracts: **Unreal Engine 5.8**.

`main` does not yet prove a complete canonical `.uproject` + `Source/` module tree and therefore does not prove the pasted UE gameplay systems as runtime-complete.

All claims requiring Unreal compilation, editor load, replication, animation, packaging, performance, save durability, World Partition, MassEntity, Chaos, or voxel destruction remain **NOT YET VERIFIED** until direct evidence exists.

## 3. PR dependency map

### PR #14 — Add secure Unreal Git LFS and CI synchronization baseline

**Disposition:** PRIMARY INFRASTRUCTURE CANDIDATE.  
**Action:** review/validate before relying on the branch for Unreal binary/source onboarding.

Required next evidence after merge candidate review:

- canonical `.uproject` + `Source/` module tree;
- fresh clone + `git lfs pull`;
- real LFS lock/unlock on a non-mergeable Unreal asset;
- trusted UE5.8 runner provisioning;
- UHT/compile/editor launch;
- Development cook/package;
- rollback/recovery proof.

PR #14 must not be treated as runtime verification by itself.

### PR #11 — Add UE5.8 Git/LFS repository safety baseline

**Disposition:** OVERLAPPED / SUPERSEDED BY #14 UNLESS A DIFF REVIEW PROVES UNIQUE REQUIRED CONTENT.  
**Action:** do not merge both blindly. Compare #11 against #14, retain any unique safe delta, then close or supersede #11 explicitly.

### PR #9 — Issue #8 server-authoritative tactical battle core

**Disposition:** DRAFT TECHNICAL CORE / SANCTIONED TACTICAL MODE ONLY.  
**Keep:** deterministic authority-domain ideas and standalone harness evidence.  
**Do not claim:** packaged UE5.8 online session, RPC/replication, reconnect, controller UI, latency, accessibility, hub return, or campaign-wide turn-based conversion.

Must remain separate from real-time main-campaign combat.

### PR #7 — Console online server turn-based Eco-Kin mode

**Disposition:** DESIGN SOURCE FOR SANCTIONED ONLINE/ARENA INSTANCES.  
**Correction:** it cannot convert the entire campaign to turn-based play. Its terminology must match current Essence/roster/canon before promotion.

### PR #6 — Eco-Kin / historical manuscript mission system

**Disposition:** DESIGN/STORY CANDIDATE.  
**Correction gate:** reconcile all manuscript naming against the current **War on Humanity**, Story Continuity Spine, current Essence taxonomy, region registry, and character registry before merge/publishing.

### PR #2 — Public Eco-Kin Data Grid / Bestiary

**Disposition:** CODED, NOT YET VERIFIED.  
**Blocking evidence:** install, typecheck, production build, browser behavior, responsive behavior, keyboard access, reduced-motion/accessibility checks, and truthfulness review.

Because its base branch is older/non-main, rebase or selectively port the validated web changes to the current integration base rather than merging stale canon with it.

### PR #1 — Bootstrap official workflow/canon structure

**Disposition:** HISTORIC BOOTSTRAP BRANCH, NOT A BLIND FINAL MERGE TARGET.  
Many later main-branch files already implement or supersede portions of its purpose. Audit remaining unique deltas, port only still-valid files, and avoid reintroducing retired terminology or older technical assumptions.

## 4. Issue dependency map

### Issue #13 — Secure Unreal Git LFS + CI synchronization pipeline

Infrastructure prerequisite. Resolve through PR #14 validation and the remaining actual project/LFS/runner/build evidence.

### Issue #12 — UE5.8 CI + main-branch protection activation gate

Do not make nonexistent/unreliable UE checks required. Activate stronger branch rules only after the real UE5.8 build check is stable.

### Issue #10 — Original NPC + Eco-Kin 3D body/animation vertical slice

**Immediate content/runtime target after the project foundation exists.**

Evidence target:

- one original humanoid NPC;
- one original Eco-Kin rig family/body;
- idle/locomotion/turn/contact;
- authored attack notify window;
- directional reactions;
- exact hit-location feedback;
- stagger/disable/death or recovery path;
- bond/care/ecology animation;
- Sequencer beat;
- controller + keyboard/mouse;
- network authority where state is shared;
- frame-time/animation-cost capture;
- packaged build;
- originality/provenance and accessibility review.

### Issue #8 — Console online tactical prototype

Secondary to the first real UE foundation and vertical-slice proof. Keep bounded to its own battle instance and verification checklist.

## 5. Final implementation order

### Gate A — Canon and data integrity

1. Merge/approve the final universe consolidation after review.
2. Keep 125 permanent EcoKinIDs frozen as roster authority.
3. Route all other names to Forms Registry or Historical Naming Pool.
4. Apply `Aurivelle Form` rename and retire Prismana/Prusmana labels in active metadata when source assets/records are actually available.
5. Reconcile current Essence + Geo/Echo tag model in the Data Dictionary before implementing damage code.

### Gate B — Repository foundation

1. Validate PR #14.
2. Resolve #11 overlap.
3. Establish actual UE5.8 `.uproject`, targets, plugins, module tree, and content root.
4. Prove clean clone/LFS/lock flow.
5. Build `EchoheartsEditor` and preserve raw UHT/UBT evidence.

### Gate C — First playable proof

1. Execute Issue #10 with one canonical NPC and one canonical Eco-Kin body.
2. Implement the smallest A.E.G.I.S./Kindling interaction required for the slice.
3. Prove one real-time encounter with authoritative damage result + exact impact data.
4. Prove one persistent restoration result.
5. Package and launch Development build.

### Gate D — Funding vertical slice

Target a **15–30 minute** polished slice using approximately **4–6 production-quality Eco-Kin**, not the whole 125 at once.

Required experience:

- one polished region;
- one compact story/quest chain;
- exploration/traversal;
- A.E.G.I.S. observation + interaction;
- Kindling/care decision;
- real-time combat;
- one growth/adaptation moment;
- restoration before/after state;
- basic inventory/save/UI;
- music/SFX;
- one cinematic beat;
- accessible controller + keyboard/mouse play.

### Gate E — Tactical/online expansion

After core real-time proof:

1. re-evaluate PR #7/#9 against final data and UE networking;
2. implement Issue #8 in a bounded Arena instance;
3. validate reconnect/latency/result authority/cross-mode return;
4. only then expand online scope.

### Gate F — Large-world R&D

MassEntity crowds, deep destructible terrain, nested-city streaming, high-density AI, large boss segmentation, multi-region orbital events, and advanced automated Sanctuary operations enter profiling/R&D only after the core game is stable.

## 6. Technical snippets: final status

The following reposted code families are **not shipping code** until rewritten inside the actual UE5.8 module and tested:

- `AERMonsterBase` / old monster-state ownership model;
- direct `APlayerController::Possess` somatic-transference of Eco-Kin;
- custom movement smoothing that trusts client-submitted positions;
- manually pooled audio components without a proven lifecycle/world-registration design;
- raw radial harvesting that destroys actors and bypasses inventory transactions;
- generic cross-breeding/mutation code that ignores species/canon rules;
- placeholder voxel APIs and whole-world persistence assumptions;
- 50-segment boss prototypes without network/physics/performance proof;
- `.cpp` self-includes or placeholder null VFX calls;
- configuration values presented as universal shipping optimizations without profiling.

Rewrite criteria:

- current Echohearts naming/data;
- server authority and exploit resistance;
- ownership/lifecycle safety;
- rollback/persistence semantics;
- profiler evidence;
- automated tests where practical;
- packaged runtime evidence.

## 7. Copyright/originality intake

Directly named Terraria/Digimon/Nexomon/Pokémon/Aniimo/Roots material stays outside active canon and production code. Any transferable lesson must be expressed through original Echohearts systems, encounters, names, art, dialogue, progression, and implementation.

## 8. Final game-creation statement

The project is no longer organized as disconnected chat inventions. Every future addition must route through:

`INTAKE → CONTINUITY → ORIGINALITY/IP → CANON/DATA STATUS → IMPLEMENTATION OWNER → EVIDENCE → PROMOTION`

The final game is built outward from the smallest proven experience, while the complete 125-ID universe, forms archive, historical pool, DLC/cosmic material, and long-term systems remain connected but gated.

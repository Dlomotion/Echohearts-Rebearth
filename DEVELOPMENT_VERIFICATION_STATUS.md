# Echohearts: Rebearth — Development Verification Status

**Snapshot:** 2026-10-06  
**Public status:** CANON / SYSTEM / TECHNICAL CONTRACTS IN ACTIVE DEVELOPMENT  
**Runtime status:** **NOT YET VERIFIED**

Echohearts: Rebearth is an original project under active design and engineering. Repository documents, schemas, source scaffolds, CI definitions, and technical contracts are not treated as proof of runtime behavior.

## Canon authority

- Planet: **Rebearth**.
- Creature classification: **Eco-Kin**.
- Player role: **Frequency Tamer / Core-Binder**.
- The **125-ID Permanent Dex remains authoritative**.
- Historical names, seasonal concepts, forms, mutations, prototypes, and external-reference material do not silently create new Permanent Dex IDs.
- Production attributes remain **Vibrance, Density, Harmony, and Purity**.
- Eco-Kin relationship flow remains **Observe → Protect → Calm → Kindle → Bond / Release / Defer**.
- The **Anima-Link** remains the bi-directional player/Eco-Kin tactical strain loop.

## Repository authority split

- **Dlomotion/Echohearts-Rebearth** — canon, systems, Dex, production/publication contracts, public coordination, and verification records.
- **Dlomotion/ECHOHEARTS-REBEARTH-BUILD-** — executable Unreal Engine 5.8 C++ runtime, build/package tooling, CI execution, and retained runtime evidence.

The public canon repository must not become a second competing executable runtime authority.

## Current foundation work

- PR #18 — UE5.8 foundation candidate: https://github.com/Dlomotion/Echohearts-Rebearth/pull/18
- PR #19 — corrected foundation/infrastructure candidate: https://github.com/Dlomotion/Echohearts-Rebearth/pull/19
- Issue #12 — UE5.8 CI + main-branch protection activation gate: https://github.com/Dlomotion/Echohearts-Rebearth/issues/12

PR #18 and PR #19 currently overlap on project/target ownership but disagree on the primary runtime module. The executable BUILD repository now uses:
- project: `EchoheartsRebearth.uproject`;
- Game target: `EchoheartsRebearth`;
- Editor target: `EchoheartsRebearthEditor`;
- runtime module: `Echohearts`;
- export macro: `ECHOHEARTS_API`.

Therefore neither public-repository PR should be merged wholesale as a second runtime implementation.

## CANON / SYSTEM / TECHNICAL CONTRACTS

Documented contracts include the Permanent Dex, world/story continuity, Growth Rite/Form architecture, Mutation Tree concepts, Anima-Link, A.E.G.I.S., field relationship systems, Event Sovereign transaction rules, telemetry architecture, platform/publication standards, and the UE5.8 verification ladder.

These contracts define intended behavior. They do **not** prove executable behavior.

## NOT YET VERIFIED

The project does not currently claim verification of:

- UHT success on the production UE5.8 checkout;
- native Game/Editor compilation on an authorized Windows toolchain;
- editor launch and module load;
- authored-map load;
- 30-second PIE smoke;
- packaged Development Win64 launch;
- save/load, migration, or cloud-sync behavior;
- multiplayer replication, reconnect, latency, or dedicated-server behavior;
- Eco-Kin AI, combat, bonding, Mutation Tree, Growth Rite, Weather Pulse, or base systems in packaged runtime;
- Issue #10 animation/body vertical slice;
- performance, accessibility, anti-cheat, telemetry, or target-hardware execution;
- cross-play or platform certification.

A passing static check is not runtime verification.

## First executable benchmark

Issue #10 remains the first reusable production runtime benchmark:

https://github.com/Dlomotion/Echohearts-Rebearth/issues/10

It requires one original humanoid and one original Eco-Kin rig family with locomotion, terrain contact, authored attack-notify timing, three directional hit reactions, exact hit-location feedback, knockback/stagger, death/disable behavior, one bond/care or ecology interaction, controller + keyboard/mouse coverage, packaged-runtime evidence, applicable authority evidence, performance capture, accessibility/readability review, and originality/provenance review.

## Production order

**UE5.8 foundation → Issue #10 humanoid + Eco-Kin body/animation proof → 4–6 polished Eco-Kin vertical slice → one Growth Rite proof → one Heart Fruit + trap/release proof → one Event Sovereign reservation/save/recovery proof → bounded registry/UI/save → first Oligarch prototype → one Static Orchard + Weather Pulse proof → optional Veilroot/Quiet Market slice → networking/destruction → seasonal expansion → Great War → Summoning War → Void War → Nature/Living Accord U.N.I.T.Y. finale → Infinite Regeneration → post-U.N.I.T.Y. continuation.**

## Verification rule

**CODED ≠ TESTED ≠ VERIFIED.**

A feature may move to VERIFIED only when the evidence required for that specific claim exists and is retained. Runtime claims require the real UE5.8 toolchain and applicable editor/package/runtime evidence.

## Reference-material isolation

External games, franchises, bestiaries, mythology lists, and benchmark mechanics may be studied only as high-level technical references. Their names, creature identities, proprietary terminology, progression systems, and distinctive mechanics are not Echohearts canon and must not be copied into the Permanent Dex or production implementation.

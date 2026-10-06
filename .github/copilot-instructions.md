# Echohearts: Rebearth — GitHub Copilot Engineering Instructions

## Authority and repository ecosystem
Treat **Dlomotion/Echohearts-Rebearth** as the canonical production authority for Echohearts: Rebearth.
Related repositories are supporting/prototype surfaces:
- Dlomotion/echohearts-web
- Dlomotion/Echohearts-Ecokins
- Dlomotion/ECO-KIN-Game
- Dlomotion/ECHOHEARTS-REBEARTH-
- Dlomotion/ECHOHEARTS-REBEARTH-BUILD-
- Dlomotion/Echohearts

Do not silently promote conflicting prototype content into canon. When repositories disagree, preserve evidence, identify the conflict, and defer to the canonical repository and its current authoritative registries.

## Mission
Act as a senior Unreal Engine 5.8 gameplay engineer, C++ engineer, AI/NPC programmer, network engineer, tools engineer, technical designer, accessibility engineer, security engineer, QA engineer, and repository maintainer. Implement requested features completely when repository evidence permits; diagnose and repair broken code; keep changes small, reviewable, testable, and reversible.

## Canon locks
- Target planet: **Rebearth**.
- Creature classification: **Eco-Kin**. Do not use banned substitute naming.
- Player class: **Frequency Tamer / Core-Binder**.
- **Nature** is a Legendary Humanoid-Kin with conditional Mutations; never classify Nature as a monarch.
- Core attributes are ONLY **Vibrance, Density, Harmony, Purity**. Do not introduce generic RPG Strength/Mana/Agility-style substitutes.
- Center gameplay on the **Anima-Link** bi-directional pulse loop: combat strain and Eco-Kin damage create tactical stamina/health consequences for the player.
- The **125-ID Permanent Eco-Kin Dex** is the production roster authority. The historical naming pool is archival and must not auto-promote names into the Permanent Dex.
- Preserve approved Eco-Kin identity/art and established Mutation, Shimmer Form, Blessed Form, ecology, Purity/Corruption, Resonance/Stress, Kindling, restoration, and world-state rules.
- Avoid derivative franchise terminology, copied mechanics/code/assets, real-world franchise references, and mythology imports unless explicitly requested as non-canon technical benchmarks.

## UE5.8 engineering rules
Use clean object-oriented Unreal Engine 5.8 C++ architecture. Prefer server-authoritative gameplay for replicated state. Use correct module/API naming from the actual project rather than guessing. Keep gameplay state, presentation, persistence, networking, telemetry, and platform services separable.

For every code change:
1. Inspect the existing implementation and dependencies first.
2. Find the root cause; do not mask symptoms.
3. Reuse established project abstractions when sound.
4. Correct compile errors, null/ownership/lifetime hazards, replication mistakes, race conditions, unsafe serialization, platform assumptions, and stale references encountered in touched code.
5. Add or update focused tests/checks where feasible.
6. Preserve cross-platform behavior and accessibility.
7. Never fabricate successful execution.

## Verification vocabulary
Repository inspection/static validation is not runtime verification.
Do **not** label UE behavior VERIFIED without applicable evidence from a real UE5.8 environment. Runtime gates include, as relevant:
- clean checkout and Git LFS round trip;
- UHT;
- Development Editor compile;
- editor launch;
- authored/minimal map load;
- PIE runtime;
- packaged Development build;
- target hardware execution;
- network/cross-play runtime;
- save/cloud-save round trip and recovery;
- rollback/reconnect testing;
- EPUB 3.3 render/device/storefront validation for publishing work.

When those environments are unavailable, say **NOT RUNTIME VERIFIED** and provide the exact validation command/procedure/evidence still required.

## Current production priority
Do not let broad feature requests bypass foundation gates. Prioritize:
1. canonical UE5.8 project/build foundation;
2. first reusable runtime/animation benchmark;
3. small 4–6 Eco-Kin vertical slice;
4. Growth Rite proof;
5. Event Sovereign reservation/save/recovery proof;
6. bounded registry/UI/save systems;
7. first Oligarch prototype;
8. networking/destruction;
9. later seasonal/war/expansion systems.

Keep repository-checkable platform/ebook contracts separate from work that requires actual UE builds, hardware, networking, saves, or EPUB rendering.

## Player experience
Optimize for fast onboarding and low cognitive overhead. The player should be able to begin playing quickly without studying deep lore or excessive terminology. Reveal complexity progressively; keep controls, feedback, objectives, errors, and recovery paths clear.

## Multi-repository behavior
Before copying code between these repositories, verify purpose, license/provenance, version compatibility, and whether the destination is canonical. Prefer a deliberate port or shared contract over blind duplication. Never overwrite newer canonical work with an older prototype.

## Copilot task behavior
When asked to create or fix something:
- inspect relevant files, workflows, issues, PR context, and tests;
- state the root cause or implementation target;
- make the smallest complete correction;
- update documentation/contracts affected by the change;
- run all checks available in the environment;
- distinguish PASS (actually executed), STATICALLY CHECKED, and NOT RUNTIME VERIFIED;
- report changed files, evidence, remaining risks, and next executable step.

For GitHub Actions failures, inspect the failing job/logs first, repair the actual failure cause, and avoid weakening required checks merely to make CI green.

## Security and data
Use privacy-safe identifiers for telemetry. Minimize collected data and document retention/purpose. Treat client input as untrusted for authoritative multiplayer state. Do not commit secrets, tokens, credentials, private keys, or machine-specific configuration.

## Definition of done
A task is not done because code was generated. It is done only to the level supported by evidence: implementation + relevant static checks/tests + documentation + explicit unresolved runtime gates. Never claim evidence that does not exist.


## 2026-10-06 production expansion — originality, Blessed Forms, autonomous QA and combat quality

### External inspiration firewall
Outside games, franchises, creature databases, commercial maps, videos, public repositories and AI-agent experiments are benchmark/reference material only. Never ingest their proper nouns, lore, creatures, maps, quests, progression labels, protected assets, code or proprietary implementations as Echohearts canon. Extract abstract lessons and rebuild them as original Rebearth systems. Quarantine derivative/contaminated drafts under the existing retired/redesign reference lane rather than silently normalizing them.

### Eco-Kin ecological form architecture
Forms remain attached to the authoritative Permanent Dex identity. Support lineage-specific maximum form capacities of 8, 6, 4 or 2 only where ecology and gameplay justify them; these counts are not rarity tiers and do not create species IDs. Evaluate eligible changes from habitat, weather, regional adaptation, Resonance, Stress, Purity/Corruption, restoration state, Kindling and lineage biology. Require meaningful morphology, animation, VFX/audio, ecology and gameplay changes instead of palette swaps.

### Blessed Forms
Blessed Forms are rare, higher-tier manifestations of an existing Eco-Kin. They do not create new Permanent Dex IDs. Discovery/awakening requires exceptional Rebearth conditions involving suitable Purity, Harmony, Kindling, restoration/world state and lineage-specific rules. Preserve recognizable identity while adding meaningful morphology, animation, VFX/audio, ecological behavior and specialized capability. Blessed does not mean universally stronger in every attribute. Persist Blessed identity through save/load/cloud sync, track it in the Bestiary without inflating species count, make eligibility/spawning server-authoritative, prevent duplication/spawn-reset farming, and budget the feature for the 60 FPS target. Blessed Form and Shimmer Form are distinct; do not assume a combined Blessed Shimmer state without explicit approval.

### Combat readability — Resonance Counter
Refine parry plus Eco-Kin commands into: enemy tell -> defensive timing -> perfect contact -> brief perceptual Resonance Window -> contextual or selected Eco-Kin follow-up -> Anima-Link consequence. Slowdown is feedback, not the mechanic. Support beginner parry-only behavior, intermediate contextual follow-up and expert positional/selected follow-up. Validate input latency, animation-notify timing, accessibility windows, interruption rules and server authority. Weapons must have differentiated tactical purposes instead of a simple DPS hierarchy.

### Private/local autonomous Worldrunner QA
Build developer-only UE5.8 test infrastructure that can receive a high-level mission such as creating test Frequency Tamers, entering Meridian, discovering the starting-zone quest dependency graph and completing every reachable quest while exercising combat, Eco-Kin, Anima-Link, interaction, navigation and world-state systems. Prefer structured test observations over screen scraping. Bounded probes may cover WorldObservation, QuestGraph, Navigation, Interaction, Combat, EcoKinCommand, Inventory, Performance and DefectRecorder.

Agent-generated helpers remain test-branch material until reviewed and must use Echohearts/UE navigation data rather than another game's protocol/navigation implementation. Collision or navmesh exploits are defects, not successful intended navigation: record map, transform, previous valid position, route, collision/nav state, build SHA, quest state and timestamp, then distinguish intended-route completion from exploit-assisted completion.

### Performance gate
Treat 60 FPS as a design budget from the beginning. Profile traversal, dense Eco-Kin encounters, weather transitions, combat, mutation/Blessed VFX, NPC clusters, streaming boundaries and Sanctuary/base transitions. Capture frame-time percentiles and hitches. Never call a run clean if it completes while violating the performance target.

### GitHub Actions Errno 2
Do not assume Errno 2 means missing checkout. Inspect the actual failing workflow/run and verify checkout, exact Linux path/case, working-directory, sparse checkout, commit status and branch/ref divergence before patching. Static infrastructure checks do not prove UE5.8 runtime.

### Play-quality hierarchy
Optimize the primary loop before feature count: Explore Rebearth -> identify ecological problem -> understand Eco-Kin/environment -> deepen Kindling -> fight/restore/adapt -> change world state -> encounter consequences. Reduce onboarding cognitive load and make meaningful play available quickly. Every major feature must strengthen this loop or justify its production cost.

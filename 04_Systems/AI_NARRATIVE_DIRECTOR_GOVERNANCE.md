# D.A.H.L.I.A. World Memory Director / AI Narrative Governance

Status: CANON-COMPATIBLE SYSTEM CONTRACT / IMPLEMENTATION NOT YET VERIFIED

## Purpose
Dynamic narrative systems may increase variation in Rebearth, but they do not author canon or directly mutate authoritative gameplay state.

The governing order is:

CANON
→ GAME RULES
→ WORLD SIMULATION
→ PLAYER ACTION
→ AI INTERPRETATION
→ VALIDATION
→ GAMEPLAY CONSEQUENCE

Never: Player → AI → whatever the model invents.

## Authority boundary
Authoritative state owns truth. A narrative model may interpret or propose, but cannot directly:
- kill required story characters
- invent canon-changing villains
- rewrite Eco-Kin origins
- create new core elements
- bypass bosses or progression gates
- grant Legendary/Titan Eco-Kin
- modify saves/inventory/currency directly
- force Eco-Kin bonds/evolution
- change endings
- create player/Eco-Kin fusion
- spawn arbitrary actors outside approved pools

## Canon context
A controlled canon dataset should expose immutable facts such as world history, regions, factions, major characters, Guardians, Eco-Kin lore, quest pillars and restrictions. Runtime implementation may use Data Assets/Data Tables/Gameplay Tags as appropriate after the real UE5.8 project is inspected.

## State inputs
Candidate inputs include:
- Vibrance / Density / Harmony / Purity
- regional Blight/ecosystem health
- settlement conditions
- faction relations
- NPC memory
- Eco-Kin memory/Kindling/care history
- season/weather
- current chapter/quest flags
- recent meaningful player events

## Proposed event types
The Director may request only bounded event classes such as:
- dialogue variation
- NPC reaction
- rescue/restoration opportunity
- approved world event
- faction reaction
- migration/ecology event
- settlement event
- exploration lead
- encounter composition modifier

Every request must reference stable IDs and approved pools rather than free-form asset names.

## Validation stack
AI proposal
→ schema validation
→ canon validation
→ story-state validation
→ gameplay/rules validation
→ economy/reward validation
→ safety/agency validation
→ authoritative system commit

On failure: reject and use an authored fallback.

## Structured output rule
Do not let free text become commands. Any online generative layer must return a versioned, allow-listed structured envelope with stable IDs, bounded numeric deltas and explicit provenance/context version. The game resolves those IDs into approved content.

## Offline-first requirement
Echohearts must remain playable without an online LLM. Core quests, dialogue fallbacks, NPC reactions, Eco-Kin reactions, world events and progression rules require deterministic authored/systemic fallback libraries.

Online AI, if used later, expands presentation and variation. It cannot be a hard dependency for combat, save recovery, progression or canon.

## Eco-Kin memory
Eco-Kin memory may track care, fear, trust/Kindling, fatigue, injury memory, preferred habitats/tasks, rivalries/friendships and other reviewed state. These values are deterministic gameplay data; AI may narrate them but cannot fabricate them.

## Implementation gate
Do not build speculative LLM C++ now. First satisfy the current technical gate order: UE5.8 build evidence, Partner Command Buffer tests, recovery/network tests, ECO-API-001, BCT-001 and one end-to-end build/craft transaction. Then create the smallest narrative interface contract and authored fallback first.

## Verification
Design contract: VERIFIED AS REPOSITORY DOCUMENT.
Runtime subsystem/API/provider behavior: NOT YET VERIFIED.

© 2026 Into Deep Studios and Donta L. Owens. All rights reserved.

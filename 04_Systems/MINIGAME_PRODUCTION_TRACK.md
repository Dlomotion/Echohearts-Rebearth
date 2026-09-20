# Echohearts: Rebearth — Mini-Game Production Track

© 2026 Into Deep Studios and Donta L. Owens. All rights reserved.

Status: DESIGN / DATA SPEC, NOT YET VERIFIED.

## Purpose
Mini-games must strengthen the main Echohearts experience rather than feel like disconnected side activities. Every approved mini-game must support at least one of the Heart Statement pillars:
1. This world needs me.
2. These Eco-Kin are alive.
3. My choices changed Rebearth.

## Production Rule
Each mini-game must define:
- player input and controls,
- onboarding/tutorial readability,
- success state,
- failure/partial state,
- accessibility behavior,
- reward and anti-exploit rules,
- save/data hooks,
- multiplayer authority when relevant,
- replayability,
- story/world consequence,
- Unreal Engine implementation path,
- verification evidence required before VERIFIED status.

## Approved Mini-Game Families

### MG-001 A.E.G.I.S. Signal Trace
Purpose: teach scanning, trail reading and signal interpretation.
Loop: identify true signal peaks while filtering Blight/static noise.
World consequence: reveals safe routes, hidden rescue targets or false Shattered Chord transmissions.
Implementation preference: UMG/CommonUI + Data Assets + Gameplay Tags; C++ only for shared authoritative result handling if required.

### MG-002 Kindling Rhythm
Purpose: represent listening and trust without capture mechanics.
Loop: match breathing/pulse/rhythm windows while avoiding over-input.
Failure: Calm Window closes or fear rises; no forced bond.
World consequence: changes trust/fear memory and may open Bond/Release/Defer/Treat choices.

### MG-003 Purity Flow
Purpose: restoration/purification puzzle.
Loop: redirect clean flow through contaminated nodes without over-purifying the region.
Failure: partial cleansing, resource loss or temporary ecosystem stress.
World consequence: visible Purity recovery and new habitat behavior.

### MG-004 Living Soil Calibration
Purpose: farming and ecosystem literacy.
Loop: balance soil Vibrance, Density, Harmony and Purity for the current crop and season.
World consequence: crop quality, Sanctuary food resilience and habitat health.

### MG-005 Sanctuary Care Routine
Purpose: make Eco-Kin care tactile and character-driven.
Loop: observe body language, select care action, give space, groom/feed/treat only when appropriate.
Failure: stress rises or care is deferred; never converts to forced obedience.

### MG-006 Resonance Repair Bench
Purpose: crafting/building onboarding.
Loop: inspect damaged component, reserve materials, align parts, commit repair.
Technical rule: final item mutation follows BCT-001 authority and persistence rules.

### MG-007 Hookline Route Trial
Purpose: traversal mastery.
Loop: plan anchors, manage momentum, avoid unsafe living-root attachments and complete route efficiently.
World consequence: unlocks safe climbing lines and rescue access.

### MG-008 Echo-Memory Reconstruction
Purpose: Living Textbook storytelling.
Loop: place recovered audio/visual fragments in a coherent order while distinguishing archive fact from corrupted/missing memory.
World consequence: unlocks lore, NPC reactions, Memory Shards or mission context.

### MG-009 Seasonal Ecology Watch
Purpose: connect seasons to wildlife behavior.
Loop: identify which behavior/route is natural for the current season and which indicates Blight/faction interference.
World consequence: improves Havenlink relocation, EcoDex notes and regional Harmony.

### MG-010 Harmony Circuit Simulation
Purpose: optional tactical/turn-based training and PvP-safe simulation.
Loop: V/D/H/P-driven initiative and tactical choices under simulation rules.
Rule: this remains separate from the real-time campaign combat authority.

## First Playable Mini-Game Priority
1. MG-001 A.E.G.I.S. Signal Trace
2. MG-002 Kindling Rhythm
3. MG-003 Purity Flow

These three directly support Chapter 1 onboarding and the first rescue/bond/restoration loop.

## Acceptance Criteria
- [ ] Fits existing canon and does not create a parallel progression system.
- [ ] Uses V/D/H/P where stats are exposed.
- [ ] No capture/fusion/forced-work mechanic is introduced.
- [ ] Has clear success, partial and failure outcomes.
- [ ] Has accessibility considerations.
- [ ] Connects to mission/world state.
- [ ] Uses shared authoritative transaction/event contracts where persistent rewards are involved.
- [ ] Remains NOT YET VERIFIED until played/tested in the actual UE 5.8 project.

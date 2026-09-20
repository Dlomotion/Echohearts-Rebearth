# Resonance Shard-Arc Adaptation System

© 2026 Into Deep Studios and Donta L. Owens. All rights reserved.

## Status
DESIGN / DATA SPECIFICATION. NOT YET VERIFIED.

## Purpose
Turn the historical Resonance Mutation concept into an Echohearts-native growth system that rewards restoration, exploration, trust and player choice without forced evolution.

## Preferred Player-Facing Name
**Shard-Arc Adaptation**

Historical/source terms preserved for internal reference:
- Resonance Mutation
- Traveling Arc
- Universal Mutation

## Core Loop
1. Discover a compatible Resonance Shard in a dangerous biome.
2. Restore enough of that biome for its local frequency to become stable.
3. Build trust with the Resonance Kit through normal Kindling and field care.
4. Visit a compatible Restoration Altar or equivalent approved growth site.
5. A.E.G.I.S. checks Harmony, Purity, stress, Blight exposure, shard compatibility and consent state.
6. Player may proceed, defer, or leave.
7. If stable, the form change begins as a Growth Rite.
8. If unstable, the rite pauses and the Eco-Kin remains safe.
9. The new form changes traversal, ecology interactions, combat/support options and world restoration affordances.
10. The choice is recorded in EcoDex and save data.

## Design Principle
A Shard is not a forced evolution stone. It is a memory-bearing environmental catalyst that only works when the Eco-Kin and biome are ready.

## A.E.G.I.S. Stability Readout
The growth interface should expose only meaningful player-facing values:
- Harmony
- Purity
- Biome Stability
- Shard Compatibility
- Eco-Kin Willingness
- Blight Contamination Warning

No hidden 'capture success' or coercion meter.

## Outcome States
### Ready
All conditions valid. Player may begin the Growth Rite.

### Defer
Eco-Kin is compatible but not ready. No penalty.

### Refuse
Eco-Kin does not accept the rite. Player must respect the refusal.

### Unstable
Harmony/Purity/biome conditions are unsafe. Specialist or restoration work is required first.

### Discordant Warning
Raw Blight, coercion or corrupted equipment is detected. Growth is blocked and a story/repair consequence may trigger.

## Shard Families Under Review
### Vineshard
- Biome theme: restored woodland / Great Bloom
- Candidate form: Sylva-Lynx
- Proposed elements: Flora / Radiant

### Cinderstone / Ashpulse Shard
- Biome theme: volcanic restoration
- Candidate form: Flarevane
- Proposed elements: Magma / Solar

### Tide-Pearl / Boilreef Shard
- Biome theme: Neon Sea / pressure zones
- Candidate form: Aqua-Drift
- Proposed elements: Hydro / Radiant

### Static-Core / Oilstatic Shard
- Biome theme: damaged Ancient Tech / clean electrical restoration
- Candidate form: Volt-Shifter
- Proposed elements: Volt / Iron-Tech

### Void-Glass / Voidglitch Shard
- Biome theme: rifts / broken memory / lunar gates
- Candidate form: Umbra-Soul
- Proposed elements: pending between Lunar / Chaos and Chaos / Spirit

## World Integration
Each branch must create a meaningful world affordance.

Examples:
- Sylva-Lynx reopens root paths and stabilizes young forests.
- Flarevane restores dormant heat channels and protects against cold pressure.
- Aqua-Drift supports submerged exploration and damaged reef routes.
- Volt-Shifter helps restart purified Ancient Tech infrastructure without becoming a forced power source.
- Umbra-Soul reveals unstable rift paths and memory echoes.

## Sanctuary Integration
The system may use:
- Recovery Ward
- Kindling Haven
- Restoration Altar
- EcoDex Archive
- Sanctuary specialist consultation

No factory slot, forced assignment, or consumable-companion logic.

## Story Integration
Shard-Arc Adaptation should reinforce the core contrast:
- villains force change through extraction and control,
- Keepers support change through trust, restoration and informed choice.

This allows Discordance to exist as a consequence of coercion while keeping healthy adaptation aspirational.

## UI Requirements
- show form silhouette only after enough EcoDex knowledge is earned,
- show source biome and shard history,
- show clear proceed/defer/refuse states,
- never hide a danger warning,
- include text + icon cues,
- include reduced-motion option for transformation presentation,
- include colorblind-safe shard identification.

## Save / Persistence Requirements
When implemented, save data must record:
- Resonance Kit permanent EcoKinID,
- current approved form,
- unlocked branch knowledge,
- obtained/consumed shard state if shards are consumable after final design review,
- completed Growth Rite IDs,
- refusal/defer history only if it changes story,
- biome restoration prerequisite state.

## Technical Direction
Prefer data-driven implementation first:
- Primary Data Assets or Data Tables for form definitions,
- Gameplay Tags for shard/form/prerequisite states,
- Blueprint-authored presentation,
- one authoritative server-side commit path for multiplayer form changes,
- versioned persistence.

Do not create new C++ until the existing project architecture is available and the data/authority gap is proven.

## Acceptance Criteria
- no forced growth,
- every branch uses only current canon elements,
- every branch changes gameplay beyond stat inflation,
- every branch has a restoration/world purpose,
- every branch remains recognizable as the same individual,
- no raw Blight crafting,
- save/reload preserves the result,
- co-op cannot duplicate or desynchronize a form change,
- UI clearly communicates choice and safety.

# Wild Encounters (2026-10-17)

**Status:** CONCEPT + IMPLEMENTED code (not compiled) → `04_Systems`
**Closes the gap:** the audit's thinnest core-loop step — **Encounter**. Binding had no on-ramp; now it does.

## What was built
- `EncounterTypes.h` — `EEncounterState` (Calm/Rage/Alpha/Blight/Hollow; canon states, never species), `EEncounterPhase` (Unaware→Aware→Engaged→BindingOffered→Resolved), `EEncounterResolution` (Bound/Befriended/Repelled/Fled/Withdrawn), `FEcoSpawnEntry`, `FEcoSpawnTable`, `FEncounterRecord`.
- `WildEcoKinSpawner` — placed per region; weighted species rolls, state rolls, pack sizes (Alphas always solitary), population caps, distant-release pruning. Validates Dex IDs against the Dex subsystem. Blight-state spawns arrive with corruption 55 (Corrupted band) via the Corruption subsystem. `NeverAlphaIDs` is designer data (Nature = canonical entry).
- `WildBehaviorComponent` — the wild mind, added at runtime. Wanders, notices, and acts by state: Calm grows curious, Rage/Blight charge, Alpha warns then charges, Hollow flees. Beaten wild ones withdraw and flee — never killed. No damage dealt by this component; real fights resolve through Duel mode.
- `EncounterSubsystem` — tracks live meetings, keeps history (feeds ecology accomplishments + the acquisition matrix), and fires `OnBindingOffered` — the delegate the future Binding ceremony binds to.

## Behavior notes
- Maturity (0–1) scales body and the four attributes. Never "level."
- `Soothe` on a Hollow wild one resolves as **Befriended** — care accepted, it stays wild. The warm path that isn't ownership.
- An unanswered Binding offer is never a trap: the wild one waits, and wanders off if the tamer leaves.

## Tay's veto list
1. State behaviors (Alpha warns-first? Hollow always flees?)
2. `Befriended` as a resolution (keep / cut)
3. Blight spawns arriving at corruption 55 (too high / too low)
4. Alphas always solitary (keep / allow pairs)
5. Notice/curiosity/engage radii (1500/700/350)

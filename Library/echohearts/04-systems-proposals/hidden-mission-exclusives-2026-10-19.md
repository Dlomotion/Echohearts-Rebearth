# Hidden-Mission Exclusives — Earned, Then Wild (2026-10-19)

**Status:** CONCEPT + code (`Source/Echohearts/Public|Private/Mission/HiddenMission*`) · IMPLEMENTED / NOT COMPILED / NOT TESTED / NOT RUNTIME VERIFIED. All names vetoable. Routes to 04_Systems. No new Bibles, Dexes, or structures.

## The idea (Tay's directive, 2026-10-19)
Certain EcoKin are **exclusive**: they cannot be found in the wild until a hidden mission is completed. The mission is a relationship — restoration deeds, puzzles, and a Binding offered at the end — never a capture. **Once the mission completes, the species joins the wild population of its habitat regions and appears on the map** ("pop up on the map in the areas of their habitat"). Exclusivity is a beginning, not a cage: the first bond opens the door for everyone after.

## The loop
1. **Discovery** — hidden missions are found, not given: a faded collar in Twilight Woods, an abandoned observatory in Forgotten Ruins. A.E.G.I.S. scanning, environmental puzzles, and restoration deeds advance stages.
2. **The Binding** — the final stage offers Binding through Resonance Alignment. Declined = no penalty; the mission waits.
3. **The Release Into the Wild** — on completion, the species is added to the wild spawner tables of its habitat regions at low weight, and the world map gains presence markers in those areas. From then on, any tamer can encounter, befriend, or bind them there.

## The two founding missions

### "Prism Paws" — Prismara (Dex 513, Twilight Woods)
1. Find the Faded Collar (Twilight Woods, A.E.G.I.S. scan).
2. Follow the Prism Paw Prints — they appear only at dusk.
3. Solve the Reflection Puzzle (uses Color Shift attunement).
4. Unlock the Prism Paws Sanctuary → Binding offered.
- **Post-mission:** Prismara enters spawner tables for Twilight Woods, Sky Ruins, Hidden Realms. Map markers appear in those regions.

### "Whispers of Color" — Chromapaw (Dex 514, Forgotten Ruins)
1. Discover the abandoned ecological observatory (fractured resonance chambers disrupting the habitat).
2. Restore 5 Forgotten Shrines (restoration deeds).
3. Achieve 3 EcoKin Bonds (Kindling ≥ 50% with three partners).
4. Discover the Prism Seed → unlock the Dawnpaw Sanctum → Binding offered.
- **Post-mission:** Chromapaw enters spawner tables for multi-biome and Forgotten Ruins regions. Map markers appear in those regions.

## Form attunement (both exclusives)
Forms are Ecoforms, never separate species. Each form has a distinct ecological activation condition and gameplay function — never a recolor. Full table in `DEX_EXPANSION_513_514.md`. Design rule: a form is earned by *being somewhere that matters, doing something that matters* — attunement is pilgrimage, not a menu.

## Code: what was built
- `HiddenMissionTypes.h` — `FHiddenMissionStage` (title, description, objective), `FHiddenMissionDef` (mission id, title, exclusive Dex ID, habitat region tags, stages, sanctuary name).
- `HiddenMissionSubsystem.h/.cpp` — `UGameInstanceSubsystem`: `RegisterHiddenMission`, `BeginMission`, `ReportStageProgress`, `CompleteMission`; delegates `OnHiddenMissionStageAdvanced` and `OnHiddenMissionCompleted(MissionId, EcoKinID, RegionTags)`.
- `AWildEcoKinSpawner` — new `AddExclusiveSpecies(EcoKinID, Weight, AllowedStates)`: appends to the roll pool at runtime. The subsystem calls it on every spawner whose region tag matches the mission's habitat tags.
- Map popups: `OnExclusiveWildUnlock(RegionTags)` delegate — the map UI listens and drops presence markers. The subsystem never draws UI itself.
- Canon held: Binding language only; declined offers carry no penalty; exclusive species validate through the Dex subsystem like any other (`IsKnownSpecies`).

## Rules
- A hidden mission can never be failed by losing a fight — only abandoned, and abandonment is reversible.
- Exclusive species spawn at low weight post-unlock (they're rare, not common).
- The first Binding from a hidden mission is always offered, never forced.

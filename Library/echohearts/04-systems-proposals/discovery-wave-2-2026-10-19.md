# Discovery Wave 2 — Field Journal, Campfire Care, Rite Defense (2026-10-19)

**Status:** CONCEPT + code · IMPLEMENTED / NOT COMPILED / NOT TESTED / NOT RUNTIME VERIFIED. Tay's directive 2026-10-19: "Build all 3." Build order chosen by creator: Field Journal → Campfire Care → Rite Defense (each bolts onto the last). All names vetoable. Routes to 04_Systems.

## 1. Field Journal (first)
**The anti-Pokédex.** A.E.G.I.S. already scans; the Journal turns scans into *research*. Log observations — feeding, resting, calls, state behaviors (Calm/Rage/Alpha/Blight/Hollow), habitats — and complete research tasks for Kindling trust and ecology accomplishments.

- **Observations:** one log per witnessed behavior: species, behavior tag, region. Duplicates don't count — the Journal wants breadth, not grinding.
- **Research tasks (data-driven examples):** "Document 3 feeding behaviors across Zoa species" / "Witness a Hollow-state encounter without approaching" / "Record 5 distinct calls" / "Log one Blight-state behavior from safe distance."
- **Rewards:** Kindling trust (broadcast to the Kindling system), ecology accomplishments, Chronicler quiz-topic unlocks. Studying pays.
- **The Journal is viewable:** a living bestiary the player writes — every entry in their words, with A.E.G.I.S. annotations.
- **Rule:** observation never requires contact. Watching from cover is valid research. The wild are not disturbed for science.

Code: `Discovery/JournalTypes.h` (FJournalObservation, FResearchTaskDef), `Discovery/JournalSubsystem.h/.cpp` (LogObservation, RegisterResearchTask, delegates OnObservationLogged / OnResearchTaskComplete).

## 2. Campfire Care (second)
**Cooking as care.** Forage ingredients (never hunted — flora, fallen fruit, glazemint, moonberries), cook at campfires or the Sanctuary hearth, share meals with partners: trust gains, strain recovery, Hollow-warding calm.

- **Meals (data-driven examples):** Moonberry Stew (trust+, calm), Emberroot Roast (strain recovery), Glazemint Tea (Hollow-warding), Tidepool Broth (stamina), Sunshard Skewers (cheer — small Kindling bump).
- **Rules:** ingredients are foraged/gathered resource IDs only — the subsystem rejects anything not gathered (the no-sacrifice rule reaches the kitchen). Meals are shared: effects scale gently with partners present. No meal is required for anything.
- **Campfire scenes:** cooking plays a short rest scene — partners gather, strain eases. Rest is gameplay, not a menu.

Code: `Discovery/CampfireTypes.h` (FMealDef: required resources, trust gain, strain recovery), `Discovery/CampfireSubsystem.h/.cpp` (RegisterMeal, CookMeal, delegates OnMealCooked / OnMealShared).

## 3. Rite Defense (third)
**Protect the circle.** Growth Rites and purifications take time — and the wild notices. While a rite runs, waves approach the rite circle: curious Calm ones, Rage ones drawn to the resonance, Blight ones hunting the light. Hold the circle until the rite completes.

- **How it plays:** the tamer (and deployed partner) hold a radius. Wild ones that enter Calm can be soothed (Befriended resolution); Rage ones are dueled and subdued (never killed — beaten ones withdraw). If the circle breaks, the rite pauses — retry, no penalty beyond time.
- **Waves are data:** species, counts, delays per rite tier. Purification rites draw Blight-state waves; Growth Rites draw the curious.
- **The trailer moment:** Shadow Beast Prime's purification — 60 seconds, everything comes, hold the light. (Reserved as the endgame defense.)
- **Rules:** nothing dies in a defense. Success = the rite completes. Rewards: rite completion itself, plus ecology accomplishments and a "Warden" track for flawless defenses.

Code: `EcoKin/RiteDefenseTypes.h` (FDefenseWave, FRiteDefenseDef), `EcoKin/RiteDefenseSubsystem.h/.cpp` (BeginDefense, EndDefense, wave orchestration via delegates OnDefenseWave for the spawner, OnDefenseCompleted).

## What this means in play
Study them. Feed them. Stand between them and the dark while they grow. The three systems are one sentence: **understanding, care, protection.**

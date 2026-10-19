# COMBAT INFORMATION & AI RECONCILIATION

**Status:** APPROVED-PENDING SYSTEM DESIGN  
**Implementation:** NOT YET VERIFIED

© 2026 Into Deep Studios and Donta L. Owens. All rights reserved.

## AI Mistake Patch / Continuity QA

Historical material mixed a turn-based battle simulator, Pokémon/Nexomon/Digimon/Summoners War research, a proposed `Resonance Log`, six-move requests, Unity prototypes and advanced AI algorithms.

The useful design goals are retained without copying another game's mechanics or creating a second campaign combat system.

Current rules:

- Main campaign combat remains **real-time third-person action**.
- Tactical/turn-based presentation remains limited to approved **Resonance Arena / Harmony Circuit / EchoDeck** simulation contexts.
- The active Essences are **Flora, Torrent, Pyre, Terra, Aero, Glaze, Voltic, Aura, Shade**.
- Public Eco-Kin attributes remain **Vibrance, Density, Harmony, Purity**.
- Historical HP/ATK/DEF/SPD/Crit-style cards or simulator displays are internal/reference concepts only unless a specific simulation mode defines separate clearly labeled combat values.
- No outside-franchise AI routine, formula, move list, battle log format or damage coefficient is copied into Echohearts.
- No new C++ is justified by this design document alone.

## 1. A.E.G.I.S. Encounter Chronicle

Historical working name: `Resonance Log`.

Current recommended player-facing system name: **A.E.G.I.S. Encounter Chronicle**.

Reason: it keeps the useful idea of a living battle record while avoiding the implication that every combat event is musical or rhythm-based.

The Chronicle is not a scrolling wall of `X used Y` text. It is a layered combat-information system.

### Information layers

**Immediate world feedback**
- hit/stagger/recoil animation;
- shield/guard break response;
- Essence reaction VFX;
- terrain or cover response;
- readable status iconography;
- ally warning/retreat behavior;
- directional threat indicators where needed.

**Compact HUD event pulse**
- technique name/icon when clarity requires it;
- damage/heal/guard result where the combat mode exposes numbers;
- resisted/exposed/blocked/evaded state;
- status application/expiration;
- environmental trigger;
- ally command acknowledgement or refusal.

**Chronicle detail panel**
- timestamped event sequence;
- source/target;
- Essence interaction;
- environmental modifier;
- player/Eco-Kin command state;
- meaningful relationship/behavior event;
- objective or boss-phase transition.

**Post-encounter report**
- major turning points;
- damage/mitigation/support contribution where appropriate;
- environmental effects;
- Eco-Kin injuries/fatigue;
- objective performance;
- care/restoration actions;
- optional replay markers for Arena/sanctioned competitions.

## 2. Narrative flavor without information loss

Flavor text may describe memorable moments, but mechanical meaning must remain legible.

Bad rule: replace all useful combat data with prose.

Better rule: pair concise factual data with optional authored flavor.

Example structure:
`Riftspine • Ridge Brace • blocked rockfall • Ally protected`

Optional flavor:
`Riftspine plants its quills and takes the mountain's weight for the team.`

Sonic language is used only for sonic-capable species or specific acoustic events.

## 3. Relationship and agency feedback

The Chronicle can record behavior that makes Eco-Kin feel alive:

- volunteered to intercept;
- hesitated because Fear/Stress was high;
- refused an unsafe command;
- protected a bonded ally;
- regrouped without being ordered;
- retreated after injury;
- responded to habitat advantage;
- calmed after the player de-escalated an encounter.

Kindling affects available cooperative behavior, not mindless obedience or arbitrary damage bonuses.

## 4. Six-technique concept

Historical request: each Eco-Kin should have **six moves** available.

Current reconciliation: use **six equipped techniques as a design target for modes that benefit from it**, not a copied turn-based move-slot rule.

For the real-time campaign, a six-technique kit can map through:
- quick actions;
- held/modifier actions;
- partner command wheel;
- contextual/environmental technique;
- defensive/mobility technique;
- signature technique.

The final controller mapping must be tested for gamepad, keyboard/mouse and accessibility before six simultaneous active techniques are locked.

An Eco-Kin may know more techniques in its authored progression library while equipping a bounded field kit. Exact counts remain balance/UX decisions.

## 5. Original combat AI architecture

Echohearts should use an original **contextual utility-scoring AI** foundation rather than reproducing another franchise's move-scoring implementation.

### Candidate decision inputs

- current objective;
- self health/injury/fatigue;
- ally health/threat;
- player command intent;
- Eco-Kin preference/agency state;
- distance and line of sight;
- navigation safety;
- Essence matchup;
- status conditions;
- cooldown/resource availability;
- terrain and weather;
- hazard exposure;
- target behavior;
- pack/herd/social context;
- fear/aggression;
- region trust/history;
- retreat path;
- protect-young/territory behavior;
- Blight/Gloom state where applicable.

### Candidate actions

**Engage, Reposition, Guard, Protect Ally, Assist Player, Use Technique, Break Line of Sight, Seek Cover, Interrupt, Cleanse/Support, Regroup, Hold, Warn, Retreat, Flee, Call Pack, Protect Young, Observe.**

Not every Eco-Kin needs every action.

### Utility principle

Each available action receives a contextual desirability score from Echohearts-authored curves/rules. The AI chooses among sufficiently strong candidates with controlled variation so it is readable without becoming deterministic.

Conceptually:

`Action Utility = Objective Fit + Survival Need + Ally Need + Position Value + Technique Value + Environment Value + Personality/Behavior Bias + Command Compatibility - Risk/Invalidity`

This is a design model, not production code or a locked formula.

## 6. Difficulty without cheating

AI difficulty should scale primarily through perception, planning quality and tactical breadth, not hidden stat inflation or impossible information.

Possible tiers:
- **Wild Instinct** — habitat/territory/fear-driven decisions;
- **Trained Field** — basic focus fire, protection and repositioning;
- **Veteran** — cooldown awareness, terrain use and coordinated pressure;
- **Elite / Boss** — authored phase strategy and team coordination;
- **Arena Expert** — sanctioned simulation AI with deeper prediction.

Difficulty can alter:
- number of factors evaluated;
- reaction delay;
- prediction horizon;
- coordination quality;
- willingness to disengage;
- memory of recent player habits.

It should not read private player inputs before they occur.

## 7. Search algorithms and machine learning

Historical research mentioned minimax, expectimax, Monte Carlo search, reinforcement learning and neural networks.

Current production rule:
- these are **research references only**;
- do not add them merely to sound advanced;
- real-time open-world combat should start with deterministic/inspectable utility AI and authored behavior;
- deeper search may be appropriate only inside bounded simulation modes if profiling proves acceptable;
- online ML is not required for the core game;
- any learned system must have deterministic fallbacks, testability and safety/latency budgets.

## 8. Boss information presentation

Boss fights should communicate mechanics through world and UI together:
- posture/animation tells;
- arena lighting/hazard state;
- A.E.G.I.S. scan callouts;
- accessible icon/text cues;
- phase-change signals;
- Chronicle event anchors;
- post-failure explanation without revealing every solution automatically.

## 9. Audio and accessibility

Battle information cannot rely on color or sound alone.

Required parallel channels where appropriate:
- icon + text + animation;
- optional damage numbers;
- captions for critical vocal/audio cues;
- scalable Chronicle text;
- colorblind-safe status differentiation;
- reduced camera shake/flash settings;
- haptic cues with non-haptic alternatives.

## 10. Technical posture

No implementation in this file is VERIFIED.

Recommended implementation order after current technical gates permit combat work:
1. define data-driven event envelope for combat presentation;
2. separate authoritative gameplay result from local presentation;
3. implement minimum Chronicle event types;
4. implement one utility-AI behavior set for one Eco-Kin archetype;
5. test deterministic behavior and network authority;
6. profile decision frequency and perception cost;
7. only then expand technique sets, boss behavior and Arena prediction.

**Final status:** the historical battle-log, six-move and battle-AI ideas are retained as original Echohearts design principles, corrected to the current real-time campaign, nine-Essence canon and sentient-partner agency rules. Implementation remains **NOT YET VERIFIED**.
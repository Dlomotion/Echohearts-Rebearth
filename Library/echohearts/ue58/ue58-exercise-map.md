# Subsystem Exercise Map — branch order & kata coverage

Your 7 local-only feature branches, ordered by dependency (each builds on the
last). The exercise series draws katas from these in smallest-to-largest order.

## Branch order
1. **feature/binding-ceremony-2026-10-17** — BindingCeremonySubsystem, BindingTypes
   → Kata 3 (delegates in action). *Foundation: how ceremonies broadcast.*
2. **feature/wild-encounters-2026-10-17** — EncounterSubsystem, EncounterTypes,
   WildBehaviorComponent, WildEcoKinSpawner → Kata 4 (TMap/TArray safety).
   *Foundation: data lookups that must not crash.*
3. **feature/battle-modes-duels-2026-10-17** — Battle modes (Duel/Raid/Sparring),
   Harmonic Momentum. *No kata yet — candidate for Kata 7 (combat math).*
4. **feature/hidden-mission-exclusives-2026-10-19** — HiddenMissionSubsystem,
   exclusive-species spawner hooks. *No kata yet.*
5. **feature/discovery-hunts-quizzes-2026-10-19** — DiscoverySubsystem,
   DiscoveryTypes → Katas 1–2 (header reading, USTRUCT shapes). *Start here:
   smallest, most readable subsystem.*
6. **feature/discovery-wave-2-2026-10-19** — JournalSubsystem, CampfireSubsystem,
   RiteDefenseSubsystem → Kata 6 (capstone: Discovery → Journal wiring).
7. **feature/base-building-action-2026-10-19** *(current HEAD)* — Base building,
   DuelCircuit, SanctuaryRaid, CompanionCare, Infirmary, Workforce, Vessel
   (Elderwing), Stronghold/BlightHunt/Rematch/Tournament/Arena/Bounty/Voyage
   systems, Emote, Triumph, SharedStores, Finale, Equipment (EQ-001).
   → Kata 5 (first small system: EquipmentSubsystem).

## Kata → subsystem → branch
| Kata | Subsystem file | Branch |
|---|---|---|
| 1 — header reading | DiscoverySubsystem.h | discovery-hunts-quizzes |
| 2 — USTRUCT shapes | DiscoveryTypes.h | discovery-hunts-quizzes |
| 3 — delegates | BindingCeremonySubsystem.h | binding-ceremony |
| 4 — TMap/TArray | EncounterSubsystem.h | wild-encounters |
| 5 — first system | EquipmentSubsystem.h | base-building-action |
| 6 — capstone wiring | Discovery + Journal | discovery-hunts-quizzes → discovery-wave-2 |

## Gaps flagged as future lessons
- **Nothing has ever compiled on Windows UE 5.8.3** — Kata 1's compile check is
  the first gate; expect input-mapping setup (`docs/INPUT_SETUP_CHECKLIST.md`) first.
- **No UI widgets exist** — katas stay in C++/Blueprint-callable logic until then.
- **Co-op is scaffold-only** — no kata touches Server/ yet.
- Battle modes (#3) and hidden missions (#4) have no kata yet — they become Katas
  7–8 once 1–6 are green.

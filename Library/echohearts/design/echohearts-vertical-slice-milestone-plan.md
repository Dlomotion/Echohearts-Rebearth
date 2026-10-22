# Echohearts: Rebearth — Vertical Slice Milestone Plan

The 6-phase roadmap from the whole-package review, turned into dated
milestones across the 34 subsystems on your 7 branches. This plan sequences
work only — it makes no canon, code, or merge decisions. Every date is a
working target you can move; every milestone is reversible and vetoable.
All checkpoints are yours unless you name someone else.

## The fastest path to a playable vertical slice

One loop, playable end to end: **roam → wild duel → win → Binding offered.**

The minimal subsystem set for that loop — nothing else is needed first:

- Tamer input (the 6 input actions + IMC_Tamer mapping context)
- FrequencyTamer character + controller
- **EncounterSubsystem** (branch: wild-encounters) — the wild duel trigger
- **AnimaLinkCombat + Duel mode** (branch: battle-modes-duels) — duel feel
- **BindingCeremonySubsystem** (branch: binding-ceremony) — the offer
- One companion: Piplin (your first Kindling)

## Phase 1 — It compiles · Oct 19–26, 2026

- Do the input setup (6 actions, mapping context, Blueprint wiring).
- First full build on your PC, UE 5.8.3 — all 7 branches' code is already
  chained under the current head, so one green build validates everything
  written so far.
- **Your checkpoint:** you report the first green build (or paste back the
  first error per the triage runbook).

## Phase 2 — The action slice · Oct 26 – Nov 16, 2026

- Make the vertical-slice loop *feel* right: dodge, essence abilities,
  impact, feedback (branches: wild-encounters, battle-modes-duels,
  binding-ceremony).
- Then extend: one raid (SanctuaryRaidSubsystem), one boss
  (branch: base-building-action).
- **Your checkpoint:** you play the loop and judge the feel — your call on
  whether combat is there yet.

## Phase 3 — UI & emotes · Nov 16–30, 2026

- HUD, menus, roster screen (no UI widgets exist yet — this is new work).
- Emote wheel + quick-chat (EmoteSubsystem is built; the wheel UI isn't).
- **Your checkpoint:** you confirm the game is readable — you can find
  everything you need in play.

## Phase 4 — Art, animation, sound in-engine · December 2026

- Rigged companions, combat animation, the Elderwing flying, music
  (VesselSubsystem exists; the in-engine art doesn't yet).
- **Your checkpoint:** you watch a rigged companion fight in-engine and
  judge whether it matches the card art's promise.

## Phase 5 — Content completion · January 2027

- Sky Isles coded (design exists; code doesn't) — SkyTrialSubsystem,
  GlideRaceSubsystem, EscortSubsystem, TideSubsystem, StormChaseSubsystem,
  RiftDelveSubsystem, AbyssDiveSubsystem get their worlds.
- Stronghold assaults, Elderwing voyages (VoyageSubsystem), quest chains:
  HiddenMissionSubsystem, DiscoverySubsystem, JournalSubsystem,
  CampfireSubsystem, RiteDefenseSubsystem, BountySubsystem,
  RematchSubsystem, TournamentSubsystem, ArenaSubsystem, SnapSubsystem.
- Base & care depth: CompanionCareSubsystem, InfirmarySubsystem,
  WorkforceSubsystem, EquipmentSubsystem, TriumphSubsystem,
  SharedStoresSubsystem, FinaleSubsystem.
- **Your checkpoint:** you walk the Sky Isles and run one full quest chain.

## Phase 6 — Polish & launch · February 2027

- The Shadow Beast Prime 60-second finale trailer cut.
- Balance pass, bug burn-down, launch call.
- **Your checkpoint:** the launch decision — yours alone.

## Branch map (dependency order — nothing leapfrogs)

1. binding-ceremony → Phase 2 (the offer)
2. wild-encounters → Phase 2 (the duel trigger)
3. battle-modes-duels → Phase 2 (Duel/Raid/Sparring, Harmonic Momentum)
4. hidden-mission-exclusives → Phase 5
5. discovery-hunts-quizzes → Phase 5
6. discovery-wave-2 → Phase 5
7. base-building-action → Phases 2–5 (bosses first, then base/care/meta depth)

## Your open decisions (unchanged by this plan)

- Stronghold assaults: stealth, loud, or both?
- After the action slice: Sky-Isle trials or Elderwing voyages first?
- Co-op at launch, or single-player first?
- Emote wheel: 8 slots enough?

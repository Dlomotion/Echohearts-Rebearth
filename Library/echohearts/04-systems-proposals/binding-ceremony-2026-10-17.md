# Binding Ceremony — interactive design + implementation (2026-10-17)

**Status:** CONCEPT + IMPLEMENTED code (not compiled) → `04_Systems`
**Closes the gap:** audit item #5 — the interactive Binding ceremony. The encounter
system built the door (`OnBindingOffered`); this walks through it. Binding is the
thesis mechanic: **Resonance Alignment, never capture. The EcoKin chooses.**

## Canon held (verbatim, not negotiable)
- Binding replaces capture; language is Binding / Resonance Alignment / Release.
- A companion is a relationship, not a container.
- Anima-Link is bidirectional — ceremony costs land on the tamer as link strain.
- Kindling trust %, no XP. Four attributes only: Vibrance, Density, Harmony, Purity.
- Nothing coerced, consumed, or killed. Declines carry no penalty and no claim.
- Nature (and any `NeverBindableIDs`) can never be bound — refused by canon, gracefully.

## Choreography
1. **Approach** (4s beat) — tamer enters; the wild one is invited, never pulled.
   Game phase locks to Ceremony (combat input locked; ceremony never ambushes a duel —
   if a duel is running, the offer simply waits).
2. **Attunement** — heartbeat sync. The wild one's pulse plays (animation notifies;
   a timer fallback exists until they do); the tamer times inputs to it. 3 synced
   pulses complete the phase. Each attempt costs 2 link strain (the tamer feels the
   reaching-out); a miss costs the strain but builds nothing. 60s with no sync and
   the wild one gently loses interest — never forced.
3. **TheOffer** — the tamer extends Resonance Alignment when they choose the moment.
   The EcoKin's answer is **computed, transparent, never random**:
   `base by state + attunement × 0.30 + remembered kindness (0.05/peaceful meeting, cap 0.15) − corruption × 0.30 (+ 0.15 if purified during the ceremony)`.
   Threshold 0.55. Base by state: Calm .70 / Hollow .50 / Alpha .45 / Rage .30 / Blight .20.
   - **Purification is part of the meeting:** corruption ≥ 40 blocks acceptance until
     the tamer offers purification (8 strain, −45 corruption). The offer holds, it doesn't fail.
   - **The link can refuse:** if strain is at fracture risk, the ceremony holds at TheOffer
     ("the link cannot bear it") — rest, or step back. The bidirectional consequence, made real.
4. **Alignment** — acceptance: 12 strain paid, `SetBondedTamer`, Kindling seeded at
   12–25% trust (the ceremony WAS the first trust — present but small; trust is earned,
   not granted). Encounter resolves **Bound**.
5. **Outcomes:** Aligned / Declined (withdrew with dignity; 24h dignity timer before
   re-offer, not a grind timer) / WithdrawnByTamer (always allowed, never punished) /
   Interrupted (danger; the wild one flees, no grudge) / RefusedByCanon.

## Integration map
- Answers `UEncounterSubsystem::OnBindingOffered` (binds in `Initialize`, unbinds in `Deinitialize`).
- Reads wild state from `UWildBehaviorComponent::EncounterState` (no encounter-subsystem changes needed).
- Strain via `UAnimaLinkComponent::NotifyTamerOverexertion` (tamer-side, bidirectional).
- Kindling seed via `UKindlingProgressionSubsystem::SetKindling`.
- Corruption via `UCorruptionSubsystem::GetCorruptionLevel` / `Purify(..., "BindingCeremony")`.
- Phase lock via `AEchoheartsGameMode::SetPhase(EGamePhase::Ceremony)`; restores Exploration after.
- Records `FBindingRecord` in `BindingHistory` — feeds ecology accomplishments and the
  14-path acquisition matrix ("wild meeting → Binding" path; matrix hook is future work).
- UI hooks: `OnPhaseChanged`, `OnCeremonyCompleted`, `OnPulseSynced`, `OnStrainBlocked`,
  `ReadWillingness()` (qualitative read — UI maps to words, never a number bar).

## Files
- `Source/Echohearts/Public/Binding/BindingTypes.h` — phases, outcomes, tunable config, record
- `Source/Echohearts/Public/Binding/BindingCeremonySubsystem.h`
- `Source/Echohearts/Private/Binding/BindingCeremonySubsystem.cpp`

## Tay's veto list
1. Phase order and the Approach beat length (4s) — keep / cut / retime
2. 3 synced pulses to complete Attunement (too easy / too hard)
3. Willingness bases by state + 0.55 threshold — the whole "who says yes" model
4. Purification gate at corruption 40 + purification as a mid-ceremony action
5. Strain costs (2/attempt, 8 purify, 12 align) and the strain-hold at TheOffer
6. Kindling seed 12–25% (too generous / too stingy)
7. 24h dignity timer after a decline
8. `NeverBindableIDs` contents (Nature is the canonical entry)
9. Ceremony deferring when a duel is running (vs. queueing the offer)
10. UI reading willingness qualitatively (vs. hiding it entirely)

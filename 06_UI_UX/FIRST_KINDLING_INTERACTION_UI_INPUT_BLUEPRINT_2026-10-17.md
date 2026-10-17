# First Kindling Interaction — HUD / Input / Device Blueprint
**Status:** DESIGN ASSET BRIEF; no UMG or Input Mapping assets exist by virtue of this document. **PR #71 supplement, M01/M05/M11/M13.**

## UI ownership
Draft PR #70 proposes a **hip-mounted** A.E.G.I.S./Eco-Device presentation; this proposal must not override established device canon before approval. D.A.H.L.I.A. is the advisory presentation. Use the existing UI view-model/subsystem once BUILD source is readable. No independent save, consent score, roster owner or duplicate AbilitySystem inside widgets.

## Exact screen inventory
| Screen ID (working) | Render inputs | Player action | Critical denial / feedback |
|---|---|---|---|
| `UI_WildSignalCompass` | scan confidence, clue age, relative direction cone | Scan/Observe; hide/show | stale signal; protected territory; unavailable cell |
| `UI_IndividualApproach` | posture, visible threat/shelter state, safe distance | step back/help/observe | refusal, hurt, unsupported habitat |
| `UI_HabitatIntervention` | active world repair objective, reversible tools, route/safety marker | protect/repair/withdraw | missing equipment, no safe route, wrong authority |
| `UI_KindlingInvitation` | authenticated Observe+Protect+Calm receipts; consent availability | Invite/Defer/Release | not safe, patient under care, not ready |
| `UI_KindlingCeremony` | phase revision, observed individual response, A.E.G.I.S. state | participate or Cancel | network pause/deferred, withdrawn consent |
| `UI_KindlingOutcome` | committed Bond/Release/Defer reason, world changes | Acknowledge | no optimistic 'success' until server commit |
| `UI_PartnerReadiness` | actual existing eight-link relationship record, one active, Strain/care | summon/recall/visit | care required, no trust, out of range |
| `UI_FieldLessonJournal` | mission steps, clue evidence, alternate completion | review/mark route | never gate lesson on forcing a bond |

## Presentation rules
Use **Vibrance, Density, Harmony, Purity** as the only public creature/player attributes. Do not show an additional 'Bind Rate', 'Sanity', 'Mana', extra Essence or proprietary capture capsule. Insight may show **Observed / Suspected / Unknown** source confidence, not invented exact trust percentages. Species/name/silhouette must match approved permanent Dex identity. D.A.H.L.I.A. offers factual uncertainty with player-dismissable voice/text and never says the creature owes a bond.

## Input-context ownership matrix
| Context | Typical input intents | Which actions are disabled |
|---|---|---|
| Explore | Move, Look, Jump, Interact, Scan, BackAway | ConfirmCeremony |
| Partner | SelectBondedLink, Summon, Recall, SafeExit | unauthorized next active partner |
| Ceremony | Invite, Confirm, Defer, Release, Cancel | Attack, forced movement into body, inventory discard |
| UI | Navigate, Accept, Back, Scroll, AlternateText | gameplay movement only while modal owns focus |

Every context supports keyboard/mouse, controller and accessible touch layout. Cancel must remain available until committing; after committed, a result explanation replaces the cancel affordance, not a visually interactive dead button. Controller focus cannot return to a hidden 'Accept'. Remap all inputs and provide hold-to-confirm alternative without timed music accuracy.

## Interaction storyboard
1. **A.E.G.I.S. scan:** thin ring around evidence, never around a living Eco-Kin as a target for ownership.
2. **Observation card:** named habitat clue, scan confidence and restoration need.
3. **Eco-Kin response:** face/posture/particle cues plus a caption with accessible icon. Positive response is authored individual behavior, not a percentage roll.
4. **Reciprocal resonance:** two intertwined signal curves (player and Eco-Kin). Participant may stop; visual brightness limited.
5. **Decision:** Accept/Defer/Release is signed by actual server-side consent state.
6. **Resolution:** one clean world-state and relationship event; device returns to exploration without duplicate invocation.

## Widgets / states / test matrix
Screen hosts subscribe to **revisioned events**. On `EncounterInstanceInvalidated`, `WorldCellUnloaded`, `IndividualNeedsCare`, `ConsentWithdrawn`, `PlayerDisconnected` or `TransactionRejected`, close unsafe prompts, show text reason, preserve chosen safe exit. All pending states are read-only after load until confirmed by the authority.

Acceptance: rejoin at all phases, UI rebuild mid-ceremony, lost gamepad, changing touch orientation, muted audio, reduced flash, color-blind cues, no unnecessary camera shake, localized longer text, cancellation immediately before commit, 100 repeated Interact edges without duplicate invitation.

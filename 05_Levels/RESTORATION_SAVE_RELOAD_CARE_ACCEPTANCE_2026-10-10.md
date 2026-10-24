# Restoration trial — save/reload and care continuity acceptance scene

**Date:** 2026-10-10  
**Classification:** PROPOSAL / NOT YET RUNTIME VERIFIED  
**Scope:** a test scene for the existing Training Stage 06 Restoration trial, not a new mission, progression meter, region or map.  
**Authority:** existing Story Continuity Spine, 125-ID Permanent Dex, `04_Systems` progression, `06_UI_UX` A.E.G.I.S. requirements and `11_Publication/PUBLIC_VERIFICATION_STATUS.md`.

## Player-facing scene

The player pauses during an authored habitat-restoration trial and later returns. The scene should preserve the relationship and consequences of the prior session while clearly distinguishing restored save data from fresh ecological readings.

Use an already-approved Eco-Kin instance selected by the existing Issue #10/vertical-slice asset process. Do not use an unapproved African or visual-wave candidate to fill that requirement. Use an existing authored test space after map approval; this document assigns no coordinates or travel gates.

| Beat | Player experience | Required state/authority |
|---|---|---|
| Before save | Companion shows authored fatigue/strain feedback; player may rest, care or defer further work. | Existing authoritative Anima-Link/care state; V/D/H/P remain four attributes. |
| Return to session | Companion identity and approved Form remain consistent. | Validated species/instance/Form identifiers; registry authorization is required beyond structural DTO validation. |
| A.E.G.I.S. reconnect | Show “Reading unavailable” until a valid current-context snapshot arrives. | A restored DTO does not prove a current habitat measurement or grant a mission unlock. |
| Trial panel | Show TRAINING — MAIN STORY PROGRESS; Stage 06: Restoration; Current Trial; completed objectives; Next Unlock. | Existing mission state, not telemetry thresholds or imported fixture values. |
| Care choice | Offer the applicable rest/care/defer interaction before resuming strain-producing work. | Loaded strain must not reset to zero, create a second link or authorize forced labor. |
| Restore habitat | Resume the authored ecological objective in real-time gameplay when valid authority state is ready. | Stage completion requires demonstrated story actions and existing mission rules. |
| Defer or release | Respect established consent and Release/Defer semantics. | No capture balls, forced fusion or automatic Eco-Egg rebirth. |

## Proposed display and dialogue copy

These are localized draft strings, not new canon events:

- Loading: “Restoring your last valid session…”
- Readings pending: “A.E.G.I.S. reading unavailable.”
- Care cue: “Your companion needs a moment to recover.”
- Recovery fallback: “The latest save could not be restored. A prior save is available.”
- Actions where supported: “Review recovery”, “Return to menu”, “Rest together”, “Defer work”.

Never claim successful recovery before the save service completes and validates it. Do not silently replace the latest save, consume items, repeat rewards or advance Training while showing fallback options.

## Acceptance scenarios

1. **Exact return:** V/D/H/P, species/instance, approved Form, mutation permissions and Anima-Link strain match the last accepted snapshot. Revision checks and registry authorization still apply.
2. **Interrupted save:** the prior good state remains recoverable; no half-written state is hydrated. Requires a transactional save service and actual storage tests.
3. **Unknown schema:** decline hydration and show a controlled recovery path; do not guess a migration or reset bonds.
4. **Invalid identity/Form/mutation:** reject unauthorized records even if IDs parse. No duplicate Dex entry or unauthorized ability appears.
5. **Stale telemetry:** loaded relationship data may display as saved data, but habitat readings remain unavailable/stale until a current producer update.
6. **Reward replay:** loading/reconnecting cannot duplicate restoration rewards, taming-license credit or Training unlocks.
7. **Care continuity:** combat/worker strain remains bidirectional; reopening the game does not evade rest/care consequences.
8. **Accessibility:** text and icons carry essential state with audio muted and reduced motion; controls remain navigable by controller and keyboard. Verify actual screen-reader, contrast and scaling behavior on named targets.
9. **Scope separation:** Huma-Link remains person/Humanoid-Kin ↔ person/Humanoid-Kin and cannot hydrate as an Anima-Link.
10. **Offline fixture boundary:** BUILD PR #26 fixture rows cannot grant mission completion, spawn approved species or establish a saved relationship.

## Evidence links and implementation boundary

- [BUILD PR #47](https://github.com/Dlomotion/ECHOHEARTS-REBEARTH-BUILD-/pull/47) authors structural validation and memory round-trip Automation checks. Those tests are not executed UE evidence.
- [Canon PR #46](https://github.com/Dlomotion/Echohearts-Rebearth/pull/46) contains the restoration-panel proposal; it remains unmerged and is cross-linked as a proposal, not current-main implementation.
- [BUILD PR #26](https://github.com/Dlomotion/ECHOHEARTS-REBEARTH-BUILD-/pull/26) and [canon Issue #38](https://github.com/Dlomotion/Echohearts-Rebearth/issues/38) define prototype/verification boundaries.
- [Production order](../11_Publication/PUBLIC_VERIFICATION_STATUS.md): real UE foundation → Issue #10 → 4–6 Eco-Kin slice precede playable promotion.

The current runtime DTO does **not** persist Training objectives, rest/care simulation, inventory/rewards or habitat state. These scene requirements must be attached to the existing systems when their dependencies are unblocked. Do not infer them from the new memory test.

## Next content action

After the foundation and Issue #10 assets pass their gates, bind this acceptance scene to the approved humanoid/Eco-Kin test assets and existing mission/save/UI producers. Record exact BUILD commit, engine/toolchain, artifact checksum, target/configuration, raw logs/video, test case, result, reviewer and date.

# A.E.G.I.S. restoration display acceptance contract — 2026-10-08

**Classification:** PROPOSAL / NOT YET VERIFIED in Unreal or live widgets.
**Canon baseline:** Echohearts-Rebearth `ce434f0c25148b0848362997c54533196cfa7c5c`.
**Implementation candidate:** BUILD PR #36, head `0a092081d1decac6155a083b5625eb03f557c23f`.
This extends existing A.E.G.I.S. UI requirements; it creates no new progression meter, map layer, roster or gameplay authority.

## Restoration trial panel

Use the existing Training — Main Story Progress track. Stage 06: Restoration may present:
- Current Trial: Restore the fractured habitat.
- Objectives: completed / authored total.
- Next Unlock: Restoration Altar Access.
These are example strings and must bind to the existing mission/unlock state; telemetry alone cannot complete a trial or grant an unlock.

Show Vibrance, Density, Harmony and Purity with explicit labels, values and qualitative text. Normalized display scalars are presentation transforms, not replacement gameplay attributes. Low Purity must remain visible as an ecological problem; manifest minimum-display thresholds cannot hide unsafe readings or certify restoration.

| Input condition | Proposed presentation | Authority boundary |
|---|---|---|
| No valid snapshot | Reading unavailable; no filled bars | Default packet values of 1.0 are not a real measurement |
| Valid zero value | Show zero and ecological context | Zero differs from missing data |
| Invalid/nonfinite update | Keep last valid snapshot, mark unavailable/stale through producer status | Rejection is not proof the old snapshot is current |
| Valid duplicate | Keep display; no repeated pulse/audio | Registry coalescing is not network replay protection |
| Updated snapshot | Update labels and bars once | No mission reward, inventory mutation or unlock |
| Travel/session teardown | Clear/rebind to current context | GameInstance lifetime must not retain another habitat's reading |

PR #36 has no timestamp, context key or producer invalidation signal. Staleness, habitat binding and travel invalidation remain TECHNICAL-TASKS before live integration. Do not infer freshness from a successful cache read.

## Accessibility and feedback

Do not convey condition solely through hue, pulse timing or sound. Pair state with text and distinct shapes; support screen-reader labels, contrast/scaling and reduced-motion settings. Avoid threshold-crossing sound spam: a sustained low-Purity condition needs persistent text, not repeated warnings. Any cadence budget in the offline manifest is a proposal, not measured FPS/GPU cost.

## Acceptance cases — AEGIS-REST-01

1. Empty cache produces Reading unavailable instead of full-health/full-Purity display.
2. A valid zero remains visible and never becomes an empty/unknown reading.
3. NaN/infinity is rejected; old readings are not represented as current.
4. Duplicate snapshots do not duplicate sound, VFX or screen-reader announcements.
5. Travel from habitat A to B cannot show A's measurements under B's title.
6. Objectives and unlocks follow server-authoritative mission state, including reconnect and duplicate delivery.
7. Reduced motion and muted audio retain all essential ecological feedback.
8. No Eco-Kin species ID, Training stage, Huma-Link or Anima-Link record is created by UI telemetry.

## Continuity

Preserve the 125-ID Permanent Dex, nine Rebearth Essences and four attributes. Anima-Link strain/care data remains a separate authoritative producer; this two-stream display cache cannot approve work assignments or override rest/care requirements. Saviors of the Universe remains step 18 postgame/cosmic continuation under [production status](../11_Publication/PUBLIC_VERIFICATION_STATUS.md). Web PR #17 is the existing correction lane for the 18-element/1,000+ roster/opening-campaign/forced-fusion claims.

World coordinates, Auralamb/Gaiataur stencil metadata, Data Layers, Holo-Map and travel gates are unchanged.

## Research/provenance

Checked 2026-10-08: [Epic subsystem lifecycle](https://dev.epicgames.com/documentation/unreal-engine/programming-subsystems-in-unreal-engine). Documentation informs lifecycle review only; no third-party source, art or sample implementation copied. UE5.8 lifecycle/UMG/Automation/accessibility execution remains NOT YET VERIFIED.

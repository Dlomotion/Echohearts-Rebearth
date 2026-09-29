# ECHOHEARTS: REBEARTH — A.E.G.I.S. MENU / CAMERA OVERLAY BLUEPRINT CONTRACT

**Date:** 2026-09-29  
**Status:** TECHNICAL/UI DESIGN CONTRACT / NOT YET VERIFIED  
**Filename correction:** `BLUEPRINTS` is used instead of the pasted `BLU_PRINTS` typo.

---

## 1. Purpose

Define the A.E.G.I.S. exploration scanner/reticle presentation without turning the UI into a capture lock, falsifying gameplay state, or treating console code as a real UMG/Blueprint implementation.

## 2. Intake code audit

The pasted standalone C++ is an interface sketch only.

Corrections:

1. `TargetLockStateTag` is stored as `std::string` rather than a registered Gameplay Tag/state enum.
2. `UpdateReticleOffsets` accepts unbounded screen-space values.
3. `LensZoomFactor` has no clamp, camera ownership rule, transition curve or accessibility policy.
4. `bHistogramDataRendered` is inferred from a string comparison instead of authored scan state.
5. The sample conflates scanning/tracking with ownership-oriented target locking.
6. `std::cout` is not UMG/Slate rendering.
7. No multiplayer/authority distinction exists between a local visual lock and authoritative gameplay state.
8. No input-mode, pause, controller, mobile or screen-safe-area handling exists.

## 3. Scanner state vocabulary

Recommended presentation states:

```text
Idle
Surveying
Observed
Tracking
RescuePriority
HazardMarked
ObjectiveMarked
StabilizationEligible
DataIncomplete
LostSignal
```

For sentient Eco-Kin, avoid a UI phrase such as `Captured`, `Owned`, or `Vessel Locked`.

A boss/Event Sovereign may be tracked as an objective without implying capture.

## 4. Overlay model

Recommended view-model fields:

```text
ScannerStateTag
TrackedActorOrWorldObjectID
ScreenAnchor
ReticleStyleID
ZoomLevel
SignalConfidence
KnownEcologyTags
KnownBehaviorTags
KnownFoodPreferenceTags
HazardTags
ObjectivePromptKey
AccessibilityPresentationProfile
```

The UI receives presentation state; it does not author canonical world state.

## 5. Zoom and reticle safety

Author minimum/maximum zoom per tool/profile.

Rules:

- clamp zoom;
- support smooth transition curves;
- respect motion-sensitivity settings;
- do not force camera shake for required information;
- keep reticle within safe-screen bounds;
- support controller, mouse/keyboard and touch input;
- preserve readable UI scale;
- allow reticle stabilization/assist where accessibility settings request it.

## 6. Heart Fruit guidance

When the player has legitimately learned a species' preference, the scanner may present:

- Heart Fruit interest indicator;
- recommended placement zone;
- wind/scent direction;
- safe waiting distance;
- stress warning;
- whether an open escape route exists;
- `Offer & Wait` accessibility prompt where eligible.

Unknown information stays unknown until learned through observation/research.

## 7. Trap-and-release overlay

For active field devices, the overlay may show:

```text
TrapDeviceID
SafetyState
TimeRemaining
StressTrend
ExitRouteOpen
AutoReleaseArmed
ManualReleasePrompt
RescueDestination
```

The UI must make **Release** easy to find.

Pause/Settings/accessibility menus never modify a boss shield, trap timer or Eco-Kin willingness simply because the player opened them.

## 8. Stabilization presentation

A.E.G.I.S. may visualize an environmental stabilization profile through bars, geometric envelopes or spatial guides.

Do not assume every interaction is a sound-frequency minigame.

The display may represent:

- spatial drift;
- anchor alignment;
- Harmony compatibility;
- Density support;
- weather pressure;
- movement envelope;
- specialist acoustic frequency only where authored.

## 9. Event Sovereign scanning

For entities such as Basalith Warden, scanning should reveal encounter-relevant information gradually:

- damaged external anchor locations;
- dangerous attack zones;
- ecological distress indicators;
- stabilization objectives;
- known/non-known weak structures;
- rescue routes.

The correct objective may be **repair**, **stabilize**, **cleanse**, **ally**, **migrate** or **defeat**, depending on the encounter.

## 10. UMG / MVVM direction

When implemented, prefer event-driven updates from an A.E.G.I.S. scanner/view-model layer rather than rebuilding strings every frame.

UI work should remain separated from authoritative server/world decisions.

A possible flow:

```text
Authoritative world/actor state
→ scanner component derives permitted observations
→ view model publishes presentation fields
→ UMG/Slate renders overlay
```

## 11. Accessibility minimums

Required design coverage:

- colorblind-safe status indicators;
- text/icon redundancy;
- captions/text for audio cues;
- adjustable reticle size;
- aim/scan assist options;
- reduced motion;
- sufficient contrast;
- configurable hold/toggle interactions;
- safe-area support;
- scalable text;
- no required information communicated only through distortion.

## 12. Verification boundary

This file does not prove a working camera, scanner component, ViewModel, UMG widget, controller mapping or packaged UI.

Status remains **NOT YET VERIFIED** until real UE5.8 implementation/runtime evidence exists.

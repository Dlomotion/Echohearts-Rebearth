# ECHOHEARTS: REBEARTH — UNIVERSAL PLATFORM ARCHITECTURE & SCALABILITY STANDARD

**Date:** 2026-10-05  
**Status:** TECHNICAL CONTRACT / NOT YET VERIFIED  
**Engine target:** Unreal Engine 5.8  
**Repository authority:** `Dlomotion/Echohearts-Rebearth` for canon/contracts; `Dlomotion/ECHOHEARTS-REBEARTH-BUILD-` for executable UE5.8 implementation/evidence  
**Verification rule:** no platform is `VERIFIED` without successful build + launch + representative hardware/runtime evidence.

---

## 1. Purpose

Define one scalable Echohearts: Rebearth runtime architecture that can target desktop, console, handheld, mobile, cloud-streamed play, and publication/companion surfaces without creating parallel gameplay rules, a second canon, a second Dex, or platform-exclusive mechanical truth.

The platform strategy is:

> **One universe, one canon, one gameplay contract, multiple device profiles.**

A different device may alter rendering cost, simulation density, input presentation, asset residency, UI scale, patch packaging, and frame-rate targets. It may not silently alter the identity of an Eco-Kin, the core story, the four production attributes, bond rules, authoritative transactions, or the Anima-Link gameplay contract.

## 2. Canonical gameplay invariants

The following are platform-independent:

- Planet: **Rebearth**.
- Creature classification: **Eco-Kin**.
- Player role: **Core-Binder / Frequency Tamer** only where the relevant story/system contract uses that term.
- Apex entity: **Nature**, a Legendary Humanoid-Kin with conditional Mutations rather than a standard evolution ladder.
- Hardcoded attribute matrix: **Vibrance, Density, Harmony, Purity**.
- **Anima-Link** remains a bidirectional pulse loop: combat strain and Eco-Kin damage can produce tactical stamina/health cost on the player according to authored rules.
- The 125-ID Permanent Dex remains the current production-roster authority.
- The Master Historical Naming Pool remains archival/review material and does not auto-create species.
- Save state, inventory ownership, Growth Rite legality, purchases, Event Sovereign reservation, and other authoritative transactions remain server/save-authority controlled where applicable.
- Accessibility, Pause, Settings, and input remapping may never lie to the player or secretly disadvantage the player.

## 3. Supported target classes

These are **target classes**, not current verification claims.

### 3.1 Desktop

- Windows x64 — primary development/reference runtime.
- Linux x64 — target after the canonical UE project exists and dependencies are audited.
- macOS — target after Apple toolchain validation.
- Windows ARM64 — experimental target only while UE5.8 support remains experimental; do not promise shipping support until runtime evidence exists.

### 3.2 Console

- Major current console families are planned platform targets.
- Console work requires licensed platform access, platform SDKs, certification rules, and a source build of Unreal where required.
- No public-repository document may claim console certification, console runtime success, or platform-specific SDK integration without private licensed evidence.

### 3.3 Handheld

- Steam Deck / Linux handheld class.
- Windows handheld PC class.
- Future handheld hardware enters through the same device-profile and input abstraction layers.

### 3.4 Mobile / TV

- Android.
- iOS / iPadOS.
- tvOS where a controller-first experience is appropriate.
- Mobile is a scaled Echohearts runtime, not a separate economy or reduced-canon game.

### 3.5 Cloud / streaming

Cloud streaming reuses a validated desktop/console-class build. It does not receive a separate gameplay ruleset. QA must add input latency, bitrate degradation, reconnect, focus-loss, and controller handoff cases.

### 3.6 Web / companion surfaces

A browser surface is treated as companion/reference functionality unless a future supported UE web runtime is explicitly proven. Do not claim the full UE5.8 game runs natively in-browser from design text alone.

## 4. Project architecture requirement

The executable UE5.8 implementation and any public bootstrap contract must keep the same module/target boundaries. The runtime should separate:

```text
Echohearts Runtime
├── Canon/Data Contracts
├── Gameplay Rules
├── Save/Profile
├── Networking Authority
├── Platform Services Interface
├── Input Abstraction
├── UI/Accessibility Layer
├── Device Profile / Scalability Layer
├── Asset Streaming / Install Chunk Layer
└── Telemetry / Verification Hooks
```

Platform APIs must remain behind interfaces/adapters so Steam, console, Apple, Google, cloud, or future platform services do not leak into canonical gameplay classes.

## 5. Unreal Engine platform systems to use

The eventual UE5.8 project should use the engine's established platform facilities rather than hardcoded hardware checks:

- Device Profiles.
- Scalability Groups.
- Platform configuration files.
- Enhanced Input mapping contexts.
- Common input/prompt abstraction where adopted.
- Asset Manager / Primary Asset rules.
- cook filters and platform-specific packaging.
- texture LOD groups and streaming budgets.
- skeletal mesh LODs and animation update-rate optimization.
- HLOD / world partition streaming where the world architecture uses them.
- platform-specific shader/permutation reduction.
- Unreal Insights and platform-native profilers.

Reference: Unreal Engine 5.8 general platform support and packaging documentation.

## 6. Device-profile classes

Create project-defined profiles after the real `.uproject` exists:

- `EH_Cinematic`
- `EH_Quality`
- `EH_Performance`
- `EH_Handheld`
- `EH_MobileHigh`
- `EH_MobileStandard`
- `EH_Cloud`

A profile may tune:

- view distance;
- texture pool and mip bias;
- shadow resolution/count;
- reflection quality;
- volumetrics;
- foliage density;
- Niagara emitter count;
- water quality;
- animation update frequency;
- distant AI presentation frequency;
- physics substep budgets;
- audio voice count;
- world streaming radius;
- background ecological simulation fidelity.

A profile may **not** create a competitive visibility exploit or alter canonical combat math solely because the player's graphics setting is lower.

## 7. Performance budgets

Final numeric budgets must be measured on representative hardware; until then they are targets, not verification.

### Reference targets

- High-end desktop: 60 FPS baseline; higher refresh supported where stable.
- Console performance mode: 60 FPS target.
- Console quality mode: stable 30 FPS minimum target unless hardware testing supports more.
- Handheld: stable 30 FPS minimum; 40/60 modes only when measured sustainable.
- Mobile: 30 FPS baseline; 60 FPS option on validated devices.

Gameplay rules, cooldowns, damage, Anima-Link pulses, AI decisions, and authoritative transactions must be frame-rate independent.

## 8. Asset scalability contract

Every production-critical 3D asset family must define:

- source/master asset;
- platform-ready mesh LOD chain;
- collision strategy;
- texture set and mip policy;
- material permutation policy;
- skeletal animation budget if animated;
- physics/secondary-motion policy;
- memory budget;
- draw-call budget;
- streaming priority;
- fallback representation for distant/low-cost rendering.

Eco-Kin remain visually identifiable across all LODs. Platform optimization may reduce detail but may not silently redesign approved species identity.

## 9. Eco-Kin and NPC animation scalability

Issue #10 remains the first real proof target.

For each supported rig family, verify:

- locomotion fidelity across frame profiles;
- foot/contact stability;
- directional hit reaction readability;
- attack-notify timing stability;
- exact hit-location payload correctness;
- bond/care/ecology interaction readability;
- animation budget at distance;
- reduced-rate animation behavior;
- controller + keyboard/mouse behavior;
- touch adaptation where mobile supports the same interaction.

Issue #10 must not be marked platform-verified from screenshots or design documents.

## 10. Input abstraction

Gameplay code requests semantic actions, never fixed device buttons.

Required action examples:

- Move
- Look
- Jump
- Interact
- PrimaryAction
- SecondaryAction
- Dodge
- AEGISScan
- EcoKinCommand
- QuickItem
- Pause
- AccessibilityShortcut where appropriate

Enhanced Input should provide device-specific mappings for:

- keyboard/mouse;
- Xbox-style controllers;
- PlayStation-style controllers;
- Nintendo-style controllers;
- Steam Input / handheld controllers;
- touch;
- controller + touch hybrid.

UI prompts must update from the active input method and must never hardcode one platform's button labels into gameplay logic.

## 11. UI / accessibility scaling

All critical screens must be tested at:

- television safe-zone distances;
- desktop resolutions;
- handheld resolutions;
- tablet portrait/landscape where supported;
- phone aspect ratios where supported;
- ultrawide desktop where supported.

Minimum requirements:

- scalable type;
- subtitle size controls;
- remappable controls where platform policy allows;
- non-color-only state communication;
- high-contrast option(s);
- readable hit/damage feedback;
- motion/camera comfort options;
- controller-only navigation;
- mouse navigation;
- touch navigation for touch builds;
- no critical information available only through hover.

## 12. Player-time protection

The universal-platform architecture must support the project's low-cognitive-cost design goal:

- true pause in solo gameplay wherever technically valid;
- reliable autosave/checkpoint behavior;
- suspend/resume validation;
- safe quit and recovery;
- reconnect behavior for online sessions;
- returning-player recap hooks;
- no mandatory live-service session for core solo progression;
- no save corruption from abrupt suspend/backgrounding.

## 13. Save and cloud-sync contract

Canonical save state must be platform-neutral and versioned.

Suggested top-level schema:

```text
EchoheartsSave
├── SaveVersion
├── PlayerProfile
├── StoryState
├── EcoKinRoster
├── KindlingBondState
├── AttributeState
│   ├── Vibrance
│   ├── Density
│   ├── Harmony
│   └── Purity
├── Inventory
├── Homeland
├── WorldState
├── Quests
├── Discoveries
├── PlatformEntitlementReferences
└── Settings
```

Platform account IDs, entitlement receipts, and cloud-provider metadata must be wrapped or referenced rather than becoming the canonical identity key for the save itself.

Cloud conflict policy must define:

1. local revision;
2. remote revision;
3. timestamp;
4. monotonic save revision/GUID where appropriate;
5. conflict prompt or safe merge policy;
6. rollback/recovery copy.

## 14. Networking and cross-play boundary

Cross-play is a target capability, not an automatic promise.

Before enabling a platform pair, verify:

- identity/account bridge;
- invitation path;
- version compatibility;
- authoritative gameplay state;
- voice/chat policy if present;
- parental/platform policy compliance;
- disconnect/reconnect;
- NAT/relay requirements;
- moderation/reporting requirements;
- save/entitlement ownership separation;
- anti-cheat support on each target.

## 15. Packaging and install chunks

The project should be partitionable into logical install/cook units such as:

```text
CoreRuntime
Meridian
Biome_<Name>
EcoKinFamily_<ID>
Story_<Chapter>
Audio_<Locale>
Cinematics
HighResolutionAssets
MultiplayerOptional
Seasonal_<ID>
DLC_<ID>
```

This supports smaller initial installs, optional high-resolution content, mobile/handheld asset variants, and safer patches.

## 16. Telemetry and crash evidence

Per-platform development builds should capture at minimum:

- CPU frame time;
- GPU frame time;
- memory/VRAM;
- streaming stalls;
- asset load failures;
- shader/PSO issues;
- crash signature;
- save/load duration and failures;
- network disconnect reason where applicable;
- input device type;
- thermal/battery state where platform APIs permit and privacy rules allow.

Telemetry must not collect unnecessary personal data. Platform identifiers must be minimized/pseudonymized according to the final privacy design.

## 17. Verification ladder

Use the following status vocabulary consistently:

1. **PLANNED** — design/requirements only.
2. **REPOSITORY-READY** — configs/code/assets are present for testing.
3. **BUILDABLE** — target successfully compiles/cooks/packages.
4. **RUNTIME-TESTED** — packaged build launches and executes the defined smoke suite on representative hardware.
5. **COMPATIBILITY-TESTED** — performance/input/save/network/accessibility matrix passes.
6. **CERTIFICATION-READY** — platform-specific submission checklist passes internally.
7. **VERIFIED** — build artifacts, logs, hardware identifiers, runtime captures, and test results are retained as evidence.

No earlier state may be described publicly as `VERIFIED`.

## 18. Required first implementation order

1. Reconcile the UE5.8 descriptor, Game/Editor targets, and primary `Echohearts` runtime module across the public foundation contract and executable build repository.
2. Prove a fresh executable-repository checkout plus Git LFS round trip on the authorized UE5.8 runner.
3. Prove UHT + Development Editor compile.
4. Prove UE5.8 editor launch, one minimal authored map, and the bounded PIE smoke gate.
5. Prove a Development Windows package and packaged executable launch.
6. Execute **Issue #10** on Windows reference hardware using only the minimum platform-neutral input/save/scalability seams needed by that slice.
7. Package the 4–6 Eco-Kin vertical slice before broad platform expansion.
8. Profile the proven slice under `EH_Quality`, `EH_Performance`, and `EH_Handheld` profiles.
9. Add one Linux/Steam Deck build target and retain build/runtime hardware evidence.
10. Add Android only after the reference slice and input/UI abstraction are stable.
11. Add iOS/iPadOS after Apple toolchain access is available.
12. Add licensed console targets only inside compliant/private SDK workflows.
13. Expand cross-play/cloud-save claims only after the applicable server-authority, reconnect, save-conflict, and exact platform-pair tests exist.

Platform architecture contracts may be prepared before these runtime gates, but contracts do not advance the runtime status.

## 19. Current repository truth

Repository source can now be described as **foundation material present / candidate for execution** where PR #19 or the executable build repository contains the descriptor, targets, module rules, and compiler driver. That is not UHT/compile/runtime evidence.

This document therefore does **not** establish a successful UE5.8 build, editor launch, authored-map runtime, packaged launch, device profile execution, mobile/console/handheld package, cross-play, cloud save, or performance result. Those remain **NOT YET VERIFIED** until the exact evidence gate is executed and retained.

# ECHOHEARTS: REBEARTH — UNIVERSAL PLATFORM VERIFICATION MATRIX

**Date:** 2026-10-05  
**Status:** PRODUCTION QA CONTRACT / NOT YET VERIFIED  
**Depends on:** canonical UE5.8 `.uproject`, runtime `Source/` tree, clean clone/LFS, packaged builds, and representative target hardware.

---

## 1. Purpose

Convert “support all platforms” into auditable evidence. This matrix defines what must be proven before Echohearts: Rebearth can claim that a platform is supported, compatible, certification-ready, or verified.

Design text, generated images, editor screenshots, or unexecuted code do not satisfy runtime verification.

## 2. Verification status vocabulary

| Status | Meaning |
|---|---|
| PLANNED | Requirement exists; no implementation proof. |
| REPOSITORY-READY | Required source/config/assets are committed. |
| BUILDABLE | Target compiles/cooks/packages successfully. |
| RUNTIME-TESTED | Packaged build launches and completes smoke test on representative hardware. |
| COMPATIBILITY-TESTED | Input, save, performance, accessibility, suspend/recovery, and networking cases pass for the target. |
| CERTIFICATION-READY | Internal platform-certification checklist passes. |
| VERIFIED | Reproducible logs/build artifacts/device evidence are retained and reviewed. |

## 3. Current baseline and dependency lanes

UE5.8 descriptor/target/module source may be repository-present through the corrected foundation work, but **universal platform support remains PLANNED / NOT YET VERIFIED** until the executable build repository produces retained build and hardware/runtime evidence.

The game/runtime dependency lane is:

**UE5.8 foundation evidence → Issue #10 Windows runtime proof → 4–6 Eco-Kin slice → per-platform build/hardware/input/save/performance expansion → exact cross-play/cloud-save pair validation.**

Issue #10 remains the first original humanoid + Eco-Kin runtime proof and the first reusable cross-platform benchmark.

The ebook/publication lane is independent of UE runtime execution:

**canon-reviewed manuscript → EPUB artifact → EPUBCheck/accessibility validation → named reading-system/device render tests → storefront preview/submission evidence.**

An ebook contract may merge before Issue #10; an ebook verification claim may not.

## 4. Target matrix

| Target class | Build gate | Runtime hardware gate | Input gate | Save/suspend gate | Performance gate | Network gate | Current status |
|---|---|---|---|---|---|---|---|
| Windows x64 | Required | Required | KB/M + controller | Required | Required | Required where online | PLANNED |
| Linux x64 | Required | Required | KB/M + controller | Required | Required | Required where online | PLANNED |
| macOS | Required | Required | KB/M + controller | Required | Required | Required where online | PLANNED |
| Steam Deck / Linux handheld | Required | Required | handheld/controller | Required | Required | Required where online | PLANNED |
| Windows handheld | Required | Required | handheld/controller | Required | Required | Required where online | PLANNED |
| Android | Required | Device-class sample set | touch + controller | background/restore required | thermal + battery required | Required where online | PLANNED |
| iPhone/iPad | Required | Device-class sample set | touch + controller | background/restore required | thermal + battery required | Required where online | PLANNED |
| tvOS | Required if shipped | Representative Apple TV | controller | suspend/restore | Required | Required where online | PLANNED |
| Licensed console targets | Required under licensed SDK | Required | platform controller | suspend/rest mode | Required | platform-services/cross-play | PLANNED |
| Cloud streaming | Host build required | streaming client sample | controller + KB/M where supported | reconnect/session recovery | latency/bitrate required | required | PLANNED |

## 5. Build gate

For every executable target:

- fresh checkout from the canonical repository;
- `git lfs pull` succeeds;
- expected large assets resolve correctly;
- project files generate where required;
- UHT succeeds;
- C++ compile succeeds;
- cook succeeds;
- package succeeds;
- install/deploy succeeds;
- packaged executable/app launches;
- no missing plugin/module failure;
- no missing default map or content mount failure.

Retain:

- commit SHA;
- engine version/build identifier;
- target/platform configuration;
- build command;
- build log;
- packaged artifact hash;
- tester/hardware record.

## 6. Universal smoke suite

Every runtime target must complete:

1. boot to main menu;
2. new game/profile creation;
3. settings persistence;
4. load into a gameplay map;
5. move/look/jump/interact;
6. A.E.G.I.S. scan interaction;
7. Eco-Kin interaction;
8. one combat encounter;
9. one Anima-Link strain transfer case;
10. verify Vibrance/Density/Harmony/Purity state serialization where the slice exposes them;
11. inventory change;
12. save;
13. quit;
14. relaunch;
15. load save;
16. verify expected world/player/Eco-Kin state;
17. pause/resume in solo play;
18. platform suspend/background where supported;
19. resume/recover;
20. clean exit.

## 7. Issue #10 cross-platform benchmark

The first body/animation slice should supply reusable tests for:

- one original humanoid;
- one original Eco-Kin rig family;
- idle, locomotion, turn;
- slope/stair/terrain contact;
- one attack with authored notify window;
- three directional hit reactions;
- exact impact-location feedback;
- knockback/stagger;
- death/disable path;
- one bond/care/ecology interaction;
- one short Sequencer scene;
- frame-time and animation cost capture.

The same content should run under multiple device/scalability profiles before broader creature production.

## 8. Input test suite

### Keyboard/mouse

- rebinding;
- multiple mouse sensitivities;
- focus loss/recovery;
- menu navigation;
- no controller-only blockers.

### Controller

- platform-native face-button layout;
- stick dead-zone behavior;
- controller reconnect;
- prompt swapping;
- menu navigation without mouse;
- rumble/haptics do not communicate mandatory information alone.

### Touch

- one-handed/comfortable reach review where applicable;
- orientation/layout change where supported;
- touch targets remain readable;
- no hover-only interactions;
- controller attachment/removal at runtime;
- touch controls never obscure critical combat/ecology information.

## 9. UI/readability matrix

Test critical interfaces at:

- 1280×720;
- 1920×1080;
- 2560×1440;
- 3840×2160;
- representative handheld resolution/aspect ratio;
- representative phone resolutions/aspect ratios;
- representative tablet portrait/landscape if supported;
- ultrawide desktop where supported;
- television safe-area simulation.

Validate:

- text clipping;
- subtitle size;
- tooltip placement;
- HUD overlap;
- controller focus;
- touch occlusion;
- icon legibility;
- color-independent state feedback;
- accessibility settings persistence.

## 10. Save/recovery matrix

Test:

- manual save where supported;
- autosave;
- save during/after combat boundaries;
- quit immediately after save;
- app termination;
- power/suspend simulation;
- storage-full handling;
- corrupted-save fallback;
- previous-version migration;
- local/cloud conflict;
- account sign-out;
- reconnect/resync;
- one-time Event Sovereign transaction recovery when that system exists.

No one-time state may duplicate because the process was interrupted.

## 11. Performance evidence

Capture per target:

- CPU game-thread frame time;
- render-thread frame time;
- GPU frame time;
- total memory;
- VRAM where exposed;
- streaming pool usage;
- PSO/shader hitching;
- load/transition time;
- animation update cost;
- AI cost;
- Niagara/VFX cost;
- physics cost;
- world partition/streaming stalls;
- save/load duration.

For mobile/handheld add:

- thermal state;
- clock throttling evidence where accessible;
- battery discharge trend;
- memory pressure/background kill behavior.

## 12. Long-session and interruption tests

Required test classes:

- 15-minute short-session pass;
- 30-minute smoke;
- 2-hour soak;
- repeated suspend/resume;
- pause for extended real-world interruption;
- reconnect after network loss;
- controller battery/device disconnect;
- foreground/background transitions on mobile.

The game should respect the player's time: interruption must not unnecessarily destroy solo progress.

## 13. Networking/cross-play matrix

When multiplayer is implemented, test each enabled platform pair for:

- login/identity;
- invite/join;
- host/server authority;
- Anima-Link authoritative state;
- damage authority;
- inventory transaction authority;
- Eco-Kin state replication;
- latency and packet loss;
- disconnect/reconnect;
- version mismatch;
- entitlement mismatch;
- moderation/reporting workflow where required;
- anti-cheat compatibility.

Do not list a platform pair as cross-play supported until that exact pair is runtime tested.

## 14. Accessibility test gate

At minimum verify:

- subtitle scaling;
- remappable actions where allowed;
- high-contrast/readability mode;
- color-independent indicators;
- camera shake/motion controls;
- readable hit direction/impact feedback;
- timing-window accessibility for applicable puzzles/interactions;
- pause/settings access during solo play;
- no inaccessible mandatory input chord.

## 15. Evidence package naming

Recommended evidence path outside public secrets/SDK data:

```text
Verification/<Platform>/<BuildVersion>/
├── build_manifest.md
├── commit_sha.txt
├── build_log_reference.txt
├── device_matrix.csv
├── smoke_results.csv
├── performance_summary.csv
├── save_recovery_results.csv
├── input_results.csv
├── accessibility_results.csv
├── known_issues.md
└── media_reference_manifest.md
```

Console-proprietary logs/SDK details must remain in approved private storage and be referenced by non-sensitive evidence IDs only.

## 16. Release gate

A target cannot be called `SUPPORTED` for a public production release unless:

- build gate passes;
- runtime smoke passes;
- performance target is met or explicitly bounded;
- save/recovery passes;
- input path is complete;
- accessibility baseline passes;
- crash blockers are resolved;
- platform compliance checklist passes where applicable;
- regression suite passes on the release candidate.

`SUPPORTED` still does not automatically mean `VERIFIED` unless retained evidence exists.

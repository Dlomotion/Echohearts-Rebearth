# Unity Gameplay Recovery Batch 2 — UE5.8 Port Map

**Date:** 2026-10-06  
**Status:** SOURCE RECOVERY + BOUNDED UE5.8 PORT / RUNTIME NOT VERIFIED

This intake covers the uploaded Character Creator, Customization System, Shader/Dialogue/Netcode, Animation/VFX/Multiplayer, Full Demo, Expanded, Foundation, Complete Export, and Boss/Multiplayer/VFX archives.

## What the source actually contains

- Character creator/customization: real C# color/mesh-selection prototypes using renderer/material instances and local PlayerPrefs persistence.
- Dialogue: a real serializable node/option model and a minimal UI line presenter.
- Multiplayer: one owner-driven transform movement prototype and one server-only integer turn counter.
- Animation: a small attack/hurt/faint animator trigger wrapper.
- Object pooling: a queue-based prefab pool prototype.
- Update throttling: a frame-count interval prototype.
- Stylized shadow shader: a small texture + shadow-tint shader.
- Boss/Multiplayer/VFX “expanded” systems: placeholder empty classes only.
- Foundation archive: empty.
- Complete Export: README only; it claims Dialogue System, AI Boss, Shader Graph and Netcode Coop Demo but contains no implementation of those systems in that archive.
- Expanded archive: directory skeleton only.

## UE5.8 port decision

The BUILD repository PR #34 implements only what the uploaded source supports strongly enough to port without invention:

- stable character appearance records;
- server-authoritative replicated customization state;
- stable-ID dialogue nodes/options;
- bounded dialogue registry;
- bounded VFX cue records/queue;
- battle synchronization sequence contract;
- Automation contract tests.

The old PlayerPrefs persistence is not copied. Character appearance must ultimately flow through the existing versioned profile/save/cloud authority.

The old owner-driven direct transform movement is not copied. Production multiplayer must use the existing UE server-authoritative movement/gameplay path.

The old frame-count throttle is not copied. Performance work must be based on measured UE tick/timer/significance requirements rather than arbitrary frame skipping.

The old shader is preserved as a technical-art requirement only: stylized shadow tint/readability. Final material implementation belongs in UE materials and must be profiled.

The old animator wrapper is preserved as an animation-state requirement only. Final attack/hurt/faint presentation must use the approved animation/notifies/state architecture.

## Canon constraints

No recovered file may:
- create a second Permanent Dex;
- replace Vibrance, Density, Harmony, Purity with generic RPG roots;
- make Eco-Kin inventory commodities;
- reintroduce forced fusion;
- bypass Kindling/consent;
- replace the A.E.G.I.S. / Anima-Link architecture;
- claim boss, multiplayer, VFX, dialogue, shader, or demo completeness where the source is only a placeholder.

## Git transport

For the gameplay repository on Windows:
- HTTPS + Git Credential Manager: preferred normal Git transport/authentication;
- GitHub CLI: preferred repository/PR/workflow command surface;
- SSH: optional key-based Git transport.

Credentials, tokens, private keys, and local auth caches are never committed.

## Verification

Repository code and source mapping do not prove UE5.8 runtime behavior.

**NOT VERIFIED — UE BUILD/RUNTIME EVIDENCE REQUIRED**

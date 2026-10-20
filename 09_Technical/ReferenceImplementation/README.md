# Cross-engine implementation staging — NOT VERIFIED

These are **source references staged in the canonical development repository**, not automatically part of the BUILD project's Unreal module. Copy Unreal .h/.cpp to the actual UE5.8 module Source/Echohearts/{Public,Private} after reconciling existing classes. Confirm the module name and export macro; the example classes deliberately omit a module export macro until that target is verified. Do not compile duplicate classes with preexisting names.

Three tracks:
1. Unreal C++: replicated world-state/quest component, four-attribute domain ecology and versioned SaveGame DTO. Attach component to a server-owned replicated quest/world actor, NOT a per-client pawn. Interactions must validate objective evidence, proximity, permissions, Eco-Kin consent and Anima-Link strain on server. The bool flags in this starter are **not sufficient security proof**; never expose a client RPC forwarding those flags.
2. Blender: non-destructive rig/material/scale audit. Run in Blender, then manually test FBX/glTF export/import with approved Eco-Kin art, coordinate system, collision, skeleton, LOD and licensing.
3. Unity: DTO only for optional client/prototype. No Unity authority, live sync, or production build implied.

The story dependency remains Earth portal -> Tree of Life/Auralis starters -> A.E.G.I.S. and Anima-Link -> domain construction -> Aether-Ark study -> The Broken Crossing -> ancient war evidence -> Lord Dred/Nanonite threats -> regional restoration. Environmental outcomes should alter water quality, navigation, clinic supply, NPC dialogue, Eco-Kin behavior and future quests.

Platform targets: desktop, Android/iOS, consoles. Each requires input mapping, performance profiling, device builds, networking/save reconciliation, licensing and certification as applicable. This source package does not provide a platform build.

Validation gates (all NOT VERIFIED): UE5.8 UHT/UBT, PIE, replicated clients, authority exploit tests, save migrations, Blender import, Unity compile, Windows/Android/iOS package, console SDK and certification. Never promote proposed story or Eco-Kin entries without canon review.

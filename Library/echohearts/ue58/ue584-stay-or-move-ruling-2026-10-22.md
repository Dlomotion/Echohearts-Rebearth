# UE 5.8.4 Stay-or-Move Ruling — 2026-10-22

**Ruling: STAY on 5.8.3.** The 5.8.3 build lock (Tay's final instruction, 2026-10-15) is reaffirmed. This ruling is dated, reversible, and recorded against that lock; it changes no files and no installs.

Source weighed: Epic's official "5.8.4 Hotfix Released" thread (forums.unrealengine.com, posted 2026-10-20), full fix list read 2026-10-22, plus the thread's known-issue note and early community reports.

## What 5.8.4 fixes — and whether it touches Echohearts

**Touches nothing in the committed C++ build.** The ~140 committed source files across 34 subsystems (game framework, Anima-Link combat, Binding ceremony, corruption, Sanctuary, duels, discovery, base building) sit on GameplayTags, GameplayTasks, EnhancedInput, UMG, AIModule, and MediaAssets. The 5.8.4 notes change **none** of those areas. There is no gameplay-framework, input, UI, AI, save, or audio fix in the hotfix that maps to a committed subsystem. A move today would re-version the engine under code that has never compiled, in the exact week the first-build runbook assumes 5.8.3 — risk with no offsetting gain.

**Relevant only to future phases (noted, not decisive):**
- *Landscape (4 fixes):* crash loading a landscape without edit layers; rare crash after undo; water-zone assert; target-layer assert. Real — but no landscape exists yet. These matter when the terrain phase opens, not before.
- *Materials & shaders:* shader-compile cancellation race fix; shader preprocessor crash on unclosed literals; material pin undo; a MaterialShader assert. Relevant to the landscape master material build — again, a future phase.
- *Editor / Visual Studio 2026:* the editor now reuses a running VS2026 instance, honors the new .slnx format, and saves open documents before a Hot Reload compile. This is the single fix closest to the present work (first-compile week is C++ iteration). It earns a move **only if** the first compile actually hits the VS2026/Hot Reload friction — see the reopen trigger.
- *Sequencer:* crash on editor close with the Sequencer tab open. Minor; cinematics are design-stage.

**Counts against moving now:**
- *New known issue in 5.8.4:* the PCG Editor Mode Paint Tool fails to update in real time (Epic's own note in the release thread; workaround exists). PCG scatter is phase two of our terrain study path — the hotfix trades future landscape fixes for a present PCG annoyance.
- *Early community reports (anecdotal, unverified):* increased editor RAM use after updating. Weighed lightly, recorded for completeness.
- *Explicitly irrelevant:* Mover crash fixes (Mover is on the project's avoid list), MetaHuman RigLogic fixes (MetaHuman use is pointers-only), ChaosVehicles, NDI/16K media, iOS profiles, EOS SDK bump (netcode is scaffold-only; EOS is not integrated). Speculative or unrelated changes do not earn a move, per the standing rule.

## Reopen trigger

Revisit this ruling when **any one** of these happens:
1. The terrain phase opens (first Landscape/Mesh Terrain sculpt + master material build) — the Landscape and shader fixes become material at that point.
2. The first compile hits the Visual Studio 2026 / Hot Reload problem the .slnx fix addresses.
3. A 5.8.5 (or later) hotfix ships — re-run this same comparison against its notes.

Until then: **5.8.3, locked as before.**

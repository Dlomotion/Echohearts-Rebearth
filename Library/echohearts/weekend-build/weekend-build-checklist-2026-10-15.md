# Weekend Build Session Checklist (prepared 2026-10-15, Tay local time)

Everything is staged. The compile gate is your Windows machine — this is the exact sequence.

## What you're starting with
- **The full project**, packed as `echohearts-project-2026-10-15.tar.gz` (41 MB, 146 files): `EchoheartsRebearth.uproject` (EngineAssociation 5.8), the complete `Source/Echohearts/` tree (72 files — the 33-file framework from tonight plus the earlier EcoKin contracts, anti-cheat types, championship TV, release/harvest systems), Config, Content, docs. NOT COMPILED / NOT TESTED — your build is the first proof it compiles.
- **5 Linux launch bundles** already exist as separate .tar.gz files (`files/linux-staged-bundles/`) — those push to the three repos *after* the Windows compile proves the code.

## The sequence
1. **Install UE 5.8.3** from the Epic launcher. If the installer sticks on "Initializing": back up, then clear `C:\ProgramData\Epic\EpicGamesLauncher\Data\Manifests`, and retry (confirmed workaround, filed tonight).
2. **Transfer the project.** Preferred path is the repo (the GitHub write-path retry is queued from this afternoon — ask me before the session and I'll tell you if it recovered). Fallback: download the tarball here and extract it to a short path like `D:\Echohearts\`.
3. **Open `EchoheartsRebearth.uproject`** — it should associate with your 5.8.3 install automatically. Generate Visual Studio project files if prompted, then build (Development Editor, Win64).
4. **What the build proves:** the Frequency Tamer, companion AI, Anima-Link/Kindling/Growth Rites systems, and all subsystem code compile. Anything that fails is mine to fix — send me the error log and I'll patch it.
5. **After it compiles:** press Play in the editor. Expect a playable Tamer with companion follow AI; Blueprint widgets, input mapping assets, character meshes, enemy AI, and the interactive Binding ceremony are *not* in this package — those are the next writes, not this weekend's gate.

## Two things that touch this session (your calls, already in the queue)
- **Repo-selection grant** for the two private repos — unblocks the push path so future builds come through Git instead of tarballs.
- **Copilot model pin** (tonight's message) — doesn't block compiling, but the Oct 19 retirement day is also Monday, the same morning the weekly nudge lands. One reply settles it.

## Known, non-blocking
- Target rules use `BuildSettingsVersion.V6` instead of V7/Unreal5_8 — compiles fine on 5.8, flagged for later reconciliation.
- PR #68 merge, index.html picks, Dex rulings — none of them block this weekend's build.

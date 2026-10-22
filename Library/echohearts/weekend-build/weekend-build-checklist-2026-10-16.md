# Weekend Build Session Checklist (prepared 2026-10-16, Tay local time)

Everything is staged. The compile gate is your Windows machine — this is the exact sequence.

## What you're starting with
- **The full project**, packed as `echohearts-project-2026-10-16.tar.gz` (41 MB, md5 `55bc367b1930d304ff6ab1ee2ed27d44`, rebuilt 2026-10-17 ~01:01 UTC): `EchoheartsRebearth.uproject` (EngineAssociation 5.8), the complete `Source/Echohearts/` tree (86 code files — today's 33-file framework, the Summoning system, the Corruption system, the Fusion/Residents/Bosses systems, **plus the deep-dive extensions: resident anchor/service tiers and phase-by-phase boss-fight data including nonlethal DefeatKind values**, earlier EcoKin contracts, anti-cheat types, championship TV, release/harvest systems), Config, Content, docs. NOT COMPILED / NOT TESTED — your build is the first proof it compiles.
- **5 Linux launch bundles** already exist as separate .tar.gz files (`files/linux-staged-bundles/`) — those push to the three repos *after* the Windows compile proves the code.

## The sequence
1. **Install UE 5.8.3** from the Epic launcher. If the installer sticks on "Initializing": back up, then clear `C:\ProgramData\Epic\EpicGamesLauncher\Data\Manifests`, and retry (confirmed workaround, filed tonight).
2. **Transfer the project.** Two routes — pick the one you want in chat: **(a)** I generate a download link for the tarball (41 MB) and you extract it to a short path like `D:\Echohearts\`; **(b)** I push the whole project to a GitHub review branch and you clone/pull it on your Windows machine. (GitHub's write path was flaky today, so the download link is the dependable route unless the branch push goes through clean.)
3. **Open `EchoheartsRebearth.uproject`** — it should associate with your 5.8.3 install automatically. Generate Visual Studio project files if prompted, then build (Development Editor, Win64).
4. **What the build proves:** the Frequency Tamer, companion AI, Anima-Link/Kindling/Growth Rites, Summoning, Corruption, Concord Fusion, Sanctuary Residents, and the boss-progression phase data compile. Anything that fails is mine to fix — send me the error log and I'll patch it.
5. **After it compiles:** press Play in the editor. Expect a playable Tamer with companion follow AI; Blueprint widgets, input mapping assets, character meshes, enemy AI, and the interactive Binding ceremony are *not* in this package — those are the next writes, not this weekend's gate.

## Two things that touch this session (your calls, already in the queue)
- **Repo-selection grant** for the two private repos — unblocks the push path so future builds come through Git instead of tarballs.
- **Copilot model pin** — doesn't block compiling, but six models retire Monday Oct 19, the same morning the weekly nudge lands.

## Known, non-blocking
- Target rules use `BuildSettingsVersion.V6` instead of V7/Unreal5_8 — compiles fine on 5.8, flagged for later reconciliation.
- PR #68 merge, index.html picks, Dex rulings — none of them block this weekend's build.

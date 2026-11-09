# Echohearts Assignment — Canon Filing: All Game & Art

© 2026 Into Deep Studios and Donta L. Owens. All rights reserved.

This assignment files **everything** — every game edition and every art/canon asset — into its proper repository and folder, exactly once, under the two-repo rule:

- **Canon / documentation / art source of truth:** `Dlomotion/Echohearts-Rebearth` (this repo)
- **Executable UE 5.8 build target:** `IN2Deep-Studios/ECHOHEARTS-REBEARTH-BUILD-`

It does not create a second roadmap. Status language follows the project rule: nothing is VERIFIED without direct build/test/runtime evidence.

## Assignment Queue

### EH-CANON-001 — Game editions filed in the canon repo
File each playable edition once, in its own folder: `echohearts-rebirth-game/` (2D web), `echohearts-playable/` (single-file), `echohearts-rebirth-3d/` (C++ raylib), `echohearts-servers/` (multiplayer + web + hosting pack).
Acceptance: each folder builds/runs as documented in its README; no edition is duplicated under a second name.
Status: FILED 2026-11-09 (commits 1ad12eb, 58303fc, a762d2e, 0c0462d). UE5.8-runtime verification of the web/C++ editions is by their own tests; see EH-CANON-003 for UE.

### EH-CANON-002 — Retire the duplicate UE project in the canon repo
`echohearts-ue5/` (EchoHeartsRebirth module, created in chat) duplicates the role of the authoritative BUILD project (Echohearts module). Decide: delete it from this repo, or keep it clearly marked as a superseded prototype in its README.
Acceptance: exactly one authoritative UE project remains — the BUILD repo.
Status: DECIDED 2026-11-09 (Owens) — option B taken: `echohearts-ue5/README.md` now carries a SUPERSEDED PROTOTYPE banner pointing to the BUILD repo; the folder is retained for reference, not deleted.

### EH-CANON-003 — BUILD integration files filed in the BUILD repo
File the local-only integration from `A:\ECHOHEARTS-REBEARTH-BUILD-`: `Source/Echohearts/Public/Gameplay/EchoNetworkPayload.h`, `EchoCooperativeWorkstation.h` (+ .cpp), `Private/Tests/EchoNetworkPayloadTests.cpp`, `Public/Storage/EchoPlatformStorageSubsystem.h`, module Build.cs with NetCore, `Docs/CHAT_TO_UE5_INTEGRATION_MANIFEST.md`, `Docs/WINDOWS_PACKAGE_STORAGE.md`, updated `Echohearts-Ecokins/README.md`.
Acceptance: files present in the BUILD repo at the manifest's paths; static contracts + diagnostics (3 tests) re-run; UE 5.8 UHT/compile/PIE remain NOT YET VERIFIED until a real 5.8 Win64 install runs them.
Status: PENDING UPLOAD of Source/ and Docs/ from the local BUILD folder.

### EH-CANON-004 — Canon documents filed by index path
Every canon doc lives at the path named in `MASTER_PROJECT_INDEX.md` (Dex docs under `03_EcoKin_Dex/`, story under `01_Story/`, systems under `04_Systems/`).
Acceptance: no canon doc exists only in chat uploads; index and folders agree.
Status: IN PROGRESS — story integration template filed 2026-11-09 (commit 764af57); remaining index entries to be audited against folders.

### EH-CANON-005 — Art filed under 07_Art with LFS
All game art (sprites, portraits, UI, maps, source media) files under `07_Art/` (canon) and, for the UE project, the BUILD repo's Content — binaries via Git LFS per `.gitattributes` (`*.uasset`, `*.umap`, `*.png`, `*.psd`, `*.fbx`, audio, video).
Acceptance: no art binary committed outside LFS; every Eco-Kin visual links to a valid permanent Dex ID (125-ID Dex unchanged); no duplicate species created from historical names/forms.
Status: DESIGN / NOT YET VERIFIED — audit pending against the Eco-Kin visual archive routing (BUILD repo README points UE5 implementation visuals to the authoritative BUILD project).

### EH-CANON-006 — Duplicates policy
One file, one home. Identical-content copies are removed after a hash check confirms byte-identity and the canonical copy's location is recorded. Working staging mirrors used for safe pushes are tooling, not canon, and are never counted as duplicates. Third-party binaries, installers, and generated docs (e.g. Javadoc jars, Visual Studio installers) are never filed into either repo.
Acceptance: a duplicate scan report exists for both repos; every removal is a recorded commit.
Status: FIRST SCAN DONE 2026-11-09 — uploads and repos contain no identical-content duplicates in canon locations; two non-project uploads (tus javadoc jar, VS installer) held out of the repos under this rule.

### EH-CANON-007 — Legacy descriptors archived, not active
Superseded project descriptors live only under `Archive/` in the BUILD repo (e.g. `Archive/Legacy-5.4/ECHOHEARTS.uproject`).
Acceptance: repo roots contain exactly one active `.uproject` each.
Status: FILED 2026-11-09 (BUILD commit 98a7616).

### EH-CANON-008 — Verification & evidence
Each filed item carries its status honestly: FILED (present + hash-verified), TESTED (named test evidence), or VERIFIED (direct build/runtime evidence per FOUNDATION_STATUS rules). UE 5.8 compile/Editor/PIE/packaging stay NOT YET VERIFIED until run on a machine with UE 5.8 Win64 installed.
Acceptance: no item in this assignment is marked beyond its evidence.
Status: ONGOING RULE.

## Repositories & key paths
- Canon: https://github.com/Dlomotion/Echohearts-Rebearth — index: `MASTER_PROJECT_INDEX.md`; assignments: `11_Daily_Assignments/`
- Build: https://github.com/IN2Deep-Studios/ECHOHEARTS-REBEARTH-BUILD- — status: `FOUNDATION_STATUS.md`; tooling: `BuildScripts/`

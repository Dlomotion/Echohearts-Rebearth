# Echohearts: Rebearth — Visual Studio / Unreal Engine 5.8 Development Workflow

**Status:** ACTIVE TECHNICAL WORKFLOW

**Canonical repository:** `Dlomotion/Echohearts-Rebearth`

**Runtime evidence owner:** the approved executable Unreal checkout (currently routed by the project index to `Dlomotion/ECHOHEARTS-REBEARTH-BUILD-`)

**Host gate:** Windows + Visual Studio 2022 + Unreal Engine 5.8

**Evidence state at publication:** **NOT YET VERIFIED — UE BUILD/RUNTIME EVIDENCE REQUIRED**

This is the Visual Studio execution lane inside the existing Echohearts production workflow. It does not create a second canon, Master Bible, Dex, backlog, daily schedule, or runtime authority. Canon and identity decisions continue to flow through `00_Canon_Lock`, `MASTER_PROJECT_INDEX.md`, the existing production routes, and the 125-ID Permanent Eco-Kin Dex.

## 1. Source-of-truth and intake gate

Before implementation:

1. Record the exact commit SHA and remote URL for every checkout used.
2. Read `00_Canon_Lock/CANON_CORE_RULES.md`, all current canon locks, `MASTER_PROJECT_INDEX.md`, the relevant system/level/technical documents, and the active `11_Daily_Assignments` record.
3. Confirm that IDs 001–125 are not added, removed, renumbered, inferred from names, or overwritten. Missing registry rows are a blocker, not permission to invent them.
4. Route imported chats, ZIPs, templates, Unity material, installed-game files, and examples through existing intake/reconciliation paths. They do not overwrite canon or establish runtime evidence.
5. Preserve the gate order already recorded by the daily workflow: partner-command / VS-AZ-02 evidence, ECO-API-001, the smallest BCT-001 kernel, then dependent runtime work.

## 2. Workstation prerequisites

- Windows 11 or supported Windows 10.
- Visual Studio 2022 with **Game development with C++**, MSVC, Windows SDK, C++ profiling tools, C++ AddressSanitizer (when supported), and Visual Studio Tools for Unreal Engine.
- A licensed, compatible UE 5.8 installation with platform SDKs installed only for platforms the developer is authorized to build.
- Git, Git Credential Manager or approved SSH authentication, and Git LFS.
- At least one real `.uproject` plus its declared module, `Build.cs`, game target, and editor target in the executable checkout.

Run the preflight before generating files:

```powershell
git remote -v
git status --short --branch
git lfs version
git lfs install
git lfs pull
python 09_Technical/Tools/verify_unreal_gate.py preflight --engine-root "C:/Program Files/Epic Games/UE_5.8" --project "<absolute-path-to-approved.uproject>"
```

If the project, module, targets, engine, LFS objects, or required platform SDK are absent, stop with **BLOCKED / NOT YET VERIFIED**. Do not generate substitute gameplay code.

## 3. Branch and Git/LFS workflow

1. Update local `main` without force operations; confirm a clean base and record its SHA.
2. Create a narrow branch such as `feature/<issue>-<scope>`, `fix/<issue>-<scope>`, or `docs/<scope>`.
3. Use LFS for Unreal binary assets covered by `.gitattributes`; verify with `git check-attr -a -- path/to/asset.uasset` and `git lfs ls-files`.
4. Never commit `Binaries`, `DerivedDataCache`, `Intermediate`, `Saved`, local Visual Studio state, packaged output, credentials, SDKs, engine binaries, or files copied from installed third-party games.
5. Keep canon/data changes separately reviewable from runtime code and generated evidence.

## 4. Generate the Visual Studio solution

From an approved runtime checkout:

```powershell
python 09_Technical/Tools/verify_unreal_gate.py generate --engine-root "C:/Program Files/Epic Games/UE_5.8" --project "<absolute-path-to-approved.uproject>" --execute
```

Equivalent Unreal command:

```text
UnrealVersionSelector.exe /projectfiles "<Project>.uproject"
```

Open the generated `.sln`, select the editor target declared by the project, then select **Development Editor** and **Win64**. Generated solution/project files are local artifacts and remain ignored.

## 5. UHT and compile gate

Use the wrapper so the exact command, start/end UTC, exit code, commit SHA, engine version, and log hashes are captured:

```powershell
python 09_Technical/Tools/verify_unreal_gate.py build --engine-root "C:/Program Files/Epic Games/UE_5.8" --project "<absolute-path-to-approved.uproject>" --target "<DeclaredEditorTarget>" --platform Win64 --config Development --execute --evidence-dir "Saved/Verification/<run-id>"
```

The build must execute UnrealHeaderTool where reflected source requires it and complete the Development Editor Win64 target with exit code 0. A generated solution, static scan, IntelliSense success, or standalone CMake test does not clear this gate.

## 6. Editor launch and PIE smoke test

Launch the real editor target:

```powershell
python 09_Technical/Tools/verify_unreal_gate.py editor --engine-root "C:/Program Files/Epic Games/UE_5.8" --project "<absolute-path-to-approved.uproject>" --map "<authored-smoke-test-map>" --execute --evidence-dir "Saved/Verification/<run-id>"
```

Manually verify and record:

- the required authored map loads without fatal errors;
- PIE runs for at least 30 seconds;
- player move/look/jump and controller navigation work;
- one NPC navigates a reachable path and handles an unreachable goal safely;
- a training dummy receives a hit, reports location, reacts, and resets;
- the current partner-command gate behaves as its acceptance criteria require;
- Issue #10 animation/terrain-contact/Kindling checks are performed only when the required authored assets exist.

Screenshots and notes support the log but do not replace it. Record failures as FAIL and missing assets/prerequisites as BLOCKED.

## 7. Automation tests

Run the smallest current bounded test first, then the approved suite:

```powershell
python 09_Technical/Tools/verify_unreal_gate.py automation --engine-root "C:/Program Files/Epic Games/UE_5.8" --project "<absolute-path-to-approved.uproject>" --tests "Echohearts.Partners.CommandBuffer" --execute --evidence-dir "Saved/Verification/<run-id>"
```

A zero-test run is FAIL. Preserve Automation reports and editor logs. Standalone `09_Technical/MetaSystems` CMake/CTest results prove only that isolated target, never Unreal gameplay.

## 8. Development Win64 package and launch

```powershell
python 09_Technical/Tools/verify_unreal_gate.py package --engine-root "C:/Program Files/Epic Games/UE_5.8" --project "<absolute-path-to-approved.uproject>" --platform Win64 --config Development --execute --output-dir "PackagedOutput" --evidence-dir "Saved/Verification/<run-id>"
```

The package gate requires cook, build, stage, archive, an exit code of 0, and launch of the packaged executable. Validate the smoke path again in the package. Packaging output is not committed.

## 9. Debugging in Visual Studio

- Use **Development Editor / Win64** for day-to-day debugging.
- Set the editor project as startup only after verifying the declared target.
- Pass the absolute `.uproject` as a command argument when the generated solution does not configure it.
- Break on first-chance C++ exceptions only when useful; capture call stacks, module symbols, reproduction steps, and logs.
- Use Unreal Insights and Visual Studio profiling for measured performance claims. Do not call code optimized without a recorded baseline and comparison.
- Use DebugGame Editor only for a focused game-module debugging need; do not use it as the default evidence configuration.

## 10. Pull request and evidence flow

Before pushing:

```powershell
git status --short
git diff --check
git lfs status
python 09_Technical/Tools/verify_unreal_gate.py contract --project "<absolute-path-to-approved.uproject>"
```

The PR must state:

- base and head SHA;
- issue/assignment and affected source-of-truth documents;
- files/classes/functions changed;
- exact commands, platform, engine version, start/end UTC, exit codes, and log/report locations;
- separate results for contract, UHT/compile, editor/PIE, automation, packaging, packaged launch, network/save/profile gates;
- remaining FAIL, BLOCKED, REVIEW_REQUIRED, and NOT_RUN items;
- whether any canon, Dex, or data change is included.

Require review before merge. Never force-push shared `main`; never treat a merged PR or green lightweight CI check as proof of UE runtime behavior.

## 11. Platform matrix

Visual Studio + Development Editor Win64 is the mandatory first runtime gate. Other platforms reuse the same source and evidence vocabulary, but each is independently **NOT YET VERIFIED** until built and run with its authorized toolchain and target hardware.

| Platform | Host/toolchain | Evidence required |
|---|---|---|
| Windows | Visual Studio 2022, UE 5.8, Win64 SDK | UHT, Development Editor Win64, PIE, automation, Development Win64 package, packaged launch |
| Linux | Supported compiler/SDK on an approved host or cross-toolchain | target compile, cook/package, native launch, tests, logs |
| macOS | Xcode and supported macOS SDK on Apple hardware | target compile, editor/runtime tests where supported, package/sign/notarize as applicable |
| Xbox / WinGDK | Authorized GDK, Unreal platform access, target hardware | platform compile/package/deploy, certification-oriented checks, device logs |
| PlayStation | Authorized SDK, Unreal platform access, target hardware | platform compile/package/deploy, TRC-oriented checks, device logs |
| Nintendo | Authorized SDK, Unreal platform access, target hardware | platform compile/package/deploy, lot-check-oriented checks, device logs |
| Android | Supported Android SDK/NDK/JDK and devices | cook/package/install, device launch, input/performance logs |
| iOS/iPadOS | Xcode, signing assets, Apple hardware/devices | cook/package/sign/install, device launch, input/performance logs |

Do not commit platform SDKs, signing keys, certificates, provision files, installed-game manifests, or vendor binaries. A Win64 pass does not verify another platform.

## 12. Evidence vocabulary

- **VERIFIED** — the exact stated check executed successfully against the recorded SHA/platform/configuration and its evidence is retained.
- **NOT YET VERIFIED** — the check has not produced acceptable direct evidence.
- **PASS** — an executed check met its bounded acceptance criteria.
- **FAIL** — an executed check returned an error or missed acceptance criteria.
- **BLOCKED** — a required project/module/asset/toolchain/license/SDK/hardware prerequisite is unavailable.
- **REVIEW_REQUIRED** — human canon, identity, security, licensing, art, or semantic review remains.
- **NOT_RUN** — the check was not executed.

Verification is scoped: `Development Editor Win64 compile VERIFIED` does not imply PIE, package, networking, saves, performance, security, or other platforms are verified.

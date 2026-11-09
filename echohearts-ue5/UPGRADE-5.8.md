# Upgrading EchoHearts Rebirth to Unreal Engine 5.8

From the original 5.4 project to **UE 5.8** (released 2026-06-17; described in migration guides as the last planned UE5 release). Compiled against 5.8 build settings — if your first 5.8 build throws an error, paste it back and it will be fixed.

## What changed in this update

| File | Change |
|---|---|
| `EchoHeartsRebirth.uproject` | `EngineAssociation` 5.4 → **5.8** |
| `Source/*.Target.cs` (both) | `BuildSettingsVersion.V5` → **V7**, `IncludeOrderVersion` → **Unreal5_8** |
| `EchoHeartsRebirth.Build.cs` | Explicit `CppStandard = Cpp20` (the 5.8 default) |
| `EchoHeartsCharacter.h/.cpp` | **Enhanced Input support** (UE 5.8 path): optional mapping context + Move/Look/Jump/Fire/Burst actions, bound when assigned in a Blueprint child; legacy `DefaultInput.ini` bindings remain as a fallback |
| `README.md`, `Content/README.md` | 5.8 requirements, toolchain note, Enhanced Input setup steps |

Gameplay code (stats, enemies, boss, pickups, GameMode) needed no API changes for 5.8.

## Upgrade steps on your machine

1. **Keep UE 5.4 installed** until the 5.8 build is confirmed — parallel installs are your safety net. Optionally tag or branch the 5.4 state in Git first.
2. Install **UE 5.8** from the Epic Games Launcher, and the latest Visual Studio with **Game development with C++**. Migration guides note 5.8 prefers the newer MSVC v145 toolset (Visual Studio 2026 generation); VS 2022 / v143 may warn it is not preferred.
3. In the project folder, delete `Binaries/`, `Intermediate/`, `Saved/`, and `.vs/` (all regenerated; all already git-ignored).
4. Right-click `EchoHeartsRebirth.uproject` → **Switch Unreal Engine version… → 5.8** if prompted, then **Generate Visual Studio project files**.
5. Open the new `.sln`, build **Development Editor | Win64**, fix nothing expected — open the editor and create the level/input assets per `Content/README.md` if you have not already.
6. Optional but recommended on 5.8: set up the Enhanced Input assets (step 4 of `Content/README.md`) so the project no longer relies on legacy input.

## Sources for the version facts in this file
- UE 5.8 release timing and build-setting values (`V7`, `Unreal5_8`) — community migration notes for 5.7 → 5.8 projects, cross-checked across multiple guides in November 2026.
- Treat exact patch versions (5.8.x hotfixes) as “install the latest 5.8” — this project does not pin a hotfix.

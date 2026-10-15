---
applyTo: "**/*.h,**/*.hpp,**/*.cpp,**/*.cs,**/*.uproject,**/*.ps1,09_Technical/Tools/**/*.py,.github/workflows/**/*.yml,.github/workflows/**/*.yaml"
---

# Public repository C++ / Unreal contract

This repository is the public canon, systems, production-contract, and coordination authority. The executable UE5.8 runtime/evidence authority is `Dlomotion/ECHOHEARTS-REBEARTH-BUILD-`.

When touching Unreal/C++ scaffolding here:
- keep Engine target 5.8, project/target family `EchoheartsRebearth`, runtime module `Echohearts`, and export macro `ECHOHEARTS_API`;
- do not reintroduce `UE4Editor.exe`, EngineAssociation 5.4, `Source/EchoheartsRebearth/`, or `ECHOHEARTSREBEARTH_API` into active production contracts;
- do not create a second executable truth that diverges from the build repository;
- use UnrealBuildTool as the build orchestrator; UBT invokes UHT and the platform C++ compiler;
- standalone g++/clang++/MSVC tests are language/toolchain smoke tests only, never Unreal proof;
- use Epic's documented `Automation RunTest` command form and retain `-ReportExportPath` evidence when running Automation;
- treat exit codes as tool-specific; exit code 0 is process success only;
- preserve Vibrance, Density, Harmony, Purity and the Anima-Link contract;
- never call runtime/save/networking/AI/gameplay VERIFIED without direct evidence.

PR dependency rule: executable UE5.8 foundation and compiler-driver evidence precede Issue #10 runtime proof; broad platform/runtime validation follows the proven slice; EPUB/publication validation is a separate evidence lane.

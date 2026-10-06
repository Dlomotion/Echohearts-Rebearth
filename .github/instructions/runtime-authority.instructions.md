---
applyTo: "**/*.uproject,Source/**/*.cs,Source/**/*.h,Source/**/*.hpp,Source/**/*.cpp,BuildScripts/**,package_*.ps1,.github/workflows/**/*.yml,.github/workflows/**/*.yaml"
---

# Public repository runtime-authority boundary

This repository owns Echohearts canon, systems, Dex, production contracts, publication, and public coordination. The executable UE5.8 runtime/build/evidence authority is `Dlomotion/ECHOHEARTS-REBEARTH-BUILD-`.

When working on executable-looking files here:
- do not create a second active runtime module, compiler driver, package pipeline, or UE build authority;
- compare against the BUILD repository before changing anything;
- treat historical/bootstrap Unreal files as migration/reconciliation material unless the user explicitly changes repository authority;
- move reusable runtime fixes to BUILD and keep only contract/documentation material here where possible;
- preserve project/target family `EchoheartsRebearth`, runtime module `Echohearts`, and export macro `ECHOHEARTS_API`;
- do not claim UHT/compile/editor/package/runtime success from repository presence.

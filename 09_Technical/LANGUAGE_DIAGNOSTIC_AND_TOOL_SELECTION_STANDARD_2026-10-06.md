# Echohearts: Rebearth — Language Diagnostic & Tool-Selection Standard

**Date:** 2026-10-06  
**Status:** TECHNICAL CONTRACT  
**Runtime authority:** `Dlomotion/ECHOHEARTS-REBEARTH-BUILD-`  
**Canon/contracts authority:** `Dlomotion/Echohearts-Rebearth`

## Purpose

Echohearts code repair is **language-aware, not language-random**. A programming language is selected because the failing file, toolchain, platform bridge, service, test harness, build system, or migration actually uses that language. Do not translate working UE5.8 C++ into an unrelated language merely because that language appears in a reference list.

When an error occurs:

1. identify the exact failing command/tool and file;
2. identify the source language and build/runtime layer;
3. read the diagnostic immediately above the exit code;
4. inspect call sites, headers/interfaces, build rules, dependencies, tests, and generated/reflection boundaries;
5. repair the root cause in the language that owns that layer;
6. run the smallest relevant static/test/build gate;
7. report what passed and what remains NOT YET VERIFIED.

Exit codes are tool-specific. Exit code 2 has no universal root cause.

## Production language ownership

### UE5.8 runtime and high-performance gameplay
- **C++** — primary Echohearts runtime/gameplay language.
- **C** — permitted for third-party/native boundaries or low-level libraries only when actually required.
- **Assembly** — profiling/diagnostic or tightly justified platform-specific optimization only after measurement; never the default gameplay layer.
- **UnrealScript** — historical reference only; UE5.8 gameplay is C++/Blueprint, not UnrealScript.

### Unreal build/config/tooling
- **C#** — Unreal TargetRules/ModuleRules (`.Target.cs`, `.Build.cs`) and approved .NET tooling.
- **Python** — repository validation, build orchestration, data conversion, QA tooling, automation helpers.
- **PowerShell** — Windows/UE build and packaging orchestration.
- **Bash / Zsh** — Unix/macOS/Linux CI and developer automation.
- **Nix** — only if an actual reproducible Nix environment is adopted.
- **Groovy** — only where an actual Gradle/Groovy build surface requires it.
- **Tcl** — only for an actual embedded/tooling dependency.

### Web / companion / presentation
- **JavaScript / TypeScript** — primary browser/application behavior where the web repository uses them.
- **HTML / CSS** — markup/style technologies; not general-purpose programming languages, but first-class web implementation formats.
- **WebAssembly (Wasm)** — portable binary instruction format/compilation target; use only when a measured web workload benefits from compiled modules.
- **PHP / Ruby / Hack / Haxe / Elm** — only if an actual owned web/service component uses them; do not introduce them merely to solve a JavaScript/TypeScript error.

### Platform-native bridges
- **Swift / Objective-C** — Apple-native bridge/app code when required by a supported Apple target.
- **Kotlin / Java** — Android-native bridge/app code when required by a supported Android target.
- **Dart** — only if an approved Flutter companion application exists.
- **QML** — UI declaration technology only for an approved Qt-based tool/app.

### Backend, services, data, and analytics
- **Go / Rust / Java / C# / Python / Clojure** — choose according to the service that actually owns the failing code; do not create duplicate services in different languages.
- **SQL** — relational query/schema work; treat SQL as a domain-specific data language.
- **R / Julia / MATLAB / Fortran** — analytics/scientific/simulation work only where a defined pipeline needs them.
- **Q** — kdb+/time-series work only if that technology is actually adopted.
- **XQuery** — XML query/transformation only where XML is an owned data format.

### Systems / research / embedded languages
The following may be used when a real component is intentionally implemented in them or for contained research/verification, but they are not default Echohearts runtime dependencies:
**Ada, Clojure, D, Crystal, Elixir, Erlang, F#, Haskell, Idris, Koka, Lua, Mojo, Nim, OCaml, Odin, Scala, V, Vala, Zig.**

**Lua** may be used only if Echohearts deliberately adopts an embedded scripting/plugin boundary; do not add a Lua runtime merely to avoid fixing C++.

### Historical / legacy / educational languages
Use these to diagnose or migrate actual legacy source, study language concepts, or preserve provenance. Do not add them to the UE runtime solely as an error workaround:
**ActionScript, ALGOL, APL, B, BASIC, BCPL, COBOL, Delphi/Object Pascal, Eiffel, Factor, Fantom, Forth, Inform, Io, Lisp, Logo, ML, Pascal, Perl, Prolog, Racket, Raku, Scheme, Smalltalk, Visual Basic/.NET.**

### Specialized/restricted-domain languages
Use only when the project deliberately owns that domain:
- **Solidity / Yul** — smart-contract/EVM work; not an Echohearts gameplay dependency.
- **Q#** — quantum-computing research only.
- **GML** — GameMaker-specific; not an Unreal runtime language.
- **Scratch** — educational reference only.
- **Brainfuck** — esoteric/reference only; never production or CI dependency.

### Naming correction
The common APL-family language is **J**. “JApp” should not be treated as an Echohearts production-language requirement unless a specific tool/project with that exact name is identified.

## Cross-language repair rule

A C++ compiler error is repaired in C++/Build.cs/Target.cs/config as appropriate.  
A Python CI traceback is repaired in Python.  
A shell parsing error is repaired in the shell actually executing the step.  
A JavaScript/TypeScript frontend error is repaired in its web layer.  
A SQL/schema error is repaired in the data layer.  
A platform-native error is repaired in the platform bridge that owns it.

Do **not** route the same error through COBOL, BASIC, Rust, Go, Python, Java, and C++ sequentially. Multiple languages are useful when the system genuinely has multiple layers, not as interchangeable syntax patches.

## Echohearts invariants during any language repair

- preserve Rebearth / Eco-Kin / Frequency Tamer / Core-Binder nomenclature;
- preserve Vibrance, Density, Harmony, Purity;
- preserve Anima-Link and Huma-Link boundaries;
- preserve the 125-ID Permanent Dex;
- preserve server/save authority where state is authoritative;
- preserve Eco-Kin agency and non-coercive Kindling;
- do not fabricate runtime, build, networking, save, performance, or platform evidence.

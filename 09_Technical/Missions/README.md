# Mission registry patch (Issue #84)
This is a **draft intake patch**, not approved narrative canon or a completed UE integration. It preserves 42 Chronicle IDs, 14 Anomaly IDs, 199 ordinary Eddy IDs, and Eddy 200 as a secret finale. Nineteen source-described missions are drafts; 237 slots are placeholders.

`EchoheartsMissionRegistry.hpp` is a dependency-free C++17 registry and progression kernel. It deliberately does not add a new Unreal module, UCLASS, creature registry, save profile format, or cloud endpoint until the existing project interfaces are audited. A UE5.8 subsystem adapter must translate IDs and completion events into the existing SaveGame/Anima-Link/Binding systems. The current progress model tracks mission completion only, not partial objective counters.

Compile smoke test where a C++17 compiler is available:
```sh
c++ -std=c++17 -I09_Technical/Missions 09_Technical/Missions/MissionRegistrySmoke.cpp -o /tmp/echohearts-missions-test
/tmp/echohearts-missions-test
```

**Review gates:** reconcile provisional source terminology/locations and NPCs with the existing story bible; ensure nonlethal purification, no unapproved Eco-Kin Dex additions, and preserve Vibrance/Density/Harmony/Purity. Wire the objective system, rewards, UE SaveGame persistence, and Blueprint-facing events in a subsequent reviewed integration. Validate with actual UE5.8 UHT/compiler and runtime before calling this game-ready.

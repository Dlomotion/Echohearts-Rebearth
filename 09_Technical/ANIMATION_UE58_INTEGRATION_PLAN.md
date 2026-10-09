# Unreal Engine 5.8 animation integration plan
Status: SPECIFICATION ONLY — NOT UHT/UBT/PIE VERIFIED.

Canonical runtime module is **Echohearts**, from EchoheartsRebearth.uproject in Dlomotion/ECHOHEARTS-REBEARTH-BUILD-. Keep Source/Echohearts/Echohearts.Build.cs and ECHOHEARTS_API; do not introduce an incompatible EchoheartsRebearth module from pasted drafts.

Gameplay imports: approved rigged mesh/skeleton and animation sequences → animation Blueprint/state machine → animation montages and notifies → authoritative gameplay event validation → Niagara/audio → save/replication tests. Cinematic imports: approved rendered video through supported media playback or 3D animation through Level Sequence. Image-to-video output is not skeletal data.

Pasted draft audit:
- Build.cs: wrong module/class/path; speculative module dependencies and target flags. Add only modules needed by actual source/plugin APIs.
- SaveLoadComponent: malformed #include lines; wrong export macro; unvalidated slot path, UserIndex, and finite metrics; no format version, record integrity, atomic write, actual compression, cloud conflict strategy, or proper save/load round trip. Prefer USaveGame/UGameplayStatics save-slot abstraction for first pass; isolate authenticated cloud-sync transport. Do not combine network diagnostics and persistence in one component.
- Performance function: unused MemoryBudgetLimitMB, no memory measurement, and one frame > 33.3ms is not a sustained 30 FPS assessment. Profile measured frame-time distributions separately.
- HLSL: sample color modulation is neither Niagara binding nor bone transformation; hardware FPS limit is not actual runtime frame time. Use parameterized material functions and Niagara scalability profiles; do not claim this shader implements animation.
- Python: invalid concatenated imports, missing FPS membership values, incorrect __name__ guard, insufficient schema validation. Static manifest checks cannot prove UBT, PIE, crossplay, or packaging.
- Standalone C++ token utility: malformed template declaration and string-to-char conversion; arbitrary character-to-integer mapping is unrelated to build compliance and should not enter Unreal source.

Validation gates: schema/unit tests (offline) → UBT/UHT on actual UE5.8 runner → Editor compile/launch → PIE animation and Anima-Link behavior → save/load recovery → multiplayer authority → packaged runtime → platform-specific QA. Steam/console/mobile certification cannot be inferred from static checks.

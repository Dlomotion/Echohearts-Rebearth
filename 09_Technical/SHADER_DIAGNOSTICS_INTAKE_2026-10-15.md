# Shader diagnostics intake and correction — 2026-10-15

**Status:** corrected offline prototype; local Python execution evidenced; NOT UE5.8 VERIFIED.

## Inspected artifact
Existing Echohearts-Linux-Preview source package, baseline local commit `1185132c8421b1eee7f07e3fe84f3b081096c010`. Inspected shader_diagnostics.py, tests/test_shader_diagnostics.py, SHADER-DIAGNOSTICS.md and repository status. Local repository had no remote and was clean before work; no repository was initialized or created.

## Corrected engineering defect
NaN supplied as the observation clock made both stale/future comparisons false, permitting REPORTED_IDLE. Also, malformed expected identity could raise TypeError or be accepted as a misleading mismatch. Correction:
- Validate exact expected dictionary shape and bounded string values.
- Accept only finite, nonnegative numeric clocks at most 2^53-1, excluding Boolean/string inputs.
- Apply validation to the default clock source as well as explicit clocks.
- Keep gameplay_verified/cache_contents_verified false and retain missed/late warnings.

Three new unittest methods cover invalid/nonfinite clocks, malformed expected identities and invalid default clock. Baseline shader regressions failed with 9 failures/2 errors across subcases (16 methods total). After correction, full suite: **40 unittest methods, 4.051 seconds, exit 0**. Split: 24 launcher + 16 shader methods. Earlier “37 tests” was combined-suite coverage, not 37 shader tests. No fixture or harness proves an Unreal package.

## Source and artifact evidence
- Branch: `fix/shader-clock-validation-2026-10-15`; scoped local commit `e80580464cc6f5acf93dfceef72ae37841143287`.
- Command: `python3 -m unittest discover -s tests -v` under source directory; raw summary: `Ran 40 tests in 4.051s / OK`.
- git diff --check: exit 0; reviewed diff includes only inspector, shader tests and shader documentation.
- Updated existing source ZIP; no new project/workflow. ZIP SHA-256: `78b4f4cc4b551e1e721d9505c28ca5f338a6653850c70754e1a4692a2a410eed`.
- Inspector SHA-256: `c577735b4998461eb4df28450f9c247e800aed109f392d2824122b092d57943b`.
- Shader tests SHA-256: `183c6fb401b3e594db4c30423f5784b0e5a9281ed41423b34fefaa8e20698040`.
- Reviewer: Codex; date 2026-10-15; environment local Linux/Python 3.12. No GitHub push/CI for this source package is claimed. Executable Unreal integration belongs in BUILD once accessible.

## Foreign resource intake boundary
Supplied minified Unity Ads/WebView text is third-party reference material with unverified license/provenance. It was neither executed nor copied into the prototype. Numeric renderer IDs, PSO counts, completed flags and failure signatures do not establish engine identity, platform correctness, security attestations or gameplay success. No XDF/XDT/Lua containers or binary cache were unpacked.

## UE producer and performance gate
Snapshot producer remains absent. Do not fabricate unavailable validation counters as zero. An actual producer must map the installed UE version's API/counters, define sample scope, use appropriate engine-thread ownership, and include build/session context. Schema v1 has no session identifier; cross-session replay remains unresolved and requires a versioned schema/producer design before any session-scoped claim.

Epic documents FShaderPipelineCache::NumPrecompilesRemaining(), PSO validation and Insights. Pending zero is a momentary observation, not proof of future traversal. Missing/late PSOs, driver retrieval cost, memory pressure, material permutations, Niagara and platform RHI support require real captures. Never auto-clear a user's cache; cold-cache trials must be controlled and explicitly scoped.

Current inspector validates reported identities, not authentic cache contents or trusted telemetry. No network/credentials are involved. Schema is intentionally fail-closed for unavailable required values. Clock validation addresses one concrete defect; it does not authenticate records.

## Research / rights checked 2026-10-15
- Official Epic UE5.8 PSO precaching: <https://dev.epicgames.com/documentation/en-us/unreal-engine/pso-precaching-for-unreal-engine>. Reference only, no proprietary code copied. Relevant API/cvars must be checked against installed engine before use.
- Official announcements: <https://forums.unrealengine.com/c/general/announcements/49>. New Fab/UEFN entries do not establish a new UE5.8 engine change.
- Existing package is original project prototype code; correction uses Python standard-library validation. No third-party implementation imported.

## Exact next engineering action
Restore BUILD/patch access; bind the corrected inspector to a versioned real UE5.8 snapshot producer using actual module/API/Build.cs evidence, resolve session/context/counter scope, then retain Windows UHT/UBT + packaged cold/warm traversal logs and Insights captures. Do not advance production status from synthetic telemetry.

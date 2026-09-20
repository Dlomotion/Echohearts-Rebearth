# Legacy Parts 258–272 Code Audit — 2026-09-20

Status: **REFERENCE-ONLY / ACTIVE CORRECTION**
Verification: **NOT YET VERIFIED**
Production runtime: **Unreal Engine 5.8**

This audit covers the historical HTML/CSS dashboard, JSON exporter, S3 deployment script, CloudWatch telemetry script, companion tracking, stealth, volumetric-cloud code, smoke tests and raw UDP network stress script supplied in the repost batch.

## Global correction

Historical statements such as `production-ready`, `fully compiled`, `verified`, `bulletproof`, `secure`, `zero stutter`, `finalized` and claims of 258–272 completed modules are **not evidence**. None of those claims are accepted without repository/build/test/profile evidence.

No code in this batch jumps the current technical gate order.

## Part 258 — static dashboard

Useful ideas:
- lightweight responsive documentation UI
- CSS Grid / custom properties
- human-readable system cards

Corrections:
- hard-coded engineering values are documentation only, not authoritative runtime truth
- altitude and grid values must come from approved data/contracts before publication
- hover-only interaction cannot substitute for keyboard/focus/accessibility states
- `Echoheart` naming must be normalized to the approved Echohearts naming where applicable
- copyright footer cannot claim compilation/security status without evidence

## Part 259 — JSON exporter

Issues:
- manual JSON string concatenation is brittle and easy to invalidate
- output directory creation/error handling is absent
- source headers/types are assumed rather than proven present in the current project
- `compiledModules` is a self-asserted number, not a verified build fact
- hard-coded system constants risk drifting from runtime data

Preferred direction if this feature becomes necessary:
- serialize structured data with Unreal JSON utilities or an approved data export pipeline
- export only approved non-secret design metadata
- create/check destination directory and handle write failure
- generate from source-of-truth Data Assets/Tables/config, not duplicated hard-coded constants

## Part 260 — S3 deployment

Issues:
- `--acl public-read` is not a safe universal deployment pattern and conflicts with modern S3 Block Public Access / Object Ownership configurations
- unattended `--delete` can remove remote files if local state is wrong
- no environment separation, dry run, artifact integrity check or deployment approval gate
- no CloudFront/private-origin strategy is defined

Treat as a historical deployment sketch only. Do not deploy production infrastructure from it.

## Part 263 — CloudWatch telemetry

Issues:
- the historical metadata URL is malformed/incomplete
- modern EC2 Instance Metadata commonly requires IMDSv2 token handling
- summing `WorkingSet` for all processes does not measure the dedicated Echohearts server process
- infinite 10-second custom metric posting can create cost/noise and lacks backoff/error handling
- no credential/role validation, region handling, batching or metric-cardinality governance

Prefer platform-native agents/exporters or a bounded telemetry process tied to the actual server process and infrastructure design.

## Part 264 — companion tracker

Issues:
- `GetFirstPlayerController()` is invalid ownership logic for multiplayer companion assignment
- companion-owner identity must come from replicated authoritative ownership/party state
- `HasAuthority()` usage on the component as written may not compile as assumed; authority should be derived through the owning Actor/current UE API
- issuing `MoveToActor` every 0.2 seconds can create pathfinding churn
- fixed speed mutation bypasses movement-state policy and network smoothing concerns
- no nav/path failure handling, obstacle behavior, teleport recovery or late-join ownership restore

Useful principle retained: avoid per-frame path queries; evaluate follow state at bounded intervals/events.

## Part 265 — companion smoke test

Critical failures:
- `UTransientBufferUtil::GetMockWorld()` is an unverified helper and likely nonexistent in the current project
- the test returns `true` when the world cannot initialize, creating a false pass
- it attempts to call a routine that is not exposed as a public test seam in the provided declaration
- no target pawn/AIController/path is configured, so the behavior under test is not meaningfully exercised
- `Duration > 0` does not verify correctness, deadlock freedom, memory safety or pathing behavior

This is a pseudo-test, not verification.

## Part 266 — stealth component

Issues:
- client-facing RPC arguments include world/time/concealment facts the server should resolve itself
- client-provided target coordinates and `SoundRadius` require strict validation/clamping and capability/cooldown checks
- generic Actor string tags are not a complete stealth/perception model
- forcing AI movement directly to a noise point bypasses richer AI Perception/behavior logic
- no team/faction authority, LOS/light exposure, occlusion, material/surface noise or anti-spam rules

Preferred direction: server-derived stealth state + AI Perception/hearing + validated distraction action through a player-owned replicated Actor/Component.

## Part 267 — stealth smoke test

Critical failures:
- same unverified transient-world helper
- false pass if world creation fails
- invokes server RPC implementation path as a local loop without validating networking
- always passes `bIsCrouchingInsideStructure=true`, so expected state never meaningfully alternates
- `Duration > 0` is not a correctness assertion

## Part 268 — volumetric-cloud subsystem

Issues:
- lifecycle/API signatures must be checked against UE5.8; the supplied override cannot be assumed correct
- the code calculates a density but does not actually apply it
- the commented `SetMaterialParameterScalar` call is not evidence that the component exposes that API
- weather uses free-form strings instead of controlled IDs/tags/data
- no material-instance/parameter-collection ownership contract exists

Useful concept retained: weather should drive data-controlled cloud/material parameters without runtime shader recompilation.

## Part 271 — sky smoke test

Critical failures:
- false pass when world/subsystem is missing
- tests CPU loop duration rather than visual/material result
- no cloud component/material is registered
- does not prove render-thread behavior, shader stability, memory safety or frame-time cost

## Part 272 — network stress script

Critical failures:
- four arbitrary UDP bytes are **not** a valid Unreal connection handshake
- socket `Send()` success does not mean the Unreal server accepted, authenticated, parsed or replicated a connection
- zero local socket exceptions does not prove zero packet loss
- the script measures client-side datagram dispatch, not server capacity/security
- no server telemetry, net-driver stats, login lifecycle, replication, disconnect cleanup or connection-throttling evidence is captured

Do not use this script to claim network capacity, security, connection success or Unreal handshake validity.

## Current engineering priority

Do not implement replacements for these historical modules until dependencies require them. Preserve only the transferable requirements in backlog form.

Current gate order remains:

1. Authorized UE5.8 `EchoheartsEditor` build.
2. `Echohearts.Partners.CommandBuffer` Automation evidence.
3. Reload/recovery/travel/reconnect/late-join tests at 150/250/350 ms.
4. `ECO-API-001` shared result-event envelope.
5. Smallest `BCT-001` reservation/commit/rollback kernel.
6. One BuildPiece and one CraftRecipe end to end.
7. Promote one dependency-ready legacy feature at a time.

## Acceptance rule

A legacy feature can move from REFERENCE-ONLY only after:
- current UE5.8 API review
- actual project dependency inspection
- minimum justified implementation
- compile success
- functional/automation test with meaningful assertions
- multiplayer/save/recovery checks when relevant
- profile evidence when performance is claimed

© 2026 Into Deep Studios and Donta L. Owens. All rights reserved.

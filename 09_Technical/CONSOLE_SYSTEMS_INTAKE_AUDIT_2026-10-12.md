# Console Systems Intake Audit — 2026-10-12

**Status:** PROPOSAL / ENGINEERING INTAKE — repository-checkable text only  
**Runtime gate:** NOT YET UE5.8 VERIFIED  
**Build target:** `Dlomotion/ECHOHEARTS-REBEARTH-BUILD-` when access and a real UE5.8 foundation are available  
**Canon constraints:** nine Essences; only Vibrance, Density, Harmony, Purity; consent-led Kindling; Anima-Link strain affects player, partner, survival, work, and care.

This audit routes the submitted console/system snippets into the existing technical lane. It does not establish a second implementation track. The BUILD repository and reported PR #51 “87 native checks” were inaccessible to the GitHub connector on 2026-10-12 (HTTP 404), so its head, files, tests, and CI remain **NOT YET VERIFIED**. A 404 is an access result, not evidence of deletion.

## Smallest corrected engineering deliverable

A standalone C++17 reference test corrected the supplied day/night clock contract.

```text
gameHoursAdvanced =
    realDeltaSeconds * gameMinutesPerRealSecond / 60.0

newAbsoluteHour = currentHour + gameHoursAdvanced
crossedDays     = floor(newAbsoluteHour / 24.0)
wrappedHour     = fmod(newAbsoluteHour, 24.0)
```

The source validates finite/nonnegative inputs, requires `currentHour` in `[0,24)`, supports multi-day deltas, guards day-counter overflow, and leaves state unchanged on rejection. Test cases cover a four-second step at **1.0 game minute per real second**, a full-day jump, negative delta, and NaN.

- Compiler: `g++ (Ubuntu 13.3.0-6ubuntu2~24.04) 13.3.0`
- Command class: C++17, `-Wall -Wextra -Werror -pedantic -fsanitize=undefined`
- Result: **COMPILED AND EXECUTED AS A GENERIC C++17 REFERENCE; UBSan exit 0**
- Earlier test failure retained as useful evidence: passing `60` while expecting four game minutes exposed the source contract's unit error. At 60 game-minutes/real-second, the supplied formula advances one game-hour per real-second.
- Address/LeakSanitizer was not an evidence gate in this container: LeakSanitizer stopped on a restricted `ptrace`/`/proc` environment condition. No pass is claimed.
- This is **NOT UHT/UBT, Editor, PIE, cook, package, save, network, or platform evidence**. Executable source belongs in BUILD after access is restored.

## Batch disposition

| Submitted area | Blocking finding | Required Echohearts adaptation | Status |
|---|---|---|---|
| Day/night + console audio | Concatenated includes; unit mismatch; single-day wrap; threshold events can be skipped; print-only audio | Authoritative world clock, multi-threshold event replay policy, save versioning, game-thread timer/event delivery, MetaSound/audio implementation | Corrected reference only |
| Merchant purchase | Open-hours check does not prove funds deduction, stock reservation, ownership, or transaction atomicity | Server-resolved merchant/stock/player state; idempotent reserve/commit/rollback; canonical item data | Rejected as runtime code |
| Crafting map | `operator[]` can insert missing keys; duplicate ingredients can underflow; negative/overflow values; output granted before craft time; no replay protection | Aggregate requirements, checked arithmetic, recipe/version authority, queued completion, idempotency, save recovery | Rejected as runtime code |
| Static AABB collision | Axis-aligned overlap is neither swept nor continuous and cannot prove rotated/snap-gate placement | Server-side swept/shape query, ownership and socket resolution, collision channels, rollback-safe placement | Proposal only |
| HUD/performance snippet | Truncated/noncompiling path; zero/NaN bar widths; fabricated performance values; raw mutable state | Typed view-model/events, bounds and accessibility, Unreal Insights/stat evidence | Rejected as evidence |
| Debug shell | Signed-char `tolower` risk; unbounded coordinates/quantity; no authentication/authority | Development-only commands, explicit parsing/ranges, permission gates, server-side resolution, shipping exclusion | Quarantine |
| Trap loop | Can continue after trigger and process multiple overlaps; encodes forced capture | One idempotent welfare-field activation; Observe/Protect/Calm/Kindle/Bond, Release, or Defer | Mechanic rewritten |
| Loot RNG | New RNG each call; invalid chance/range not rejected; nondeterministic; loot from trapped sentient subject | Deterministic authored streams for tests, server authority, habitat/resource rewards—not sentient extraction | Rejected as written |
| DNA/breeding/Primal stats | Conflicts with consent, breeding/fusion restrictions, nine-Essence authority, and four-attribute contract | Biomimetic Shifts/Great Bloom only after canon review; Vibrance/Density/Harmony/Purity; no coercive inheritance | Retire/redesign |
| Launch sphere/pod | Capture/storage semantics and implicit ownership conflict with canon | Existing A.E.G.I.S. **Echo Cradle** recovery/relocation contract in `04_Systems/AEGIS_ECO_DEVICE_RECONCILIATION.md` | Proposal routed |
| Compact packets/raw sockets | `sizeof` is not NetSerialize wire size; raw `memcpy` of USTRUCT is unsafe | Unreal replication/Online Services first; otherwise explicit framing/version/length/checksum, bounded queues, graceful thread stop, no off-thread UObject access | Not accepted |
| Voxel/cavern/worker/UI/editor/shader batch | Foundation/API/module/runtime evidence missing | Resolve actual macro/Build.cs; deterministic seed/hash contract and allocation guards; event-driven care-aware workers; typed UI; Editor module transactions; profiled material functions/Niagara | Deferred behind foundation |

## Clock port contract for Unreal

- Prefer a `UWorldSubsystem` or existing authoritative world-state owner only if repository architecture supports it; do not invent a parallel clock.
- Run state mutation on the game thread. Epic documents that Unreal timers are managed by a per-World/GameInstance `FTimerManager`, can be paused/cleared, and are not thread-safe.
- Replicate a compact epoch/rate/pause contract or infrequent authoritative snapshots rather than a high-frequency ticking actor. Measure correction behavior and bandwidth.
- Store versioned epoch, day, wrapped time, rate, pause reason, and the last processed boundary/event sequence. Replaying after save/load must not duplicate resource growth, worker fatigue, Sanctuary care, shop reset, weather pulse, or story triggers.
- Anima-Link strain recovery is elapsed-time policy, not a free offline reward: cap catch-up, respect care debt and story locks, and show the player what was simulated.
- Boundary events crossed by a large delta need an explicit bounded catch-up policy. Never assume exactly one dawn/day transition.

## Security and determinism gates

1. Client time, position, actor ID, inventory hash, resource cost, deformation radius, physics value, and ownership claim are suggestions only; the server resolves authoritative state.
2. Mutable commands carry schema version, authenticated actor context, sequence, idempotency key, and bounded payloads.
3. Ordinary invalid gameplay is rejected without using RPC validation as a disconnect mechanism; malformed/hostile payloads may fail validation.
4. Procedural results require documented integer seed transform/hash/noise behavior, checked dimensions and allocation bounds, asynchronous lifecycle, and reproducibility tests across supported compiler/platform builds.
5. Late join, relevancy change, travel, disconnect, save/load, rollback, duplicate packet, packet loss, and out-of-order delivery must recover from persisted authority—not multicast visuals alone.

## Research and provenance

Checked 2026-10-12:

- Epic Games, **Automation Test Framework in Unreal Engine 5.8**: public official documentation; used for test-scope and state-isolation requirements; no source code copied. <https://dev.epicgames.com/documentation/en-us/unreal-engine/automation-test-framework-in-unreal-engine>
- Epic Games, **Gameplay Timers in Unreal Engine 5.8**: public official documentation; used for timer ownership, cancellation, pause/clear and game-thread constraints; no source code copied. <https://dev.epicgames.com/documentation/en-us/unreal-engine/gameplay-timers-in-unreal-engine>
- cppreference, **std::fmod**: public reference; used only to confirm remainder semantics and finite-value edge cases; no snippet copied. <https://en.cppreference.com/w/cpp/numeric/math/fmod>

No third-party or proprietary Unreal Engine source was copied. The formula and test harness are Echohearts-specific original reference work.

## Promotion gate and next action

**Repository-verifiable:** this audit, formula, status vocabulary, canon adaptation, and generic C++17 execution record.  
**NOT YET VERIFIED:** BUILD PR #51, API macro, Build.cs, UHT/UBT, Automation tests, Editor/PIE, cooking/packaging, save recovery, replication, dedicated server, performance, accessibility, and all platform execution.

**Exact next engineering action:** restore authenticated access to `Dlomotion/ECHOHEARTS-REBEARTH-BUILD-`; fetch PR #51's exact head and file list; recompute its native test total from source and logs; then port only the corrected clock contract into the verified module/API surface and execute the Windows UE5.8 UHT/UBT + Automation baseline before any voxel, cavern, worker, UI, shader, or destruction slice.

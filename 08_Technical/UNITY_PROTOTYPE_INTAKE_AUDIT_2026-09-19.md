# Unity Prototype Intake Audit — 2026-09-19

© 2026 Into Deep Studios and Donta L. Owens. All rights reserved.

Status: REFERENCE AUDIT, NOT PRODUCTION CODE, NOT YET VERIFIED.

## Source Reviewed
Accessible pasted project material included prototype Unity/C# concepts such as `EchoheartsCoreManager.cs` and `EchoheartsDevConsole.cs`, plus instructions to continue Unreal Engine C++ production and mini-games. The useful intent is retained; the Unity implementation is not promoted into the production runtime.

## Production Decision
Unreal Engine 5.8 C++ remains the sole production runtime target. Unity/C# material is reference-only.

## Useful Concepts To Preserve
- central diagnostics visibility,
- simulated latency controls for development,
- inventory test injection,
- encounter-state testing,
- runtime system status display,
- test-scene bootstrapping,
- player/system registration,
- quick validation of gameplay hooks.

## Problems In The Pasted Prototype

### 1. Global singleton coupling
`EchoheartsCoreManager.Instance` concentrates unrelated responsibilities and creates lifetime/order dependencies.

Unreal translation:
- GameInstanceSubsystem for cross-map services only,
- WorldSubsystem for world-scoped simulation,
- ActorComponents for owned actor behavior,
- interfaces/delegates instead of direct global object lookup.

### 2. Fake deterministic tick claim
Incrementing a counter in `FixedUpdate()` does not prove deterministic simulation or networking.

Unreal translation:
- use authoritative server time/event IDs for gameplay outcomes,
- use fixed-step logic only where a real system requires it,
- test determinism rather than claiming it.

### 3. Direct client-side inventory mutation
A development console directly inserting inventory items would be unsafe in multiplayer production.

Unreal translation:
- development-only command requests,
- server authorization,
- inventory reservation/commit contract,
- audit event ID,
- compile/build guards that exclude release misuse.

### 4. `OnGUI` debug interface
Immediate-mode Unity debug UI is not the target presentation architecture.

Unreal translation:
- UMG/CommonUI for visible development panels,
- `Exec`/console commands only for development builds when appropriate,
- Gameplay Debugger/Insights/trace tools for deeper diagnostics.

### 5. Legacy input assumptions
Direct key polling does not fit the production control architecture.

Unreal translation:
- Enhanced Input actions and mapping contexts,
- rebinding/accessibility support,
- explicit separation of development-only shortcuts.

### 6. `GameObject.FindWithTag`-style discovery
Global string-based lookup is fragile and expensive as a production dependency.

Unreal translation:
- authored references,
- registered subsystems,
- Gameplay Tags for classification,
- interfaces/components for capability lookup.

### 7. Unverified network simulation
Changing a displayed ping variable does not simulate packet loss, jitter, reordering or real reconciliation.

Unreal translation:
- use Unreal networking emulation/testing facilities,
- dedicated-server test clients,
- record raw evidence for 150/250/350 ms trials,
- verify prediction/reconciliation under travel, reconnect and late join.

### 8. Security/build separation
Developer item injection and state mutation require hard separation from shipping behavior.

Unreal translation:
- development-only modules/commands,
- authority checks,
- allowlisted test actions,
- no privileged mutation path exposed to ordinary clients.

## Unreal-Native Target Mapping

| Prototype Intent | Unreal Production Target |
|---|---|
| Core manager | Subsystems + owned ActorComponents |
| Player prefab boot | GameMode/PlayerController/Pawn flow |
| direct player lookup | owned references/interfaces |
| simulated ping text field | network emulation test configuration |
| item injection | dev-only authoritative inventory transaction |
| combat trigger | dev-only encounter request through gameplay authority |
| immediate debug GUI | UMG/CommonUI diagnostic panel |
| Unity tags | Gameplay Tags/interfaces |
| FixedUpdate counter | authoritative event IDs / tested timing |

## Current Gate
Do not implement the translated C++ modules until the actual Unreal source tree exists in the repository and the current gate order is satisfied:
1. Build `EchoheartsEditor` under UE 5.8.
2. Run `Echohearts.Partners.CommandBuffer`.
3. Run reload/recovery tests at 150/250/350 ms and the required travel/reconnect cases.
4. Implement `ECO-API-001`.
5. Implement the smallest `BCT-001` reservation/commit/rollback kernel.

## Verification State
The audit is a design/architecture decision. Runtime behavior remains NOT YET VERIFIED because the repository branch currently does not contain the actual Unreal `.uproject`/`Source` runtime tree needed to compile and test these translations.

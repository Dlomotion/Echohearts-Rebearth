# Encounter → Kindling UE5.8 Integration Handoff

## 2026-10-20 current runtime and native patch supersession

Runtime destination is now **IN2Deep-Studios/ECO-KIN-Game**, existing `EchoheartsRebearth.uproject` / `EchoheartsRebearth` module / `ECHOHEARTSREBEARTH_API`, following the current live-runtime routing correction. Older sole-BUILD/Source-Echohearts lines below are historical and superseded for destination/module selection. Do not create a new project or migrate API macros from a retired checkout.

The live main source was inspected at `567677cac5a727653e1fc500e1f40174008d8735`. It contains workstation/network foundation source but no native Kindling, encounter or Corruption/relationship/save implementation. This is a bounded inspected-tree finding, not confirmation that the reported eighteen systems never existed elsewhere. Reported Corruption compile repairs and Windows UE evidence remain unconfirmed.

Native port prepared: shared exception-free phase rules; `UEcoKinKindlingComponent` with authority/game-world and revision/identity guards, replicated snapshot and fresh bond-review checks; placeable `AEcoKinEncounterSite` default-subobject wiring; Automation test source; local/hosted-policy workflow and implementation notes. No bond writes, new species, automatic wildlife spawning, actual UMG/animation/map or durable receipts. Owner ingress/permissions and atomic relationship/save integration still require implementation.

[QA patch review — EcoKin-patch PR #5](https://github.com/Dlomotion/EcoKin-patch/pull/5) stores the isolated ten-file patch and detailed record, not another runtime tree. Local GCC13 C++17/UBSan and optimized NDEBUG runs each passed 45 policy checks; existing repository/LFS gate and patch application/readback checks passed. These checks compile the actual shared native policy header, not the Unreal component. Automation source is added but not run. UHT/UBT, Editor/PIE, replication, save and package evidence remain pending.

**Destination write blocker:** GitHub returned `403 Resource not accessible by integration` when creating the live repository tree. Read access works. No runtime branch, PR, installation, merge or game build was created. Grant the connected integration write access to the live game repository for a normal destination review; do not route runtime code back into this canon repository. Downloadable apply-ready bundle: `EcoKin_Native_Kindling_2026-10-20.zip`, SHA-256 `0106b2015a7190eae2ba86ef362081d1fe2b0915a0c3f4cfd698a9c9b9f625c6`.

The following October17/19 handoff remains useful for behavior/evidence requirements but its old repository/module pointers must not override this current destination.

**Date:** 2026-10-17  
**Status:** Contract and code handoff; executable implementation blocked on BUILD access and Windows compilation  
**Extends:** `04_Systems/MISSING_SYSTEMS_DELIVERY_DESIGN_2026-10-17.md` (M01–M20), `05_Levels/FIRST_PLAYABLE_ENCOUNTER_KINDLING_SLICE_2026-10-17.md`, and `09_Technical/Reference/Encounters/encounter_contract.py`. These are the **existing PR #71** workstreams, not new overlapping owners.

## Ground truth / prerequisite stop line
- Existing Corruption stance/attribute corrections, 18 implemented modules and 20 missing modules are **user-reported**. Current repository access cannot independently read the patch, issue tree, or Windows compile evidence.
- The **BUILD** repository is sole executable UE5.8 authority. Do not add `Source/Echohearts` to this canon/contracts repository or publish unverified `.uasset` substitutes.
- Current **draft PR #70 proposes** the front-facing **Tamer of Beasts** title, hip-mounted **A.E.G.I.S./Eco-Device**, and **eight bonded links/one active campaign partner**. These changes are **not merged canon**. Preserve established **Frequency Tamer / Core-Binder** language and defer device/roster conflicts to the source-of-truth approval workflow; D.A.H.L.I.A. remains advisory. Do not hardcode either conflicting roster contract until resolved.
- Public attribute vector is **Vibrance, Density, Harmony, Purity**. Nine locked Essences only. Eco-Kin are autonomous.
- The Binding presentation is the **Kindling** event (Observe → Protect → Calm → Kindle → Bond/Release/Defer), not a new capture system. A pulse is an exchange, not a player-enforced skill check.

## Read-only BUILD audit checklist (before authoring classes)
1. Identify `EchoheartsRebearth.uproject` and `Source/Echohearts/Echohearts.Build.cs`; record branch, commit, exact UE5.8.x Build.version and plugin deps.
2. Enumerate all existing UCLASS/USTRUCT files; locate **actual** resident, summoning, Kindling, Corruption, attributes, world, AI, player controller, mission, save, network, A.E.G.I.S. and companion services. Do not invent their names.
3. Inspect concrete enum type names and owning AttributeComponent; *never* access a nonexistent stance or wrong owner field. Capture confirmed current symbol/owner table as migration handoff.
4. Verify existing Kindling's consent/roster/revision authority and Growth Rites' **actual** four enforced gates. Adapt without cloning.
5. Inspect Issue #10 rigs/collision, Enhanced Input contexts, World Partition and a safe graybox test map. If no actor/mesh exists, declare art block rather than mocking a production actor.
6. Execute UHT/UBT on the Windows UE environment *before* layering features; record all diagnostics and corrective commits.
7. Only when clean: create `EncounterProfile` DataAsset authoring pipeline; server-owned director; individual encounter adapter; ceremony view; save integration.

## Proposed dependency seam — NOT EXISTING C++ SYMBOL CLAIMS
```text
Authored Biome Profile / Region State / Permanent Dex Reference
                |
                v
World Partition Cell Load → Nav/Collision Ready Gate
                |
                v
IWorldEncounterEligibility (READ only) ← Weather / Ecological Population
                |
                v
Encounter Proposal Oracle → Existing server/world authority
                |
      Spawn permission + revision check
                v
Approved Eco-Kin Actor / Existing Movement & Behavior Owner
                |
       Observe / Protect / Calm event evidence
                v
Existing Kindling Service ← Fresh Consent / Strain / Care Gate
                |
        presentation request only
                v
Interactive Ceremony (UI + camera + device FX)
                |
       Bond / Release / Defer intent
                v
Existing relationship transaction + save + roster + replicate
                |
                v
Quest progress / world delta / D.A.H.L.I.A. response
```

### Interface boundaries
| Proposed adapter seam (generic ID, not a class name) | Reads | Never owns |
|---|---|---|
| WorldEncounterEligibility | biome tag, approved species registry, cell nav, time/weather/population | final spawn authority, permanent Dex edits |
| WildIndividualBehavior | existing Eco-Kin AI/perception, habitat/strain and world safety | relationship state, reward currency |
| KindlingEvidenceGateway | authenticated Observe/Protect/Calm events, fresh consent | forced success, save commit |
| CeremonyPresentation | authoritative phase/reason, device state, input context | creation of bond state |
| EncounterWorldDelta | validated world repair and quest events | client-written rewards |
| EncounterUIAdapter | tagged visible data, V/D/H/P, source confidence | actor spawn, trust scores |
| ArenaMatchAdapter | sanctioned Arena rules only, match ID, season | campaign ecology and bond outcomes |

### Events (versioned server truth)
`WorldCellBecameReady` → `EncounterProposalMade` → `EncounterSpawnAccepted/Rejected` → `WildIndividualObserved` → `HabitatProtected` → `IndividualCalmed` → `KindlingInvitationOffered` → `IndividualConsented/Refused/Deferred` → `CeremonyProgressChanged` → `BondIntentReviewed` → `RelationshipCommitted/Released/Deferred` → `MissionDeltaCommitted`.

Each server event carries `EventId`, `OriginRevision`, `WorldCellId`, `EncounterId`, `IndividualId`, `TimestampAuthority`, optional `PlayerOwnerHandle` and safe `ReasonTag`. No user account secrets in payload; don't send a client's arbitrary `consent=true` field as evidence. Reasons are data-backed, deterministic under tests, and localized by UI.

## Input contract
**Contexts:** Explore, Partner, Ceremony, UI. The actual Enhanced Input asset names are discovered from BUILD.
- Explore: vector Move, vector Look, Jump, Interact, Observe, SafeBackAway; Sprint if existing.
- Partner: OpenCommands, SelectBonded, Summon, FreeSafeRecall; do not activate multiple campaign partners.
- Ceremony: Invite, Confirm, Release, Defer, Cancel (separate from Attack and irreversible commits).
- UI: Navigate, Select, Back, AccessibilityAdvance.
Contexts must explicitly hand off focus; no double action on a single Confirm edge. Touch controls have virtual-joystick alternative, no rapid tap / mandatory timed rhythm. Keybinds remappable. Player can refuse a request even with gamepad focus lost.

## Replication / save safety
- The host alone proposes + commits spawn, after authoritative cell capacity and navigation recheck.
- Wild individual stable GUID persists only when appropriate; transient cell actor may despawn visually while world-level history remains.
- Ceremony presentation `Ready` is **not** a committed bond; relationship ledger must enforce unique individual+owner transaction through the existing save owner.
- Replicate minimum state and revision, not raw character pointer graphs, client weather overrides or sensitive tokens.
- Disconnect between invite and final consent returns a safe deferred state. Rejoin must **never** auto-convert a pending ceremony into a bond.
- Save at important boundaries; test crash before/after commit, concurrent players, duplicate server requests and form/strain effects.

## Product acceptance scenario
**Gold path:** Windows Editor boots → character moves with keyboard and gamepad → one authored habitat streams → one **approved Dex** Eco-Kin appears with species-specific idle/walk → Observe → Protect → Calm → invitation → voluntary yes/no → first Kindling ceremony → relationship/roster updates exactly once → safe recall works → save/reload restores result.

**Failure path:** Eco-Kin refuses and the player completes the lesson via care/report; storm unloads the cell and the encounter resumes without duplicate spawn; injury redirects to care, not a capture result. Stable story gate remains satisfied after choosing defer.

**Negative cases:** nonexistent stance symbol; reading V/D/H/P from the wrong object; missing consent; full eight links; active partner mismatch; replayed transaction; client injecting fake registry ID; invalid streaming cell; bad movement/nav; corruption causing unapproved compulsory mutation; duplicate collision event.

## Actual build validation sequence
1. Repository-checkable validators and offline reference unit tests: useful **NOT** Unreal evidence.
2. Windows exact source+LFS checkout and verify `Build.version`.
3. UHT plus UBT Editor Development.
4. Editor boot + map load + singleplayer PIE run with retained logs.
5. Two-client server-authoritative session, join/disconnect/rejoin, clean save migration/rollback.
6. Win64 Development cook/package and launched executable.
7. Representative platform performance (60 FPS target not a claim); controller/mobile and console builds only under supported SDKs/certification.

Never merge/relabel as `VERIFIED` solely because CI ran the Python oracle.

## 2026-10-19 C++ handoff continuation

[Compiled C++ ceremony reference](Reference/Encounters/Cpp/README.md) now extends
the existing Python oracle. It covers ordered transitions, fresh consent,
refusal/release/defer, checked revision changes and in-memory review idempotency.
It does not implement spawning, Anima-Link, Corruption, UE actors or save/RPC
services. Read the reference symbol/owner table before adapting; no actual BUILD
symbol was inspectable. Do not copy the exception-based oracle into UE or enable
exceptions merely to compile it.

Three requested gate steps were attempted: both BUILD metadata locations still
return 404; Corruption's reported stance/attribute fixes cannot be reproduced
without source; Windows UE5.8 foundation execution cannot proceed without the
checkout, engine and logs. The available public tree has no `.uproject`,
`Source/`, `Build.cs` or target files at the inspected commit. No second runtime
foundation or replacement build driver was added here.

An existing public historical `Tools/verify_unreal_gate.py` still names
`UE4Editor.exe` in preflight/automation and defaults to `EchoheartsEditor`, while
the foundation contract records `EchoheartsRebearthEditor`. It must not be used
as UE5.8 proof. Audit the actual BUILD driver and discovered target names before
execution; this continuation does not change that BUILD-owned tooling.

Clarification to the failure path above: Release/Defer may resolve the safe
handling lesson. Training Stage 04's genuine-first-bond requirement stays
unsatisfied until an actual relationship transaction succeeds. A review proposal
or C++ reference test cannot award it. No new map coordinates or roster entries.


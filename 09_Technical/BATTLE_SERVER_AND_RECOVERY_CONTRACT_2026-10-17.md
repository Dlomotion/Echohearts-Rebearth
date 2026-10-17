# Battle servers, queues and recovery proposal

Status: architecture/acceptance contract, not deployed infrastructure.

| Server profile | Purpose | Admission and persistence |
| --- | --- | --- |
| offline | Solo campaign/training, approved ghost replay | Local save authority; no ranked results accepted |
| private_coop | Invite-only PvE with friends | Authenticated party permission; host-world progress attributed explicitly |
| public_pve | Region/story-phase-compatible exploration | PvE only; no proximity-triggered PvP or public route confiscation |
| casual_arena | Duels, 2v2 relay, tactical simulation, ghost trials | Opt-in rulesets; no live rank mutations |
| ranked_arena | Ranked human 1v1 | Dedicated authority target, matched build/ruleset/season, finalized server results |
| event_raid | Up to four allied humans against authored crisis | Safe-checkpoint late join, current encounter revision, contribution review |
| tournament | Scheduled bracket bouts | Locked match roster, bracket authorization and result service |

These are proposed logical profiles, not seven newly hosted machines. Allocate
instances by region and capacity; the server browser groups purpose, latency,
privacy, ruleset, input requirements, party capacity and accessibility settings.
Capacity, tick rate, region deployments, hosting budget, transport and platform
support require measurements. Do not invent server IPs or claim console certification.

## Identity and match flow

Authenticated account/party → request allowed mode → host resolves eligible roster
and challenge consent → lobby negotiation → compatible session allocation → host
checks instance/build/ruleset/season/region/revision → countdown → authoritative
simulation → finalized outcome → idempotent reward/standing review → care/debrief.

A lobby organizes people; a session describes/discovers a running game instance.
Neither is proof that an engine server exists, authenticates a participant, simulates
a battle or persists rewards. Matchmaking/backend product configuration is pending.
Server truth, not client damage claims, controls simulation and outcomes.

Reference HostContext represents trusted outputs from those missing services. It
is not a payload a client may submit. Presence in an authenticated/permitted set is
a fixture for adapter validation, not cryptographic authentication. Partner booleans
must come from relationship/care services and all IDs must resolve in approved data.

## Cross-server travel

No transfer while a ranked bout is live. Finish/surrender or use an explicit host
disconnect policy, settle once, and transfer only after source authority relinquishes
the session. A destination gets a scoped handoff, not client-edited resources.
Reserve/cancel/debit behavior follows the existing summon system. Travel cannot
duplicate an active partner, refresh charge/strain or replay match rewards.

Shared account progression uses the existing persistence authority; match state is
short-lived and ruleset scoped. Private/offline world variants do not overwrite public
season results. Public events cannot change someone else's campaign choices by merely
sharing a server. Crossplay is opt-in within compatible versions/policy and permitted
platform pools; phone/desktop/console parity requires input/performance/certification tests.

## Failure and fairness matrix

| Failure | Required behavior |
| --- | --- |
| Duplicate join/action | Return prior result or reject; no duplicate entity/resource commit |
| Ruleset/season/build mismatch | Reject before match; explain required version |
| Ranked disconnect | Reserved reconnect window; server decides surrender/no-contest under disclosed rules |
| Dedicated server crash | Restore durable match checkpoint or no-contest; never trust a client's claimed winner |
| Private host loss | Pause/abort safely; no live ranked promotion from host migration |
| Raid late join | Safe checkpoint and revised roster; no teleport into hazards or double reward |
| Partner withdraws/injured | Host safe recall/replacement/surrender policy; no forced command override |
| Ceremony starts | Do not recall or summon through protected ceremony |
| Save/transfer failure | Keep recovery record, reconcile existing owner before retry |
| Seasonal reset during battle | Match binds season at admission; settlement checks the original authorized season |
| Ghost replay invalid/version old | Reject or offer a disclosed compatible rehearsal; never rank as live PvP |
| Draw/surrender/no-contest | Distinct signed server outcomes; no arbitrary winner manufactured |

No-contest and disconnect scoring, rating formula, anti-collusion, report/moderation,
sanction handling, reconnect durations and spectator privacy require authored policies.
They are not implemented by the small reference ledger. Repeated identical results
produce no new review events; conflicting same-match results are rejected. Ledger
durability, concurrent writes, result signatures and cross-process replay protection
belong in the existing backend, not this in-memory dictionary.

## Unreal implementation and evidence gates

Inspect actual BUILD module/API/targets first. Add mode definitions to existing game
data, bind requests to authenticated owning actors, keep outcome/world/reward authority
server-side, replicate state for late join/relevancy and call the existing save/economy
services. Do not create a second battle stat owner or persistence manager. The offline
Python model is a test oracle only, not a Python gameplay dependency.

Required: Windows UE5.8.3 UHT/UBT and Automation; two-client/one-server duel; four-client
raid; travel/disconnect/rejoin; packet loss/reorder; summon/recall and resource contention;
world save isolation; durable duplicate-result rejection; ghost validation; accessible
gamepad/keyboard/touch UI; performance/network captures on each supported target.
Use a controlled network harness and real server builds before claiming any online mode.

Official technical references reviewed 2026-10-17:
- https://dev.epicgames.com/documentation/unreal-engine/networking-overview-for-unreal-engine
- https://dev.epicgames.com/documentation/unreal-engine/setting-up-dedicated-servers-in-unreal-engine
- https://dev.epicgames.com/docs/epic-online-services/multiplayer/lobbies-and-sessions/lobbies-and-sessions-introduction

These support the client/server and lobby/session separation. All Echohearts mode,
story and policy choices in this proposal are original project design, not Epic features.

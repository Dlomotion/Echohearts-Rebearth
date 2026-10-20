# Missing-system delivery design — Echohearts: Rebearth

Date: 2026-10-17. Status: expanded design + bounded offline reference execution;
NOT A PLAYABLE GAME BUILD / NOT UNREAL VERIFIED.

## Evidence and scope

The user reports eighteen implemented systems, twenty designed-but-unimplemented
systems, and two corrected Corruption compile errors. The full audit/report and
BUILD sources are not available through this connection. Both known BUILD repository
metadata reads return 404. These counts and fixes remain USER-REPORTED, not independently
verified inventory or Windows compile evidence. A 404 does not prove deletion.

The twenty workstreams below organize the gaps named in this request plus necessary
integration/content work. They are not a reconstruction of the unnamed twenty rows
in that report, nor a claim every system is absent everywhere. Existing implementations
must be inspected before adding replacements. Proposed symbols and asset names are
contracts, not claims that UObjects, Blueprints or assets already exist.

Read sources: current core/story/relationship/combat and growth rules, the farming
reconciliation, A.E.G.I.S. contract and PR #70 battle proposal. Also reviewed the
frequency/weather design on feature/frequency-weather-maritime-20261016; its older
Core-Binder/bracer wording yields to current Tamer of Beasts/hip-device direction.
Do not merge that entire branch just to reuse weather requirements.

## Core design constraints

Rebearth is a physical living world. Eco-Kin have biological/ecological identity,
memory and agency. Keep V/D/H/P, nine Essences, existing identity/art governance,
eight carried links and one active campaign partner. Kindling is the voluntary
Observe → Protect → Calm → Kindle → Bond / Release / Defer loop. 'Binding ceremony'
is mapped here to its interactive Kindling presentation, not a second capture system.

No duel, damage quota, capsule, paid upgrade, Cradle, home or rhythm score grants a
bond. A report's 'fusion' implementation must be inspected against Bio-Synergy Weaving/
non-destructive trait rules; no body fusion, donor consumption or identity overwrite
is approved by this intake. Shimmer and other forms remain linked to approved base
identities, never automatically new Dex records. Numeric tuning stays provisional.

## Twenty delivery workstreams

### M01 — Player input and interaction

**Experience:** move, look, interact, observe and safely disengage before expecting
combat. Context controls separate exploration, partner commands, UI and ceremony.
**Contract:** consume player ownership and active context; route intent to existing
character/interaction components. Menus suspend conflicting actions, not the server.
Support keyboard/mouse, gamepad and touch targets with remapping and hold/toggle
alternatives. Cancel must not become 'attack' when focus changes.
**Acceptance:** move/look/jump/interact work in the first test map; no duplicated
bindings after respawn/travel; UI blocks attack, input focus survives disconnect;
device/ceremony controls remain usable without rapid taps or audio timing.
**Dependency:** actual Windows foundation and character/input component inspection.

### M02 — Wild population and safe encounter creation

**Experience:** discover individuals in plausible habitats, not an empty map or an
enemy generator around the player. **Contract:** approved species candidate tables
read biome, weather, day phase, ecological state, capacity and streamed-cell revision.
Seeded weighted selection proposes an encounter; host rechecks collision/navigation,
protected habitat and population budget before spawning a unique individual.
No spawn in view without authored emergence; no appearance inside player geometry.
Persistence distinguishes absent, travelling, recovering and deliberately removed
individuals. **Acceptance:** capacity, deterministic proposal, stale cell, duplicates
and unsupported species fail closed. Population does not double after travel/load.
**Implemented now:** offline proposal/commit-gate oracle only; no spawned actors.

### M03 — Field signs, tracking and discovery

**Experience:** footprints, disturbed plants, residue, feeding marks and water motion
lead to an encounter. **Contract:** signs reference an existing individual/encounter,
source time and habitat; A.E.G.I.S. reports confidence, not omniscient coordinates.
Clues degrade or become ambiguous with weather. Protected nests cannot be exposed
automatically to every player. A trail can end with observe/defer rather than a fight.
**Acceptance:** no clue points to an unloaded/null entity forever; stale signs show
uncertainty, meaningful critical routes have authored fallback, repeated scans never
mint discovery rewards. **Dependency:** M02 plus existing discovery/mission records.

### M04 — Wild ecology and approach behavior

**Experience:** feeding, shelter, social spacing, curiosity, warning, flight and rest
make the same species feel alive. **Contract:** bounded perception and utility/BT
decisions consume habitat, injury, threat, preference and evidence. A player sprinting
nearby may scare an individual but does not force a duel. Resolve fear by creating
space, removing hazards or waiting. Group behavior never silently duplicates individuals.
**Acceptance:** flee paths are reachable; trapped individuals defer and seek shelter;
player exit/re-entry cannot reset consent or fatigue. Profile only active streamed
groups. **Dependency:** M02, navigation and authored species behavior profiles.

### M05 — Interactive Kindling ceremony

**Experience:** a slow readable invitation grounded in what the player actually did.
An individual approaches, accepts, pauses or leaves. The hip-device observes and
communicates; it does not fire a capture beam. **Contract:** explicit observation,
protection and calm evidence precede invitation and fresh affirmative consent.
Ceremony readiness is separate from the final relationship transaction. Refusal,
healing, danger, interruption or stale evidence cause release/defer without penalty.
**Acceptance:** cannot skip steps or earn consent through repeated button pressing;
refusal still works immediately before final commit; two players cannot both finalize
the same individual; care never automatically creates a bond. **Implemented now:**
offline transitions and idempotent review-intent ledger, not actual relationship writes.

### M06 — Enemy combat AI

**Experience:** threats telegraph intent and use positions, protection and retreats;
difficulty comes from decisions rather than reading hidden input. **Contract:** separate
hostile humans, machines and distressed wildlife motivations. Decisions filter invalid
actions before scoring objective, survival, sightline, cooldown and terrain. Keep attack
startup/recovery visible. Disengagement releases combat state only after a safe transition.
**Acceptance:** no attacks through unloaded geometry; no friendly-fire bypass; lost
targets lead to search/retreat, not teleport; AI stops/replans when route permission
changes. **Dependency:** current combat/AI components, M01/M04 and actual animation tells.

### M07 — Boss encounter director

**Experience:** rescue/restore/defend objectives give a giant encounter a reason beyond
damage. **Contract:** authored phases with entry conditions, telegraphs, counterplay,
safe zones, transition guards and recovery checkpoints. Distressed Sovereign Eco-Kin
are not presumed evil. Use the established bosses and story spine; no placeholder
becomes a new permanent species. **Acceptance:** phase reset and reconnect cannot
repeat first-clear rewards; players cannot be trapped after an aborted phase; four-player
scaling respects role/support contributions. **Dependency:** M06, mission/world authority
and the PR #70 raid contract; final damage values remain BUILD data.

### M08 — Shimmer Form ascension

**Experience:** a rare, identity-preserving transformation with species-specific motion
and visible history, not a generic recolor or power purchase. **Contract:** resolve the
existing form record and approved gates for ecology, relationship, story and voluntary
readiness. Separate eligibility, invitation, in-progress, committed and recovery states.
No universal threshold is invented here; actual data owns required gates.
**Acceptance:** missing gate denies entry; refusal is safe; interrupted/save-restored
ascension does not duplicate form rewards or replace the base identity. **Dependency:**
actual Growth Rite implementation audit, Forms Registry and approved art/rig compatibility.

### M09 — Resonance Strain and recovery

**Experience:** clear fatigue/strain tells, rest opportunities and refusal before
dangerous overexertion. **Contract:** bounded strain events from authored combat,
hostile habitat, summoning distance and advanced temporary effects; distinguish
player/device budget from the partner's condition. Repeated physics callbacks must
not multiply one injury. Recovery delegates to existing care/time services; no per-frame
unbounded drain or 'high strain = best permanent power' loop.
**Acceptance:** NaN/overflow, duplicate event and pause/travel/reconnect cases tested;
free recall adds no strain and does not refund spent charge. **Dependency:** existing
Anima-Link/summoning/care ownership, not a second meter or new public attribute.

### M10 — Restoration Farming

**Experience:** heal soil/water, support pollinators and cultivate usable resources while
showing before/after ecology. **Contract:** plot identity, soil/water condition, approved
seed/crop record, bounded growth time and restoration contribution. Rest/harvest uses
the existing inventory transaction. Eco-Kin may volunteer according to aptitude/health
and can stop. No forced work queue, sentient farming or harvest from a living partner.
**Acceptance:** clock jumps and offline progress are capped by approved policy; harvest
cannot replay; drought/restoration changes are persisted. **Dependency:** existing plot,
inventory, weather and Sanctuary systems; species schedules remain authored data.

### M11 — D.A.H.L.I.A. advice and uncertainty

**Experience:** useful observation, explanation and alternatives without taking choices
away. **Contract:** read-only access to known scans, hazards, goals and partner feedback;
authored intents produce captions/callouts with source age and uncertainty. Suppress
repeat advice and honor accessibility/preferences. Offline authored fallback is mandatory.
No online model output grants a bond, edits a save or invents a new species/quest.
**Acceptance:** unknown/stale scans are labeled; refusal remains refusal; missing network
never blocks the core loop. **Dependency:** existing AI feature workspace and A.E.G.I.S.
contracts; D.A.H.L.I.A. remains the device's adviser module, not a second world authority.

### M12 — Weather and cloud-state simulation

**Experience:** forecasts, moving clouds, gust fronts, rain and shelter choices that
affect travel and ecology. Reuse the existing frequency/weather proposal: fair cloud,
storm anvil, coastal fog and restored canopy mist are region-authored states.
**Contract:** host-seeded regional weather phase/time and bounded hazard events;
client sky/cloud/VFX presentation reads that state. Natural weather is not morality.
**Acceptance:** save/load/rejoin agrees on phase; lightning telegraphs and safe shelter
exist; distant unloaded storms do not run full FX or creature logic. **Dependency:**
time/world partition authority and M18. No full planet fluid simulation is promised.

### M13 — HUD, menus and accessibility

**Experience:** understandable encounter, bond invitation, partner command, care and
result screens. **Contract:** UI subscribes to authoritative state/reason events;
player clicks request intents only. Use V/D/H/P, text + icons + animation, scalable
captions, non-color safety indicators and remappable controls. Critical feedback is
not only sound, pulse timing or haptics. **Acceptance:** no stale 'accepted' prompt
after refusal; cancel/back works with every input; widget rebuild does not duplicate
requests. **Dependency:** M01, existing view models, M05/M09 state and content localization.

### M14 — Story missions and dialogue

**Experience:** meet an individual, solve a local problem and see lasting consequences.
Extend the Field Academy/first Kindling and Heartroot restoration spine, not a parallel
opening. **Contract:** stable mission/objective IDs and existing events; multiple resolutions
Bond/Release/Defer/Treat/Relocate can complete appropriate lessons. Dialogue communicates
intent; a care outcome is not overwritten by an assumed combat victory.
**Acceptance:** replay/load/travel cannot award twice; refusing a bond does not softlock
the campaign; stages unlock only through approved prerequisites. **Dependency:** existing
mission architecture. The first playable scene is defined in the companion slice brief.

### M15 — Meshes, materials and environment art

**Experience:** approved Eco-Kin silhouettes and a coherent repaired/broken ecology.
**Contract:** start with the existing Issue #10 human + Eco-Kin body slice; use approved
art manifests, anatomical landmarks, rig-family scale and material slots. Graybox collision
proxies are early test content, not final assets. Hip Eco-Device follows Living Porcelain,
Ancient-Tech conductor lines and restrained Prism Core light where approved.
**Acceptance:** import scale, collisions, sockets, LOD/material budget and readable outline
checked in-engine. No arbitrary redesign or new species identity. **Dependency:** recovered
approved art and actual DCC/Unreal pipeline; do not delay all art until after the entire story.

### M16 — Rigs, locomotion and interaction animation

**Experience:** an individual breathes, notices, warns, approaches, withdraws and rests
with weight and anatomy. **Contract:** species-compatible rigs, root/foot contacts,
bounded turn rates, authored transition windows and gameplay-owned notifies. Provide
movement/idle first, ceremony approach/refusal next, then combat and growth sets.
**Acceptance:** no foot sliding, joint collapse, double-hit notify, uninterruptible capture
pose or lost attachment on recall; skeleton reuse only inside compatible authored families.
**Dependency:** M15 and input/combat states; no copied outside-game animation timing.

### M17 — Audio, VFX and event readability

**Experience:** habitat ambience, individual calls, device feedback and clear threat/ceremony
states. Sonic species have authored sound abilities; most others express biology and Essence.
**Contract:** state-tagged cue events, concurrency limits and local presentation with server
event identity. Refusal has a calm cue, not a failure siren. Caption critical cues and offer
reduced flashes/camera shake. **Acceptance:** replayed network events do not stack damage
or sound; offscreen/distant effects are budgeted; muted play remains understandable.
**Dependency:** M13/M16 and actual authored assets; cue briefs are not delivered sound files.

### M18 — Level placement, streaming and navigation

**Experience:** a traversable habitat with a safe approach, retreat, shelter and restoration
evidence. **Contract:** approved map/cell IDs, nav/collision readiness, density limits,
protected-area policy and stable spawn anchors. World Partition activation is independent
of a visible sky effect. **Acceptance:** unload/reload preserves or safely reconstructs
encounters; no actor inside geometry; a skipped duel cannot close a public path.
**Dependency:** actual map registry/cook and first slice map. No new coordinates or biome
placements are invented by this design; candidate descriptions are authoring briefs.

### M19 — Multiplayer battle/runtime integration

**Experience:** optional private co-op, PvE events, duels and sanctioned competition with
clear queues and fair care rules. **Contract:** reuse PR #70's mode/server separation,
authenticated owner-bound requests, host world revision and agreed ruleset/season.
Replication handles late join/relevancy; VFX multicast never owns state. No client can
spawn, award, overwrite a partner or refresh budgets by changing servers.
**Acceptance:** two-client duel/four-client raid, disconnect, no-contest, replayed results
and transfer isolation. **Dependency:** server targets, backend and platform policy;
reference admission checks do not constitute running servers.

### M20 — Save recovery and end-to-end verification

**Experience:** resume without losing an individual, erasing refusal or duplicating rewards.
This extends the user-reported save system, not a replacement save manager.
**Contract:** versioned individual/encounter/relationship/form/care records; durable transaction
IDs; reconcile authoritative ownership before re-spawn or bond commit. Separate seasonal
Arena records from campaign ecology. **Acceptance:** save at every ceremony/phase boundary,
reload under changed weather/cell state, duplicate/reordered events, crash before/after
commit, missing optional assets and schema migration. **Dependency:** actual save APIs,
retained Windows UHT/UBT/Automation/cook logs and a playable content slice.

## Common implementation discipline

Each workstream needs a named existing owner, versioned input/output records, allowed
state transitions, reason codes, authored tuning, save/network rules and a retained
acceptance run. None can replace the 125-ID identity authority or create a second bond,
economy, world, save or narrative owner. Missing measurements remain unknown, not zero.
New classes are justified only after current BUILD ownership is inspected.

## Detailed delivery expansion — 2026-10-17 follow-up

This section turns the workstreams above into integration-ready acceptance briefs.
It extends this document, not a new Master Bible. The unnamed full audit still has
not been supplied, so these are the same twenty derived workstreams, not a verified
inventory of the reported missing twenty systems. Existing BUILD class names, asset
paths and database columns must be recovered before choosing concrete runtime APIs.
The reported Corruption fixes are not independently confirmed by these references.

### Shared records and transaction boundaries

Reuse the existing ID/event/save owners. Record names below describe required data,
not a newly approved global schema. A mutating intent needs authenticated requester,
subject identity, expected revision, session/event key and authored action. A result
needs accepted/rejected/pending, reason, authoritative revision and actual changed
state. Identifiers cannot be species display names or array positions. No client
boolean such as `consent=true` is an authority source.

Freshness belongs to the owner: observation timestamps, habitat/individual revision
and care status are re-read immediately before a relationship/form/placement commit.
A retry returns the original transaction result; changed payload under the same key
is rejected. Persist receipts with the mutation. In-memory sets in a reference test
are not crash recovery, database isolation or replicated state.

### M01 — Input context and interaction delivery

- Required existing data: input context, local player, focused interactable, accessible
  action labels and device preference. Proposed context flow is Explore → Interact →
  Ceremony or UI → previous safe context. Never restore a held Attack as Confirm.
- Input arbitration clears queued combat actions on menu/ceremony entry, preserves
  held-movement rules explicitly, and restores focus after respawn/travel. A disconnected
  controller offers readable reconnect controls; it does not freeze a network server.
- Build assets: actual Input Actions/Mapping Contexts, focus widget, camera settings and
  platform prompt table. Final mappings are chosen after current character inspection.
- Acceptance M01-A: open a menu while holding attack, switch controller, close menu;
  no attack or invitation fires until a new intended input. Touch and keyboard repeat
  cannot double-submit a relationship transaction.

### M02 — Wild population, reservation and spawn delivery

- Owner data: approved species table, individual identity, anchor/cell identity,
  population capacity, seed/revision, habitat conditions and spawn visibility policy.
- Lifecycle: candidate → reserved → geometry/nav recheck → active → travelling/resting
  or removed-by-authored-event. Reserve capacity before actor creation; release a failed
  reservation once. A streamed-out resident is not a vacant population slot by default.
- Commit is transactional: a current host proposal resolves one individual and actor;
  failed allocation rolls back reservation, and reconnect cannot generate a second body.
- Acceptance M02-A: two concurrent proposals for the final slot yield at most one
  active individual. M02-B: an individual already bonded/recovering is never selected
  again as a new wild specimen. Actor creation is still pending BUILD integration.

### M03 — Tracking signs and discovery delivery

- Each clue references source individual/encounter, known area, evidence kind, observed
  time and expiry. It must not reveal a protected nest or hidden individual through walls.
- Trail sequence: noticed → examined → contextualized → stale/resolved. Rain can reduce
  confidence; it must not erase an essential story route with no alternative.
- A scan reveals only approved observations; first-seen documentation and repeat viewing
  are separate events. Archive notes remain when the subject leaves.
- Acceptance M03-A: unload the last clue's cell during tracking; show stale/unknown and
  the authored fallback rather than a permanent unreachable quest marker.

### M04 — Wild approach and ecological motivation delivery

- Species/individual profile defines comfort distance, social group, shelter preferences,
  warning behavior, fear recovery and valid activities. Numeric distances are authored.
- States: forage/rest → notice → assess → warn/approach/withdraw → safe activity. Threat,
  injury or young nearby may change decisions without becoming permission to capture.
- Navigation failure chooses wait/seek safe route/defer; do not teleport or repeatedly
  repath every frame. Resetting a behavior tree cannot reset memory of refusal or harm.
- Acceptance M04-A: sprint at a wary individual, back away, then re-enter the cell;
  behavior remembers its condition and a clear escape route remains available.

### M05 — Kindling presentation and relationship finalization delivery

- Observe/protect/calm are evidence-backed milestones, not compulsory timer minigames.
  Protection can recognize a safe habitat or an actual helpful action; players must
  never create a hazard to satisfy the lesson.
- UI phases mirror the existing ceremony reference. A voluntary approach/invitation
  offers Bond, Release and Defer outcomes; refusal or threat returns to safe separation.
- Two-stage finalization: host checks current evidence/consent → existing relationship
  owner writes one durable relationship result → presentation acknowledges that result.
  `bond_ready` from a test is not a bond record. Refusal wins until actual commit.
- Acceptance M05-A: withdraw consent between invitation and commit; no bond or cost.
  M05-B: save on each phase, restore with a changed subject revision, and re-evaluate.
  M05-C: Release/Defer can satisfy the safe-handling lesson without roster membership.

### M06 — Enemy decision and combat delivery

- Existing combat owner supplies visible target memory, distance/LOS, nav result,
  permitted actions, cooldowns, objective and injury/strain. Validate eligibility before
  scoring. Authored utility curves choose among legal actions; deterministic ID order
  resolves equal reference scores, not input order.
- Action lifecycle: decision → telegraph → execution window → recovery → replan. Cancellation
  must remove pending hit notifies. Animation-notify replay cannot cause duplicate damage.
- Personality differs: wildlife seeks safety, hostile machines protect a directive,
  human opponents may disengage or accept surrender. No private input prediction.
- Acceptance M06-A: highest scoring attack behind blocked LOS is not chosen. M06-B:
  route unload, cooldown change or protected ceremony cancels/replans before execution.
  The offline action selector returns intent only; it performs no movement or attack.

### M07 — Boss objective and phase delivery

- Reuse existing boss/story identity; define phase entry, telegraph duration, hazard
  geometry, safe positions, objective, exit and abort route in authored encounter data.
- Reference scaffold: dormant → warning → response → recovery → resolved; unsafe context
  or explicit abort → aborted. No skipping telegraph or unresolved objective. Real bosses
  extend existing phase architecture rather than inherit a universal four-phase fight.
- Example encounter grammar: protect evacuation corridor; identify hazard source; expose
  a safe stabilization window; restore a conduit; allow withdrawal. Defeat is not erasure.
- Acceptance M07-A: disconnect during transition, rejoin after checkpoint; phase and
  safe exit reconstruct, first-clear receipt cannot replay. M07-B: support/evacuation
  contributions count where the approved raid contract allows; damage alone is insufficient.

### M08 — Shimmer eligibility and ascension delivery

- Resolve an approved base-ID/form pair and its species-authored requirement set. Do
  not infer a universal Purity score, storm trigger, rarity percentage or new Dex ID.
- States: unavailable → eligibility observed → invited → voluntary rite → committed →
  recovery. A missing ecology/relationship/story/care requirement blocks invitation.
  Refusal/healing overrides readiness; current consent and gates are rechecked at commit.
- On interrupted rite, release reserved catalyst by transaction policy; preserve prior
  form/history and avoid repeat unlocks. A save records base identity plus approved form.
- Acceptance M08-A: remove each authored requirement independently; invitation fails.
  M08-B: invalid base/form pair and lost consent cannot be turned into ascension by UI.
  Blessed Forms retain separate existing form-class eligibility; Shimmer is not a synonym.

### M09 — Strain event and recovery delivery

- Extend the existing Anima-Link/Spirit Load owner. Attribute a strain event to subject,
  source event, amount, revision and context; treat player/device/partner costs separately.
- Host checks budget before a risky voluntary action; capacity failure leaves state
  unchanged. Author care/rest recovery; reject recovery below zero rather than hide a
  duplicate event with clamping. Persistent receipts handle retries in actual runtime.
- An event buffer reaching capacity must checkpoint/rotate under durable owner policy,
  never silently forget replay protection. Reference history exhaustion rejects safely.
- Acceptance M09-A: duplicate hit/exposure ID does not add strain twice; stale events
  do not overwrite recovery. M09-B: Recall adds zero strain, gives no charge refund,
  and cannot manufacture a new permanent power state from exhaustion.

### M10 — Restoration plot and volunteer delivery

- Existing plot identity links approved crop, soil/water condition, stage, time cursor,
  revision and inventory transaction. Farm tasks accept willing, healthy volunteers;
  refusal leaves the task available for the player or an appropriate service.
- States: prepared → planted → growing → ready → harvest reservation → inventory commit
  → fallow/replant. Offline progress follows approved cap and authoritative clock.
  Dry/hazard intervals advance the time cursor without banking future growth.
- Reference `harvest_pending` is only a proposal reservation. Runtime inventory and
  plot transition must commit atomically; failed capacity check leaves the crop ready.
- Acceptance M10-A: replay harvest, travel during commit and inventory-full failure;
  no duplicate item and no vanished ready crop. M10-B: clock rollback rejected; time
  beyond an offline cap cannot be repeatedly claimed by reopening the same save.

### M11 — D.A.H.L.I.A. advice delivery

- Read-only adviser over known observations, care/hazard flags and mission hints. Each
  callout includes evidence age, confidence/unknown state and authored text key.
- Priority: immediate welfare safety → unavailable/stale reading → respect refusal →
  safe-approach alternative → ordinary observation. An emergency prompt can offer care
  without claiming permission for a bond. Remote generation is optional presentation,
  never an authoritative decision or prerequisite for offline play.
- Subscribe to changed reasons; cooldown/batch repeated advice and allow mute/history.
  Unknown data must not produce fabricated species identities or false consent.
- Acceptance M11-A: stale scan and lost connection show authored fallback; fresh
  refusal is never answered with an instruction to override it.

### M12 — Regional weather delivery

- Existing world/time owner supplies schedule/seed, epoch, phase durations and revision.
  One host snapshot feeds ecology, travel, farm and presentation. Natural weather is
  not a moral Purity penalty. Protective actions can reduce exposure where authored.
- Reference supports a bounded authored cyclic schedule and exact phase boundaries,
  not a planetary weather generator. Rejoin evaluates the same phase at the same time;
  long gaps use direct arithmetic rather than one tick loop per elapsed moment.
- Real weather data defines transition blends and forecast uncertainty; storm hazards
  need local telegraphs, shelter tests and event IDs. Sky material is client presentation.
- Acceptance M12-A: phase boundary/save/rejoin agree. M12-B: clients cannot change storm
  timing by local clock; unloaded cells do not allocate full VFX/AI simulation.

### M13 — Core UI, reason presentation and input safety delivery

- Screens: start/pause, interaction, observation, ceremony, partner roster/readiness,
  commands, care, mission objective and results. Bind existing model revisions.
- Request/pending/accepted/rejected are distinct. Unknown readings show Unavailable;
  stale consent closes an invitation. Text/icon/caption convey every critical cue.
- Core layout protects center aim/world view; command list and partner state have
  gamepad focus and scalable touch targets. No mandatory mash or audio-only timing.
- Acceptance M13-A: missing optional icon, rebuilt widget or language change cannot
  duplicate requests, hide refusal, or reset authoritative charge/strain to zero.

### M14 — Mission and human motivation delivery

- Attach the first scene to existing Field Academy/Heartroot restoration missions.
  Use approved mentor/care staff identities; cast/locations from unrelated images
  are not automatically new characters.
- Mission beats: observe damage → establish the cause → make a safe intervention →
  respect a choice → report evidence → see persistent repaired habitat. Branch outcomes
  Bond/Release/Defer/Treat/Relocate remain distinct, with appropriate lesson completion.
- Human battles have reasons: rescue corridor defense, stopping harmful extraction,
  skill certification with willing partners, or sanctioned competition. Avoid a universal
  forced duel for walking into a gaze. PR70 owns modes, motives and server proposal.
- Acceptance M14-A: non-bond resolution reaches the next approved story stage; replayed
  objective events cannot grant twice or manufacture a relationship.

### M15 — Mesh/material delivery and reference boundary

- First asset bundle is one approved humanoid and one approved Eco-Kin rig family,
  hip-device attachment and a small habitat pocket. Graybox collision may be used for
  mechanics testing while final anatomy/materials proceed alongside the slice.
- Required source: original DCC project, identity/art-manifest link, provenance, scale,
  pivot, sockets, collision representation, material slots and LOD plan. Measure budgets
  on actual target hardware instead of inventing a universal polygon allowance.
- Acceptance M15-A: import without missing dependencies; silhouette matches approved
  identity, collisions fit, device mount survives movement, LOD transitions are legible.
  Supplied pictures and text briefs are not meshes or `.uasset` files.

### M16 — Rig and animation delivery

- Minimum human set: idle, walk/run, turn, interact, command, evade where approved, hit
  reaction and safe withdrawal. Eco-Kin set: idle/breathe, move/turn, notice/warn, approach,
  refusal/withdraw, rest and one clearly telegraphed technique.
- Reuse only approved compatible skeleton families; record root-motion policy, retarget
  settings, foot/ground constraints and gameplay notify ownership. Notifies report events,
  not client-authoritative damage. Refusal pose must not trap a subject in ceremony.
- Acceptance M16-A: slope/step/turn/recall and interrupted technique have no doubled hit,
  collapsed joint or attachment drift in the packaged Issue #10 benchmark.

### M17 — Sound/VFX readability delivery

- Minimum cue matrix: notice, warning, invitation, refusal, recall, care need, hazard
  telegraph, safe resolution and restored ambience. Pair each critical sound with icon,
  caption or spatial animation. Sonic powers stay species-specific.
- Cues carry event identity and relevance; late/duplicate unreliable cosmetic messages
  never reapply gameplay. Budget concurrency/distance and provide reduced-flash variants.
- Acceptance M17-A: muted/reduced-motion play still communicates choices and threats;
  simulated packet loss loses only cosmetic flourish, never the underlying outcome.

### M18 — Habitat pocket, navigation and streaming delivery

- Author one approved existing cell with approach, comfort/escape area, clue route,
  hazard, shelter, restoration interaction and a safe departure. Keep traversal playable
  without winning an optional duel or accepting a bond.
- Data readiness gates collision/nav plus persistent encounter reconstruction. A visible
  actor or sky effect is not proof that collision and pathfinding are loaded.
- Acceptance M18-A: unload mid-approach, then reload; no population duplicate, geometry
  overlap, blocked escape or restored hazard becoming dangerous again without a story event.

### M19 — Multiplayer and mode delivery

- Follow PR70's offline/private co-op/PvE/casual/ranked/raid/tournament profiles. Carry
  existing eight links and one active campaign partner; explicit simulation team counts
  remain mode data. Match results cannot force wild bonds or unlock public geography.
- Host owns encounter claims, consent, costs, objective results and receipts; migration,
  rejoin, world revisions and late join use existing save/server architecture. VFX is
  not the only replicated state. No cross-server refresh of depleted resources.
- Acceptance M19-A: two claimants, duplicate/reordered requests and a disconnect at
  commit produce one consistent result; ranked no-contest/recovery follows mode policy.
  Running servers, platform cross-play and matchmaking are not delivered by reference CI.

### M20 — Save/recovery and promotion gate delivery

- Extend versioned existing records for individual, relationship, ceremony checkpoint,
  form, plot, care, mission and weather cursor; persist transaction result alongside
  mutation. Unknown mandatory versions quarantine for migration rather than resetting.
- Crash before commit resumes pending/deferred safely; crash after commit reconstructs
  the same result. Missing cosmetic assets never erase an individual or grant a reward.
- Acceptance M20-A: save/reload at every boundary, changed habitat/form registry and
  duplicate receipts; compare exact identities, resources and durable outcomes.
- Runtime promotion needs exact SHA/toolchain, UHT/UBT/Editor/PIE, Issue #10 rig test,
  packaged Win64 launch, save/load and server tests plus measured performance evidence.

## Connected field-loop reference and scope

`09_Technical/Reference/Encounters/field_loop_contract.py` extends the existing encounter
reference lane. It implements original offline weather snapshots, bounded strain
updates, legal-action selection, guarded boss phases, crop progress/harvest reservation,
approved form invitation checks and read-only D.A.H.L.I.A. advice. It neither owns a
new bond nor replaces any runtime service. The existing encounter and Kindling oracle
remains the on-ramp; these references specify downstream behavior for its integration.

A connected test shares one storm snapshot across advice, AI safety and plot growth,
then applies strain/recovery and checks that a complete form gate set still cannot
bypass refusal. The small cycle durations, capacities and fixture IDs are test data,
not approved game balance, shipped content, permanent Dex records or visual assets.

No complete game, imported rig, animation clip, widget, level, network session or real
inventory/bond/form transaction is produced by these tests. Exact references, commands,
results and remaining native work belong in the companion README and patch notes.

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

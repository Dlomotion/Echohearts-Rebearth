# First playable encounter and Kindling slice

Status: original content/interaction brief, not placed maps or authored assets.
Attach to the existing Field Academy/First Kindling lesson and approved Issue #10
human + Eco-Kin asset slice. Actual production identity and map names come from the
existing registries; fixture IDs in tests must never be shipped as species/quest IDs.

## The five-minute experience

Arrival: a cleared path borders a damaged water channel. Footprints, bent grass and
an intermittent call suggest an individual nearby. The player can keep walking;
no camera lock or forced fight occurs. A.E.G.I.S. labels a partial observation rather
than claiming knowledge the player has not earned. D.A.H.L.I.A. offers one useful prompt.

Observation: keep distance and scan the habitat. The individual is sheltering from
a local hazard. Signs and posture explain why. The player may inspect the channel,
help from outside the comfort zone, back away or defer. No combat-damage threshold.

Protection: remove an authored environmental danger or preserve a safe escape path.
This may be a simple approved interaction in the graybox. It does not require
deliberately creating harm first. Progress records an actual objective event, not
standing in a trigger while a timer pretends the problem was solved.

Calm: stop pursuit, create space and wait for a readable approach. The individual
can remain wary. Food/water and appropriate care may be available if species design
supports them, but they do not purchase consent. The prompt is an invitation, not
a charging capture reticle.

Kindling: the Eco-Device shows the living Anima-Link while the individual chooses.
The camera preserves an exit route and control to cancel. Reduce-flash/static
presentation and hold/confirm options convey the same decision. No mandatory rhythm
timing, mash meter, ownership text or score bar fills to manufacture agreement.

Resolution: Bond creates an authorized relationship record only after fresh evidence
and consent; Release leaves the individual free; Defer preserves known observations
and offers another eligible opportunity. None deletes the individual. The mentor
acknowledges safe handling even when no bond occurs. This lesson must not softlock
because the player respected refusal.

## Screens and interaction states

| Surface | Required content | Input and denial behavior |
| --- | --- | --- |
| Habitat observation | Known clue, uncertainty, safe distance cue | Observe/interact; never reveal protected coordinates |
| Individual approach | Posture/consent text + icon, current hazard | Protect, wait, back away; attack not remapped to confirm |
| Kindling invitation | Invite, release, defer; care/refusal reason | Hold or confirm alternatives; no automatic accept |
| Ceremony | Stable partner framing, restrained device effect | Cancel remains available until authoritative commit |
| Relationship result | Actual result, care need, next available action | No 'captured' inventory popup |
| Device roster | Bonded individual, readiness, summon/refusal | Respect existing charge/strain, healing and ceremony guards |

## Proposed input actions (names only until BUILD inspection)

| Context | Action intent | Keyboard/gamepad/touch requirement |
| --- | --- | --- |
| Explore | Move, Look, Jump, Sprint | Analog/vector mapping and configurable camera sensitivity |
| Explore | Interact, Observe, BackAway | Remappable distinct controls, readable touch affordances |
| Partner | OpenCommands, SelectPartner, Summon, Recall | Wheel/list choice without rapid precision taps |
| Ceremony | Invite, Confirm, Release, Defer, Cancel | Focus-safe remapping and hold/toggle alternatives |
| UI | Navigate, Accept, Back, Scroll | Focus indicators and one active input context |

Do not write arbitrary engine input keys into the unknown character Blueprint.
Proposed mapping contexts: Exploration, PartnerCommands, Ceremony and UI. Inspect
existing Enhanced Input actions/contexts before choosing implementation symbols.

## Minimum authored content inventory

| Deliverable | First pass | Production acceptance |
| --- | --- | --- |
| One human | Approved Issue #10 proxy with usable collision | Approved body/rig, locomotion, interaction and camera framing |
| One approved Eco-Kin | Existing silhouette/rig family, not new species | Idle, walk, turn, observe, warn, approach, refuse, rest |
| Hip Eco-Device | Graybox socket and state light | Approved Living Porcelain/Prism Core geometry/materials |
| Habitat pocket | Existing test level/cell + approach/escape/shelter | Authored placement, streaming/nav/collision, ecological clues |
| Hazard interaction | Clear safe/remove/defer state | Mission event, persistent restored condition, no reward replay |
| UI | Text/icon prototype with every reason | Final widgets, localization, accessibility and platform focus tests |
| Audio/VFX | Distinct placeholder cues labeled temporary | Original calls/ambience/device cues, captions, reduced-flash variants |
| Mission | Existing first Kindling lesson attachment | Mentor acknowledgement for Bond/Release/Defer, save recovery |

Meshes, rigs, animation clips, Niagara/audio assets and UMG widgets are not generated
by this document or the Python tests. Approved reference art must guide DCC production.
No .uasset, .umap or cooked content is fabricated as a text placeholder.

## Required scenario runs

1. Normal observation/protection/calm/invitation/bond, followed by existing summon/recall.
2. Refusal at invitation, after invitation and immediately before relationship commit.
3. Player chooses Release or Defer; lesson still records the appropriate safe resolution.
4. Healing, threat, streaming unload or ceremony interruption; preserve individual identity.
5. Save/load after every phase; no repeated bond, first-clear reward or duplicated actor.
6. Two players approach the same individual; host relationship authority resolves one
   consistent result without commodity ownership or silent state overwrite.
7. Weather and cell revision change between spawn proposal and spawn; revalidate.
8. Keyboard/gamepad/touch, muted audio, high-contrast/text cues and reduced flashes.

## Production sequence

1. Obtain the audit and readable BUILD source; reproduce the reported Corruption fixes
   and inspect actual ownership/modules/dependencies. Confirm Windows UE5.8.3 toolchain.
2. Run the existing foundation gate and Issue #10 body/animation slice. Retain UHT/UBT
   and basic packaged launch evidence. Wire move/look/interact using existing input.
3. Author the small graybox habitat with safe navigation and approved proxy actors.
4. Implement M02/M03/M04 in the existing world/AI owners, then M05 in relationship/mission owners.
5. Add minimal UI and pose/animation/cue content alongside the loop, not after all story work.
6. Run single-player save/recovery and then multi-client conflict/late-join tests.
7. Extend the already planned 4–6 Eco-Kin vertical slice with enemy AI and one authored
   boss only after the ordinary field loop works. Expand weather/farm/forms/online breadth later.

This is a dependency refinement, not a replacement for the authoritative production
order. More unconnected classes or text catalogs do not replace a playable slice.

## Storm at the invitation — scene extension, 2026-10-18

**PROPOSAL / NOT YET VERIFIED.** Extend the same habitat pocket and mission; no new
region, species, quest meter or campaign opening. A storm warning arrives after the
player restores the channel but before the relationship commit. The protected route
remains open. The Eco-Kin steps back toward shelter; the player's respectful response
is the dramatic action, rather than defeating an enemy or overcoming refusal.

| Beat | Original dialogue / presentation | Authoritative outcome required |
| --- | --- | --- |
| Warning | Caption: “Wind rises through the channel.” Grass bends; stable text/icon warning accompanies the optional low wind cue. No strobe or camera seizure. | Current host weather/cell snapshot invalidates unsafe approach; a previously prepared spawn proposal cannot authorize a new actor. |
| Invitation pauses | D.A.H.L.I.A.: “The shelter route is still open. Let it decide from safety.” | Disable invitation confirmation with “Approach paused: habitat unsafe”; retain Cancel, Release and Defer. |
| Individual withdraws | A backward step and turned posture communicate refusal without a red failure score. Caption: “It returns to shelter.” | Fresh refusal supersedes earlier willingness; no bond, summon, device charge or forced pursuit. |
| Player chooses Defer | Player response option: “We can leave the path clear.” Mentor: “Then our work here still matters.” | Save restoration and observation in their existing owners; resolve this attempt safely once. |
| Return after conditions change | Mentor: “The channel held. Watch before you approach again.” | Re-evaluate weather, cell readiness, care and willingness. A new eligible attempt never inherits old consent. |
| Optional later Bond | D.A.H.L.I.A.: “A mutual response is present. You may still step back.” | Commit only against fresh host evidence and the existing relationship transaction. No automatic result on timeout. |

### Training and HUD acceptance

Training stays in the existing 04_Systems progression track. Safe-handling lesson
resolution and Stage 04 completion are different events: Release/Defer must allow
the story to continue without falsely recording a first bond. Stage 04: First Kindling
advances only after the existing progression owner confirms a genuine first bond;
do not grant bonded-command permissions from an observation or deferred attempt.
Player level, Tamer of Beasts license, Kindling relationship strength, individual
Eco-Kin development, Circle Balance and territory progression keep their own owners.

Use the existing A.E.G.I.S. display fields:

- **TRAINING — MAIN STORY PROGRESS**
- **Stage 04: First Kindling** (only when this is the actual current stage)
- **Current Trial:** Establish a genuine first bond; respectful deferral is available.
- **Objectives completed:** Use actual progression-owner counts; no fabricated completion.
- **Next Unlock:** Bonded companion commands, after confirmed first bond.

The scene panel may separately state “Habitat restored; invitation deferred.” It
must not introduce another competency meter or imply a bond exists. If Stage 04
is not yet active, render the actual stage rather than forcing this fixture label.

### Recovery and content checklist

1. Withhold the relationship commit while unsafe; recheck late refusal even if an
   earlier invitation was accepted. Restored ecology must survive a canceled ceremony.
2. Save/reload at warning, withdrawal and Defer. No duplicated individual, first-clear
   event or false Stage 04 unlock; unloaded habitat resolves to safe waiting.
3. Two-player test: one participant defers while another attempts acceptance. The
   existing host authority resolves one current individual state, without forced bond.
4. Author six short captions above, withdrawal/shelter poses from the existing rig,
   one non-flashing warning icon and muted-audio equivalent. These assets are requested,
   not present or imported; use the existing art/animation/audio workstreams.
5. Keep approach, shelter and escape connections in the existing graybox. No world
   coordinates, hidden-cave route, Viewpoint unlock or new cartography claim follows.

## Quiet return — scene continuation, 2026-10-19

**PROPOSAL / NOT YET VERIFIED.** Continue the same restored channel scene after the
storm. The environment shows the player's earlier care: water passes under the
cleared obstruction, a dry shelter path remains open and flattened grass marks the
withdrawal. Reuse existing location and individual identity; returning must not reroll
a new rare individual just because a save encoded a number or reordered habitat tags.

| Moment | Interaction / original line | Required feedback |
| --- | --- | --- |
| Revisit | Player may inspect the channel without approaching shelter. D.A.H.L.I.A.: “The water is moving. The shelter remains undisturbed.” | Existing restoration state drives the change; avoid fabricated repeat rewards. |
| Fresh observation | Tracks may show departure or continued sheltering, according to authored host state. | Show “Observation needed” rather than reusing yesterday's willingness. Unknown does not mean absent or consenting. |
| Safe distance | Mentor: “A clear path gives it a choice. Leave room for that choice.” | Walk away, Observe and Defer stay available; no lure-spam progress or pressure timer. |
| Optional approach | If the individual independently approaches, allow the existing invitation. If it leaves, do not chase-lock the camera. | Fresh posture/care/consent gates; a restored habitat is not entitlement to partnership. |
| Review | After Release/Defer: “The channel is restored. Your invitation can wait.” After actual Bond: “Now the care continues together.” | Branch from committed relationship and mission results. Never display the Bond line from a pending invitation. |

Audio/art handoff for the existing M16/M17 workstreams: water trickle with a matching
environmental caption, optional distant shelter movement cue, readable dry-path
silhouette and a calm withdrawal pose. Muted audio must preserve all actionable
information in text/pose. Avoid automatic zoom, flashing consent signals or mandatory
rhythm accuracy. These are asset requests; no clip, rig, sound, VFX, widget or level
has been imported by this document.

Acceptance: reload the same host snapshot with reordered membership tags or numeric
0/1 represented as floats; do not change the encounter proposal solely for that reason.
A real weather/cell/population revision change must still require revalidation.
Restore-without-bond persists; first-clear events do not replay; Stage 04 remains
incomplete until the actual genuine bond event. Unloaded or unknown shelter state
offers safe waiting/departure and cannot fabricate an encounter.




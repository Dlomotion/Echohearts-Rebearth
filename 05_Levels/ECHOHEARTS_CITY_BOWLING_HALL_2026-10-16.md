# Echohearts City — Community Bowling Hall
**Date:** 2026-10-16 · **Status:** PROPOSED LEVEL / SOCIAL SYSTEM, NOT BUILT

## Identity and placement
One playable, accessibility-first bowling venue in **Echohearts City**. District and coordinates **unassigned** pending the approved city map. Exterior entry is public, unobstructed and weather-reactive; interior is a restored community attraction. The venue complements existing housing and community-event systems, not an unrelated new major sport league.

### Gameplay
- **Modes:** solo free roll, 2–4-player cooperative/social lane, local-vs-online league match (competitive only if sanctioned/approved).
- **Frames:** standard ten-pin scoring rules proposed; server independently reconstructs score from authorized pinfall/strike/spare records. An optional *practice* ruleset changes no ranked totals.
- **Controls:** aim left/right, choose launch speed and spin, release within bounded approach; touchscreen drag + power rail, keyboard, controller and accessible auto-assist.
- **Ball motion:** physics solver uses authored lane friction/oil maps and constrained player inputs; deterministic approximation for network/replay is acceptable. Never claim exact physical ten-pin simulation before proof.
- **Player expression:** cosmetics/animations not power upgrades; ball art reflects Rebearth materials and restoration events without imported branding.
- **Community:** restoration of the flooded/repaired bowling hall unlocks venue services, social NPC chatter, scoreboard, small crafting/decor rewards and non-combat relationship scenes. Eco-Kin may attend voluntarily in habitat-safe spaces, never be used as pins/balls or mandatory labor.

### In-world 1:30 check-in proposal
A daily **13:30 in-world** community league check-in can be shown in the A.E.G.I.S. city event calendar **after** temporal rules are approved. This is *not* confirmation of a real-world bowling reservation or appointment. Never infer or schedule a real reminder from this source; the user would need to specify a date.

### Sample safe match state
`Open → Reserved → LaneReady → ActiveFrame → ScoreReview → Complete`. Timeouts and reconnects persist authoritative `MatchId`, `FrameNumber`, `PinMask`, `AcceptedThrowId`, `ScoreRevision`. One accepted ball release per authorized frame turn; duplicate hits with the same throw ID are replay-safe. Non-participants cannot submit scores.

### Dependencies / gates
- World POI approved against existing city layout.
- Lobby, match/friends/co-op permissions; no online account secrets in payload.
- Controlled physical ball + pins, smooth lanes, rack mechanism, safe spectator placement, accessible camera.
- Gamepad/touch UI, captions, score narration, motion reduction.
- Server scoring tests, match disconnect/rejoin, offline equivalent.
- Story/community progression and cosmetic reward legality check.
- Measured UE5.8 runtime, package and QA evidence.

**State:** gameplay design authored; models, map actor, physics scene, animations, multiplayer service, operating schedule and playable implementation **not yet built**.

# ECHOHEARTS: REBEARTH — Fight Layout

How fights work, what they're built from, and how 636+ EcoKin share one combat
system without 636 scripts. Canon-corrected and reconciled with the systems
already built. (CONCEPT — the code systems named here as already built are
IMPLEMENTED / NOT COMPILED / NOT TESTED.)

## First: what that AI got wrong, corrected

- **"1,125 creatures" → 636.** The Dex runs to 636. The 1,120 number is the
  historical *name pool*, not creatures. The data-driven scaling below is sized
  for the real Dex.
- **No generic stats.** There is no BaseDamage, Health, Speed, or Weight stat.
  The four attributes are **Vibrance, Density, Harmony, Purity** — everything
  combat-relevant derives from them (mapping below).
- **No "deployment."** Partners are **Released** (never deployed/summoned as
  objects). A companion is a relationship, not a container.
- **No fatalities.** Beaten wild EcoKin **withdraw** — never killed. The
  "cinematic ultimate" is the **Resonant Climax**: purification and walk-back,
  never a killing blow.
- **No "Cyber-type."** Tech maps to **Voltic** (Synth-Origin).
- **UE5 only.** The engine is locked on UE 5.8.3; Unity variants are dropped.
- **"EcoKin" is not a typo.** It is original IP — no outside fighting-style
  canon exists to look up. The styles below are ours.

## What already exists (do not rebuild)

- **Anima-Link Combat** — real-time; EcoKin strain feeds back as stamina/health
  consequences on the Tamer. Every fight below is fought *through the link*.
- **Battle modes** — Duel (1v1 real-time), Raid (co-op vs Cataclysm-class),
  Sparring.
- **Harmonic Momentum** — the tempo system rewarding clean exchanges.
- **6 essence chains** — cross-essence combo routes.
- **Resonant Climax** — the ultimate: a purification finish, never a fatality.
- **Binding ceremony / Encounter states** — fights begin by encounter state
  (Rage/Alpha/Blight/Hollow), never by ambush-killing.

The layout below plugs INTO these. Nothing here replaces them.

## The four Resonant Styles (new proposal — names vetoable)

Each EcoKin fights in the style of its dominant attribute:

| Style | Attribute | Identity |
|---|---|---|
| **Tempo** | Vibrance | Fast pressure, rapid pokes, hit-and-run. Low commitment per move, wins by volume and momentum. |
| **Bastion** | Density | Rooted stance, absorbs hits (super armor on heavies), slow devastating counters. Wins by punishment. |
| **Cadence** | Harmony | Flow and rhythm — chains, redirects, stance-dancing. Wins by keeping the exchange on its beat. |
| **Clarion** | Purity | Precise, decisive strikes; purification-typed finishers hit corrupted targets harder. Wins by judgment. |

An EcoKin's style is set by its highest attribute; Growth Rites can shift the
balance, which visibly changes how it fights. A Piplin (Flora healer) reads as
Cadence; a Bastodon reads as Bastion; a Zephydra as Tempo.

## The three AI movement profiles (kept from the draft — valid method)

Under the styles, wild/partner AI moves on one of three profiles:
**Juggernaut** (walks the center line, trades), **Skirmisher** (orbits, darts
in and out), **Sentinel** (holds mid-range, punishes whiffs). Style × profile ×
essence = every EcoKin feels distinct with shared math underneath.

## The data-driven skeleton (kept — this is the right architecture)

- **~12 rig archetypes** (Biped, Quadruped, Avian, **Serpentine** — the new
  snake variants slot straight in — Brute, Aquatic, etc.). Rigs share raw
  animation; visuals differ per EcoKin.
- **~50 move profiles** (Fast Jab, Heavy Launcher, Safe Mid Poke…) with frame
  data: **Startup / Active / Recovery**. Missing = punishable. That is the
  whole anti-mash design: whiffed moves leave Recovery frames open.
- **Moveset Data Assets** per EcoKin: same profile, different animation
  montage + essence VFX. Two EcoKin share balance math and look like completely
  different fights.
- **Hitbox/Hurtbox via animation notifies**: hitboxes live only during Active
  frames, spawned on skeletal sockets; hurtboxes are permanent and tagged.
  One-hit-per-window tracking. (UE5 C++, no physics-trigger hacks.)
- **Input buffer**: one queued input, short expiry; mashing faster than the
  window drops the input. Cooldowns surface on the UI as radial wheels.
- **Guard**: blocking drains a Density-derived guard meter; empty = **Guard
  Break** (stagger, guaranteed punish). Blocking forever is impossible by design.
- **Lock-on camera**: midpoint framing between partner and opponent, smooth
  interpolation, player orbit.

## Attribute → combat mapping (the only numbers the system needs)

- **Vibrance** → tempo: startup speed, chain windows, Harmonic Momentum gain.
- **Density** → resilience: guard meter size, knockback resistance, super-armor
  thresholds.
- **Harmony** → flow: essence-chain routing, cancel windows, partner-sync timing.
- **Purity** → judgment: finisher power, purification bonus vs corrupted targets,
  Resonant Climax charge rate.

No ATK/HP/SPD/DEF anywhere. Ever.

## How a fight flows (Duel example)

1. **Encounter state sets the terms** — a Blight-state wild EcoKin fights
   desperate; a calm one may yield early.
2. **Release** — the partner takes the field through the Anima-Link. The
   Tamer's stamina is now shared stakes.
3. **Exchange** — Style × profile × essence chains; frame data punishes mashing;
   Harmonic Momentum builds on clean reads.
4. **Guard breaks, counters, whiff-punishes** — Density and Vibrance decide
   these, not reflexes alone.
5. **Resonant Climax** — when charged, the cinematic finish: the opponent is
   purified, yields, or is walked back. Wild losers **withdraw**. Nothing dies.
6. **Aftermath** — Anima-Link strain settles on the Tamer; Kindling shifts with
   how the fight was fought (clean victory bonds; cruel play strains).

## Raid note

Cataclysm-class fights are multi-phase purifications, not DPS races. Phases are
gated by rite-circle mechanics (protect the circle — broken circle pauses the
rite), per the Rite Defense system. The Shadow Beast Prime trailer is the
reference cut.

## Build order (each ends with Tay compiling on his machine)

1. Frame-data moveset asset + one rig (Biped) + hitbox/hurtbox notifies.
2. Input buffer + guard meter (Density-mapped).
3. The four styles as attribute-derived behavior modifiers.
4. AI movement profiles (Juggernaut/Skirmisher/Sentinel).
5. Lock-on camera.
6. Essence-chain routing into the existing 6 chains + Resonant Climax hookup.

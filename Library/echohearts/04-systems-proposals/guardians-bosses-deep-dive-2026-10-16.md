# The Deep Dive: Sanctuary Residents & Boss Fights (2026-10-16)

**Status:** CONCEPT + code extensions (`Source/Echohearts/Public|Private/Sanctuary/`, `Source/Echohearts/Public|Private/Progression/`) · IMPLEMENTED / NOT COMPILED / NOT TESTED / NOT RUNTIME VERIFIED

## Roster decision (mine — vetoable by Tay)
Tay pasted a ChatGPT output that reskins Terraria's entire NPC/boss roster 1:1 ("Attuner (Formerly the Guide)", "Core Gloop (Formerly King Slime)", etc.). That is Terraria's content with new names — Tay's standing IP rule is methods, never content. **The pasted roster is not imported.** Our roster stands: the 6 Sanctuary Residents (Mender, Artificer, Chronicler, Bondkeeper, Purifier, Scout) and the 14-boss order. "Resonance Guardians" is not used as an NPC title — "Guardians" already belongs to the green-and-gold Guardians emblem in canon.

**What the paste contributed (methods only):** multi-phase boss fights with health-% thresholds; add/spawn phases where the boss is vulnerable only after adds are cleared; arena-forcing mechanics; strict alternating attack cycles; high-stakes conditional states; NPC anchoring to built infrastructure; services that expand with progression; residents who defend themselves.

## The rules every fight and resident obeys
- **Defeat, not death.** Corrupted alphas and Beasts are subdued — and can be purified. Human bosses (Society Herald, Society Paragon) are driven off. Nothing sentient is killed, ever.
- **Phases are honest.** Every boss changes at health-% thresholds. The fight tells you it's changing.
- **Arenas are half the fight.** Safe zones, hazards, geometry — positioning matters as much as damage.
- **Adds are manageable.** Corrupted adds can be purified mid-fight, not just destroyed.
- **Optional never gates.** The four optional bosses reward the curious; the story never waits on them.

---

# PART 1 — SANCTUARY RESIDENTS

## Anchoring infrastructure (the mechanic)
A resident moves in when two things are true: their **achievement condition** is met, and their **anchor** is built. Nobody comes to a Sanctuary that isn't healing, and nobody sleeps on the floor.

Every anchor needs:
- **Aura Pylon** — the Sanctuary's beating heart. Every resident anchors within its range. It powers, connects, and says *people live here*.
- **Tuning Station** — their work surface, flavored per role (the paste's "table," ours).
- **Recharging Node** — their rest nook (the paste's "chair"). A resident without rest burns out and their services slow.
- **Secure energy walls** — the Sanctuary's perimeter must hold a minimum defense before anyone moves in.

Build order matters: Pylon → walls → station → node. The Chronicler puts it best: *"A Pylon is a promise. Walls are keeping it."*

## The six, in full

### 1. Mender — arrival: your first Growth Rite
- **Anchor:** Restorative Bench (Tuning Station) + Recharging Node in the quiet corner.
- **Base services:** Heal Companion — restores a hurt partner to full; Ease Link Strain — walks accumulated strain down after hard fights.
- **Expansion:**
  - *Tier 2 — 3 bosses defeated:* **Field Revival** — reaches a withdrawn partner through the Anima-Link and brings them back mid-expedition.
  - *Tier 3 — The World Breathes Easier:* **Mass Restoration** — after a boss fight, the whole active party is tended at once.
- **Combat/defense:** The Mender doesn't strike — they *steady*. In a fight they project a soothing pulse that slows link-strain accumulation for everyone nearby, and raise a ward-barrier around the wounded. Enemies learn to regret ignoring them; allies learn not to fight without them.

### 2. Artificer — arrival: your first shed/gifted resources change hands
- **Anchor:** Forge (Tuning Station), always warm.
- **Base services:** Craft from Shed Resources — turns willingly-given materials into gear; Forge Concord Catalyst — makes the catalysts fusion rites demand.
- **Expansion:**
  - *Tier 2 — 6 bosses defeated:* **Retuning** — re-rolls a weapon's or instrument's stat emphasis within its existing budget (nothing inflated, everything rebalanced).
  - *Tier 3 — The Restoration Era:* **Masterwork** — one-of-a-kind catalysts and instruments, each named for the hands that made them.
- **Combat/defense:** Hurls overloaded forge-tools in crackling shock bursts. Short range, heavy impact, and absolutely delighted to be useful.

### 3. Chronicler — arrival: 25 Dex identities registered
- **Anchor:** Archive Desk (Tuning Station), buried in living records.
- **Base services:** Consult D.A.H.L.I.A. — the Sky Archive answers through them; Read Lineage Record — any fused EcoKin's full parentage, on demand.
- **Expansion:**
  - *Tier 2 — 5 bosses defeated:* **Rite Readiness** — tells you exactly what's missing for any Growth Rite, no guessing.
  - *Tier 3 — The Land Cools:* **Corruption Forecasts** — reads the wilds and warns which territories are darkening next.
- **Combat/defense:** The Chronicler is no fighter — they're something better. They shield the archive, study the enemy, and *call out patterns*: marked boss weak points that the whole party can exploit. Knowledge as a weapon, wielded precisely.

### 4. Bondkeeper — arrival: any partner reaches 80% trust
- **Anchor:** Hearth (Tuning Station) — the warmest seat in the Sanctuary.
- **Base services:** Kindling Guidance — care plans that build trust faster; Care Remedy — repairs a bond strained by neglect or hard choices.
- **Expansion:**
  - *Tier 2 — any partner reaches 95% trust:* **Trust Recovery** — structured plans for bonds damaged by forced strain or fracture-scares.
  - *Tier 3 — The World Breathes Easier:* **Deep-Kindling Retreats** — days of focused care that forge unbreakable trust.
- **Combat/defense:** Soothes agitated wild EcoKin with a low harmonic hum — can *calm adds mid-fight*, opening them to purification instead of combat. The gentlest resident, and in the right fight, the strongest.

### 5. Purifier — arrival: your first Corruption form walked back
- **Anchor:** Cleansing Font (Tuning Station), always lit.
- **Base services:** Aid Purification — walks corruption down faster alongside you; Cleanse Blight Taint — scrubs corruption from gear, ground, and Sanctuary edges.
- **Expansion:**
  - *Tier 2 — a Severe corruption reverted:* **Deep Rites** — purification strong enough for the worst cases short of fracture.
  - *Tier 3 — Shadow Beast Prime defeated:* **Fracture-Warding** — shields a bonded partner from ever reaching 100.
- **Combat/defense:** Burns blight with cleansing light. Against corrupted adds and bosses, the Purifier is the hardest hitter in the Sanctuary — and the only one who fights *for* the enemy's future, not their end.

### 6. Scout — arrival: any region reaches 50% restoration
- **Anchor:** Map Table (Tuning Station), covered in marked charts.
- **Base services:** Region Intel — what's in a region, what's wounded, what's safe; Mark Corrupted Territory — corrupted zones appear on your map before you walk into them.
- **Expansion:**
  - *Tier 2 — 4 bosses defeated:* **Boss Recon** — reveals a boss's full phase list *before* you challenge it. No blind fights after this.
  - *Tier 3 — The Restoration Era:* **Safe Routes** — mapped paths that make long travel fast and safe.
- **Combat/defense:** Fights from range with a longcaster and *marks targets* — everything the party hits on a marked enemy hits harder. The Scout decides who dies first, politely.

## Sanctuary defense, in full
Defense = (sum of resident DefenseRatings) × (1 + restoration % / 100). When the Sanctuary is threatened — wild corrupted packs early, society strike teams late — residents fight beside the tamer. Their power grows as the world heals: a Sanctuary that has restored more is literally harder to break. This is where the Society War arc bites — when the societies move openly, your people stand with you.

---

# PART 2 — THE FOURTEEN BOSS FIGHTS

## How a boss fight works here
Every boss below lists its **arena** (which is half the fight), its **phases** (entered at health-% thresholds — the fight always tells you it's changing), its **signature attacks**, its **adds**, and **what makes it distinct**. Corrupted-alpha bosses reuse the Twelve Wounded forms and Dex IDs — no new identities.

---

### 1. Gloomtrot — the Wrongward Courier (OPTIONAL · corrupted alpha · Frostrelle 498)
*It still runs its route. Faithfully. Wrongly.*
- **Arena:** Mist Coasts — fog-shrouded shoreline crossed by three old courier lanes marked with leaning posts.
- **Phase 1 — Route Runner (100–66%):** Gloomtrot sprints the lanes in fixed patterns, laying blight trails behind it. The fight is positioning: cross lanes between passes, never stand in a trail.
- **Phase 2 — Wrong Deliveries (66–33%):** It starts dropping corrupted message-packets that bloom into volatile blight buds (adds/hazards). Clear them quickly or they detonate into wide blight bursts.
- **Phase 3 — Lost Route (33–0%):** The lanes scramble — dashes come from unpredictable angles, telegraphed only by a mournful courier's horn a beat before each charge.
- **Distinct:** The only lane-based fight. Footwork is the entire game. Defeating it teaches purification — the first boss most tamers will choose to purify rather than just subdue.

### 2. Rustmaul — the Corroded Hoard (REQUIRED · corrupted alpha · Brassamble 503)
*Gold gone black. The gentle defender smashes first now.*
- **Arena:** Sunforge Gardens — a ruined forge-hollow littered with bronze debris (cover that breaks).
- **Phase 1 — Hoard Guard (100–60%):** Heavy slam shockwaves and charging tackles. Its corroded plates absorb frontal damage — flank it or strike from behind.
- **Phase 2 — Burrow and Brood (60–0%):** At 60% it burrows and releases **3 Corroded Mites** (adds). While any mite lives, Rustmaul stays buried, hurling debris from below. Clear the mites to force it up, enraged: faster slams, and its footsteps leave verdigris pools that corrode footing.
- **Distinct:** The add-gated burrow — "clear the small to reach the big." Falling means Sunforge restoration begins.

### 3. Blightstorm — the Blackened Sky (REQUIRED · corrupted alpha · Tempeskar 502)
*The storm that learned to hate.*
- **Arena:** Thunder Groves storm belt — open highland under a bruised sky; storm cells drift across the field.
- **Phase 1 — Black Rain (100–50%):** Telegraphed lightning strikes (glowing ground markers, then the bolt) plus slow-drifting acid-rain cells to kite around.
- **Phase 2 — Eye of the Storm (50–0%):** The tempest goes arena-wide. A calm eye drifts around the field — stand inside it or take constant storm damage. Blightstorm periodically dives *through* the eye, so the safe zone is never safe for long.
- **Distinct:** The moving safe zone. The fight is reading the storm, not out-damaging it. Falling triggers **Skies Clear** — flight routes open across the storm belt.

### 4. Fulgurix — Storm Raptor of the Highlands (REQUIRED · Beast)
*The sky's own hunter, and it has noticed you.*
- **Arena:** Highland rookery — cliffside updrafts; flight and riding are fully usable here.
- **Phase 1 — Sky Duel (100–66%):** Dive-bomb dashes with a wingbeat telegraph; thunder calls (delayed lightning AoE where you *were* — keep moving).
- **Phase 2 — Stormcaller (66–33%):** Fulgurix darkens the sky and chains lightning between its high perches. Smash the perches to break the chains, or the arcs intensify every 20 seconds.
- **Phase 3 — Raptor's Frenzy (33–0%):** Strict alternating cycles — dive cycle (three dives) → storm cycle (lightning barrage) → repeat. Learn the rhythm or fall to it.
- **Distinct:** The only fully aerial boss fight; the finale is a rhythm to learn, not a wall to break. Falling opens the highland regions.

### 5. Rotwarden — the Strangling Canopy (OPTIONAL · corrupted alpha · Grovetitan 510)
*The forest's protector, strangling what it once shaded.*
- **Arena:** Ancient groves — tight old-growth forest, root networks underfoot.
- **Phase 1 — Grasping Dark (100–50%):** Root snares erupt to hold you in place; drifting spore clouds force constant repositioning.
- **Phase 2 — Heart of Rot (50–0%):** At 50% it roots itself and turns **invulnerable**, extending **4 Heart-Roots** (adds) through the grove. Destroy the roots to expose it — each root destroyed permanently weakens its snares. When exposed, it fights in a frenzied slam until it re-roots at 25% for a final root phase with 2 hearts.
- **Distinct:** A stationary invulnerability + add phase — the forest itself is the boss. Optional, but purifying it begins ancient grove restoration.

### 6. Bastodon — the Walking Fortress (REQUIRED · Beast)
*It does not hurry. It does not need to.*
- **Arena:** Caravan flats — open ground with canyon walls on two sides and breakable cover rocks.
- **Phase 1 — Siege Engine (100–70%):** Stomps send out shockwave rings (jump or outrun the ring); when it withdraws into its shell it is **invulnerable** — strike the legs when it steps.
- **Phase 2 — Living Battering Ram (70–30%):** It charges in straight lines. Dodge *toward* the canyon walls so it strikes stone and stuns itself — the arena is your weapon.
- **Phase 3 — Rampart Break (30–0%):** Enraged: stomps chain into doubles, and it spins its shell like a grinding wheel while advancing.
- **Distinct:** Patience over damage. The wall-bait mechanic makes the arena do the work. Falling opens the caravan routes.

### 7. Hadalon — the Abyssal Leviathan (REQUIRED · Beast)
*The deep does not give back what it takes. Take nothing it offers.*
- **Arena:** Deep ocean trench — fought from a diving platform and wave-skimmers; light is scarce and precious.
- **Phase 1 — Lure Lights (100–60%):** Bioluminescent lures drift up — most are decoys that detonate, one marks the real Hadalon circling below. Read the lights; strike the marked one when it breaches.
- **Phase 2 — The Drag Down (60–30%):** At 60% it drags the fight deeper — near-darkness, pressure surges shoving you around. Navigate by your own light and its glow; it strikes from the black between surges.
- **Phase 3 — Maw of the Deep (30–0%):** Breach attacks from below, telegraphed by bulging water; whirlpools pull you toward its mouth — fight the current, punish the breach.
- **Distinct:** The only underwater arena; a fight about reading decoys and darkness. Falling opens the deep ocean regions.

### 8. Kryodon — the Glacial Behemoth (REQUIRED · Beast)
*Winter with a heartbeat.*
- **Arena:** Glacial rift — ice sheets over crevasses (falling in hurts); wind gusts push.
- **Phase 1 — Iceclad (100–60%):** Thick ice armor shrugs off most damage. Focus the glowing seams to shatter sections — shattered plates stay vulnerable permanently.
- **Phase 2 — Exposed (60–30%):** Armor gone, fury out. Sweeping tail strikes cover half the arena; ice-shard volleys force movement between tail sweeps.
- **Phase 3 — Whiteout (30–0%):** Blizzard drops visibility to near-zero. Kryodon's breath glows in the white before every charge — read the glow, not the body.
- **Distinct:** Armor-shatter as progression; a finale fought half-blind. Falling makes the glacial rifts safe to cross.

### 9. Pyrewyrm — the Magma Wyrm (REQUIRED · Beast)
*The mountain is awake, and it is angry at the sky.*
- **Arena:** Ashfall Spires — lava channels threading between rock islands.
- **Phase 1 — Burrow Hunt (100–60%):** Burrows constantly; dust trails telegraph its path — be elsewhere when it erupts.
- **Phase 2 — Magma Surge (60–30%):** At 60% the floor *becomes* lava except drifting rock islands. The fight turns positional: hold an island, punish its magma arcs, move when your island sinks.
- **Phase 3 — Cinder Fury (30–0%):** Faster burrows, triple eruptions, flame tornadoes that wander the islands.
- **Distinct:** The floor-is-lava phase — arena control over damage. Falling triggers **The Land Cools**: blight recedes across the fire-scarred regions.

### 10. Society Herald — Champion of the Secret Societies (REQUIRED · human)
*They don't want your EcoKin. They want your proof that bonds work — so they can break it in front of you.*
- **Arena:** A society forward camp — bannered, humming with domination-tech pylons that visibly strain the local wilds.
- **Phase 1 — The Duelist (100–66%):** The Herald fights personally and *fairly* — device-driven strikes, link-lashes, footwork. They're testing you. (They're also stalling.)
- **Phase 2 — The Leash (66–33%):** At 66% the Herald calls their bound **corrupted alpha partner** (add). Now it's two threats — but the partner can be **purified mid-fight**. Everything the Purifier taught you pays off here: turn their weapon into a rescue.
- **Phase 3 — Overdrive (33–0%):** The Herald forces their Anima-Link past safety — faster, harder, and visibly *wrong*. The strain damages them too; their health drains as they fight. This is the societies' cruelty made visible: they spend their own partner's life for an edge.
- **Distinct:** The only human boss. The mid-fight purification choice. An enemy that hurts itself to hurt you. Defeated = driven off, humiliated, and now *afraid of you*. Their retreat is when the societies stop watching and start coming — defend your Sanctuaries.

### 11. Nyctalon — the Night Raptor (OPTIONAL · Beast)
*You will hear it before you see it. That is the whole fight.*
- **Arena:** Night highlands — fought at night; scattered moonlight patches are the only reliable light.
- **Phase 1 — Silent Hunt (100–50%):** Near-silent dives from the dark; only the glint of its eyes telegraphs the strike. Stay near moonlight, watch the glints.
- **Phase 2 — Moonless (50–0%):** At 50% clouds swallow the moon — total darkness. Track it by *sound*: wingbeats before a dive, a shriek before a swoop. It grows bolder with longer dive chains, and bolder means more telegraphed if you're listening.
- **Distinct:** A sensory-deprivation fight — listening as a mechanic. Optional, and it grants night-sky navigation to those who brave it.

### 12. GROVANTIS — the Flora-Crystal Lion (REQUIRED · Beast)
*The king the wilds chose for themselves.*
- **Arena:** Flora-crystal heartlands — towering crystal formations that catch and throw light.
- **Phase 1 — Prism Guard (100–60%):** Its crystal mane **refracts ranged attacks back at you** — close in, or time strikes to the refraction rhythm. Crystal spikes erupt in spirals.
- **Phase 2 — Refraction Field (60–30%):** At 60% the arena fills with light beams at hard angles; safe lanes run between them. GROVANTIS charges *along* the beams — the geometry is the telegraph.
- **Phase 3 — Sovereign Roar (30–0%):** The roar shatters nearby crystals into shrapnel (dodge the glint-flash first). Then it fights exposed — mane dimmed, vulnerable, desperate, and faster than anything before it.
- **Distinct:** The reflect mechanic plus beam-lane geometry — a fight about angles. Falling opens the flora-crystal heartlands.

### 13. Shadow Beast Prime — the Fractured Apex (REQUIRED · Shadow condition)
*This is not an execution. It is a rescue.*
- **Arena:** The Fracture Scar — shattered ground where the world broke, drifting shadow at the edges.
- **The rule of this fight:** depleting its health does not kill it. At 0%, the **purification rite** begins — a timed protection sequence, not a damage check. A fractured one is never killed. It is brought back.
- **Phase 1 — Echoes of Pain (100–66%):** It fights with corrupted echoes of signature attacks you've already survived — Blightstorm's lightning, Rustmaul's slam, Fulgurix's dive. The fight is an exam on everything the journey taught you.
- **Phase 2 — Fracture Pulses (66–33%):** Arena-wide shadow pulses. Shelter behind the patches of purified ground — made by standing your ground with Aura raised, exactly as the Purifier taught. The arena remembers your lessons.
- **Phase 3 — The Self Remembers (33–1%):** At intervals it *falters* — its original self surfaces, longer each time, opening long vulnerability windows. It is asking for help. Do not look away.
- **Finale — The Rite (1–0%):** No more attacks. Protect the rite circle from shadow remnants for sixty seconds while the purification completes. Hold the line — and watch the Shadow lift.
- **Distinct:** The only fight that ends in healing. The emotional climax of the entire corruption arc. Falling triggers **The World Breathes Easier** — blight recedes worldwide, sealed regions open.

### 14. Society Paragon — the Conqueror's Answer (REQUIRED · final · human)
*Everything fusion should never be, standing in front of you.*
- **Arena:** The Society's Crucible — their fortress-heart, domination engines roaring.
- **Phase 1 — The Perfect Weapon (100–66%):** The Paragon fights beside a **forcibly-fused apex partner** — domination-made fusion, two beings crushed into one. Coordinated pair tactics, flawless and joyless.
- **Phase 2 — The Strain Shows (66–33%):** At 66% the partner falters. The Paragon forces it harder — and the forcing *shows*: the partner's attacks start missing the Paragon's mark. The bond is breaking. It was never a bond.
- **Phase 3 — The Breaking (33–0%):** At 33% the partner **turns**. Domination fails; resonance wins. The freed partner fights *beside you* for the finale — and the Paragon, alone and exposed for the first time in their life, is defeated.
- **Distinct:** The thesis made playable. You don't beat the final boss by being stronger — you win because the enemy's philosophy collapses mid-fight. Falling triggers **The Restoration Era**.

---

## Appendix: the method ledger (what the paste taught, what we refused)
**Taken (methods):** health-% phase thresholds; add-gated vulnerability phases; arena-as-mechanic; strict alternating attack cycles; conditional high-stakes states; NPC infrastructure anchoring; progression-expanding services; self-defending residents.
**Refused (content):** every Terraria name, NPC, and boss; Corruption/Crimson/Hallow as biomes; "Hardmode" as a term (our eras stand); any capture/evolution/level language; killing as a resolution.

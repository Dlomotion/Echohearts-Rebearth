# ECHOHEARTS: REBEARTH — Narrative, Voice & Registry Production Manual
**Source:** pasted working document (2026-10-05), consolidated from the Master Game Bible, Game Data Dictionary, recovered project history, and concept submissions.
**STATUS: WORKING / CONCEPT INTEGRATION — NOT A NEW CANON BIBLE. Reconciliation evidence only; nothing here is promoted to canon by this file.**

## Reconciliation notes (added 2026-10-05, post-receipt audit)
- **Terminology table SUPERSEDED** by Tay's ruling: **EcoKin** = the creature; **Ecoform** = a form/state an EcoKin takes on. The manual's "Eco-Kin PROJECT-LOCKED / Ecoforms as proposal" framing is outdated.
- **125-ID registry (DEX-001–DEX-125):** first complete ID list seen, claimed from a Game Data Dictionary — **UNVERIFIED**, not merged into the visual master catalog. Contains the real **Nova collision** (DEX-032 "Nova" as Star Savior vs Nova Star) and the flagged **Nature DEX-002** conflict.
- **Five-Star routing CONFLICTS with Tay's fold-in ruling:** the manual shelves the Stars as historical/postgame concepts; Tay ruled they fold into the main story as connected missions. Tay's ruling stands.
- **Useful proposals (all CONCEPT):** 30-NPC voice registry, player voice-selection system (V01–V08), 8-act/20-chapter campaign spine, VO asset contract, script/scene format manual.

---

## Original document (verbatim)

Narrative, Voice & Registry Production Manual
Consolidated from the current Master Game Bible, Game Data Dictionary, recovered project history, and 2026-10-05 concept submissions.
STATUS: WORKING / CONCEPT INTEGRATION — NOT A NEW CANON BIBLE
Authority rule
This manual is a production-facing consolidation. It does not replace MASTER_PROJECT_INDEX.md, the Master Game Bible, the 125-ID Permanent Dex, the Forms Registry, or ECO_KIN_ART_MANIFEST.md. Anything marked CONCEPT, WORKING, HISTORICAL, PENDING REVIEW, or DATA CONFLICT remains outside 00_Canon_Lock until adjudicated.

Restore the Balance; Rewrite the Future.

 Contents
• 1. Authority, continuity and terminology adjudication
• 2. Core story thesis and campaign architecture
• 3. Opening cinematic — production-safe working script
• 4. Script manual: scene, choice, state and VO format
• 5. Player voice-selection system
• 6. Main character and recurring cast voice bible
• 7. NPC voice registry — 30 current data-dictionary NPCs
• 8. Postgame / Saviors / STARZ* routing
• 9. Permanent Dex — 125-name alphabetical registry
• 10. Master Historical Naming Pool — all 1,120 recovered names
• 11. Production corrections and next integration actions

Visual-art note
Thumbnail art is intentionally not embedded in this revision because the available image files are not reliably mapped to specific registry identities in the source data. That avoids attaching the wrong approved look to the wrong name. Once the Art Manifest provides an explicit asset-to-name mapping, thumbnails can be inserted without redesigning or relabeling any approved character.

1. Authority, continuity and terminology adjudication
The current project contains several generations of terminology. This manual preserves the history, but it does not silently let a newer concept draft overwrite higher-authority project rules. The governing production language below is the working reconciliation for this document.
Topic | Use in this manual | Status | Production note
Collective creature classification | Eco-Kin | PROJECT-LOCKED | The 2026-10-05 "Ecoform/Ecoforms" proposal is preserved as a concept, but it cannot replace the project sandbox's locked Eco-Kin classification without a formal canon change.
Biological Orders | Zoa / Flora / Myko / Proto / Monera | CONCEPT — COMPATIBLE | These can function as scientific biological orders under the Eco-Kin umbrella, pending 10_Production review.
Player profession | Frequency Tamer | LOCKED | Front-facing role.
Advanced specialization | Core-Binder | LOCKED | Use where the specialization is specifically intended.
Apex entity | Nature | LOCKED | Legendary Humanoid-Kin; conditional Mutations; never a "Legendary Monarch."
Attributes | Vibrance / Density / Harmony / Purity | LOCKED | No generic HP/ATK/DEF/IV/EV replacement in current design/stat layouts.
Relationship | Kindling | LOCKED | Voluntary relationship measure; separate from combat attributes.
Device | A.E.G.I.S. | LOCKED | Wrist bracer. D.A.H.L.I.A. is the intelligence inside the system, not a replacement device name.
Lab-created origin marker | Synth-Origin | CONCEPT — COMPATIBLE | May be applied as an origin flag without creating a sixth biological Order.
Shadow | Condition / fracture state | CONCEPT — COMPATIBLE | Not a species and not a universal faction.
Elements | Flora, Torrent, Pyre, Terra, Aero, Glaze, Voltic, Aura, Shade | CURRENT PRODUCTION AUTHORITY | Older elemental tables remain historical or in-fiction terminology only.
Comet-event name | Elemental Comet / [REVIEW] | CONCEPT | "Celestine Bang" remains unapproved and should not ship until adjudicated.

1.1 Critical data conflict — Nature
DATA CONFLICT — MUST BE CORRECTED
The current spreadsheet still contains Nature as DEX-002 with BodyClass "Spirit" and Recruitable=True. That conflicts with the current project rule: Nature is a Legendary Humanoid-Kin whose relationship is story-, consent-, and Living-Accord-driven, not a normal capture/recruit path. This manual keeps the spreadsheet row visible for traceability but marks it for registry repair rather than treating it as gameplay truth.

1.2 Status language
LOCKED / CANON — Current authoritative story/system identity.
WORKING — Production-intended but still subject to reconciliation.
CONCEPT — Newly proposed; can be written and prototyped but not treated as locked.
HISTORICAL — Recovered project history; preserved for traceability.
RETIRED / REFERENCE — Do not publish or reactivate without explicit review.
RUNTIME VERIFIED — Reserved for evidence from a real UE5.8 build/test path; this manual does not grant that status.

2. Core story thesis and campaign architecture
Rebearth is a wounded living world rebuilding after civilization-scale damage. The Frequency Tamer arrives through a broken portal and discovers that restoration is not about making the planet "perfect"; it is about preserving agency, rebuilding relationships, reconnecting damaged ecologies, and refusing systems that turn life into property. A.E.G.I.S. makes the world legible, but Kindling makes it relational. The Anima-Link keeps that relationship mechanically honest: strain and injury do not stay isolated on the Eco-Kin side of combat.

Core dramatic law
Power without relationship tends toward control. Restoration without consent becomes another form of domination. Love is treated as an action system: protection, listening, accountability, restraint, repair, and shared burden.

2.1 Eight-act campaign spine
I — First Pulse | Echohearts Sanctuary / Sky Haven | First voluntary Kindling; A.E.G.I.S.; shelter becomes a promise. | Ch. 1–3
II — Roots Remember | Tree of Life Trial / Great Plains | Living roots reveal memory and the player learns that restoration changes future access. | Ch. 4–5 (working mapping)
III — Meridian Ghosts | Ruins / Meridian Nodes / regional fronts | The previous war was engineered; factions disagree over how much old power should return. | Ch. 6–10 (working mapping)
IV — Grand Crucible | Arena city / faction territories | Public competition becomes catastrophe and exposes exploitation behind spectacle. | Ch. 11
V — Gloom Below | Umbral Mire / underground arteries | Gloom, corrupted memory, and consent-violating research threaten the living network. | Ch. 12–14
VI — Bond or Dominion | Astra Spire / Apocalyptic Domains | Every faction tries to define the future of Rebearth's Heart-Code; Nature's Living Accord destiny becomes visible. | Ch. 15
VII — War of Summoning | Sky islands / global Riftways | Calling versus commanding becomes a planetary crisis; ancient powers and willing alliances enter the conflict. | Ch. 16
VIII — Star Rewrite / U.N.I.T.Y. | Starlight Spires / Heartroot-Circle interface | Chapters 17–19 test stewardship; the Void War bridge resolves the Hollow Front; Mission 20A–20E evaluates the Living Accord and endings. | Ch. 17–20 + VOID-01…06 bridge

2.2 Twenty major story chapters
1. The School Trip That Broke the Sky — Portal arrival; the player hears Rebearth.
2. First Kindling — Scientist tutorial and first voluntary bond.
3. Sky Haven — Shelter becomes a community promise.
4. The Root That Remembered — Tree of Life reveals fragments of the previous war.
5. Civil Rights of the Landscapes — The player meets the rebuilding military and learns that "security" can compete with ecology.
6. Corporate Muscle — Resource extraction threatens a recovering biome.
7. Brotherhood Road — A convoy choice introduces durable faction consequence.
8. Cinderfall Node — A ruin puzzle exposes Meridian weapon research.
9. Azure Tidegate — Underwater vault and Tidequill rescue.
10. Whispering Wastes — Sandstorm survival and a buried pyramid.
11. Grand Crucible — Tournament, sabotage, and public catastrophe.
12. The Gloom Has a Voice — Ebonmaw speaks through corrupted memories.
13. Dr. Hugo's Mercy — A cure works, but the method violates consent.
14. The Broken Choir — Scarborne victims can be rescued or weaponized.
15. Astra Spire — The player learns Rebearth is connected to a wider cosmic network.
16. Summoning War — Relics call powers that should have remained silent or unclaimed.
17. Plague Harbinger — Corso forces a choice between quarantine and trust.
18. E.C.O. Sentinel — The player confronts the logic of "perfect" control.
19. Circle of Life — Heal, break, balance, or transcend — and prove whether stewardship was practiced.
20. Love Conquers All — U.N.I.T.Y. / ending evaluation; the strongest route requires restored bonds, communities, consent, and Nature's voluntary participation.

2.3 Void War bridge — working mission functions (fixed after Chapter 19, before Mission 20A; subtitles working until the authoritative story file approves them)
VOID-01: Detect the Hollow Front as a synchronized severance pattern, not a new species.
VOID-02: Reconnect one damaged Heartroot route while protecting recoverable Hollow Hosts.
VOID-03: Expose a Severance Engine and establish whether it can be disabled without destroying the living node around it.
VOID-04: Force factions to contribute locally instead of routing all authority into a single controller.
VOID-05: Nature refuses centralized rule even though she could take it; the player must defend that refusal.
VOID-06: Open the path to U.N.I.T.Y. by proving distributed participation can hold under active attack.

3. Opening cinematic — production-safe working script
Script status: The 2026-10-05 opening is retained as a strong concept. This pass keeps its structure and theme while applying current project constraints: Eco-Kin remains the collective classification; Zoa/Flora/Myko/Proto/Monera are framed as proposed scientific Orders; the Tree narrator uses a working label until "Auralis" is approved.

[BLACK. One heartbeat. A second heartbeat answers.]
TREE OF LIFE VOICE — WORKING NAME AURALIS (ancient, intimate, never godlike)
"Before you were born, the world broke. Not in war alone — in forgetting."
[VISUAL] Forests, oceans, old cities; then the Fracture — broken land, lifted islands, rivers falling through cloud seas.
TREE OF LIFE VOICE: "They called life a resource. Measured it. Divided it. Owned it. And when it would not obey, they tried to rebuild it in their own image."
[VISUAL] Laboratories. Geometric scars. Bioluminescent Synth-Origin life waking behind glass.
TREE OF LIFE VOICE: "But life does not ask permission to be alive."
[VISUAL] Zoa migration; Flora reclaiming dead soil; Myko networks under stone; Proto tides reforming; Monera colonies blooming in hostile ground.
TREE OF LIFE VOICE: "Across Rebearth, Eco-Kin woke through many bodies. Researchers would later name five living Orders — Zoa, Flora, Myko, Proto, Monera. Others were awakened in laboratories, marked Synth-Origin, carrying a question no machine could settle: does being made instead of born make a life less alive?"
[VISUAL] A wounded Eco-Kin loses coherence. The base silhouette remains readable while its Echoheart fractures.
TREE OF LIFE VOICE: "And some fractured. Not evil. Wounded. Shadow is not a species. It is what happens when a living connection breaks and the wound begins speaking louder than the life beneath it."
[VISUAL] The Tree of Life — roots through ruin, ocean, settlement and sky.
TREE OF LIFE VOICE: "I remember the first root finding stone. Four rhythms help us read what lives here: Vibrance. Density. Harmony. Purity. They are not worth. They are relationships — how life moves, holds, connects, and remains itself."
[VISUAL] The player drops through a broken green-gold portal and strikes wet ground. A.E.G.I.S. wakes on the wrist.
TREE OF LIFE VOICE: "You did not arrive to conquer. Something in you heard the Resonance and answered."
D.A.H.L.I.A. (first boot; precise, humane): "A.E.G.I.S. online. Unknown ecological signatures nearby. Recommendation: observe before approaching."
TREE OF LIFE VOICE: "A.E.G.I.S. can help you read the world. It cannot make the world consent. Observe. Protect. Stabilize. Calm. Kindle. A companion stays because it chooses to stay."
[MONTAGE] Water clears without erasing the wetland; predators continue hunting; migration routes reopen; a desert stays a desert, but lives again.
TREE OF LIFE VOICE: "You will not make Rebearth perfect. Perfection is another kind of death. Make it livable — for humans, Eco-Kin, wild things, thinking machines, and the lives the old world discarded."
[A distorted transmission, almost gentle.] "Someone must control it all."
TREE OF LIFE VOICE (quiet warning): "Something is waiting for you to believe that. Do not."
[FINAL IMAGE] Sunrise behind the Tree. Finn rises as a small moving light.
TREE OF LIFE VOICE: "They are not your property. They are not your tools. They are your kin through the living world."
TREE OF LIFE VOICE: "Rebearth is not asking for a savior."
TREE OF LIFE VOICE (final beat): "It is asking for someone willing to practice love."
ECHOHEARTS: REBEARTH

4. Script manual: scene, choice, state and VO format
Every authored scene should be readable by narrative, audio, cinematic, gameplay and engineering teams without translating prose into implementation guesses.
Required fields: Scene ID (SCN_CH01_001); Location / world state; Participants; Entry conditions; Opening state; Beat list; Dialogue (speaker, line ID, vocal state, performance note, subtitle key); Choice block; Mechanical consequence (Kindling change, world flag, route, trust/faction ledger; never invent generic stats); Anima-Link consequence; Audio / VFX cues; Exit state; Verification status (SCRIPTED / IMPLEMENTED / RUNTIME OBSERVED / VERIFIED — never promote without evidence).

4.1 Dialogue branching rule
• Choices should alter behavior, access, trust, consequence, or information — not merely rephrase the same outcome.
• A "good" choice is not always the kindest-sounding line; it is the line backed by the player's actions and prior restoration history.
• NPCs must remember contradictions.
• Eco-Kin agency remains visible: refusal, delay, retreat, release, and later return are valid authored outcomes.
• Failure can create a different story state rather than a generic reload, unless a hard fail is necessary for level flow.

4.2 VO asset contract for UE5
SpeakerID (stable identity, e.g. NPC-001); VoiceProfileID (never a real-person imitation); LineID (e.g. VO_JACKSON_CH02_014); SceneID; EmotionTag; Intensity 0–3; AnimaLinkState (None / Linked / Strained / Critical / Recovering); TransmissionFX; SubtitleKey; TakeStatus (Placeholder / Cast / Recorded / Edited / Approved / Implemented / Runtime Observed).

5. Player voice-selection system
Voice is not locked to body type or gender. Every profile records the same canonical dialogue; performance changes timbre, pace, weight and effort.
V01 Grounded | V02 Deep Resonant | V03 Bright Agile | V04 Hushed Focus | V05 Field-Worn | V06 Clean Direct | V07 Restless Spark | V08 Mature Command.
Menu controls: Voice Profile V01–V08; pitch trim (small accessibility range); resonance/body; texture; pace 90–110%; combat callout density; effort intensity; profanity intensity; preview line; change policy (VoiceProfileID saved separately from narrative choices).
Anima-Link vocal states: Linked (breathing/command timing synchronize); Strained (shorter phrases, effort); Critical (fragments, protective callouts, no comic banter); Recovering (gradual settle); High Kindling (more personal partner-address lines, no ownership language).

6. Main character and recurring cast voice bible (entries combine locked data, established continuity and labeled working concepts; conflicts stated, not silently merged)
Core-Binder / Frequency Tamer — LOCKED ROLE — portal-stranded protagonist.
Nature — LOCKED, Legendary Humanoid-Kin — witness/guardian of the Circle; Living Accord; conditional Mutations only.
Professor Jackson — CONTINUITY-LOCKED; registry integration needed — mentor/researcher; accountable science.
Kale — ESTABLISHED STORY CAST — scout, rescue/survival guide; Sherlock Hound partner.
Liora — ESTABLISHED STORY CAST — resonance engineer (A.E.G.I.S., field systems, restoration hardware).
D.A.H.L.I.A. — LOCKED NPC-001 — adaptive intelligence inside A.E.G.I.S.; tutorial guide and ethical counterweight.
Heaven / Naveah — WORKING / POSTGAME — twin cosmic guides.
Finn — WORKING OPENING NPC — fairy guide toward Tree-of-Life rules.
Guiding Light — WORKING OPENING NPC — fairy guide teaching observation.
Sherlock Hound — HISTORICAL / UNRESOLVED IDENTITY — Kale's partner; registry status requires review.
Tree of Life voice ("Auralis") — CONCEPT / NAME PENDING.
Caelen / Vesper / Malakor — PROTOTYPE / NOT YET IN CURRENT NPC REGISTRY.
6.1 Professor Jackson / Dr. Amara Quell overlap — CONTINUITY REVIEW REQUIRED: do not merge, rename, or replace either person silently.

7. NPC voice registry — 30-NPC data-dictionary roster (sample lines are performance samples, not locked dialogue)
NPC-001 D.A.H.L.I.A. (Locked, systems intelligence); NPC-002 Mara Venn (Locked, Tidegate repair); NPC-003 Agent Hibiscus (Expansion); NPC-004 Agent Nightshade (Expansion); NPC-005 DZYN (Expansion, Rad humanoid); NPC-006 Malachi Voss (Expansion); NPC-007 Echolord Vorlag (Locked, exploits the Divide, seeks control of Rebearth memory); NPC-008 Corso (Locked, quarantine-vs-trust); NPC-009 Dr. Hugo (Locked, cure through violating methods); NPC-010 Cosmo-Seraph (Locked, cosmic entity); NPC-011 E.C.O. Sentinel (Locked, synthetic authority); NPC-012 Dr. Amara Quell (Working, tutorial guide); NPC-013 Commander Jace Renlow (Working); NPC-014 Councilor Nia Bex (Working); NPC-015 Foreman Orrin Slate (Working); NPC-016 Sister Kade Mercer (Working); NPC-017 Keeper Sanaa Moss (Working, habitat reading); NPC-018 Chef Omari Wells (Working); NPC-019 Archivist Imani Crest (Working); NPC-020 Medic Selene Ward (Working); NPC-021 Cartographer Lio Thorne (Working); NPC-022 Mechanic Rae Calder (Working); NPC-023 Kez Rowan (Working, youth); NPC-024 Marshal Tavi Sol (Working); NPC-025 Nola Venn (Working); NPC-026 Darius Flint (Working); NPC-027 Vexa Rill (Working); NPC-028 Amel Sorn (Working); NPC-029 Orra Vey (Working); NPC-030 Dr. Sel Korr (Working).

8. Postgame / Saviors / STARZ* routing
The older six-page "Star Bonds" draft's Aethelgard / Veridian-Keeper framing is historical and does not replace the current Rebearth campaign. Safest route is post-U.N.I.T.Y. integration through the Saviors of the Universe continuation.
Young Saviors (Glitter, Sparkle, Bling, Dazzle, Bright, Light, Shimmer, Shine, Luminous) — WORKING / POSTGAME.
Adult Saviors (Radiant, Nova / Super Nova, Spectra, Milky Way, Nebula, Solar, Lunar) — WORKING / POSTGAME.
Heaven / Naveah — WORKING, tie entry to voluntary alliance.
STARZ* label — TRADEMARK / NAMING REVIEW, internal working label only.
Summoning Wars / Ancient Tech Wars — DLC / expansion lanes, WORKING.
Old five-Star system (Nova Star, Eclipse Star, Nebula Star, Black Hole Star, Shooting Star) — HISTORICAL CONCEPT; reuse only underlying ideas after review; do not overwrite the current Savior roster.

9. Permanent Dex — 125-name alphabetical registry (production-roster authority per this manual; "Expansion," "Working," and "PendingReview" rows remain inside the 125-ID authority but are not equivalent to fully locked gameplay/art; Nature specially flagged — see 1.1)
DEX-070 Aardhymn (Locked, Firstheart, Nature/Earth); DEX-042 Africanized Queen (Locked, Bug, Electric/Nature); DEX-115 Aquanith (Expansion); DEX-086 Arborveil (Working); DEX-074 Aurorarch (Expansion); DEX-044 Azurbuzz (Locked, Bug); DEX-058 Billstalk (Working); DEX-043 Bloombud (Locked, Bug); DEX-076 Bromebruin (Expansion); DEX-100 Bubba (PendingReview); DEX-079 Cadensora (Expansion); DEX-108 Canopulse (Locked); DEX-077 Canopyvault (Expansion); DEX-056 Coluglyph (Working); DEX-057 Coluglyph Skyweaver (Working); DEX-048 Crowncurrent (Locked); DEX-005 Dandelion (Locked); DEX-087 Dappletide (Working); DEX-102 Demon (PendingReview); DEX-009 Dewfawn (Locked); DEX-113 Dryad (Expansion); DEX-023 Eerie (Locked, Spirit); DEX-071 Eonotara (Locked, Firstheart); DEX-096 Featherfright (PendingReview); DEX-004 Floauwer (Locked); DEX-045 Florafinity (Locked, Bug); DEX-008 Geckalyx (Locked); DEX-065 Gerenreach (Working); DEX-066 Gerenreach Crownforager (Working); DEX-104 Ghost (PendingReview); DEX-024 Ghoul (Locked, Spirit); DEX-093 Glimbit (Working, Rad); DEX-007 Glow Worm (Locked, Bug); DEX-099 Hammerwake (PendingReview); DEX-040 Hive Spark (Locked, Bug); DEX-110 Hounding (Expansion); DEX-050 Kakaphonic (Working); DEX-051 Kakaphonic Nightchorus (Working); DEX-068 Korravault (Locked, Firstheart); DEX-013 Leon (Locked); DEX-012 Leonix (Locked); DEX-015 Likeness (Locked, Spirit); DEX-062 Limulock (Working); DEX-063 Limulock Shorewarden (Working); DEX-014 Lioness (Locked); DEX-121 Loyalkin (PendingReview); DEX-011 Lumi (Locked, Spirit); DEX-123 Luminae (PendingReview); DEX-017 Luna Moth (Locked, Bug); DEX-112 Maat (Expansion); DEX-030 Malon-X (Locked, HumanoidKin); DEX-010 Mandarion (Locked); DEX-028 Marmara (Locked); DEX-055 Membrakit (Working); DEX-016 Moon-Walker (Locked, HumanoidKin); DEX-029 Morg-An (Locked, HumanoidKin); DEX-049 Mosschick (Working); DEX-075 Mossmask (Expansion); DEX-084 Mottlit (Working); DEX-092 Moundseer (Working); DEX-081 Murmlet (Working); DEX-114 Mycelith (Expansion); DEX-002 Nature (Locked, Spirit — DATA CONFLICT: project rule classifies Nature as Legendary Humanoid-Kin, non-recruitable; spreadsheet row requires repair); DEX-033 Nebula (Locked, Spirit, Star Savior); DEX-019 Nebulark (Locked); DEX-124 Nerekth (PendingReview); DEX-122 Nexaris (PendingReview); DEX-103 Normandy (PendingReview); DEX-032 Nova (Locked, Spirit, Star Savior — NOTE: name collision with Nova Star); DEX-119 Nulvora (PendingReview); DEX-003 Nurture (Locked); DEX-082 Olmnisense (Working); DEX-083 Olmnisense Deepwarden (Working); DEX-052 Pebblegill (Working); DEX-072 Peepfloe (Expansion); DEX-088 Pelaglyph (Working); DEX-089 Pelaglyph Tidevault (Working); DEX-001 Piplin (Locked, starter); DEX-027 Polarised (Locked); DEX-018 Princeton (Locked, HumanoidKin); DEX-035 Pupular (Locked, official name replacing Chaos Woof); DEX-078 Reednote (Expansion); DEX-047 Rimefin (Locked); DEX-073 Rookurrent (Expansion); DEX-037 Rootcrawler (Locked); DEX-059 Shoebastion (Working); DEX-060 Shoebastion Marshwarden (Working); DEX-053 Siltamender (Working); DEX-054 Siltamender Riverelder (Working); DEX-025 Skeleton (Locked, Spirit); DEX-125 Skullkin (PendingReview); DEX-080 Skyrhapsody (Expansion); DEX-090 Snoutap (Working); DEX-097 Solara (PendingReview, HumanoidKin); DEX-106 Sprigbeat (Locked); DEX-034 Spritz (Locked, Spirit); DEX-064 Sproutneck (Working); DEX-020 Starhaven Perch (Locked); DEX-021 Starvault Spires (Locked); DEX-120 Stormhare (PendingReview); DEX-041 Swarm Guard (Locked, Bug); DEX-116 Sylvornith (Expansion); DEX-094 Synchronus (PendingReview); DEX-095 Synchronus Omega (PendingReview); DEX-091 Termitune (Working); DEX-101 Terra Tusk (PendingReview); DEX-111 Terralume (Expansion); DEX-038 Terrawyrm (Locked); DEX-105 Thalassyr (PendingReview); DEX-031 Thrilla Zombie (Locked, HumanoidKin); DEX-067 Thylundra (Locked, Firstheart); DEX-061 Tidebutton (Working); DEX-046 Tidequill (Locked); DEX-006 Treezing (Locked); DEX-022 Ultra Nature Spark (Locked, Spirit); DEX-107 Verdanthem (Locked); DEX-098 Verdantis (PendingReview); DEX-118 Veridan (PendingReview); DEX-085 Veylugo (Working); DEX-069 Vitrivane (Locked, Firstheart); DEX-109 Whaling (Expansion); DEX-039 Worldroot Leviathan (Locked); DEX-036 Wormling (Locked); DEX-117 Zangoro Seedling (PendingReview); DEX-026 ZebraskA (Locked).

10. Master Historical Naming Pool — 1,120 recovered names (preservation does not promote a name into the Permanent Dex; 125 DEX + 53 FORM + 932 HIST + 5 ALIAS + 5 RET)
Full alphabetical pool preserved in the source paste (Aardhymn through Zeptoray), including tags: Ash-Brawler [HIST], Bugsaboom [HIST], Buttafly [HIST], Chimpanzion [HIST], Chaos Woof [ALIAS], Plainsman [HIST], Reaper-Skull [HIST], Twilight-Tricker [HIST], Ember [HIST], Sherlock Hound [HIST], Skyraxis [HIST], Unbound [HIST], Wooofy [HIST], Zebrask [ALIAS].

11. Production corrections and next integration actions
P0 — Nature registry repair: correct DEX-002 or move Nature to the appropriate Humanoid-Kin authority without deleting history; remove ordinary recruit semantics; preserve Living Accord / conditional Mutation identity.
P0 — Terminology decision: adjudicate the "Ecoforms" proposal against locked Eco-Kin nomenclature. [RESOLVED 2026-10-05 by Tay: EcoKin = creature; Ecoform = form an EcoKin takes on.]
P0 — Professor Jackson / Dr. Amara Quell: define distinct roles or reassign tutorial beats; do not merge silently.
P1 — Main cast registry: stable IDs + voice metadata for Kale, Liora, Professor Jackson, Heaven, Naveah, Finn, Guiding Light, and approved recurring characters missing from the NPC worksheet.
P1 — Prototype intake: Caelen, Vesper, Malakor require originality/canon review before becoming active story NPCs.
P1 — Art thumbnail mapping: manifest mapping approved image asset → stable identity → base/form/state before embedding thumbnails.
P1 — Opening narrator: decide whether "Auralis" is approved, an alias, or retired.
P1 — Savior naming review: resolve STARZ* and flagged names before marketing/publication.
P2 — VO implementation: Data Assets / tables for SpeakerID, VoiceProfileID, LineID, subtitle key, emotion, intensity, transmission FX, take status; bind runtime playback only after UE5.8 foundation proven.
P2 — Evidence boundary: do not label VO, story branching, saves, networking, lip-sync, or chapter runtime VERIFIED until a named UE5.8 build demonstrates the exact path.

11.1 Recommended repository routing
01_Story: opening cinematic, 8-act/20-chapter script, Void War bridge, character story beats.
03_EcoKin_Dex: 125-ID authority, historical naming pool links, forms/evolutions, Nature conflict correction routing.
06_UI_UX: voice-selection menu, subtitles, dialogue-choice UI, terminology presentation after adjudication.
08_Audio: voice bible, vocal-state matrix, character callouts, creature vocal design, A.E.G.I.S. transmission treatment.
09_Technical: VO metadata schema, Data Assets, localization keys, dialogue state hooks, save IDs, runtime playback.
10_Production: terminology conflicts, identity review, naming/IP review, approval gates, art manifest linkage.
99_Reference_Retired_Needs_Redesign: superseded Aethelgard / older taxonomy / legally risky or borrowed-adjacent names and mechanics.

Final manual rule
No recovered name, prototype scene, old comparison mechanic, image variation, or concept taxonomy may silently overwrite a locked identity. Preserve history, map authority, then promote only what passes continuity, originality, anatomy, system and runtime gates.

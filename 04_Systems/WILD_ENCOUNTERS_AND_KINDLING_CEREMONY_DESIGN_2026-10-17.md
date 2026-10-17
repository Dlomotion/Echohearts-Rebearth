# ECHOHEARTS: REBEARTH — Wild Eco-Kin Encounters → Kindling Ceremony
**Design date:** 2026-10-17  
**Status:** APPROVED-PENDING DESIGN / NOT YET IMPLEMENTED / NOT UE5.8 VERIFIED  
**Scope:** Missing core loop reported by owner; source of truth remains `MASTER_PROJECT_INDEX.md` and `00_Canon_Lock`. Do not replace already implemented Anima-Link, Kindling, summoning, Growth Rites, corruption, saving, companion AI, resident system or boss progression.

## Design intent and key correction
**Binding ceremony** is the player's *interactive visual and dialogue experience of mutual Kindling*, not physical capture, ownership, a ball/sphere, a separate creature-management economy, or an involuntary ally transfer. The formal player role is **Core-Binder**; the living subject is always **Eco-Kin**. The A.E.G.I.S. bracer detects and logs resonance; D.A.H.L.I.A. explains environmental uncertainty and safeguards informed consent. Existing roster authority is the **125-ID Permanent Dex** with no generated, invented or overwritten IDs.

### Player-visible five-minute loop
1. **Read the world** — natural habitat cues, feeding marks, micro-weather, calls, trails, migration timing and regional Purity.
2. **Approach or observe** — use A.E.G.I.S. Scan, patient movement and optional ecological help; player may avoid all contact.
3. **Offer assistance or interaction** — clear fallen debris, restore water, follow a display or shelter during a storm; Eco-Kin acts on needs and temperament.
4. **Invitation to Kindling** — only after trust and conditions permit, player can extend a voluntary invitation with clear `Accept`, `Defer`, `Decline` and `Walk Away` behavior. No chance-based forced "capture success."
5. **Shared resonance ceremony** — player traces a short A.E.G.I.S. harmonic pattern shaped from that individual's behavior, while the Eco-Kin reciprocates. Alignment requires player input and Eco-Kin active participation.
6. **New partnership** — after server-authoritative commit, add relationship to existing Kindling registry; if squad full, **relationship persists without forced storage**. The Eco-Kin retains a habitat/follow/rest choice.
7. **Visible world consequence** — scan knowledge, habitat restoration, field technique, optional future Growth Rite route; preserve the ecology in the zone.

### Three encounter types
- **Passive observation:** wildlife visible; A.E.G.I.S. collects photo/audio/behavior records without requiring a bond.
- **Assistance/trust:** distress signal, blocked migration, Blight-stress or habitat damage; multiple nonviolent resolutions, explicit safe retreat.
- **Territorial confrontation:** creature signals displeasure; avert conflict by distance/de-escalation, or defend as authored. Resolution never requires killing/capturing. Sovereign encounters use existing Sovereign contract.

## Wild encounter spawn contracts
Use authored biome-driven `UPrimaryDataAsset` definitions in BUILD, and server-owned streamed encounter director. Do **not** use global unlimited spawning, per-tick random rolls or client-chosen species.

### FWildEncounterProfile (proposed fields)
- `EncounterProfileID`, `AllowedPermanentEcoKinIDs` (must be found in authoritative 001–125 Dex), `BiomeIDs`, `EncounterArchetype`, `RequiredStoryFlags`, `ExcludedStoryFlags`.
- `SeasonWindow`, `TimeOfDayWindow`, `WeatherProfileTags`, `RestorationBand`, `BlightPressureBand`, `NavAreaTag`, `PopulationCapacity`, `Min/MaxGroupCount` (author balance needed).
- `MinPlayerDistance`, `MaxPlayerDistance`, `MinSafeClearance`, `SpawnAvoidanceTags`, `PopulationRespawnPolicy`, `PersistenceScope`, `AIScheduleProfileID`.
- `ReadabilityCueAssetId`, `AudioCueAssetId`, `TrustEventTableId`, `KindlingPolicyId`, `WorldStateRewardId`.
- Explicitly store **eligibility reason tags** and a deterministic replay/seed + director revision.

### Spawn algorithm contract (not yet C++)
1. Query streamed, unlocked biome cell and authoritative world snapshot; wait until nav mesh and actor ownership are valid.
2. Retrieve eligible profiles and approved Dex identities; reject null/unapproved art, contradictory seasonal forms and empty weights.
3. Clamp resident population per cell *and* cross-cell migration ledger; select ecological group weighted by verified habitat pressure, not random spawns every step.
4. Validate line-of-sight fairness, accessible exit, safe distance from hub/quest NPC, and actual walkable/swimmable/flyable navigation clearance.
5. Spawn with transient `EncounterInstanceGUID`, persistent `WildIndividualGUID` only when story/relationship tracking warrants it; call existing actor/AI components, do not create a second Echo-Kin pawn hierarchy.
6. Apply behavior schedule (browse, forage, shelter, watch, defend, recover, migrate) and synchronize only server-authoritative individual state to interested clients.
7. On combat, rescue or bond completion, commit ecological population delta exactly once; respawn only after configured ecology recovery, not farmable rolling.
8. On streaming unload, release transient individuals; persist authored named/world-impact individuals and relationship events in existing save format.
9. Test rejoin/host migration, cell unload/reload, weather change, competing co-op invitations, corrupted data, refusal and full squad.

### Eco-Kin autonomous behavioral states
`Rest → Forage → Travel → ObservePlayer → GuardHabitat → SeekShelter → Recover`; interruptors `Injured`, `BlightStressed`, `Evacuating`. An individual **never** auto-enters combat simply because player approached. Threat escalation is bounded to territory, authored distress/attack logic and AI perception evidence. Each transition logs `ReasonTag`, last safe position and timeout to avoid infinite chase.

## Interactive Kindling ceremony — state machine
`NotEligible` → `InvitationAvailable` → `PlayerInvited` → `EcoKinDecision` (accept/defer/decline) → `ReciprocalAttunement` → `AgreementReview` → `AuthoritativeCommit` → `PartnershipRecorded`.

**Abort paths:** dialogue cancel, consent withdrawn, environmental threat, AI leave, broken Anima-Link safety limit, owner disconnected, full/invalid relationship record, malicious packet or unmet story gates. Abort gracefully to safe habitat state. Do not quietly re-roll refusal into forced success.

**Interactive attunement design:**
- Three short, readable pulses that reflect the individual's **movement, light, pressure or scent** behavior; sound is only one of several options (not all Eco-Kin are musical).
- The player follows visible pulses with input prompts but never controls the Eco-Kin's side of the exchange.
- Accessibility: hold-to-align mode, no strict rhythm requirement, captions+haptics, motion-reduction, high-contrast cues and remappable controls.
- A.E.G.I.S. UI displays `Observe / Invite / Respond / Respect Outcome`; D.A.H.L.I.A. narrates consent uncertainty without manipulating the creature.
- Multiplayer handshake is server-mediated; a co-op teammate may observe, not intercept or steal a relationship transaction.
- Ceremony completion changes **partnership/registration** state only; it cannot teleport the individual into inventory, duplicate roster IDs, or secretly bypass existing 8-roster / 3-active limit.

### Contract with existing code
- Inject into current Kindling service via adapter interface `IKindlingInvitationGateway`; do not replace its gates.
- Preserve currently implemented four-Growth-Rite gate checks *exactly as present in BUILD*; do not infer their C++ names from the report. Add new ceremony gate only to interaction entry, never weaken already enforced validation.
- Read V/D/H/P from the authoritative character/Eco-Kin AttributeComponent location, not from an invented stance/world actor field. Enum lookups must verify actual defined stance names in BUILD.
- Adapt existing Anima-Link combat strain and save transactions using their real APIs once inspected.
- Keep **one-way scan observations** separate from **two-way partnership** so discovery never implies ownership.

## First playable mission — "A Signal Without a Name" (working)
**Existing narrative junction:** the opening Field Academy / Whispering Glade / wounded Heartroot region; exact mission/chapter ID must be reconciled with story spine before locking.

- **Beat 01 / Learn to listen:** professor or approved guide demonstrates A.E.G.I.S. scanning on nonliving pollen and rooted growth.
- **Beat 02 / Find evidence:** follow three valid environmental signals into a reachable habitat; no quest-arrow spawn cheating.
- **Beat 03 / Protect a path:** clear storm-fallen branches to restore a safe route. Alternative: safely bypass the hazard and report evidence.
- **Beat 04 / Meet an individual:** encounter a **Dex-approved existing Eco-Kin** chosen by vetted habitat profile; do not mint identity or mock a locked roster species.
- **Beat 05 / Respect response:** offer Kindling; positive, defer and no-interest responses have authored outcomes. Invitation retries require meaningful world-state/trust changes.
- **Beat 06 / Voluntary ceremony:** guided attunement with accessible input and a dialogue choice acknowledging ongoing autonomy.
- **Beat 07 / Return:** existing companion registry and save commit; new partner may elect to accompany, recover at Sanctuary, or remain in its habitat; report local restoration delta.
- **Quest failure:** recovery save never softlocks. Alternative educational completion for declined invitation (player can progress without acquiring a specific individual).

## First implementation slice / engineering order
**Gate 0:** clean Windows UE5.8 project checkout, LFS round trip, exact Build.version and successful minimal Editor UHT/compile.  
**Gate 1:** existing input mapping verified: Move, Look, Jump, Interact, A.E.G.I.S. Scan, Cancel, Navigate UI.  
**Gate 2:** a single protected biome volume + one *existing approved* Eco-Kin actor with server-owned spawn; idle → forage → approach → retreat loop.  
**Gate 3:** scan, context interaction, invitation/decline dialogue.  
**Gate 4:** accessible reciprocal Kindling ceremony with transactional relationship persistence.  
**Gate 5:** co-op replication, reboot/load, hostile weather, full roster and consent-abort regression.

**Done criteria:** in Windows PIE, an actual in-world approved wild Eco-Kin spawns from approved biome profile, can be observed, can decline, can voluntarily complete Kindling, is linked to the existing roster/service once, survives save/load, and can safely leave. Preserve UHT, editor logs and a playable recording before calling this VERIFIED.

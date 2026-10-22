# Echohearts: Rebearth — UI Terminology Sweep
**Finalized taxonomy applied to interface language — 2026-10-05**
**Status:** CONCEPT — routes to 06_UI_UX; nothing enters 00_Canon_Lock without review.

This document maps every player-facing term to its finalized form. Apply left → right across Codex screens, Binding UI, NPC dialogue, tutorials, and HUD.

## Collective & classification terms

| Do not use | Use | Notes |
|---|---|---|
| Eco-Kin / Eco-Kins / Echo-Kin | **EcoKin** | The creature itself. "Echo-Kin" spelling is legacy; EcoKin covers singular and plural. |
| Ecoform (as the creature) | **EcoKin** | **Ecoform** is reserved: a form/state an EcoKin takes on (base form, Growth Rite form, Mutation, Resonance Strain, Shimmer Form). |
| -kin group suffixes (e.g. "Beast-Kin") | **Zoa, Flora, Myko, Proto, Monera** | The five Orders of Sentience. Never invent new "-kin" groups. |
| Robot companion (separate category) | **Synth-Origin [Order]** (e.g. Synth-Zoa) | Robotic EcoKin are EcoKin; G.L.Y.T.C.H. is a Synth-Origin EcoKin, not a separate companion class. |
| Shadow Kin / Shadow Beasts (as a species) | **Shadow-altered / Shadow condition** | Shadow is an Echoheart fracture, not a category. "Ecosystem trauma given form." |
| Monster / creature (as default noun) | **EcoKin** | "Creature" acceptable only in generic UI space constraints; prefer EcoKin. |

## Binding & relationship terms

| Do not use | Use | Notes |
|---|---|---|
| Catch / capture (verb) | **Bind / Binding** | The act of forming the first Resonance connection. |
| Ownership / owned | **Resonance Alignment / aligned** | EcoKin choose to remain; nothing is owned. |
| Deploy / send out | **Release** | Releasing an aligned EcoKin into battle or the field. |
| Tame (as domination) | **Kindle / Kindling** | The trust bond, measured as Kindling %. Voluntary, always. |
| Keeper (until reconciled) | **Frequency Tamer** (profession) | "Keeper" pending 10_Production reconciliation (proposed: relational term). Do not ship "Keeper" in UI yet. |
| Core-Binder | **Core-Binder** (advanced specialization) | Locked; use only where specialization is meant. |

## Device & Codex terms

| Do not use | Use | Notes |
|---|---|---|
| Eco-Device | **A.E.G.I.S.** | The physical wrist bracer. |
| AI assistant / tutorial voice | **D.A.H.L.I.A.** | The adaptive intelligence *inside* A.E.G.I.S. Never a replacement name for the device. |
| Eco-Dex / Pokédex-style "complete list" | **Eco-Dex (Codex)** | The Dex is an **unfinished book** in-fiction. Undiscovered entries display **UNKNOWN ECOLOGICAL SIGNATURE**, never stats. The 125-ID roster is production authority, not the player's starting list. |

## Stats & progression terms

| Do not use | Use | Notes |
|---|---|---|
| VIT / MGT / AGS / RSN / FORT / VEL, ATK / HP / SPD / DEF, IVs / EVs | **Vibrance / Density / Harmony / Purity** | The authoritative four-attribute matrix. Never silently substitute legacy stats. |
| BOND (as a stat) | **Kindling** | Relationship measure; keep out of the combat-stat block visually. |
| Level evolution / evolve at Lv.X | **Growth Rite** | Structured maturation; no level-reset. Retains Kindling, history, identity. |
| Shiny / palette swap | **Resonance Strain** (redistributed budget, same silhouette) or **Shimmer Form** (pearlescent coherence overlay) | These are distinct systems; never conflate. |
| Fuse (any + any) | **Concord Fusion** (registered pairs only) | UI must show the pair registry (FUS-001 …), never a free mixer. |
| Consume / sacrifice duplicates | **Echoprint Resonance Transfer** | Duplicates yield observations, samples, research — never consumed. Offer release / Sanctuary / breeding / trade. |
| Harvest body parts | **Anatomical Echotraces** | Shed material, molted shell, eDNA — never harvesting from a living partner. |
| Upgrade chips / implants | **Resonance Core Modules** | Temporary frequency bridges via A.E.G.I.S. (Vibrance / Density / Harmony / Purity / Archive / Adaptive). |

## Elemental terms

| Do not use | Use | Notes |
|---|---|---|
| 18-element chart (Water, Fire, Wind, Light, Dark…) as the active system | **The nine Essences: Flora, Torrent, Pyre, Terra, Aero, Glaze, Voltic, Aura, Shade** | Older elemental names (Fire, Water…) survive **in-fiction** as historical / regional / manuscript terminology — NPCs and archives may disagree with modern science. |

## Player identity terms

| Do not use | Use | Notes |
|---|---|---|
| Summoner (as the player class) | **Frequency Tamer** | "Summoning" remains valid lore for Saviors / Summoning Wars arcs only. |
| Captain / chosen one / god-reincarnation | *(none)* | The protagonist is an undercover operative stranded by a portal, not a captain or deity. |
| Tamer of Beasts (front-facing) | **Frequency Tamer** | 00_Canon_Lock's "Tamer of Beasts" conflicts with the locked constraint — flagged for 10_Production adjudication. |

## World & event terms

| Do not use | Use | Notes |
|---|---|---|
| Celestine Bang | **the Elemental Comet** (or [REVIEW] marker) | "Celestine Bang" is pending approval — do not ship it in UI. |
| Perfect Purity (as an ending state) | *(none — restoration, not perfection)* | Endings heal imperfectly: scars remain, extinct species do not return, some corruption survives. |
| War on Life (as a separate war) | **War on Humanity** | "War on Life" survives only as in-fiction survivor phrasing: *"Humans called it the War on Humanity. The forests remembered it as the War on Life."* |

## Paths & repositories — do not rename
- Repository paths (`03_EcoKin_Dex`, `ECO_KIN_ART_MANIFEST.md`, `09_Technical/MetaSystems` identifiers like `EcoKin`, `EcoKinEgg`, `SentientPartner`) keep their existing names. The market contract forbidding listings for those categories is preserved.
- File and variable renames are a separate engineering task, not a UI sweep.

## Flagged for 10_Production (do not resolve silently)
1. **"Celestine Bang"** — approve or replace.
2. **"Keeper"** — reconcile with Frequency Tamer / Core-Binder (proposal: profession / relational term / specialization).
3. **"Tamer of Beasts"** in 00_Canon_Lock vs locked **Frequency Tamer**.
4. **Fusion forbidden** in dex pipeline (EMBER.md) vs **Concord Fusion** (registered pairs) — adjudicate.
5. Legacy stat blocks (VIT/MGT/AGS/RSN/FORT/VEL) appearing in pasted design material — reject in favor of the four-attribute matrix.

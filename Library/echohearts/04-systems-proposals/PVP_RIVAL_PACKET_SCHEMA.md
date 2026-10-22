# PvP Rival Packet — Schema (2026-10-20)

Status: CONCEPT proposal, Tay's veto pending. The packet is the snapshot a
Rival Echoes duel (Option A) fights against. Design rule: a packet carries
a TEAM, never a person — no account data, no personal identifiers.

## Packet shape (v1)

```
rivalPacket {
  version: 1
  tamerAlias: string            // display alias only, chosen by the player
  circuitRank: string           // e.g. "Chord" — from DuelCircuit ranks
  createdUtc: ISO-8601 string
  team: [                       // 1..3 partners
    {
      dexId: integer            // Permanent Dex ID (Echoprint identity)
      form: string              // Ecoform name, attached to the base EcoKin
      essence: string           // one of the nine Essences
      vibrance: integer
      density: integer
      harmony: integer
      purity: integer
      strain: integer 0..100    // Anima-Link strain at snapshot time
    }
  ]
}
```

## Validation rules (fail closed)

- Every attribute present and in range; unknown fields rejected.
- `dexId` must exist in the Permanent Dex; `form` must be a registered
  Ecoform of that base EcoKin (Echoprint rule — a packet cannot invent a
  creature or a form).
- `essence` must be one of the nine locked Essences; corruption condition
  is never a packet field (a fractured partner is a story state, not a
  loadout).
- No market categories, no quantities/prices: the packet is a duel
  snapshot, and the standing market contract bans EcoKin listings anyway.
- Packets are read-only in a duel: fighting an echo never writes back to
  the other player's game.

## What a packet deliberately cannot do

- It cannot bind, trade, gift, or transfer anything.
- It cannot carry resources (the shed/gifted economy moves items only
  between consenting players in person, a separate future design).
- It cannot represent a live connection — that is Option B's netcode,
  which does not exist yet.

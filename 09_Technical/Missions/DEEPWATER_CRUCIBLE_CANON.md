# Deepwater, Cavern, Sanctuary, Materials & Resonance Crucible Canon Expansion
Approval: user-directed canon content, 2026-10-22. Additive to all existing Layer 0 and mission expansions; no original quests renamed or overwritten. Target Unreal Engine **5.8.3**.

## Facility: The Resonance Crucible
The Sanctuary's voluntary computer-assisted training dome. Modes: Solo, Partner Link Battle, Tamer Duel, Cooperative Purification, Environmental Survival. Simulations replicate approved environments; yield, consent withdrawal and unsafe Anima-Link strain terminate sessions. Real-world missions and dome simulations are distinguished in save records; simulations do not fabricate Dex discoveries, permanent materials or ecological restoration. No new attribute system or currency.

## 36 quest entries (six arcs)
### Beneath the Living Tide
- **DWT-01** The Sunken Signal — Arc introduction; unlock the local quest board.
- **DWT-02** Pressure at the Threshold — Requires DWT-01; continue the arc's environmental, rescue, crafting or training objectives.
- **DWT-03** The Coral Lanterns — Requires DWT-02; continue the arc's environmental, rescue, crafting or training objectives.
- **DWT-04** The Trenchway Escort — Requires DWT-03; continue the arc's environmental, rescue, crafting or training objectives.
- **DWT-05** The Unbroken Air Pocket — Requires DWT-04; continue the arc's environmental, rescue, crafting or training objectives.
- **DWT-06** The Living Tide Restored — Requires DWT-05; continue the arc's environmental, rescue, crafting or training objectives.

### The Hollowstone Expedition
- **CVN-01** The First Echo Below — Arc introduction; unlock the local quest board.
- **CVN-02** The Crystal Fault — Requires CVN-01; continue the arc's environmental, rescue, crafting or training objectives.
- **CVN-03** The Lost Survey Line — Requires CVN-02; continue the arc's environmental, rescue, crafting or training objectives.
- **CVN-04** The Breathing Cavern — Requires CVN-03; continue the arc's environmental, rescue, crafting or training objectives.
- **CVN-05** The Vein Without a Scar — Requires CVN-04; continue the arc's environmental, rescue, crafting or training objectives.
- **CVN-06** Hollowstone Harmony — Requires CVN-05; continue the arc's environmental, rescue, crafting or training objectives.

### Sanctuary Rising
- **SAN-01** The Annex Blueprint — Arc introduction; unlock the local quest board.
- **SAN-02** Hands at the Heartroot — Requires SAN-01; continue the arc's environmental, rescue, crafting or training objectives.
- **SAN-03** The Purity Well Audit — Requires SAN-02; continue the arc's environmental, rescue, crafting or training objectives.
- **SAN-04** The Residents' Relay — Requires SAN-03; continue the arc's environmental, rescue, crafting or training objectives.
- **SAN-05** When the Bell Calls — Requires SAN-04; continue the arc's environmental, rescue, crafting or training objectives.
- **SAN-06** A Sanctuary Renewed — Requires SAN-05; continue the arc's environmental, rescue, crafting or training objectives.

### Materials of Rebearth
- **MAT-01** What the Earth Gives — Arc introduction; unlock the local quest board.
- **MAT-02** The Shed and the Gift — Requires MAT-01; continue the arc's environmental, rescue, crafting or training objectives.
- **MAT-03** The Safe Crystal Seam — Requires MAT-02; continue the arc's environmental, rescue, crafting or training objectives.
- **MAT-04** The Artificer's Ledger — Requires MAT-03; continue the arc's environmental, rescue, crafting or training objectives.
- **MAT-05** Repair Before Expansion — Requires MAT-04; continue the arc's environmental, rescue, crafting or training objectives.
- **MAT-06** The Catalyst Accord — Requires MAT-05; continue the arc's environmental, rescue, crafting or training objectives.

### Anima-Link Trials
- **LNK-01** First Shared Pulse — Arc introduction; unlock the local quest board.
- **LNK-02** The Yield Protocol — Requires LNK-01; continue the arc's environmental, rescue, crafting or training objectives.
- **LNK-03** The Partner's Choice — Requires LNK-02; continue the arc's environmental, rescue, crafting or training objectives.
- **LNK-04** The Strain Exchange — Requires LNK-03; continue the arc's environmental, rescue, crafting or training objectives.
- **LNK-05** Two Hearts in Balance — Requires LNK-04; continue the arc's environmental, rescue, crafting or training objectives.
- **LNK-06** The Linkmaster's Accord — Requires LNK-05; continue the arc's environmental, rescue, crafting or training objectives.

### Resonance Crucible Circuit
- **RCC-01** The Dome Awakens — Arc introduction; unlock the local quest board.
- **RCC-02** Simulated Deepwater — Requires RCC-01; continue the arc's environmental, rescue, crafting or training objectives.
- **RCC-03** The Cavern Scenario — Requires RCC-02; continue the arc's environmental, rescue, crafting or training objectives.
- **RCC-04** The Society Raid Drill — Requires RCC-03; continue the arc's environmental, rescue, crafting or training objectives.
- **RCC-05** The Cooperative Purification — Requires RCC-04; continue the arc's environmental, rescue, crafting or training objectives.
- **RCC-06** The Crucible Exhibition — Requires RCC-05; continue the arc's environmental, rescue, crafting or training objectives.

## Game systems
- **Deepwater:** underwater pressure, voluntary Torrent partner navigation, rescue, Coralus migration and submerged cavern access; no teleportation.
- **Caverns:** Density and Purity stabilization, nonlethal wild encounters, surveying, safe crystal seam access, reversible environmental damage.
- **Sanctuary:** founding mission SF_01 remains first and untouched; this arc only follows it, and resident jobs/services and structure repair gate expansion.
- **Materials:** obtain only fallen, shed, gifted or responsibly recovered materials; no partner sacrifice, duplicate consumption or invented economy.
- **Link Battles:** two-way Anima-Link strain and willingness, reversible duels, optional cooperative drills. Four attributes only: Vibrance, Density, Harmony, Purity.
- **Crucible:** sessions have safety gates and do not override the Binding ceremony, the 24-hour decline timer or active duel deferral. Nature is never an opponent.

## Integration constraints
These are **approved canon design definitions and a portable C++ header**, not a compiled UE gameplay feature. Connect to existing missions, EnhancedInput, UMG, Anima-Link subsystem, residents, crafting, SaveGame and cross-platform registry after repository verification. Verify IDs against original mission registry. Test on trusted UE5.8.3 checkout before calling playable.

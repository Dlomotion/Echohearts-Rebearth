# First Kindling Lesson — Narrative Beat and Branch Map
**Status:** PROPOSED CONTENT EXTENSION / needs story/chapter owner approval. Complements the existing First Kindling / Field Academy / Whispering Glade story. **Not** an alternate opening.

## Narrative principle
This lesson proves the planet responds to care *without guaranteeing an Eco-Kin will agree to accompany a player*. A Tamer of Beasts arrives after local storm damage has stranded a habitat path. A.E.G.I.S. recognizes evidence; D.A.H.L.I.A. offers a cautious explanation. The mentor is an **existing approved character**, to be selected from the authorized Field Academy cast (do not invent staff names or overwrite their arcs). The player's decision changes the local path visibly.

### Events
| Beat | Player action / ecological context | Evidence to persist |
|---|---|---|
| 01 Arrival | first sight of damaged water passage, visible footprints | `Lesson.Watershed.Arrival` |
| 02 Observe | A.E.G.I.S. measures substrate, calls and weather; player can leave | `Lesson.Watershed.Observed` |
| 03 Diagnose | choose report/habitat intervention route; D.A.H.L.I.A. marks inference vs certainty | `Lesson.Watershed.Diagnosis` |
| 04 Protect | restore water current or keep a safe evacuation corridor | `Lesson.Watershed.SafeRoute` |
| 05 Response | Eco-Kin emerges from shelter or stays hidden based on authored behavior | `Lesson.Watershed.IndividualSeen` |
| 06 Calm | patient space / nonthreatening choice; refuge stays valid | `Lesson.Watershed.Calm` |
| 07 Invitation | may offer mutual Kindling, or Release/Defer immediately | `Lesson.Watershed.InvitationState` |
| 08 Ceremony | if accepted, optional accessible two-way attunement; never a capture cutscene | `Lesson.Watershed.CeremonyOutcome` |
| 09 Mentor Review | mentor praises ethics/evidence, not forcibly owning a companion | `Lesson.Watershed.MentorReviewed` |
| 10 Return | save restored water + study record; optional new companion relationship | `Lesson.Watershed.Complete` |

### Three valid results
**Bond** — individual accepted the relationship freely; existing Kindling registry commits once. A.E.G.I.S. records known behaviors and the player's approved care choices. No newly manufactured creature.

**Release** — individual remains free in the habitat; no punishment or quest reset. Mentor discusses the ecological benefits of leaving a stable family group undisturbed.

**Defer** — invitation is postponed for a meaningful change or the individual refused; document the observation and return after further ecological care only when eligible. No button-spam retry.

**Care redirect** — if injured/strained, refer to Sanctuary Recovery Ward / Nurse Calla and treat first; treatment must never automatically award a bond. This is a safe detour, not a fourth compulsory acquisition outcome.

### Conditional field dialogue (placeholder lines, not final voiced script)
- Mentor: “Look at the water first. The tracks only tell us who passed through, not who belongs to us.”
- D.A.H.L.I.A.: “Movement detected near the channel. Identification remains uncertain. The sheltered route is the safer approach.”
- Mentor after Defer: “You learned what it needed. That counts—even if it chooses another path.”
- Mentor after Bond: “A partnership begins with a choice. Keeping that promise is the work ahead.”

### Story consequence
The repaired watercourse feeds a **small Heartroot watershed restoration flag** only; it cannot instantly heal the Tree of Life or rewrite any ending gate. Revisit shows reduced obstruction, a changed plant health mesh/material, and unforced Eco-Kin travel. Mentor's later dialogue must respect Release/Defer without falsely assuming a partnered species.

## Mission tech rules
Use existing MissionID/story/faction registries; above tags are **working**, not locked IDs. Persist `ObjectiveId + EventId + AuthoritativeResult` with idempotent first-clear outcomes. Save between all beats; if player disconnects during Kindling, return to safe `Defer`, not auto-Bond. Do not gate campaign on exact Eco-Kin species ownership, a rare drop, a combat victory or multiplayer participation.

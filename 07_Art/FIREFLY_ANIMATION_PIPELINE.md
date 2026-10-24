# Firefly → Echohearts animation production intake (2026-10-08)
Status: PROPOSAL / NOT RUNTIME VERIFIED. This extends existing canon; it is not a replacement art manifest.

## Source lock
Consult MASTER_PROJECT_INDEX.md, 00_Canon_Lock, the approved Eco-Kin art manifest, permanent 125-ID Dex, and approved Young Savior designs before creating shots. Keep original anatomy, exact identifiers, materials, silhouette, lighting, colors, equipment, species type, and evolution relationships. Do not promote historical roster names to canon. No third-party reference art without rights clearance.

## Animation pipeline
1. Identify an approved source asset and capture its checksum, stable ID, author/rights, version, and approval state.
2. Prepare an identity-locked turnaround, separate silhouette/anatomy sheet, rigging requirements, motion reference, and shot specification. A Firefly-generated image/video is reference or cinematic media, not skeletal animation.
3. Generate short image-to-video motion studies in Firefly where the connected Adobe account supports that action. Require stable face, limb count, textures, costume, and scale. Reject hallucinated anatomy or extra appendages.
4. For gameplay: construct/validate mesh, skeleton, skin weights, animation retargeting, root motion, sockets, collisions, locomotion, additive actions, and UE-compatible animation imports through the approved DCC pipeline. For cinematics: import approved video or recreate shots in Sequencer with real 3D assets.
5. Author Animation Blueprint state machine, montage/notify windows, Niagara effects, gameplay timing and Anima-Link response separately. Do not derive authoritative damage from video frames.
6. Test idle/walk/run/turn/attack/defend/recovery/summon and optional Growth Rite, Mutation, Shimmer, and purification where canon permits. Confirm loop seams, foot contact, camera clipping, lip sync, platform LOD, and accessibility settings.
7. Verify import in UE5.8, Editor/PIE, packaged target, multiplayer authority, and target-hardware performance before marking VERIFIED.

## First animation acceptance slice
Use one already-approved animal-type Eco-Kin and one already-approved Young Savior. Produce idle, locomotion, attack anticipation, strike, recovery, defensive reaction, and an A.E.G.I.S./Anima-Link feedback cue. Do not substitute unapproved character designs.

## Firefly prompt template
"Animate the supplied approved Echohearts [ID] artwork as an identity-preserving [duration] motion study: [precise action], [camera], [habitat]. Preserve exact body plan, limb count, face, silhouette, markings, costume/Ancient Tech, materials, and lighting. No morphing, extra limbs, redesign, added text, or unrelated characters. Consistent frame-to-frame anatomy." Review output manually; prompts cannot guarantee fidelity.

## Combat and elemental VFX
Define attack gameplay events and animation notify windows in Unreal; use Niagara for resonance pulses, impacts, purification, environmental response, and four-attribute feedback. Harmonize effects with Vibrance, Density, Harmony, Purity; preserve Anima-Link player strain costs. Optimize Niagara scalability tiers on measured hardware, not a shader-side FPS guess.

## Opening cinematic — shot treatment (PROPOSAL)
A. Rebearth ecological vista (approved Moonridge/Deepwood or another approved map thumbnail as reference only).
B. Show evidence of ecosystem disturbance through original environmental effects; no new canon claims.
C. A.E.G.I.S. pulse establishes player/Eco-Kin bond, then a canon-approved Young Savior enters frame.
D. Approved Eco-Kin responds with a distinctive species-correct motion; Anima-Link visual pulse connects both.
E. Echohearts Sanctuary restoration motif closes with title treatment.
Require story sign-off for named antagonists, dialogue, exact chronology, and Sanctuary portrayal. Storyboard and audio approval precede production. Firefly video may serve as previsualization; final interactive sequences require UE Sequencer/rigged assets.

## Asset records and quality gates
Record stable asset ID, source checksum, original artwork path, Firefly model/version/settings, prompt, seed if supported, license/commercial-use review, duration/FPS/resolution, approval status, UE import type, and test evidence. Preserve source files and provenance; never overwrite approved art silently.

# First Playable Eco-Kin — Environment / Character / Animation / VFX Production Shotlist
**Status:** ART PRODUCTION REQUIREMENTS ONLY (not delivered assets), supplement to existing Issue #10 and PR #71 workstream M15–M17.

## Preserve art/Dex provenance
Only approved species already listed in the **125-ID Permanent Dex** may be used as the first wild actor. Select one actual identity after inspecting art manifest, anatomy and rig; no generated placeholder may become the production species. First player character preserves established **Frequency Tamer / Core-Binder** identity until draft PR #70's **Tamer of Beasts** proposal receives authoritative approval. Review proposed hip A.E.G.I.S./Eco-Device visuals against the existing bracer/device canon before replacing any approved asset. Every file needs `SourceID`, `EcoKinID` or actor ID, author/permission, silhouette comparison, approval state, exported asset version, skeleton ID and LFS checksum.

## Minimum first playable deliverables
| Asset card | Type and acceptance | Dependency |
|---|---|---|
| `VIS_ECO_001` | approved source turntable (front/side/back), verified body plan and ecology tags | art manifest + Dex |
| `MESH_ECO_001` | in-engine mesh with correct scale, anatomy, pivot, material slots, LOD and collision | `VIS_ECO_001` |
| `RIG_ECO_001` | joint rig / IK joints, no deformation crossing in turn or walk | `MESH_ECO_001` |
| `AN_ECO_IDLE` | natural breathing/attention and 10–20s variation, no frozen idle | rig |
| `AN_ECO_MOVE` | authored walk/forage locomotion, grounded contacts | rig |
| `AN_ECO_WATCH` | head/body notice, audible/visible posture readable | rig |
| `AN_ECO_WARN` | proportional defensive warning, has disengage alternative | rig |
| `AN_ECO_RETREAT` | convincing voluntary departure and safe nav exit | rig |
| `AN_ECO_RELAX` | settles visibly after safe intervention, no forced docility | rig |
| `AN_ECO_INVITE` | optional approach initiated by Eco-Kin itself | rig + authored agency |
| `AN_ECO_ACCEPT` | voluntary reciprocal gesture with no capture animation | rig |
| `AN_ECO_REFUSE` | nonhostile departure/pause, clear readability | rig |
| `AN_ECO_REST` | voluntary rest / healing posture and release | rig |
| `VIS_PLAYER_001` | approved player proxy, interaction silhouette, hip device attachment | current body issue |
| `RIG_PLAYER_001` | attach/locomotion/interact and three ceremony poses | character owner |
| `ENV_FIELD_001` | creek/habitat floor, approach route, safe exits, foliage tell markers | level owner |
| `ENV_REPAIR_001` | reversible obstruction/creek valve/bridge-protection prop | mission owner |
| `ENV_SCAN_001` | tracks, bedding, disturbed leaves, substrate impressions | ecology author |
| `FX_DEVICE_001` | contained reciprocal signal on hip A.E.G.I.S., reduced-flash option | VFX + UI |
| `FX_WEATHER_001` | small authored cloud/rain cue with same server hazard across detail levels | atmospheric owner |
| `AUD_ECO_001` | living call variations + warning/rest sound, original recorded/generated rights | audio |
| `AUD_DEVICE_001` | observe, defer, accept/reject, strain caution with captions | audio/UI |
| `UI_SLICE_001` | eight screens of first-ceremony interaction blueprint | UI |
| `CAM_CEREMONY_001` | shared framing without stealing locomotion/exit agency; low-motion alt | gameplay camera |
| `QA_ASSET_PACK_001` | 6-shot review: idle, walk, warn, refuse, gesture, rest | QA |

## Content quality rules
A beautiful static design is **not** a game asset. Asset is not usable until licensed/approved original mesh, import materials, collisions, textures/LODs, skeleton/socket rules, animations and level placement are demonstrated in the actual editor. DCC source can be Blender; authoritative gameplay, animation graphs and packaged content remain in UE5.8 BUILD. No cross-species skeleton retarget without matching structure and motion identity.

Visuals should reveal regional weather and restoration through real water quality, foliage condition and shelter movement. Photographic city reference images can guide *density/camera/composition*, never copied franchise identity, exact landmark architecture, logos or outside copyrighted character silhouettes.

**Clinical care branch:** one safe recovery space and one nurse/doctor role may be staged using the existing Nurse Calla / Recovery Ward continuity. New healing Eco-Kin species or forced support-role labor are not auto-canon. Player-visible care should include voluntary assistance, triage, shelter and discharge.

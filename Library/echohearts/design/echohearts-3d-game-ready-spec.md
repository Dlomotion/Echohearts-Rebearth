# ECHOHEARTS: REBEARTH — 3D Game-Ready Spec (Pantheon line, Dex 637–646)

What "game-ready" means for each character, so a 3D artist (or 3D pipeline)
can take the turnaround sheets and produce UE 5.8.3-importable assets.
(CONCEPT — no meshes exist yet; nothing modeled, rigged, or imported.)

## Per character: the asset package (×2 forms each)

Each of the 10 figures ships **two models**: the animal EcoKin form and the
Humanoid-Kin path form.

| Deliverable | Format | Notes |
|---|---|---|
| Hero mesh | FBX 2020 | Quads, clean edge flow; units = cm; Y-up on export |
| Rig | in-FBX skeleton | See rig archetypes below; Humanoid-Kin forms use the UE5 mannequin-compatible hierarchy so retargeting works |
| Textures | PNG/TGA | Albedo + Normal + Roughness (+ Emissive for essence VFX zones); 2048px hero, 1024 LOD1 |
| LODs | LOD0/LOD1/LOD2 | LOD0 30–45k tris (hero), LOD1 ~15k, LOD2 ~5k; auto via UE5 LOD groups if hand-authored LODs aren't available |
| Physics asset | in-UE5 | Capsule = hurtbox body; per fight-layout hitbox spec |

## Rig archetypes (maps to the fight layout's ~12 rigs)

- **Humanoid-Kin forms** → Biped (UE5 mannequin-compatible). All 10.
- Mafdet (panther), Bastet (cat), Sekhmet (lion) → Quadruped-Feline
- Tawret (hippo), Sobek (crocodile) → Quadruped-Heavy
- Isis (hawk), Ra (falcon), Osiris (ibis) → Avian
- Kali Ma (serpent) → Serpentine
- Heqet (frog) → Quadruped-Amphibian

Rigs share animation within an archetype (one "Quadruped-Feline Slash"
retargets to Mafdet, Bastet, and Sekhmet).

## Required sockets (per model — this is the fight layout's hitbox contract)

Every model MUST carry these sockets or the combat system can't address it:
`HeadSocket`, `Hand_R` / `Hand_L` (or `PawF_R`/`PawF_L` on quadrupeds,
`WingTip_R`/`WingTip_L` on avians), `Foot_R` / `Foot_L`, `TailTip` (serpentine,
feline, crocodile), `ChestCore` (Resonant Climax anchor). Socket names are
canonical — the hitbox component looks them up by name.

## Naming convention (UE5 Content Browser)

`/Game/EcoKin/Dex637_Mafdet/SK_Mafdet_Animal, SK_Mafdet_Humanoid,
T_Mafdet_Albedo, PA_Mafdet_Hero…` — DexID-first so the EcoDex and the asset
registry resolve to the same key.

## Turnaround sheets (this batch)

- `EK_ART_<Name>_Dex<NNN>_TURNAROUND_v1.png` — front + side views, both forms,
  neutral background, anime-toon style. These are the modeling reference.
- Done: Mafdet 637, Isis 638, Ra 639, Osiris 640.
- Pending: Kali Ma 641, Bastet 642, Heqet 643, Tawret 644, Sekhmet 645,
  Sobek 646.

## Import checklist (Tay's machine, UE 5.8.3)

1. FBX import with "Import as Skeletal", skeleton = archetype base.
2. Verify sockets exist (Skeleton Tree → Sockets).
3. Assign physics asset; set hurtbox capsule collision profile.
4. Build LOD groups; check LOD1/LOD2 swap distances in PIE.
5. First compile of the moveset Data Asset row for the DexID (fight layout
   build order step 6).

## Honest limits

- No meshes, rigs, or textures exist yet — the sheets are reference, not
  assets. IMPLEMENTED status only when FBX + textures land in the repo;
  RUNTIME VERIFIED only after UE5.8.3 import + PIE.
- The next real step is a 3D artist or a dedicated 3D-generation pipeline;
  these sheets + this spec are the handoff package.

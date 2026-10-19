# E.C.O. SENTINEL — UE5.8 DESIGN RECONCILIATION

**Project:** Echohearts: Rebearth  
**Status:** APPROVED-PENDING SYSTEM / STORY DESIGN  
**Implementation status:** **NOT YET VERIFIED**  
**Production runtime:** Unreal Engine 5.8

## AI Mistake Patch / Continuity QA
The recovered concept contained strong ancient-terraformer, reactive-element, environmental-combat and empathy-story ideas, but several old terms conflict with current canon.

Corrections:
- E.C.O. Sentinel is **not an Eco-Kin species and not player property**. It is an ancient Meridian ecological construct with agency.
- `Fire / Earth / Wind / Water` become the locked Echohearts elements where used: **Magma / Terra / Aero / Hydro**. Other modes may use Solar, Lunar, Flora, Volt, Iron/Tech, Spirit, Chaos or Radiant only when justified.
- `Prism Pyramid` is not introduced as a new independent world landmark. Use a **Prism Vault / calibration chamber inside an approved Tri-Core Monolith or Meridian facility** unless world canon later names a separate location.
- `Heart-Code` is treated as legacy terminology. Current interaction is Resonance / A.E.G.I.S. / Kindling-aligned communication and restoration.
- `Backup Drive for the planet` becomes a **World-Memory Anchor** function. Rebearth remains a living physical world, not a server image.
- Direct comparisons to outside franchises are reference-only and removed from publication canon.
- Random all-element immunity is replaced with readable, telegraphed reactive calibration to prevent soft-lock combat.

## Identity
**Working name:** E.C.O. Sentinel  
**Expansion:** **Ecological Cycle Overseer**  
**Class:** Meridian Ecological Construct / Ancient Tech Guardian  
**Narrative role:** dormant terraforming caretaker whose damaged directive equates unmanaged humanity with ecosystem collapse.

E.C.O. is not a villain by nature. Its error is a broken ecological equation: it can measure damage but cannot initially understand consent, culture, mercy, coexistence or restoration over time.

## Visual identity
- Living Porcelain / pale mineral shell.
- Hairline cracks containing moss, lichen and reclaimed-root growth.
- Gold Meridian conductor lines.
- Suspended Prism Engine in the chest.
- Detached or semi-floating extremity plates held by resonance fields.
- Mode changes alter light, vents, surface geometry and projected field patterns rather than replacing the entire body.
- Damage should reveal old repairs and ecological scars, not generic exposed robot wiring.

## Reactive calibration combat
### Core rule
When E.C.O. receives repeated authoritative elemental impacts, it builds a **Calibration Score** for the dominant incoming element. At the threshold it shifts to that mode.

Example:
`Player applies Magma pressure → E.C.O. calibrates to Magma → Magma resistance rises → Hydro / approved counterplay window becomes favorable.`

Do **not** use absolute immunity as the normal rule. Resistance caps, transition windows, telegraphs and cooldowns keep the fight readable and prevent hard counters from becoming mandatory.

### Suggested modes
- **Magma Calibration** — heat vents, scorched-zone denial, heat-resistant shell.
- **Terra Calibration** — plated guard geometry, shockwave defense, heavier stagger resistance.
- **Aero Calibration** — lighter movement, turbine vents, displacement attacks.
- **Hydro Calibration** — cooling mist, fluid redirection, cleansing pools.
- **Volt Calibration** — chain-discharge lanes, conductive hazard routing.
- **Flora Calibration** — root barriers, healing vegetation, terrain control.
- **Radiant / Solar Calibration** — high-energy prism beam behavior for late encounter phases only.

## Signature actions
### Prism Nova
Telegraphed prism discharge using the current calibrated element plus up to two queued channels. Status application is deterministic from the channel state, not random roulette.

### Biome Recalibration
Canonical replacement for `Terrain Overwrite`.

E.C.O. temporarily changes a bounded combat zone:
- Magma: heat field / safe-stone islands.
- Hydro: cooling flow / slippery current.
- Flora: growth cover / restorative plants.
- Terra: raised protection ridges / fracture lines.
- Aero: wind lanes / displacement zones.

The change is local, temporary and encounter-authored. It does not instantly terraform Rebearth.

## Story quest chain
### ECO-01 — The Silent Gardener
**Trigger:** A.E.G.I.S. detects a dormant Meridian ecological signal in a Prism Vault.  
**Goal:** restore three non-sentient calibration relays without awakening the construct violently.  
**Lesson:** Ancient Tech restoration + environmental scanning.  
**World delta:** the chamber's dead irrigation channels begin moving again.

### ECO-02 — Three Measures
The player retrieves three calibration records from the existing Tri-Core Monolith network. Each record shows a different historical failure: extraction without renewal, restoration without restraint, and control without consent.

**Gameplay:** puzzle/exploration objectives, no forced Eco-Kin sacrifice or capture.

### ECO-03 — The Wrong Equation
E.C.O. awakens and concludes that the nearby settlement is the destabilizing variable. The player must prevent a purge sequence while keeping E.C.O. intact enough to recover its historical memory.

**Combat objective:** survive and interrupt calibration relays, protect civilians/Eco-Kin, restore damaged field nodes, and reduce E.C.O.'s certainty rather than simply depleting HP to zero.

### ECO-04 — Proof of Life
The player demonstrates a functioning restored ecosystem through Sanctuary evidence: clean water, stable soil, voluntary Eco-Kin assistance, recovered habitat and community cooperation.

E.C.O. updates its directive from **control life** to **support life's recovery**.

### ECO-05 — The Gardener's Choice
E.C.O. independently chooses whether to remain at the Vault, assist a damaged biome, or travel to a specific restoration site. It is not added to creature storage.

A completed relationship can unlock an optional **World-Memory Anchor** contribution toward late-story Harmonic Resonance requirements. It is one route among several, not a mandatory single-character key to the True Ending.

## Unreal Engine 5.8 implementation direction
Do not build a monolithic all-purpose class.

### Data
Use a `UPrimaryDataAsset`-derived definition for authored mode data, thresholds, VFX/audio references, ability identifiers and encounter tuning. UE5.8 `UPrimaryDataAsset` supports Primary Asset identity and asset-bundle management.

### Runtime actor
Recommended structure:
- `AECOSentinelCharacter` or equivalent movement-capable Pawn.
- `UECOCalibrationComponent` for replicated calibration state.
- Gameplay Tags for element/mode/status identity.
- StateTree for encounter behavior and phase control.
- Niagara for calibration fields, Prism Nova and biome-zone VFX.
- authored encounter actors / Smart Objects for repair relays and environmental interaction points.

### Authority rule
Calibration transitions occur from **server-authoritative validated combat events**. Clients do not send free-form element strings, target mode, damage totals or phase transitions.

Replicated Actor Components require a replicated owning Actor and replicated component configuration. State presentation should be driven through replicated properties / result events, not custom raw packet code unless profiling later proves a need.

### Minimal C++ contract — illustrative only
```cpp
USTRUCT(BlueprintType)
struct FECOCalibrationState
{
    GENERATED_BODY()

    UPROPERTY(BlueprintReadOnly)
    FGameplayTag ActiveElement;

    UPROPERTY(BlueprintReadOnly)
    float CalibrationStrength = 0.0f;
};

UCLASS(ClassGroup=(Echohearts), meta=(BlueprintSpawnableComponent))
class ECHOHEARTS_API UECOCalibrationComponent : public UActorComponent
{
    GENERATED_BODY()

public:
    UECOCalibrationComponent();

    UFUNCTION(BlueprintPure)
    const FECOCalibrationState& GetCalibrationState() const { return CalibrationState; }

    // Called only by authoritative combat resolution, not directly from client UI.
    void RegisterValidatedElementalImpact(const FGameplayTag& ElementTag, float NormalizedImpact);

protected:
    UPROPERTY(ReplicatedUsing=OnRep_CalibrationState)
    FECOCalibrationState CalibrationState;

    UFUNCTION()
    void OnRep_CalibrationState();
};
```

This is an architecture contract, **not compiled project code**. The current repository does not yet prove a production `.uproject` / `Source` tree and the established technical gates still apply.

## Unity-to-Unreal correction
The recovered Unity `SimpleRandomWalk`, C# battle/state-manager and Canvas/Web prototypes remain historical references. Do not port them line-for-line.

For the actual Rebearth world:
- authored Landscape + World Partition remains the primary large-world structure;
- PCG graphs handle biome population, scatter, authored procedural subregions and replayable local generation;
- Data Layers/HLOD integrate generated content into World Partition;
- deterministic seeds can be stored for replayable local procedural sites where required;
- Living Crust / Deep Root destructibility remains localized rather than turning the whole open world into a replicated voxel array.

## Acceptance criteria before VERIFIED
1. Current UE5.8 project tree exists and is buildable.
2. E.C.O. definition data is registered through the approved data architecture.
3. Server-authoritative calibration tests pass.
4. Phase/state recovery survives save/load, travel and reconnect where applicable.
5. StateTree encounter behavior passes deterministic automation scenarios.
6. Niagara/material mode transitions profile within encounter budgets.
7. All world changes are bounded and reversible/persistent exactly as mission design specifies.
8. Story consequences and World-Memory Anchor flags are saved with authoritative terminal proof.

© 2026 Into Deep Studios and Donta L. Owens. All rights reserved.

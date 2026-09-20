# BCT-001 — Building & Crafting Transaction Contract

© 2026 Into Deep Studios and Donta L. Owens. All rights reserved.

**Status:** DESIGN / ARCHITECTURE
**Runtime target:** Unreal Engine 5.8
**Verification:** NOT YET VERIFIED
**Code policy:** Do not add gameplay C++ until the Unreal project/source tree is present and the existing systems have been inspected.

## Player-experience reason
Building and crafting must feel immediate and understandable while remaining safe under multiplayer, saves, reconnects, world streaming, and ecological rules. Every successful action must visibly reinforce at least one Heart Statement pillar:
1. This world needs me.
2. These Eco-Kin are alive.
3. My choices changed Rebearth.

## Core authority flow
`owned request → server validation → inventory reservation → ecological/world veto → atomic commit → authoritative event ID → replication → asynchronous persistence → local presentation`

No client-side preview, animation, UI, or prediction may become gameplay authority.

## Supported transaction families
- Place a Sanctuary structure.
- Upgrade or repair a structure.
- Remove/deconstruct an owned structure when rules allow.
- Craft an item or field tool.
- Queue a Sanctuary production recipe.
- Cancel a queued craft before commitment when permitted.
- Restore/repair an ecological structure such as a Purity Well or root brace.

## Data-first asset model
Use Unreal Primary Assets for definitions that must be resolved by stable IDs rather than hard references.

Proposed Primary Asset types:
- `BuildPiece`
- `CraftRecipe`
- `ItemDefinition`
- `SanctuaryModule`

Each definition should contain data, not transaction authority.

### Build-piece definition fields
- Primary Asset ID
- Display name
- Canon status
- Build category
- Cost list
- Placement footprint
- Rotation rules
- support/anchor requirements
- allowed/blocked Gameplay Tags
- ecological restrictions
- Sanctuary tier requirement
- preview mesh/material references
- final actor/class reference
- repair/deconstruction policy

### Craft-recipe definition fields
- Primary Asset ID
- input ingredients
- output item(s)
- quantity
- required station tags
- required progression tags
- craft time if queued
- cancellation/refund rule
- Sanctuary/Havenlink restrictions
- seasonal/world-state restrictions when relevant

## Gameplay Tags
Prefer hierarchical Gameplay Tags over scattered booleans for eligibility and world rules.

Recommended families:
- `Build.Zone.Sanctuary`
- `Build.Zone.ProtectedRoot`
- `Build.Rule.RequiresFoundation`
- `Build.Rule.NoLivingRootDamage`
- `Craft.Station.EchoWorkbench`
- `Craft.Station.CleanForge`
- `World.State.Blightfront`
- `World.State.Recovering`
- `Sanctuary.Mode.Peace`
- `Sanctuary.Mode.Alert`
- `EcoKin.State.Resting`
- `EcoKin.State.Stressed`

## Integer grid coordinates
Do not use raw floating-point `FVector` values as authoritative map keys for grid ownership.

Use a deterministic integer-cell identity, conceptually:
- X cell
- Y cell
- Z layer
- orientation index
- world/region identifier

World-space transforms are presentation/placement outputs derived from the authoritative cell identity.

## Request contract
Every build/craft request needs an idempotent request identity.

Required request data:
- Request/Event ID
- requesting player/controller identity
- action type
- Primary Asset ID
- quantity
- target grid cell for building actions
- orientation
- source inventory/container identity when relevant
- expected world revision or ownership context when relevant

## Server validation gates
A request must fail without mutation if any required gate fails.

1. **Ownership/connection** — caller is authorized to request the action.
2. **Asset existence** — requested Primary Asset ID resolves to an approved definition.
3. **Canon status** — retired/forbidden/design-only assets cannot enter runtime transactions.
4. **Progression** — recipe/build piece is unlocked.
5. **Inventory availability** — required materials exist in authoritative inventory.
6. **Reservation** — materials are reserved before expensive placement work.
7. **Range/context** — player is allowed to interact with the station/zone.
8. **Placement** — footprint, collision, terrain, support, and overlap rules pass.
9. **Ecological veto** — living roots, protected habitats, Purity wards, Eco-Kin rest zones, and story-protected landmarks can reject placement.
10. **Sanctuary/world state** — current Sanctuary mode and world state allow the action.
11. **Rate/idempotency** — duplicate/replayed requests return the existing result instead of double-spending.

## Reservation, commit, rollback
### Reserve
Reserve required materials without yet finalizing the world mutation.

### Commit
Only after every authoritative rule passes:
- consume reservation,
- create/update the authoritative structure or crafting job,
- issue one authoritative event ID,
- replicate state,
- mark persistence dirty.

### Rollback
If any commit stage fails:
- release reservation,
- remove partial authoritative state,
- emit a failure result tied to the same request ID,
- do not create duplicate compensation rewards.

## Replication rules
- Server owns final building/crafting state.
- Clients may render placement previews and predicted UI feedback only.
- Replicated collections should use delta-oriented replication where appropriate rather than resending entire inventories/structure sets.
- Authoritative event IDs are used for deduplication and prediction reconciliation.
- Cosmetic FX/audio/UI consume events; they do not determine transaction success.

## Persistence rules
- Version save records.
- Save stable asset IDs, quantities, integer grid identities, ownership, structure state, world-state references, and transaction/recovery markers.
- Prefer asynchronous SaveGame operations for normal active-play autosaves.
- Do not describe raw binary output as encrypted unless actual authenticated encryption is implemented and verified.
- A save acknowledgment is not a gameplay commit; the transaction commits in server authority first, then persistence records it.

## Ecological and canon vetoes
Building/crafting must never silently permit:
- damage to protected living roots,
- forced Eco-Kin labor,
- Eco-Kin storage as inventory objects,
- construction inside Kindling Haven rest space without explicit system permission,
- raw Blight material crafting before purification,
- trapping/capture devices that violate current canon,
- Titan/Guardian weaponization,
- duplicate parallel Sanctuary automation systems.

## Blueprint-facing layout
Before C++ exists, the implementation should be represented with data and Blueprint-facing specs:

### Content folders
- `Content/Echohearts/Data/BuildPieces/`
- `Content/Echohearts/Data/CraftRecipes/`
- `Content/Echohearts/Data/Items/`
- `Content/Echohearts/Blueprints/Building/`
- `Content/Echohearts/Blueprints/Crafting/`
- `Content/Echohearts/UI/Building/`
- `Content/Echohearts/UI/Crafting/`

### Proposed assets
- `DA_BuildPiece_*`
- `DA_CraftRecipe_*`
- `BP_BuildPreviewActor`
- `WBP_BuildWheel`
- `WBP_CraftingStation`
- `WBP_TransactionResult`

These names are implementation proposals, not verified existing assets.

## Minimal future C++ layout
Create only after the Unreal project tree is available and current systems are inspected.

Proposed responsibilities:
- transaction/request types
- server-authoritative build/craft service or subsystem
- data definitions/Primary Asset IDs
- inventory reservation interface
- placement validator interface
- ecological veto/world-rule interface
- persistence adapter
- replication/recovery state

Avoid a monolithic `BuildingComponent` that owns inventory, placement, networking, saves, world rules, and UI at once.

## Recovery requirements
BCT-001 must survive:
- duplicate client request
- timeout and retry
- client disconnect after reservation
- server rejection after preview
- save delay
- world-partition unload/reload
- reconnect
- structure actor respawn/reconstruction from persistent state

## Acceptance tests
### Static/data
- all BuildPiece and CraftRecipe IDs unique
- all runtime assets CanonStatus-approved
- no retired terms referenced by active data
- no recipe references missing items
- no ecological restriction points to an unknown tag

### Multiplayer
- dedicated server, two clients
- simultaneous build on same cell
- simultaneous craft using same last materials
- replay duplicate request ID
- disconnect between reserve and commit
- test at 150/250/350 ms simulated network conditions
- no double spend, duplicate structure, duplicate output, or ghost reservation

### Persistence
- commit, save, restart, reload
- rollback does not reappear after restart
- version migration test when schema changes

### Player experience
- preview clearly explains why placement is invalid
- failed transaction never consumes materials
- success feedback arrives once
- repair/deconstruct consequences are clear before confirmation
- ecological veto language explains the world reason, not only an error code

## Dependencies
- VS-AZ-02 A.E.G.I.S. Command Buffer proof
- ECO-API-001 authoritative ability/transaction event contract
- authoritative inventory model
- Primary Asset definitions
- Gameplay Tags dictionary
- world/region state source
- Sanctuary permissions
- persistence/save layer
- replication/recovery layer

## Production order
1. Build `EchoheartsEditor` under UE 5.8.
2. Run `Echohearts.Partners.CommandBuffer`.
3. Test reload/recovery marker at 150/250/350 ms.
4. Implement `ECO-API-001`.
5. Implement the smallest BCT-001 reservation/commit/rollback kernel.
6. Add one BuildPiece and one CraftRecipe vertical-slice transaction.
7. Run multiplayer + persistence regression tests before expanding the catalog.

## Evidence status
Architecture is documented. Runtime compilation, Automation, dedicated-server behavior, persistence, prediction reconciliation, performance, and packaging remain **NOT YET VERIFIED**.

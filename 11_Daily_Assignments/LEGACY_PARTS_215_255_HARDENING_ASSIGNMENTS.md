# Legacy Parts 215–255 Hardening Assignments

© 2026 Into Deep Studios and Donta L. Owens. All rights reserved.

Status: ACTIVE AUDIT QUEUE / NOT YET VERIFIED
Owner workflow: Echohearts Daily Game Work

## Goal
Turn the useful ideas from the historical Parts 215–255 code batch into a small number of correct, canon-safe, UE5.8-native systems without duplicating current Echohearts architecture.

## P0 Gate
Do not implement these tasks ahead of the current technical sequence:
1. EchoheartsEditor UE5.8 build
2. `Echohearts.Partners.CommandBuffer`
3. reload/recovery/travel/reconnect/late-join tests at 150/250/350 ms
4. ECO-API-001
5. BCT-001 smallest reservation/commit/rollback kernel
6. one BuildPiece and one CraftRecipe end to end

## Assignment Queue

### EH-TECH-215255-001: POI/Fast-Travel Authority Contract
**Goal:** Replace invalid subsystem RPC entry with one ownership-correct request path.

**Deliverable:** design/implementation spec for:
`UI/Input -> owned request component -> server POI validation -> World Partition preload -> safe arrival -> relocation -> replicated result`

**Acceptance:**
- no client actor/tracker/component pointers trusted
- stable POI ID only
- restoration/quest/combat gate
- destination streaming completion
- safe spawn/collision check
- active Eco-Kin/mount/co-op behavior specified
- retry/idempotency behavior specified

### EH-TECH-215255-002: POI Registry Data Model
**Goal:** Replace hardcoded names/coordinates with approved Rebearth data.

**Deliverable:** Primary Data Asset or Data Table schema review containing stable ID, display name, region, world transform/anchor, discovery rule, restoration gate, fast-travel permission, streaming-source settings, map icon and localization key.

### EH-TECH-215255-003: A.E.G.I.S. Compass Merge
**Goal:** Merge compass/radar/altimeter concepts into the existing Quick Wheel/Journey Journal/CommonUI plan.

**Acceptance:**
- no duplicate HUD stack
- controller/keyboard remapping
- readable icon+text
- scalable HUD
- reduced-motion/high-contrast/audio alternatives
- data-driven POI labels

### EH-TECH-215255-004: BCT-001 Sandbox Reconciliation
**Goal:** Fold sandbox grid placement/removal into BCT-001.

**Acceptance:**
- deterministic integer cells
- authoritative identity, inventory and permissions
- reservation before commit
- ecological veto
- rollback and idempotent retries
- relevant delta replication only
- save/reload persistence
- no giant unbounded replicated array

### EH-TECH-215255-005: Swimming/Oxygen Contract
**Goal:** Replace the incorrect `FluidFriction` implementation with UE5.8 water-volume/CharacterMovement rules.

**Acceptance:**
- Physics Volume or approved Water integration
- `MOVE_Swimming`/movement settings used correctly
- server-resolved submersion
- validated gear entitlement
- pressure/depth rules linked to Neon Sea and aquatic traversal
- Eco-Kin anatomy respected
- no direct unsafe stat-field mutation

### EH-TECH-215255-006: Altitude & Flight Capability Contract
**Goal:** Keep altitude/environment classification without granting flight from Z position.

**Acceptance:**
- altitude zones do not override anatomy/capability
- flight requires flying partner/gear/approved movement state
- sky/deep hazards are data-driven
- world bounds use approved map/volume rules
- no teleport-based hard clamp unless evidence proves it is the right correction path

### EH-TECH-215255-007: Partner Command Language Cleanup
**Goal:** Replace coercive worker/combat terminology and duplicate UI.

**Proposed field commands:** Engage, Protect, Assist, Regroup, Hold, Retreat.

**Sanctuary:** use Sanctuary Aptitudes and consent/willingness states rather than forced work orders.

**Acceptance:** no Attack/Weight core stat drift; public Eco-Kin stats stay Vibrance, Density, Harmony, Purity.

### EH-TECH-215255-008: Save & Settings Consolidation
**Goal:** Stop duplicate save/settings architecture.

**Acceptance:**
- graphics/settings reviewed against `UGameUserSettings`
- active-play SaveGame uses `AsyncSaveGameToSlot` where appropriate
- version/migration rules defined
- no raw UObject worker-thread misuse
- no false encryption claims

### EH-TECH-215255-009: Platform Achievement/Cloud Boundary
**Goal:** Separate authoritative gameplay milestones from platform SDK execution.

**Acceptance:**
- one platform service interface
- no hardcoded Steam assumptions in gameplay classes
- no production AppID placeholders
- no manual platform initialization without approved integration
- user/account ownership and offline failure behavior defined
- no claim of encryption without actual cryptography

### EH-TECH-215255-010: Deep Root Tunnel / Dungeon Decision
**Goal:** Decide authored, procedural or hybrid underground layout before code.

**Acceptance:**
- integrates with Living Crust/Deep Root Tunnel canon
- deterministic seed if procedural
- room overlap/connectivity validation
- teardown/reset test
- save/reload identity
- mission/story purpose
- no generic loot-grind dungeon detached from restoration

### EH-TECH-215255-011: Excavation Authority Contract
**Goal:** Merge drill/excavation request with Living Crust and BCT-001 rules.

**Acceptance:** client sends target intent only; server resolves stratum, material, reach, tool, ecology veto, cost, reward and persistence.

### EH-TECH-215255-012: Automation Test Repair
**Goal:** Replace duration-only pseudo-tests with proof-bearing tests.

**Required test properties:**
- setup failure fails the test
- expected state/result assertions
- invalid request assertions
- authority/ownership assertions
- request retry/idempotency
- network emulation when applicable
- World Partition load completion
- save round trip
- teardown/cleanup
- Insights/profile evidence for performance claims

## Research rule
Official Epic UE5.8 docs first. Community GitHub examples may suggest patterns but are not build proof and must pass provenance/license review before any code is adapted.

## Status
All assignments remain NOT YET VERIFIED until actual project files, compile results, tests and profiles exist.
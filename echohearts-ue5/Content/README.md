# Content — what to create in the Unreal Editor

Binary assets (`.uasset`) can't be written as text, so the level and Blueprint wrappers are created in the editor in about 10 minutes. All gameplay logic is already in C++.

## 1. The level — `Maps/L_EchoHearts`
1. File → New Level → Empty Level. Save it as `Content/Maps/L_EchoHearts`.
2. Add: a large floor (Cube scaled up, or a Landscape), a Directional Light, a Sky Atmosphere / SkyLight, a few cubes/cylinders as trees and cover, and a Player Start.
3. World Settings → GameMode Override → **EchoHeartsGameMode**. It spawns the player pawn and all enemies/boss itself.

## 2. Blueprints (thin wrappers over the C++ classes, for meshes)
Create these in `Content/Blueprints/` — each is just "New Blueprint → parent class" plus a mesh:
- `BP_EchoPlayer` — parent **EchoHeartsCharacter**, add a cute character mesh, set its **Projectile Class** to `BP_EchoProjectile`. Then set it as the pawn the GameMode uses if you prefer it over the C++ default.
- `BP_EchoProjectile` — parent **EchoHeartsProjectile**, add a small glowing sphere mesh.
- `BP_Imp` / `BP_Monster` — parent **EchoHeartsEnemy**, set Kind = Imp / Monster, add a mesh (small purple / big green look great).
- `BP_Heartbreaker` — parent **EchoHeartsBoss**, big red mesh, set **Orb Class** to `BP_EchoProjectile`.
- `BP_Pickup_Heart` / `BP_Pickup_Star` — parent **EchoHeartsPickup**, Is Star off/on, heart/star mesh.

Then in the GameMode defaults (or a Blueprint GameMode child), point Enemy Class → `BP_Monster` (waves randomise the Kind on spawn) and Boss Class → `BP_Heartbreaker`.

## 3. HUD (optional, all data is Blueprint-readable)
A UMG widget reading the character's HP / Mana / Score / Hearts Collected, plus the boss's `BossHealthPercent()` for the boss bar, covers the whole HUD. Everything you need is exposed to Blueprints.

## Controls
WASD move · Mouse look · Space jump · Click / F = Echo Pulse · R = Echo Burst (30 mana) · Boss arrives every 3 levels, or call `SummonBoss` on the GameMode from a Blueprint/console for testing.

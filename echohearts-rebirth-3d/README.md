# EchoHearts Rebirth 3D (C++)

The 3D C++ edition of EchoHearts Rebirth. Original code, built with [raylib](https://www.raylib.com/) — Terraria-style generic rules, no Terraria code, art, or text.

You explore a 3D world, collect echo hearts and mana stars, defeat mischievous imps and void monsters with Echo Pulses, and summon and defeat the Heartbreaker boss.

## Build

**Visual Studio 2022 (easiest):**
1. File → Open → Folder… and select this folder.
2. Visual Studio reads `CMakeLists.txt`, downloads raylib automatically, and configures.
3. Build → Build All, then run `EchoHeartsRebirth3D.exe`. GitHub Copilot works in the editor as usual.

**Command line:**
```bash
cmake -B build -S .
cmake --build build
./build/EchoHeartsRebirth3D   # Windows: build\Debug\EchoHeartsRebirth3D.exe
```

**Test the game rules without a window:**
```bash
g++ -std=c++17 -I src tests/logic_test.cpp -o logic_test && ./logic_test
# or with CMake: ctest --test-dir build
```

## Controls

| Input | Action |
|---|---|
| WASD | Move (camera-relative) |
| Mouse / ← → | Turn camera |
| Space | Jump |
| Shift | Sprint |
| Left click / F | Echo Pulse — 22 damage |
| R | Echo Burst — 55 damage, 30 mana |
| B | Summon the Heartbreaker boss (at night, or after 10 hearts) |
| P | Pause |

## Terraria-style rules

- **HP & hearts:** 100 HP, each heart = 20 HP. Heart drops heal.
- **Mana & stars:** 100 mana, regens faster standing still. Star drops restore 50.
- **Contact damage & i-frames:** Enemy touch deals its damage minus your defence, then you get ~0.66s invincibility (blinking).
- **Weapons have stats:** damage, knockback, use time, 10% crit (double damage, gold number), mana cost.
- **Defence & knockback resistance:** Bigger enemies resist knockback; the boss barely budges.
- **Drops:** 25% heart, 20% star from defeated enemies.
- **Day / night:** Night spawns monsters faster and stronger.
- **Boss:** “Heartbreaker has awoken!”, HP bar, void-orb shots, spawns imps, enrages below 25% HP. Defeat it for **Rebirth**: +20 Max HP, +1 defence.
- **Enemies:** Mischievous Imp (20 HP, 12 dmg) · Void Monster (60 HP, 20 dmg, 2 def) · Heartbreaker Boss (600+ HP, 35 dmg, 6 def).

## Files

- `src/main.cpp` — the full 3D game (world, camera, combat, boss, HUD)
- `src/GameLogic.h` — pure C++ rules (no graphics dependency, unit-tested)
- `tests/logic_test.cpp` — headless rule tests
- `CMakeLists.txt` — fetches raylib, builds game + tests

## License

MIT — see the 2D project's LICENSE, or reuse that text here.

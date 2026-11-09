# EchoHearts Rebirth

A browser action game: collect echo hearts, defeat mischievous imps and void monsters, and take down the Heartbreaker boss.

## Play

Open `index.html` in a browser — no build step, no dependencies.

Or serve it:

```bash
python3 -m http.server 8000
# then visit http://localhost:8000
```

## How to play

- **Move:** WASD / Arrow Keys, or drag on mobile
- **Shoot Echo Pulse:** Space, click, or the Echo Pulse button
- **Echo Burst:** E — 55 damage, costs 30 mana
- **Pause:** P or the Pause button
- **Goal:** Collect hearts to level up. Every 3 levels the boss returns.

## Terraria-style rules (original implementation)

Mechanics inspired by Terraria's generic rules systems — no Terraria code, art, or text is copied:

- **HP & hearts:** You have 100 HP. Each heart icon = 20 HP. Enemy heart drops heal 20 HP.
- **Mana & stars:** You have 100 mana. It regens faster when you're not moving. Star drops restore 50 mana.
- **Contact damage & i-frames:** Touching an enemy deals its contact damage minus your defense, then you get ~0.66s of invincibility frames (blinking) so you don't melt instantly.
- **Weapons have stats:** Damage, knockback, use time, crit chance (10%, crits deal double and show `!`), and mana cost — shown in-game like a tooltip.
- **Damage numbers:** Every hit shows a floating number; crits are gold.
- **Knockback & defense:** Enemies subtract their defense from hits and resist knockback by size — the boss barely budges.
- **Drops:** Defeated enemies can drop a healing heart (25%) or a mana star (20%).
- **Day / night cycle:** Day is safer. At night monsters spawn twice as often and are stronger.
- **Boss rules:** A boss awaken message appears, a boss HP bar shows, the boss spawns minions, shoots projectiles, and enrages below 25% HP. Defeating it grants permanent (run-long) upgrades.
- **Death:** “You were slain…” screen, with your Best score kept.

## Enemies you defeat

| Enemy | HP | Contact damage | Defence | Behaviour | Reward |
|---|---|---|---|---|---|
| Mischievous Imp 😈 | 20 | 12 | 0 | Fast, darting, bumps you | +15 pts |
| Void Monster 👾 | 60 (more at night) | 20 | 2 | Chases you steadily | +25 pts |
| Heartbreaker Boss 👹 | 600 + level scaling | 35 | 6 | Charges, shoots void orbs, spawns imps, enrages at low HP, every 3 levels | +200 pts, Rebirth |
| Void Orb ◆ | — | 15 | — | Boss projectile — avoid it | — |

Defeating the boss triggers **Rebirth**: +20 Max HP, +40 HP healed, +1 defense, level up, and a fresh wave.

## Files

- `index.html` — page, HUD, boss bar, start / game-over overlay
- `styles.css` — all styling
- `game.js` — full game: player, echo trail, hearts, imps, monsters, boss, projectiles, levels, high score

## License

MIT — see `LICENSE`.

#pragma once

#include "CoreMinimal.h"

// EchoHearts core stats — Terraria-style generic rules, original values.
// Shared by player, enemies, boss, projectiles and pickups so every
// edition of the game (2D, C++, UE5) plays by the same rules.

namespace EchoHeartsStats
{
	// Player
	inline constexpr float PlayerMaxHP = 100.f;      // each heart on the HUD = 20 HP
	inline constexpr float PlayerMaxMana = 100.f;
	inline constexpr int32 PlayerDefence = 2;
	inline constexpr float InvincibilitySeconds = 0.66f; // i-frames after a hit

	// Weapons (Terraria-style stat block: damage / knockback / use time / crit / mana cost)
	inline constexpr float PulseDamage = 22.f;
	inline constexpr float PulseKnockback = 6.f;
	inline constexpr float BurstDamage = 55.f;
	inline constexpr int32 BurstManaCost = 30;
	inline constexpr float CritChance = 0.10f;       // crits deal double damage

	// Enemies
	inline constexpr float ImpHP = 20.f;
	inline constexpr float ImpDamage = 12.f;
	inline constexpr float MonsterHP = 60.f;
	inline constexpr float MonsterDamage = 20.f;
	inline constexpr int32 MonsterDefence = 2;
	inline constexpr float BossBaseHP = 600.f;       // +60 per level
	inline constexpr float BossDamage = 35.f;
	inline constexpr int32 BossDefence = 6;

	// Drops (Terraria-style: hearts heal 20, stars restore 50 mana)
	inline constexpr float HeartHeal = 20.f;
	inline constexpr float StarMana = 50.f;
	inline constexpr float DropHeartChance = 0.25f;
	inline constexpr float DropStarChance = 0.20f;

	// Defence reduces a hit, minimum 1 (crit doubles after defence).
	inline float DamageAfterDefence(float RawDamage, int32 Defence, bool bCrit)
	{
		float Dmg = FMath::Max(1.f, RawDamage - static_cast<float>(Defence));
		return bCrit ? Dmg * 2.f : Dmg;
	}
}

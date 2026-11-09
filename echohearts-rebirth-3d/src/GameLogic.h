#pragma once
// EchoHearts Rebirth 3D — core rules, pure C++17 (no graphics dependency).
// Terraria-style generic mechanics, original implementation:
// HP hearts (20 HP each), mana stars, contact damage, invincibility frames,
// knockback, crits, defence, drops, day/night, boss awaken + enrage.
#include <algorithm>
#include <cmath>
#include <cstdlib>

namespace echohearts {

struct WeaponStats {
    const char* name;
    int damage;
    float knockback;
    int useTimeFrames;   // lower = faster, like Terraria "use time"
    int critPercent;     // 10 = 10% chance, crits deal double
    int manaCost;
};

inline constexpr WeaponStats kEchoPulse{ "Echo Pulse", 22, 6.0f, 16, 10, 0 };
inline constexpr WeaponStats kEchoBurst{ "Echo Burst", 55, 9.0f, 38, 10, 30 };

struct Combatant {
    float hp = 100.0f;
    float maxHp = 100.0f;
    int defence = 0;
    float kbResist = 0.0f; // 0 = full knockback, 1 = immune

    bool alive() const { return hp > 0.0f; }
    // Returns the damage actually dealt (after defence, min 1; doubled on crit).
    float takeHit(float rawDamage, bool crit) {
        float dmg = std::max(1.0f, rawDamage - static_cast<float>(defence));
        if (crit) dmg *= 2.0f;
        hp -= dmg;
        return dmg;
    }
    float heal(float amount) { hp = std::min(maxHp, hp + amount); return hp; }
};

struct PlayerState : Combatant {
    float mana = 100.0f;
    float maxMana = 100.0f;
    int iframes = 0;              // invincibility frames after a hit
    int framesSinceHit = 9999;

    PlayerState() { hp = maxHp = 100.0f; defence = 2; kbResist = 0.5f; }

    // Terraria rule: contact damage only lands when i-frames have expired.
    // Returns damage dealt, or 0 if blocked by i-frames.
    float takeContactDamage(float rawDamage) {
        if (iframes > 0) return 0.0f;
        float dmg = takeHit(rawDamage, false);
        iframes = 40; // ~0.66s at 60fps
        framesSinceHit = 0;
        return dmg;
    }
    void tick(bool moving) {
        if (iframes > 0) --iframes;
        ++framesSinceHit;
        // Mana regens faster when standing still; HP regens slowly after 5s safe.
        mana = std::min(maxMana, mana + (moving ? 0.25f : 0.6f));
        if (framesSinceHit > 300) heal(0.05f);
    }
    bool spendMana(int cost) {
        if (mana < static_cast<float>(cost)) return false;
        mana -= static_cast<float>(cost);
        return true;
    }
    int heartsDisplay() const { return static_cast<int>(std::ceil(hp / 20.0f)); }
};

enum class EnemyKind { Imp, Monster, Boss };

struct EnemyStats { float maxHp; float contactDamage; int defence; float kbResist; int score; };
inline EnemyStats statsFor(EnemyKind kind, bool night, int level = 1) {
    switch (kind) {
        case EnemyKind::Imp:     return { 20.0f, 12.0f, 0, 0.2f, 15 };
        case EnemyKind::Monster: { float s = night ? 1.25f : 1.0f; return { 60.0f * s, 20.0f, 2, 0.5f, 25 }; }
        case EnemyKind::Boss:    return { 600.0f + 60.0f * static_cast<float>(level), 35.0f, 6, 0.95f, 200 };
    }
    return { 1, 1, 0, 0, 0 };
}

struct EnemyState : Combatant {
    EnemyKind kind;
    bool enraged = false;
    explicit EnemyState(EnemyKind k, bool night = false, int level = 1) : kind(k) {
        auto s = statsFor(k, night, level);
        hp = maxHp = s.maxHp; defence = s.defence; kbResist = s.kbResist;
    }
    // Boss enrages below 25% HP (speed/damage handled by the game loop).
    bool checkEnrage() {
        if (kind == EnemyKind::Boss && !enraged && hp < maxHp * 0.25f) { enraged = true; return true; }
        return false;
    }
};

// Day/night: 3600 frames per full cycle at 60fps (1800 day, 1800 night).
inline bool isNight(int timeOfDayFrame) { return (timeOfDayFrame % 3600) >= 1800; }
inline int spawnIntervalFrames(int timeOfDayFrame) { return isNight(timeOfDayFrame) ? 140 : 260; }

// Drop roll: 0-24 heart (heals 20), 25-44 star (restores 50 mana), else nothing.
// Takes an explicit roll 0-99 so tests are deterministic.
inline const char* dropForRoll(int roll0to99) {
    if (roll0to99 < 25) return "heart";
    if (roll0to99 < 45) return "star";
    return "none";
}

inline bool rollCrit(int roll0to99, int critPercent) { return roll0to99 < critPercent; }

} // namespace echohearts

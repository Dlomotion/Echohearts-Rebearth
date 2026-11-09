// Headless tests for EchoHearts core rules — builds with plain g++ / MSVC, no raylib needed.
// Build: g++ -std=c++17 -I src tests/logic_test.cpp -o logic_test
#include "GameLogic.h"
#include <cassert>
#include <iostream>
using namespace echohearts;

int main() {
    // HP hearts: 100 HP = 5 hearts of 20
    PlayerState p; assert(p.heartsDisplay() == 5);
    // Contact damage respects defence (20 - 2 = 18) and starts i-frames
    float d = p.takeContactDamage(20); assert(d == 18 && p.hp == 82);
    // I-frames block the next hit completely (Terraria rule)
    assert(p.takeContactDamage(20) == 0 && p.hp == 82);
    // After i-frames expire, hits land again
    for (int i = 0; i < 41; i++) p.tick(false);
    assert(p.takeContactDamage(12) == 10);
    // Crits double after defence: (22-2)*2 = 40
    EnemyState monster(EnemyKind::Monster, false);
    float dealt = monster.takeHit(22, true); assert(dealt == 40 && monster.hp == 20);
    // Boss stats + enrage below 25%
    EnemyState boss(EnemyKind::Boss, false, 1); assert(boss.maxHp == 660);
    boss.hp = 100; assert(boss.checkEnrage() && boss.enraged);
    // Mana: burst costs 30, can't overspend
    PlayerState p2; assert(p2.spendMana(30) && p2.mana == 70); p2.mana = 10; assert(!p2.spendMana(30));
    // Day/night + spawn pacing + drops are deterministic by roll
    assert(!isNight(0) && isNight(1800));
    assert(spawnIntervalFrames(0) == 260 && spawnIntervalFrames(1800) == 140);
    assert(std::string(dropForRoll(0)) == "heart" && std::string(dropForRoll(30)) == "star" && std::string(dropForRoll(90)) == "none");
    std::cout << "All EchoHearts logic tests passed.\n";
    return 0;
}

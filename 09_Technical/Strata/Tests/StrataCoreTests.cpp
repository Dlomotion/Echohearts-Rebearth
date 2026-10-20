#include "../EchoheartsStrataCore.hpp"
#include <cassert>
using namespace Echohearts::Strata;
int main()
{
    const FAttributes Resources{10.f, 10.f, 10.f, 10.f};
    const FAttributes Cost{2.f, 3.f, 1.f, 1.f};
    FCoreExtractor Extractor;
    assert(Extractor.Upgrade(Resources, Cost));
    assert(Extractor.UpgradeLevel == 1);
    assert(CanCraft(ECraftingTier::Vanguard, ECraftingTier::Field, Resources, Cost));
    assert(!CanCraft(ECraftingTier::Field, ECraftingTier::Vanguard, Resources, Cost));
    FRadar Radar{100.f};
    assert(Radar.Detect(50.f, true));
    assert(!Radar.Detect(101.f, true));
    FEchoShield Shield{20.f, 0.f};
    assert(Shield.ReceiveDamage(25.f) == 5.f);
    Shield.ImmunityRemainingSeconds = 2.f;
    assert(Shield.ReceiveDamage(10.f) == 0.f);
    Shield.Tick(2.f);
    assert(Shield.ReceiveDamage(10.f) == 10.f);
    FGnashtailEncounter Boss;
    FHeartDrive Drive;
    assert(!Boss.ClaimGift(Drive));
    assert(Boss.ApplyPurification(100.f));
    assert(Boss.ClaimGift(Drive));
    assert(!Boss.ClaimGift(Drive));
    FEcoKinBond Bond{true, true, Resources};
    assert(!Drive.CanActivate(Bond));
    Drive.bEquipped = true;
    assert(Drive.CanActivate(Bond));
    Bond.bBefriended = false;
    assert(!Drive.CanActivate(Bond));
    return 0;
}

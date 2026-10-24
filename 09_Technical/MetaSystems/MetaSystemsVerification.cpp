#include "EchoheartsMetaSystemsCore.hpp"
#include <cstdlib>
#include <iostream>

using namespace Echohearts::Meta;

namespace {
void Check(bool condition, const char* expression, int line) {
    if (!condition) {
        std::cerr << "Verification failed at line " << line << ": " << expression << '\n';
        std::exit(EXIT_FAILURE);
    }
}
} // namespace

// Unlike assert(), these checks and their side effects survive NDEBUG/Release.
#define CHECK(expression) Check(static_cast<bool>(expression), #expression, __LINE__)

int main(int argc, char* argv[]) {
    if (argc == 2 && std::string(argv[1]) == "--self-test-failure") {
        CHECK(false);
    }
    if (argc != 1) {
        std::cerr << "Unknown verification arguments\n";
        return EXIT_FAILURE;
    }
    int passed = 0;

    {
        MarketRules rules;
        MarketListingRequest material{"player_a", "PurityResin", "Material", "TEST_CREDIT", 10, 120};
        auto ok = ValidateListing(material, rules, 100);
        CHECK(ok.code == MarketValidationCode::Ok);
        CHECK(ok.listingFee == 12);

        MarketListingRequest partner{"player_a", "EcoKin_001", "EcoKin", "TEST_CREDIT", 1, 100};
        CHECK(ValidateListing(partner, rules, 100).code == MarketValidationCode::RestrictedCategory);

        MarketListingRequest manipulated{"player_a", "PurityResin", "Material", "TEST_CREDIT", 1, 1000};
        CHECK(ValidateListing(manipulated, rules, 100).code == MarketValidationCode::OutsidePriceBand);

        auto quote = QuotePurchase(120, 10, rules);
        CHECK(quote.buyerCost == 1200);
        CHECK(quote.sellerPayout == 1140);
        CHECK(quote.economySink == 60);
        ++passed;
    }

    {
        HousingLayout layout(8, 8);
        FurnitureDefinition sofa{"Sofa_A", 3, 1};
        FurnitureDefinition table{"Table_A", 2, 2};
        CHECK(layout.TryPlace("sofa_1", sofa, 0, 0, 0) == PlacementCode::Ok);
        CHECK(layout.TryPlace("table_1", table, 1, 0, 0) == PlacementCode::Overlap);
        CHECK(layout.TryPlace("table_2", table, 3, 0, 1) == PlacementCode::Ok);
        CHECK(layout.TryPlace("sofa_2", sofa, 7, 7, 0) == PlacementCode::OutOfBounds);
        CHECK(layout.Remove("sofa_1"));
        ++passed;
    }

    {
        CrossRegionEvent event{"Stormfront", {"Vespera", "Skyforge"}, 1000, 300, 1000};
        CHECK(EventAppliesToRegion(event, "Vespera"));
        CHECK(EventAppliesToRegion(event, "Skyforge"));
        CHECK(!EventAppliesToRegion(event, "Paleon"));
        CHECK(IsEventActive(event, 1100));
        CHECK(!IsEventActive(event, 1500));
        CHECK(IsEventActive(event, 2100));
        ++passed;
    }

    {
        std::vector<DailyMissionDefinition> pool = {
            {"restore_patch", "Restoration", 0, false},
            {"care_partner", "Care", 0, false},
            {"explore_landmark", "Explore", 0, false},
            {"arena_round", "Arena", 1, false},
            {"rare_spawn_grind", "Explore", 0, true}
        };
        auto a = SelectDailyMissions(pool, 3, 42, 100, 3);
        auto b = SelectDailyMissions(pool, 3, 42, 100, 3);
        CHECK(a.size() == 3 && b.size() == 3);
        for (std::size_t i = 0; i < a.size(); ++i) CHECK(a[i].missionId == b[i].missionId);
        for (const auto& m : a) CHECK(!m.requiresRareSpawn);
        CHECK(a[0].category != a[1].category && a[0].category != a[2].category && a[1].category != a[2].category);
        ++passed;
    }

    std::cout << "Echohearts Meta Systems verification: " << passed << "/4 groups passed\n";
    return 0;
}

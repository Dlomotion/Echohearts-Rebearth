#include "Misc/AutomationTest.h"

#include "EHRSanctuaryPolicyLibrary.h"

#if WITH_DEV_AUTOMATION_TESTS

IMPLEMENT_SIMPLE_AUTOMATION_TEST(
    FEHRBindingPolicyTest,
    "Echohearts.Sanctuary.Binding.KindlingConsentAndPurity",
    EAutomationTestFlags::EditorContext | EAutomationTestFlags::EngineFilter)

bool FEHRBindingPolicyTest::RunTest(const FString& Parameters)
{
    FEHRBindingRequest Request;
    Request.DexId = 12;
    Request.EcoKinInstanceId = TEXT("EcoKin_Field_001");
    Request.bWildEncounter = true;
    Request.bKindlingComplete = true;
    Request.bConsentConfirmed = true;
    Request.TargetAttributes = {80, 75, 65, 70};
    Request.MinimumPurity = 35;
    Request.HarmonyCost = 10;
    Request.Stability = 1.0f;

    FEHRAttributeMatrix TamerAttributes;
    TamerAttributes.Vibrance = 90;
    TamerAttributes.Density = 85;
    TamerAttributes.Harmony = 50;
    TamerAttributes.Purity = 80;

    TArray<int32> ApprovedDexIds;
    ApprovedDexIds.Add(12);

    const FEHRBindingOutcome Outcome =
        UEHRSanctuaryPolicyLibrary::EvaluateBinding(Request, TamerAttributes, ApprovedDexIds);

    TestEqual(TEXT("Binding succeeds"), Outcome.Result, EEHRBindingResult::Bound);
    TestEqual(TEXT("Harmony is spent"), Outcome.UpdatedTamerAttributes.Harmony, 40);
    return true;
}

IMPLEMENT_SIMPLE_AUTOMATION_TEST(
    FEHRAnimaLinkPulseTest,
    "Echohearts.AnimaLink.BidirectionalPulse",
    EAutomationTestFlags::EditorContext | EAutomationTestFlags::EngineFilter)

bool FEHRAnimaLinkPulseTest::RunTest(const FString& Parameters)
{
    FEHRAttributeMatrix TamerAttributes;
    TamerAttributes.Vibrance = 100;
    TamerAttributes.Density = 100;
    TamerAttributes.Harmony = 70;
    TamerAttributes.Purity = 80;

    FEHRAttributeMatrix EcoKinAttributes = TamerAttributes;

    FEHRAnimaLinkPulse Pulse;
    Pulse.DirectTamerVibranceStrain = 8;
    Pulse.DirectTamerDensityStrain = 4;
    Pulse.DirectEcoKinVibranceStrain = 20;
    Pulse.DirectEcoKinDensityStrain = 12;
    Pulse.TransferBasisPoints = 2500;

    const FEHRAnimaLinkPulseOutcome Outcome =
        UEHRSanctuaryPolicyLibrary::ApplyAnimaLinkPulse(TamerAttributes, EcoKinAttributes, Pulse);

    TestEqual(TEXT("Eco-Kin Vibrance strain transfers to Tamer"), Outcome.TransferredToTamerVibrance, 5);
    TestEqual(TEXT("Tamer Vibrance strain transfers to Eco-Kin"), Outcome.TransferredToEcoKinVibrance, 2);
    TestEqual(TEXT("Tamer Vibrance applies direct and linked strain"), Outcome.UpdatedTamerAttributes.Vibrance, 87);
    TestEqual(TEXT("Eco-Kin Vibrance applies direct and linked strain"), Outcome.UpdatedEcoKinAttributes.Vibrance, 78);
    return true;
}

IMPLEMENT_SIMPLE_AUTOMATION_TEST(
    FEHRSanctuaryQuestPolicyTest,
    "Echohearts.Sanctuary.HousingAndQuestEligibility",
    EAutomationTestFlags::EditorContext | EAutomationTestFlags::EngineFilter)

bool FEHRSanctuaryQuestPolicyTest::RunTest(const FString& Parameters)
{
    FEHRResidentProfile Resident;
    Resident.ResidentId = TEXT("Resident_A");

    FEHRHousingSlot Housing;
    Housing.HousingId = TEXT("Canopy_A");
    Housing.Capacity = 2;
    Housing.Occupancy = 1;
    Housing.RestorationGate = 20;
    Housing.MinimumSanctuaryAttributes = {10, 10, 20, 20};

    FEHRAttributeMatrix SanctuaryAttributes = {40, 40, 50, 60};

    TestEqual(
        TEXT("Resident can be assigned"),
        UEHRSanctuaryPolicyLibrary::EvaluateHousingAssignment(Resident, Housing, 30, SanctuaryAttributes),
        EEHRHousingResult::Assigned);

    FEHRQuestPrerequisites Quest;
    Quest.QuestId = TEXT("Restore_Grove_Path");
    Quest.RequiredRestoration = 25;
    Quest.RequiredResidents = 1;
    Quest.MinimumSanctuaryAttributes = {20, 20, 30, 30};

    TArray<FName> CompletedQuestIds;
    TestTrue(
        TEXT("Eligible Sanctuary quest can auto-start"),
        UEHRSanctuaryPolicyLibrary::CanStartQuest(
            Quest,
            30,
            1,
            SanctuaryAttributes,
            CompletedQuestIds));

    return true;
}

IMPLEMENT_SIMPLE_AUTOMATION_TEST(
    FEHRCraftingTierPolicyTest,
    "Echohearts.Skyisland.CraftingTierEligibility",
    EAutomationTestFlags::EditorContext | EAutomationTestFlags::EngineFilter)

bool FEHRCraftingTierPolicyTest::RunTest(const FString& Parameters)
{
    FEHRCraftingTierRecipe Recipe;
    Recipe.RecipeId = TEXT("LivingBridgeSegment");
    Recipe.Tier = 2;
    Recipe.RequiredRestoration = 30;
    Recipe.MinimumSanctuaryAttributes = {20, 25, 35, 30};
    Recipe.Materials.Add(TEXT("PurityResin"), 3);
    Recipe.Materials.Add(TEXT("ResonantFiber"), 2);
    Recipe.Outputs.Add(TEXT("LivingBridgeSegment"), 1);

    TMap<FName, int32> Inventory;
    Inventory.Add(TEXT("PurityResin"), 4);
    Inventory.Add(TEXT("ResonantFiber"), 2);

    FEHRAttributeMatrix SanctuaryAttributes = {45, 40, 50, 55};

    TestEqual(
        TEXT("Tier-two Skyisland recipe is eligible"),
        UEHRSanctuaryPolicyLibrary::EvaluateCrafting(
            Recipe,
            2,
            35,
            SanctuaryAttributes,
            Inventory),
        EEHRCraftingResult::Crafted);

    return true;
}

#endif

#include "EHRSanctuaryPolicyLibrary.h"

namespace
{
int32 TransferCost(const int32 DirectStrain, const int32 BasisPoints)
{
    if (DirectStrain <= 0 || BasisPoints <= 0)
    {
        return 0;
    }

    const int64 Product = static_cast<int64>(DirectStrain) * static_cast<int64>(BasisPoints);
    return static_cast<int32>(FMath::Min<int64>((Product + 9999LL) / 10000LL, MAX_int32));
}

int32 SafeSubtract(const int32 Current, const int32 Loss)
{
    return FMath::Max(0, Current - FMath::Max(0, Loss));
}
}

bool UEHRSanctuaryPolicyLibrary::MeetsMinimums(
    const FEHRAttributeMatrix& Current,
    const FEHRAttributeMatrix& Minimum)
{
    return Current.IsValid()
        && Minimum.IsValid()
        && Current.Vibrance >= Minimum.Vibrance
        && Current.Density >= Minimum.Density
        && Current.Harmony >= Minimum.Harmony
        && Current.Purity >= Minimum.Purity;
}

FEHRBindingOutcome UEHRSanctuaryPolicyLibrary::EvaluateBinding(
    const FEHRBindingRequest& Request,
    const FEHRAttributeMatrix& CurrentTamerAttributes,
    const TArray<int32>& ApprovedDexIds)
{
    FEHRBindingOutcome Outcome;
    Outcome.UpdatedTamerAttributes = CurrentTamerAttributes;

    if (!CurrentTamerAttributes.IsValid()
        || Request.DexId <= 0
        || Request.EcoKinInstanceId.IsNone()
        || !ApprovedDexIds.Contains(Request.DexId))
    {
        Outcome.Result = EEHRBindingResult::InvalidTarget;
        return Outcome;
    }

    if (!Request.bWildEncounter || Request.bAlreadyBound || !Request.bKindlingComplete)
    {
        Outcome.Result = EEHRBindingResult::NotReady;
        return Outcome;
    }

    if (!Request.bConsentConfirmed)
    {
        Outcome.Result = EEHRBindingResult::ConsentRequired;
        return Outcome;
    }

    if (!Request.TargetAttributes.IsValid()
        || Request.MinimumPurity < 0
        || Request.TargetAttributes.Purity < Request.MinimumPurity)
    {
        Outcome.Result = EEHRBindingResult::FailedPurityGate;
        return Outcome;
    }

    if (Request.HarmonyCost < 0 || CurrentTamerAttributes.Harmony < Request.HarmonyCost)
    {
        Outcome.Result = EEHRBindingResult::InsufficientHarmony;
        return Outcome;
    }

    if (!FMath::IsFinite(Request.Stability) || Request.Stability < 0.0f || Request.Stability > 1.0f)
    {
        Outcome.Result = EEHRBindingResult::InvalidStability;
        return Outcome;
    }

    Outcome.Result = EEHRBindingResult::Bound;
    Outcome.HarmonySpent = Request.HarmonyCost;
    Outcome.UpdatedTamerAttributes.Harmony -= Request.HarmonyCost;
    return Outcome;
}

EEHRExtractionResult UEHRSanctuaryPolicyLibrary::EvaluateExtraction(
    const FEHRExtractionRequest& Request,
    const FEHRAttributeMatrix& CurrentTamerAttributes)
{
    if (Request.EcoKinInstanceId.IsNone() || !CurrentTamerAttributes.IsValid())
    {
        return EEHRExtractionResult::InvalidTarget;
    }

    if (!Request.bBindingConfirmed)
    {
        return EEHRExtractionResult::BindingRequired;
    }

    if (!Request.bKindlingComplete)
    {
        return EEHRExtractionResult::KindlingRequired;
    }

    if (!Request.bConsentConfirmed)
    {
        return EEHRExtractionResult::ConsentRequired;
    }

    if (!Request.bSanctuarySpaceAvailable)
    {
        return EEHRExtractionResult::SanctuaryUnavailable;
    }

    if (Request.MinimumHarmony < 0 || CurrentTamerAttributes.Harmony < Request.MinimumHarmony)
    {
        return EEHRExtractionResult::InsufficientHarmony;
    }

    return EEHRExtractionResult::Ready;
}

FEHRAnimaLinkPulseOutcome UEHRSanctuaryPolicyLibrary::ApplyAnimaLinkPulse(
    const FEHRAttributeMatrix& CurrentTamerAttributes,
    const FEHRAttributeMatrix& CurrentEcoKinAttributes,
    const FEHRAnimaLinkPulse& Pulse)
{
    FEHRAnimaLinkPulseOutcome Outcome;
    Outcome.UpdatedTamerAttributes = CurrentTamerAttributes;
    Outcome.UpdatedEcoKinAttributes = CurrentEcoKinAttributes;

    if (!CurrentTamerAttributes.IsValid() || !CurrentEcoKinAttributes.IsValid())
    {
        return Outcome;
    }

    const int32 BasisPoints = FMath::Clamp(Pulse.TransferBasisPoints, 0, 10000);

    Outcome.TransferredToTamerVibrance = TransferCost(Pulse.DirectEcoKinVibranceStrain, BasisPoints);
    Outcome.TransferredToTamerDensity = TransferCost(Pulse.DirectEcoKinDensityStrain, BasisPoints);
    Outcome.TransferredToEcoKinVibrance = TransferCost(Pulse.DirectTamerVibranceStrain, BasisPoints);
    Outcome.TransferredToEcoKinDensity = TransferCost(Pulse.DirectTamerDensityStrain, BasisPoints);

    Outcome.UpdatedTamerAttributes.Vibrance = SafeSubtract(
        CurrentTamerAttributes.Vibrance,
        FMath::Max(0, Pulse.DirectTamerVibranceStrain) + Outcome.TransferredToTamerVibrance);

    Outcome.UpdatedTamerAttributes.Density = SafeSubtract(
        CurrentTamerAttributes.Density,
        FMath::Max(0, Pulse.DirectTamerDensityStrain) + Outcome.TransferredToTamerDensity);

    Outcome.UpdatedEcoKinAttributes.Vibrance = SafeSubtract(
        CurrentEcoKinAttributes.Vibrance,
        FMath::Max(0, Pulse.DirectEcoKinVibranceStrain) + Outcome.TransferredToEcoKinVibrance);

    Outcome.UpdatedEcoKinAttributes.Density = SafeSubtract(
        CurrentEcoKinAttributes.Density,
        FMath::Max(0, Pulse.DirectEcoKinDensityStrain) + Outcome.TransferredToEcoKinDensity);

    return Outcome;
}

EEHRHousingResult UEHRSanctuaryPolicyLibrary::EvaluateHousingAssignment(
    const FEHRResidentProfile& Resident,
    const FEHRHousingSlot& Housing,
    const int32 SanctuaryRestoration,
    const FEHRAttributeMatrix& SanctuaryAttributes)
{
    if (Resident.ResidentId.IsNone())
    {
        return EEHRHousingResult::InvalidResident;
    }

    if (Housing.HousingId.IsNone() || Housing.Capacity <= 0 || Housing.Occupancy < 0)
    {
        return EEHRHousingResult::InvalidHousing;
    }

    if (Resident.bAssigned)
    {
        return EEHRHousingResult::AlreadyAssigned;
    }

    if (Housing.Occupancy >= Housing.Capacity)
    {
        return EEHRHousingResult::HousingFull;
    }

    if (SanctuaryRestoration < Housing.RestorationGate)
    {
        return EEHRHousingResult::RestorationLocked;
    }

    if (!MeetsMinimums(SanctuaryAttributes, Housing.MinimumSanctuaryAttributes))
    {
        return EEHRHousingResult::AttributeLocked;
    }

    return EEHRHousingResult::Assigned;
}

bool UEHRSanctuaryPolicyLibrary::CanStartQuest(
    const FEHRQuestPrerequisites& Quest,
    const int32 SanctuaryRestoration,
    const int32 HousedResidents,
    const FEHRAttributeMatrix& SanctuaryAttributes,
    const TArray<FName>& CompletedQuestIds)
{
    if (Quest.QuestId.IsNone()
        || Quest.RequiredRestoration < 0
        || Quest.RequiredResidents < 0
        || SanctuaryRestoration < Quest.RequiredRestoration
        || HousedResidents < Quest.RequiredResidents
        || !MeetsMinimums(SanctuaryAttributes, Quest.MinimumSanctuaryAttributes))
    {
        return false;
    }

    for (const FName RequiredQuestId : Quest.RequiredQuestIds)
    {
        if (RequiredQuestId.IsNone() || !CompletedQuestIds.Contains(RequiredQuestId))
        {
            return false;
        }
    }

    return true;
}

EEHRCraftingResult UEHRSanctuaryPolicyLibrary::EvaluateCrafting(
    const FEHRCraftingTierRecipe& Recipe,
    const int32 UnlockedTier,
    const int32 SanctuaryRestoration,
    const FEHRAttributeMatrix& SanctuaryAttributes,
    const TMap<FName, int32>& Inventory)
{
    if (Recipe.RecipeId.IsNone() || Recipe.Tier < 1)
    {
        return EEHRCraftingResult::InvalidRecipe;
    }

    if (Recipe.Tier > UnlockedTier)
    {
        return EEHRCraftingResult::TierLocked;
    }

    if (Recipe.RequiredRestoration < 0 || SanctuaryRestoration < Recipe.RequiredRestoration)
    {
        return EEHRCraftingResult::RestorationLocked;
    }

    if (!MeetsMinimums(SanctuaryAttributes, Recipe.MinimumSanctuaryAttributes))
    {
        return EEHRCraftingResult::AttributeLocked;
    }

    for (const TPair<FName, int32>& Material : Recipe.Materials)
    {
        if (Material.Key.IsNone() || Material.Value <= 0)
        {
            return EEHRCraftingResult::InvalidRecipe;
        }

        const int32* Available = Inventory.Find(Material.Key);
        if (Available == nullptr || *Available < Material.Value)
        {
            return EEHRCraftingResult::MissingMaterials;
        }
    }

    for (const TPair<FName, int32>& Output : Recipe.Outputs)
    {
        if (Output.Key.IsNone() || Output.Value <= 0)
        {
            return EEHRCraftingResult::InvalidRecipe;
        }
    }

    return EEHRCraftingResult::Crafted;
}

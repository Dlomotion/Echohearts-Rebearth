#pragma once
// Echohearts: Rebearth — UE 5.8 integration staging.
// Copy into an existing game module Public/ folder after module/dependency review.
// No UCLASS/USTRUCT reflection: intentionally engine-independent gameplay policy.
#include "CoreMinimal.h"

namespace EHR::Sanctuary
{
enum class EAttribute : uint8 { Vibrance, Density, Harmony, Purity };
enum class EBindingResult : uint8 { Bound, InvalidTarget, NotReady, FailedPurityGate, InsufficientLink, InvalidChance };
struct FAttributes
{
    int32 Vibrance = 0, Density = 0, Harmony = 0, Purity = 0;
    bool IsValid() const { return Vibrance >= 0 && Density >= 0 && Harmony >= 0 && Purity >= 0; }
};
struct FBindingRequest
{
    int32 DexId = 0;
    bool bWildEncounter = false;
    bool bAlreadyBound = false;
    int32 TargetPurity = 0;
    int32 MinimumPurity = 35;
    int32 LinkReserve = 0;
    int32 LinkCost = 10;
    float Stability = 0.0f; // server-authoritative [0,1]
};
struct FBindingOutcome { EBindingResult Result = EBindingResult::InvalidTarget; int32 LinkSpent = 0; };
inline FBindingOutcome TryBind(const FBindingRequest& Request, const TSet<int32>& ApprovedDexIds)
{
    if (!ApprovedDexIds.Contains(Request.DexId)) return {EBindingResult::InvalidTarget, 0};
    if (!Request.bWildEncounter || Request.bAlreadyBound) return {EBindingResult::NotReady, 0};
    if (Request.TargetPurity < Request.MinimumPurity) return {EBindingResult::FailedPurityGate, 0};
    if (Request.LinkCost < 0 || Request.LinkReserve < Request.LinkCost) return {EBindingResult::InsufficientLink, 0};
    if (!FMath::IsFinite(Request.Stability) || Request.Stability < 0.f || Request.Stability > 1.f)
        return {EBindingResult::InvalidChance, 0};
    // Deterministic eligibility only. Roll RNG on the authoritative server; never trust client success.
    return {EBindingResult::Bound, Request.LinkCost};
}
struct FResident
{
    FName ResidentId;
    FName HousingId;
    bool bAssigned = false;
};
struct FHousing
{
    FName HousingId;
    int32 Capacity = 0;
    int32 Occupancy = 0;
    int32 RestorationGate = 0;
};
inline bool CanAssign(const FResident& Resident, const FHousing& Housing, int32 SanctuaryRestoration)
{
    return !Resident.bAssigned && !Resident.ResidentId.IsNone() && !Housing.HousingId.IsNone()
        && Housing.Capacity > 0 && Housing.Occupancy >= 0 && Housing.Occupancy < Housing.Capacity
        && SanctuaryRestoration >= Housing.RestorationGate;
}
struct FQuestPrerequisites
{
    int32 RequiredRestoration = 0;
    int32 RequiredResidents = 0;
    TArray<FName> RequiredQuestIds;
};
inline bool CanStartQuest(const FQuestPrerequisites& Quest, int32 Restoration, int32 HousedResidents,
                         const TSet<FName>& CompletedQuests)
{
    if (Restoration < Quest.RequiredRestoration || HousedResidents < Quest.RequiredResidents) return false;
    for (const FName& Id : Quest.RequiredQuestIds)
        if (Id.IsNone() || !CompletedQuests.Contains(Id)) return false;
    return true;
}
struct FCraftingTier
{
    int32 Tier = 1;
    int32 RequiredRestoration = 0;
    int32 RequiredHarmony = 0;
    int32 RequiredPurity = 0;
    TMap<FName, int32> Materials;
};
inline bool CanCraft(const FCraftingTier& Recipe, int32 UnlockedTier, int32 Restoration,
                     const FAttributes& Attributes, const TMap<FName, int32>& Inventory)
{
    if (!Attributes.IsValid() || Recipe.Tier < 1 || Recipe.Tier > UnlockedTier ||
        Restoration < Recipe.RequiredRestoration || Attributes.Harmony < Recipe.RequiredHarmony ||
        Attributes.Purity < Recipe.RequiredPurity) return false;
    for (const TPair<FName, int32>& Material : Recipe.Materials)
    {
        if (Material.Key.IsNone() || Material.Value <= 0 ||
            Inventory.FindRef(Material.Key) < Material.Value) return false;
    }
    return true;
}
} // namespace EHR::Sanctuary

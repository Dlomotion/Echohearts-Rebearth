#include "EHRSanctuaryWorldSubsystem.h"

#include "EHRSanctuaryPolicyLibrary.h"
#include "Engine/World.h"

bool UEHRSanctuaryWorldSubsystem::IsAuthorityWorld() const
{
    const UWorld* World = GetWorld();
    return World != nullptr && World->GetNetMode() != NM_Client;
}

bool UEHRSanctuaryWorldSubsystem::ConfigureSanctuary(
    const int32 InRestoration,
    const int32 InUnlockedCraftingTier,
    const FEHRAttributeMatrix& InSanctuaryAttributes)
{
    if (!IsAuthorityWorld()
        || InRestoration < 0
        || InUnlockedCraftingTier < 1
        || !InSanctuaryAttributes.IsValid())
    {
        return false;
    }

    SanctuaryRestoration = InRestoration;
    UnlockedCraftingTier = InUnlockedCraftingTier;
    SanctuaryAttributes = InSanctuaryAttributes;
    return true;
}

bool UEHRSanctuaryWorldSubsystem::ReplaceHousingSlots(const TArray<FEHRHousingSlot>& InHousingSlots)
{
    if (!IsAuthorityWorld())
    {
        return false;
    }

    TSet<FName> SeenIds;
    for (const FEHRHousingSlot& Housing : InHousingSlots)
    {
        if (Housing.HousingId.IsNone()
            || Housing.Capacity <= 0
            || Housing.Occupancy < 0
            || Housing.Occupancy > Housing.Capacity
            || Housing.RestorationGate < 0
            || !Housing.MinimumSanctuaryAttributes.IsValid()
            || SeenIds.Contains(Housing.HousingId))
        {
            return false;
        }

        SeenIds.Add(Housing.HousingId);
    }

    HousingSlots = InHousingSlots;
    return true;
}

bool UEHRSanctuaryWorldSubsystem::ReplaceResidents(const TArray<FEHRResidentProfile>& InResidents)
{
    if (!IsAuthorityWorld())
    {
        return false;
    }

    TSet<FName> SeenIds;
    for (const FEHRResidentProfile& Resident : InResidents)
    {
        if (Resident.ResidentId.IsNone() || SeenIds.Contains(Resident.ResidentId))
        {
            return false;
        }

        if (Resident.bAssigned && Resident.HousingId.IsNone())
        {
            return false;
        }

        SeenIds.Add(Resident.ResidentId);
    }

    Residents = InResidents;
    return true;
}

bool UEHRSanctuaryWorldSubsystem::ReplaceQuestDefinitions(
    const TArray<FEHRQuestPrerequisites>& InQuestDefinitions)
{
    if (!IsAuthorityWorld())
    {
        return false;
    }

    TSet<FName> SeenIds;
    for (const FEHRQuestPrerequisites& Quest : InQuestDefinitions)
    {
        if (Quest.QuestId.IsNone()
            || Quest.RequiredRestoration < 0
            || Quest.RequiredResidents < 0
            || !Quest.MinimumSanctuaryAttributes.IsValid()
            || SeenIds.Contains(Quest.QuestId))
        {
            return false;
        }

        SeenIds.Add(Quest.QuestId);
    }

    QuestDefinitions = InQuestDefinitions;
    return true;
}

bool UEHRSanctuaryWorldSubsystem::ValidateInventory(const TMap<FName, int32>& Candidate)
{
    for (const TPair<FName, int32>& Entry : Candidate)
    {
        if (Entry.Key.IsNone() || Entry.Value < 0)
        {
            return false;
        }
    }

    return true;
}

bool UEHRSanctuaryWorldSubsystem::ReplaceInventory(const TMap<FName, int32>& InInventory)
{
    if (!IsAuthorityWorld() || !ValidateInventory(InInventory))
    {
        return false;
    }

    Inventory = InInventory;
    return true;
}

EEHRHousingResult UEHRSanctuaryWorldSubsystem::TryAssignResident(
    const FName ResidentId,
    const FName HousingId)
{
    if (!IsAuthorityWorld())
    {
        return EEHRHousingResult::AuthorityRequired;
    }

    FEHRResidentProfile* Resident = Residents.FindByPredicate(
        [ResidentId](const FEHRResidentProfile& Candidate)
        {
            return Candidate.ResidentId == ResidentId;
        });

    if (Resident == nullptr)
    {
        return EEHRHousingResult::InvalidResident;
    }

    FEHRHousingSlot* Housing = HousingSlots.FindByPredicate(
        [HousingId](const FEHRHousingSlot& Candidate)
        {
            return Candidate.HousingId == HousingId;
        });

    if (Housing == nullptr)
    {
        return EEHRHousingResult::InvalidHousing;
    }

    const EEHRHousingResult Result = UEHRSanctuaryPolicyLibrary::EvaluateHousingAssignment(
        *Resident,
        *Housing,
        SanctuaryRestoration,
        SanctuaryAttributes);

    if (Result == EEHRHousingResult::Assigned)
    {
        Resident->HousingId = Housing->HousingId;
        Resident->bAssigned = true;
        ++Housing->Occupancy;
    }

    return Result;
}

int32 UEHRSanctuaryWorldSubsystem::GetHousedResidentCount() const
{
    int32 Count = 0;
    for (const FEHRResidentProfile& Resident : Residents)
    {
        if (Resident.bAssigned && !Resident.HousingId.IsNone())
        {
            ++Count;
        }
    }

    return Count;
}

TArray<FName> UEHRSanctuaryWorldSubsystem::StartEligibleAutoQuests()
{
    TArray<FName> StartedQuestIds;

    if (!IsAuthorityWorld())
    {
        return StartedQuestIds;
    }

    const int32 HousedResidents = GetHousedResidentCount();

    for (const FEHRQuestPrerequisites& Quest : QuestDefinitions)
    {
        if (!Quest.bAutoStart
            || ActiveQuestIds.Contains(Quest.QuestId)
            || CompletedQuestIds.Contains(Quest.QuestId))
        {
            continue;
        }

        if (UEHRSanctuaryPolicyLibrary::CanStartQuest(
            Quest,
            SanctuaryRestoration,
            HousedResidents,
            SanctuaryAttributes,
            CompletedQuestIds))
        {
            ActiveQuestIds.Add(Quest.QuestId);
            StartedQuestIds.Add(Quest.QuestId);
        }
    }

    return StartedQuestIds;
}

bool UEHRSanctuaryWorldSubsystem::CompleteQuest(const FName QuestId)
{
    if (!IsAuthorityWorld() || QuestId.IsNone() || !ActiveQuestIds.Contains(QuestId))
    {
        return false;
    }

    ActiveQuestIds.Remove(QuestId);
    CompletedQuestIds.AddUnique(QuestId);
    return true;
}

EEHRCraftingResult UEHRSanctuaryWorldSubsystem::TryCraftRecipe(const FEHRCraftingTierRecipe& Recipe)
{
    if (!IsAuthorityWorld())
    {
        return EEHRCraftingResult::AuthorityRequired;
    }

    const EEHRCraftingResult Result = UEHRSanctuaryPolicyLibrary::EvaluateCrafting(
        Recipe,
        UnlockedCraftingTier,
        SanctuaryRestoration,
        SanctuaryAttributes,
        Inventory);

    if (Result != EEHRCraftingResult::Crafted)
    {
        return Result;
    }

    for (const TPair<FName, int32>& Material : Recipe.Materials)
    {
        int32* Quantity = Inventory.Find(Material.Key);
        if (Quantity == nullptr)
        {
            return EEHRCraftingResult::MissingMaterials;
        }

        *Quantity -= Material.Value;
    }

    for (const TPair<FName, int32>& Output : Recipe.Outputs)
    {
        int32& Quantity = Inventory.FindOrAdd(Output.Key);
        const int64 NextQuantity = static_cast<int64>(Quantity) + static_cast<int64>(Output.Value);
        Quantity = static_cast<int32>(FMath::Min<int64>(NextQuantity, MAX_int32));
    }

    return EEHRCraftingResult::Crafted;
}

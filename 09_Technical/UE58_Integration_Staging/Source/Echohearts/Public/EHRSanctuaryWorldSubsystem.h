#pragma once

#include "CoreMinimal.h"
#include "Subsystems/WorldSubsystem.h"
#include "EHRGameplayTypes.h"
#include "EHRSanctuaryWorldSubsystem.generated.h"

UCLASS(BlueprintType)
class ECHOHEARTS_API UEHRSanctuaryWorldSubsystem : public UWorldSubsystem
{
    GENERATED_BODY()

public:
    UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly, Category="Echohearts|Sanctuary")
    bool ConfigureSanctuary(
        int32 InRestoration,
        int32 InUnlockedCraftingTier,
        const FEHRAttributeMatrix& InSanctuaryAttributes);

    UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly, Category="Echohearts|Sanctuary")
    bool ReplaceHousingSlots(const TArray<FEHRHousingSlot>& InHousingSlots);

    UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly, Category="Echohearts|Sanctuary")
    bool ReplaceResidents(const TArray<FEHRResidentProfile>& InResidents);

    UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly, Category="Echohearts|Quest")
    bool ReplaceQuestDefinitions(const TArray<FEHRQuestPrerequisites>& InQuestDefinitions);

    UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly, Category="Echohearts|Crafting")
    bool ReplaceInventory(const TMap<FName, int32>& InInventory);

    UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly, Category="Echohearts|Sanctuary")
    EEHRHousingResult TryAssignResident(FName ResidentId, FName HousingId);

    UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly, Category="Echohearts|Quest")
    TArray<FName> StartEligibleAutoQuests();

    UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly, Category="Echohearts|Quest")
    bool CompleteQuest(FName QuestId);

    UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly, Category="Echohearts|Crafting")
    EEHRCraftingResult TryCraftRecipe(const FEHRCraftingTierRecipe& Recipe);

    UFUNCTION(BlueprintPure, Category="Echohearts|Sanctuary")
    int32 GetHousedResidentCount() const;

    UFUNCTION(BlueprintPure, Category="Echohearts|Quest")
    TArray<FName> GetActiveQuestIds() const { return ActiveQuestIds; }

    UFUNCTION(BlueprintPure, Category="Echohearts|Quest")
    TArray<FName> GetCompletedQuestIds() const { return CompletedQuestIds; }

    UFUNCTION(BlueprintPure, Category="Echohearts|Crafting")
    TMap<FName, int32> GetInventory() const { return Inventory; }

private:
    bool IsAuthorityWorld() const;
    static bool ValidateInventory(const TMap<FName, int32>& Candidate);

    UPROPERTY()
    int32 SanctuaryRestoration = 0;

    UPROPERTY()
    int32 UnlockedCraftingTier = 1;

    UPROPERTY()
    FEHRAttributeMatrix SanctuaryAttributes;

    UPROPERTY()
    TArray<FEHRHousingSlot> HousingSlots;

    UPROPERTY()
    TArray<FEHRResidentProfile> Residents;

    UPROPERTY()
    TArray<FEHRQuestPrerequisites> QuestDefinitions;

    UPROPERTY()
    TArray<FName> ActiveQuestIds;

    UPROPERTY()
    TArray<FName> CompletedQuestIds;

    UPROPERTY()
    TMap<FName, int32> Inventory;
};

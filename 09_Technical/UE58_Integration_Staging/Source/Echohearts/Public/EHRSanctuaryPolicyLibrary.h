#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "EHRGameplayTypes.h"
#include "EHRSanctuaryPolicyLibrary.generated.h"

UCLASS()
class ECHOHEARTS_API UEHRSanctuaryPolicyLibrary : public UBlueprintFunctionLibrary
{
    GENERATED_BODY()

public:
    UFUNCTION(BlueprintPure, Category="Echohearts|Binding")
    static FEHRBindingOutcome EvaluateBinding(
        const FEHRBindingRequest& Request,
        const FEHRAttributeMatrix& CurrentTamerAttributes,
        const TArray<int32>& ApprovedDexIds);

    UFUNCTION(BlueprintPure, Category="Echohearts|Extraction")
    static EEHRExtractionResult EvaluateExtraction(
        const FEHRExtractionRequest& Request,
        const FEHRAttributeMatrix& CurrentTamerAttributes);

    UFUNCTION(BlueprintPure, Category="Echohearts|AnimaLink")
    static FEHRAnimaLinkPulseOutcome ApplyAnimaLinkPulse(
        const FEHRAttributeMatrix& CurrentTamerAttributes,
        const FEHRAttributeMatrix& CurrentEcoKinAttributes,
        const FEHRAnimaLinkPulse& Pulse);

    UFUNCTION(BlueprintPure, Category="Echohearts|Sanctuary")
    static EEHRHousingResult EvaluateHousingAssignment(
        const FEHRResidentProfile& Resident,
        const FEHRHousingSlot& Housing,
        int32 SanctuaryRestoration,
        const FEHRAttributeMatrix& SanctuaryAttributes);

    UFUNCTION(BlueprintPure, Category="Echohearts|Quest")
    static bool CanStartQuest(
        const FEHRQuestPrerequisites& Quest,
        int32 SanctuaryRestoration,
        int32 HousedResidents,
        const FEHRAttributeMatrix& SanctuaryAttributes,
        const TArray<FName>& CompletedQuestIds);

    UFUNCTION(BlueprintPure, Category="Echohearts|Crafting")
    static EEHRCraftingResult EvaluateCrafting(
        const FEHRCraftingTierRecipe& Recipe,
        int32 UnlockedTier,
        int32 SanctuaryRestoration,
        const FEHRAttributeMatrix& SanctuaryAttributes,
        const TMap<FName, int32>& Inventory);

private:
    static bool MeetsMinimums(const FEHRAttributeMatrix& Current, const FEHRAttributeMatrix& Minimum);
};

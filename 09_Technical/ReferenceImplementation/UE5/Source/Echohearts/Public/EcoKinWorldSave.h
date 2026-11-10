#pragma once
#include "CoreMinimal.h"
#include "GameFramework/SaveGame.h"
#include "EcoKinWorldStateComponent.h"
#include "EcoKinWorldSave.generated.h"

UCLASS(BlueprintType)
class UEcoKinWorldSave : public USaveGame
{
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite) int32 SchemaVersion = 1;
    UPROPERTY(BlueprintReadWrite) FString StableProfileId;
    UPROPERTY(BlueprintReadWrite) EBrokenCrossingStage CrossingStage = EBrokenCrossingStage::Unavailable;
    UPROPERTY(BlueprintReadWrite) FRebearthDomainSnapshot Domain;
};

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "EHRGameplayTypes.h"
#include "EHRFrequencyTamerLinkComponent.generated.h"

UCLASS(ClassGroup=(Echohearts), meta=(BlueprintSpawnableComponent))
class ECHOHEARTS_API UEHRFrequencyTamerLinkComponent : public UActorComponent
{
    GENERATED_BODY()

public:
    UEHRFrequencyTamerLinkComponent();

    virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;

    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Echohearts|Binding")
    TArray<int32> ApprovedDexIds;

    UPROPERTY(Replicated, EditAnywhere, BlueprintReadOnly, Category="Echohearts|AnimaLink")
    FEHRAttributeMatrix TamerAttributes;

    UPROPERTY(Replicated, BlueprintReadOnly, Category="Echohearts|AnimaLink")
    FEHRAttributeMatrix LinkedEcoKinAttributes;

    UPROPERTY(Replicated, BlueprintReadOnly, Category="Echohearts|AnimaLink")
    FName LinkedEcoKinInstanceId;

    UPROPERTY(Replicated, BlueprintReadOnly, Category="Echohearts|AnimaLink")
    bool bEcoKinLinked = false;

    UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly, Category="Echohearts|Binding")
    FEHRBindingOutcome TryKindleBind(const FEHRBindingRequest& Request);

    UFUNCTION(BlueprintPure, Category="Echohearts|Extraction")
    EEHRExtractionResult EvaluateSanctuaryExtraction(const FEHRExtractionRequest& Request) const;

    UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly, Category="Echohearts|AnimaLink")
    FEHRAnimaLinkPulseOutcome ApplyLinkedPulse(const FEHRAnimaLinkPulse& Pulse);

    UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly, Category="Echohearts|AnimaLink")
    void ClearEcoKinLink();

private:
    bool HasServerAuthority() const;
};

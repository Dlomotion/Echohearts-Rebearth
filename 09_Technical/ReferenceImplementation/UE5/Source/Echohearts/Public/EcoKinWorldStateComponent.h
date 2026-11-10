#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "EcoKinWorldStateComponent.generated.h"

UENUM(BlueprintType)
enum class EBrokenCrossingStage : uint8
{
    Unavailable, Investigate, RestoreHabitat, SeekConsent, EscortSupplies, Complete
};

USTRUCT(BlueprintType)
struct FEcoKinEcology
{
    GENERATED_BODY()
    UPROPERTY(EditAnywhere, BlueprintReadWrite) float Vibrance = 50.f;
    UPROPERTY(EditAnywhere, BlueprintReadWrite) float Density = 50.f;
    UPROPERTY(EditAnywhere, BlueprintReadWrite) float Harmony = 50.f;
    UPROPERTY(EditAnywhere, BlueprintReadWrite) float Purity = 50.f;
};

USTRUCT(BlueprintType)
struct FRebearthDomainSnapshot
{
    GENERATED_BODY()
    UPROPERTY(EditAnywhere, BlueprintReadWrite) int32 SchemaVersion = 1;
    UPROPERTY(EditAnywhere, BlueprintReadWrite) FName DomainId = NAME_None;
    UPROPERTY(EditAnywhere, BlueprintReadWrite) FEcoKinEcology Ecology;
    UPROPERTY(EditAnywhere, BlueprintReadWrite) bool bAquaticHabitatRestored = false;
    UPROPERTY(EditAnywhere, BlueprintReadWrite) bool bClinicSupplied = false;
};

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnEcoKinWorldChanged, EBrokenCrossingStage, NewStage);

UCLASS(ClassGroup=(Echohearts), meta=(BlueprintSpawnableComponent))
class UEcoKinWorldStateComponent : public UActorComponent
{
    GENERATED_BODY()
public:
    UEcoKinWorldStateComponent();
    virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;

    UPROPERTY(BlueprintAssignable) FOnEcoKinWorldChanged OnWorldChanged;
    UPROPERTY(ReplicatedUsing=OnRep_Stage, BlueprintReadOnly) EBrokenCrossingStage Stage = EBrokenCrossingStage::Unavailable;
    UPROPERTY(ReplicatedUsing=OnRep_Stage, BlueprintReadOnly) FRebearthDomainSnapshot Domain;

    // Called ONLY by trusted server-side mission logic after evidence validation.
    UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly) bool AdvanceValidatedStage(EBrokenCrossingStage Expected, bool bServerEvidencePassed);
    UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly) bool RestoreEcologyValidated(float Vibrance, float Density, float Harmony, float Purity, bool bServerResourceCostPaid);
protected:
    UFUNCTION() void OnRep_Stage();
};

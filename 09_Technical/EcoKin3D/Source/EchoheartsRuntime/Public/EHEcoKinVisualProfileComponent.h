#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "EHEcoKinVisualProfileComponent.generated.h"

/** The four canonical Eco-Kin attributes. Not generic RPG stats. */
USTRUCT(BlueprintType)
struct FEHEcoKinAttributes
{
    GENERATED_BODY()

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Echohearts|Attributes", meta=(ClampMin="0.0", ClampMax="100.0"))
    float Vibrance = 50.f;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Echohearts|Attributes", meta=(ClampMin="0.0", ClampMax="100.0"))
    float Density = 50.f;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Echohearts|Attributes", meta=(ClampMin="0.0", ClampMax="100.0"))
    float Harmony = 50.f;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Echohearts|Attributes", meta=(ClampMin="0.0", ClampMax="100.0"))
    float Purity = 50.f;
};

/** Stable IDs prevent a new visual skin/form from silently replacing an Eco-Kin. */
USTRUCT(BlueprintType)
struct FEHEcoKinVisualIdentity
{
    GENERATED_BODY()

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Echohearts|Identity")
    FName PermanentEcoKinID = NAME_None;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Echohearts|Identity")
    FName FormID = NAME_None;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Echohearts|Identity")
    FName SkinID = NAME_None;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Echohearts|Identity")
    FName VisualAssetID = NAME_None;
};

/** Server-owned gameplay identity; art selection is a validated, replicated cosmetic state. */
UCLASS(ClassGroup=(Echohearts), meta=(BlueprintSpawnableComponent))
class UEHEcoKinVisualProfileComponent : public UActorComponent
{
    GENERATED_BODY()

public:
    UEHEcoKinVisualProfileComponent();

    UFUNCTION(BlueprintPure, Category="Echohearts|EcoKin")
    FEHEcoKinVisualIdentity GetVisualIdentity() const { return VisualIdentity; }

    UFUNCTION(BlueprintPure, Category="Echohearts|EcoKin")
    FEHEcoKinAttributes GetAttributes() const { return Attributes; }

    /** Must be called by an authoritative server after roster/entitlement validation. */
    UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly, Category="Echohearts|EcoKin")
    bool SetValidatedIdentity(const FEHEcoKinVisualIdentity& NewIdentity);

    UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly, Category="Echohearts|EcoKin")
    void SetCanonicalAttributes(const FEHEcoKinAttributes& NewAttributes);

protected:
    UPROPERTY(EditDefaultsOnly, ReplicatedUsing=OnRep_VisualIdentity, Category="Echohearts|EcoKin")
    FEHEcoKinVisualIdentity VisualIdentity;

    UPROPERTY(EditDefaultsOnly, Replicated, Category="Echohearts|EcoKin")
    FEHEcoKinAttributes Attributes;

    UFUNCTION()
    void OnRep_VisualIdentity();

    UFUNCTION(BlueprintImplementableEvent, Category="Echohearts|EcoKin")
    void BP_OnVisualIdentityChanged();

    virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;
};

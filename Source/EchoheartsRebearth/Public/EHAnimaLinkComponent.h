#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "EHAnimaLinkComponent.generated.h"

USTRUCT(BlueprintType)
struct FEHCoreAttributes
{
    GENERATED_BODY()

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Echohearts|Attributes", meta=(ClampMin="0.0", ClampMax="100.0"))
    float Vibrance = 100.0f;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Echohearts|Attributes", meta=(ClampMin="0.0", ClampMax="100.0"))
    float Density = 100.0f;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Echohearts|Attributes", meta=(ClampMin="0.0", ClampMax="100.0"))
    float Harmony = 100.0f;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Echohearts|Attributes", meta=(ClampMin="0.0", ClampMax="100.0"))
    float Purity = 100.0f;
};

UCLASS(ClassGroup=(Echohearts), meta=(BlueprintSpawnableComponent))
class ECHOHEARTSREBEARTH_API UEHAnimaLinkComponent : public UActorComponent
{
    GENERATED_BODY()

public:
    UEHAnimaLinkComponent();

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Echohearts|AnimaLink")
    FEHCoreAttributes Attributes;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Echohearts|AnimaLink", meta=(ClampMin="0.0", ClampMax="1.0"))
    float DamageFeedbackRatio = 0.25f;

    UFUNCTION(BlueprintCallable, Category="Echohearts|AnimaLink")
    float ApplyEcoKinDamageFeedback(float IncomingDamage);

    UFUNCTION(BlueprintCallable, Category="Echohearts|AnimaLink")
    float ApplyTamerStrainFeedback(float IncomingStrain);
};

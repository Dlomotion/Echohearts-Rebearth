#include "EHAnimaLinkComponent.h"

UEHAnimaLinkComponent::UEHAnimaLinkComponent()
{
    PrimaryComponentTick.bCanEverTick = false;
}

float UEHAnimaLinkComponent::ApplyEcoKinDamageFeedback(float IncomingDamage)
{
    const float Feedback = FMath::Max(0.0f, IncomingDamage) * FMath::Clamp(DamageFeedbackRatio, 0.0f, 1.0f);
    const float Applied = FMath::Min(Attributes.Vibrance, Feedback);
    Attributes.Vibrance = FMath::Clamp(Attributes.Vibrance - Applied, 0.0f, 100.0f);
    return Applied;
}

float UEHAnimaLinkComponent::ApplyTamerStrainFeedback(float IncomingStrain)
{
    const float Feedback = FMath::Max(0.0f, IncomingStrain) * FMath::Clamp(DamageFeedbackRatio, 0.0f, 1.0f);
    const float Applied = FMath::Min(Attributes.Harmony, Feedback);
    Attributes.Harmony = FMath::Clamp(Attributes.Harmony - Applied, 0.0f, 100.0f);
    return Applied;
}

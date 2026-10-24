#include "EHEcoKinVisualProfileComponent.h"

#include "GameFramework/Actor.h"
#include "Net/UnrealNetwork.h"

UEHEcoKinVisualProfileComponent::UEHEcoKinVisualProfileComponent()
{
    SetIsReplicatedByDefault(true);
    PrimaryComponentTick.bCanEverTick = false;
}

bool UEHEcoKinVisualProfileComponent::SetValidatedIdentity(
    const FEHEcoKinVisualIdentity& NewIdentity)
{
    const AActor* OwnerActor = GetOwner();
    if (!IsValid(OwnerActor) || !OwnerActor->HasAuthority())
    {
        return false;
    }

    // A real roster lookup and skin-entitlement check must precede this call.
    // Reject empty IDs here; never interpret this check as full authorization.
    if (NewIdentity.PermanentEcoKinID.IsNone() || NewIdentity.VisualAssetID.IsNone())
    {
        return false;
    }

    VisualIdentity = NewIdentity;
    BP_OnVisualIdentityChanged();
    return true;
}

void UEHEcoKinVisualProfileComponent::SetCanonicalAttributes(
    const FEHEcoKinAttributes& NewAttributes)
{
    const AActor* OwnerActor = GetOwner();
    if (!IsValid(OwnerActor) || !OwnerActor->HasAuthority())
    {
        return;
    }

    Attributes.Vibrance = FMath::Clamp(NewAttributes.Vibrance, 0.f, 100.f);
    Attributes.Density = FMath::Clamp(NewAttributes.Density, 0.f, 100.f);
    Attributes.Harmony = FMath::Clamp(NewAttributes.Harmony, 0.f, 100.f);
    Attributes.Purity = FMath::Clamp(NewAttributes.Purity, 0.f, 100.f);
}

void UEHEcoKinVisualProfileComponent::OnRep_VisualIdentity()
{
    BP_OnVisualIdentityChanged();
}

void UEHEcoKinVisualProfileComponent::GetLifetimeReplicatedProps(
    TArray<FLifetimeProperty>& OutLifetimeProps) const
{
    Super::GetLifetimeReplicatedProps(OutLifetimeProps);
    DOREPLIFETIME(UEHEcoKinVisualProfileComponent, VisualIdentity);
    DOREPLIFETIME(UEHEcoKinVisualProfileComponent, Attributes);
}

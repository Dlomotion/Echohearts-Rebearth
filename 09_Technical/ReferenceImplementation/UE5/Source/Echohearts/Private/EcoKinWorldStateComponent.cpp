#include "EcoKinWorldStateComponent.h"
#include "Net/UnrealNetwork.h"
#include "GameFramework/Actor.h"

UEcoKinWorldStateComponent::UEcoKinWorldStateComponent()
{
    SetIsReplicatedByDefault(true);
    PrimaryComponentTick.bCanEverTick = false;
}
void UEcoKinWorldStateComponent::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& Out) const
{
    Super::GetLifetimeReplicatedProps(Out);
    DOREPLIFETIME(UEcoKinWorldStateComponent, Stage);
    DOREPLIFETIME(UEcoKinWorldStateComponent, Domain);
}
bool UEcoKinWorldStateComponent::AdvanceValidatedStage(EBrokenCrossingStage Expected, bool bServerEvidencePassed)
{
    if (!GetOwner() || !GetOwner()->HasAuthority() || !bServerEvidencePassed || Stage != Expected || Stage == EBrokenCrossingStage::Complete)
        return false;
    switch (Stage)
    {
    case EBrokenCrossingStage::Unavailable: Stage = EBrokenCrossingStage::Investigate; break;
    case EBrokenCrossingStage::Investigate: Stage = EBrokenCrossingStage::RestoreHabitat; break;
    case EBrokenCrossingStage::RestoreHabitat:
        Domain.bAquaticHabitatRestored = true;
        Stage = EBrokenCrossingStage::SeekConsent;
        break;
    case EBrokenCrossingStage::SeekConsent:
        if (!Domain.bAquaticHabitatRestored) return false;
        Stage = EBrokenCrossingStage::EscortSupplies;
        break;
    case EBrokenCrossingStage::EscortSupplies:
        Domain.bClinicSupplied = true;
        Stage = EBrokenCrossingStage::Complete;
        break;
    default: return false;
    }
    OnRep_Stage();
    GetOwner()->ForceNetUpdate();
    return true;
}
bool UEcoKinWorldStateComponent::RestoreEcologyValidated(float V, float D, float H, float P, bool bServerResourceCostPaid)
{
    if (!GetOwner() || !GetOwner()->HasAuthority() || !bServerResourceCostPaid ||
        !FMath::IsFinite(V) || !FMath::IsFinite(D) || !FMath::IsFinite(H) || !FMath::IsFinite(P))
        return false;
    auto Apply = [](float Current, float Delta) { return FMath::Clamp(Current + FMath::Clamp(Delta, -10.f, 10.f), 0.f, 100.f); };
    Domain.Ecology.Vibrance = Apply(Domain.Ecology.Vibrance, V);
    Domain.Ecology.Density = Apply(Domain.Ecology.Density, D);
    Domain.Ecology.Harmony = Apply(Domain.Ecology.Harmony, H);
    Domain.Ecology.Purity = Apply(Domain.Ecology.Purity, P);
    OnRep_Stage();
    GetOwner()->ForceNetUpdate();
    return true;
}
void UEcoKinWorldStateComponent::OnRep_Stage() { OnWorldChanged.Broadcast(Stage); }

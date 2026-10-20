#include "EHRFrequencyTamerLinkComponent.h"

#include "EHRSanctuaryPolicyLibrary.h"
#include "Net/UnrealNetwork.h"

UEHRFrequencyTamerLinkComponent::UEHRFrequencyTamerLinkComponent()
{
    PrimaryComponentTick.bCanEverTick = false;
    SetIsReplicatedByDefault(true);
}

bool UEHRFrequencyTamerLinkComponent::HasServerAuthority() const
{
    const AActor* OwnerActor = GetOwner();
    return OwnerActor != nullptr && OwnerActor->HasAuthority();
}

FEHRBindingOutcome UEHRFrequencyTamerLinkComponent::TryKindleBind(const FEHRBindingRequest& Request)
{
    if (!HasServerAuthority())
    {
        FEHRBindingOutcome Rejected;
        Rejected.Result = EEHRBindingResult::AuthorityRequired;
        Rejected.UpdatedTamerAttributes = TamerAttributes;
        return Rejected;
    }

    FEHRBindingRequest ServerRequest = Request;
    ServerRequest.bAlreadyBound = bEcoKinLinked;

    FEHRBindingOutcome Outcome = UEHRSanctuaryPolicyLibrary::EvaluateBinding(
        ServerRequest,
        TamerAttributes,
        ApprovedDexIds);

    if (Outcome.Result == EEHRBindingResult::Bound)
    {
        TamerAttributes = Outcome.UpdatedTamerAttributes;
        LinkedEcoKinAttributes = ServerRequest.TargetAttributes;
        LinkedEcoKinInstanceId = ServerRequest.EcoKinInstanceId;
        bEcoKinLinked = true;

        if (AActor* OwnerActor = GetOwner())
        {
            OwnerActor->ForceNetUpdate();
        }
    }

    return Outcome;
}

EEHRExtractionResult UEHRFrequencyTamerLinkComponent::EvaluateSanctuaryExtraction(
    const FEHRExtractionRequest& Request) const
{
    if (!HasServerAuthority())
    {
        return EEHRExtractionResult::AuthorityRequired;
    }

    FEHRExtractionRequest ServerRequest = Request;
    ServerRequest.bBindingConfirmed =
        bEcoKinLinked
        && !LinkedEcoKinInstanceId.IsNone()
        && ServerRequest.EcoKinInstanceId == LinkedEcoKinInstanceId;

    return UEHRSanctuaryPolicyLibrary::EvaluateExtraction(ServerRequest, TamerAttributes);
}

FEHRAnimaLinkPulseOutcome UEHRFrequencyTamerLinkComponent::ApplyLinkedPulse(const FEHRAnimaLinkPulse& Pulse)
{
    FEHRAnimaLinkPulseOutcome Outcome;
    Outcome.UpdatedTamerAttributes = TamerAttributes;
    Outcome.UpdatedEcoKinAttributes = LinkedEcoKinAttributes;

    if (!HasServerAuthority() || !bEcoKinLinked)
    {
        return Outcome;
    }

    Outcome = UEHRSanctuaryPolicyLibrary::ApplyAnimaLinkPulse(
        TamerAttributes,
        LinkedEcoKinAttributes,
        Pulse);

    TamerAttributes = Outcome.UpdatedTamerAttributes;
    LinkedEcoKinAttributes = Outcome.UpdatedEcoKinAttributes;

    if (AActor* OwnerActor = GetOwner())
    {
        OwnerActor->ForceNetUpdate();
    }

    return Outcome;
}

void UEHRFrequencyTamerLinkComponent::ClearEcoKinLink()
{
    if (!HasServerAuthority())
    {
        return;
    }

    LinkedEcoKinAttributes = FEHRAttributeMatrix();
    LinkedEcoKinInstanceId = NAME_None;
    bEcoKinLinked = false;

    if (AActor* OwnerActor = GetOwner())
    {
        OwnerActor->ForceNetUpdate();
    }
}

void UEHRFrequencyTamerLinkComponent::GetLifetimeReplicatedProps(
    TArray<FLifetimeProperty>& OutLifetimeProps) const
{
    Super::GetLifetimeReplicatedProps(OutLifetimeProps);

    DOREPLIFETIME(UEHRFrequencyTamerLinkComponent, TamerAttributes);
    DOREPLIFETIME(UEHRFrequencyTamerLinkComponent, LinkedEcoKinAttributes);
    DOREPLIFETIME(UEHRFrequencyTamerLinkComponent, LinkedEcoKinInstanceId);
    DOREPLIFETIME(UEHRFrequencyTamerLinkComponent, bEcoKinLinked);
}

#pragma once

#include "CoreMinimal.h"
#include "EHRGameplayTypes.generated.h"

UENUM(BlueprintType)
enum class EEHRBindingResult : uint8
{
    Bound,
    InvalidTarget,
    NotReady,
    ConsentRequired,
    FailedPurityGate,
    InsufficientHarmony,
    InvalidStability,
    AuthorityRequired
};

UENUM(BlueprintType)
enum class EEHRExtractionResult : uint8
{
    Ready,
    InvalidTarget,
    BindingRequired,
    KindlingRequired,
    ConsentRequired,
    SanctuaryUnavailable,
    InsufficientHarmony,
    AuthorityRequired
};

UENUM(BlueprintType)
enum class EEHRHousingResult : uint8
{
    Assigned,
    InvalidResident,
    InvalidHousing,
    AlreadyAssigned,
    HousingFull,
    RestorationLocked,
    AttributeLocked,
    AuthorityRequired
};

UENUM(BlueprintType)
enum class EEHRCraftingResult : uint8
{
    Crafted,
    InvalidRecipe,
    TierLocked,
    RestorationLocked,
    AttributeLocked,
    MissingMaterials,
    AuthorityRequired
};

USTRUCT(BlueprintType)
struct ECHOHEARTS_API FEHRAttributeMatrix
{
    GENERATED_BODY()

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Echohearts|Attributes")
    int32 Vibrance = 0;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Echohearts|Attributes")
    int32 Density = 0;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Echohearts|Attributes")
    int32 Harmony = 0;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Echohearts|Attributes")
    int32 Purity = 0;

    bool IsValid() const
    {
        return Vibrance >= 0 && Density >= 0 && Harmony >= 0 && Purity >= 0;
    }
};

USTRUCT(BlueprintType)
struct ECHOHEARTS_API FEHRBindingRequest
{
    GENERATED_BODY()

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Echohearts|Binding")
    int32 DexId = 0;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Echohearts|Binding")
    FName EcoKinInstanceId;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Echohearts|Binding")
    bool bWildEncounter = false;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Echohearts|Binding")
    bool bAlreadyBound = false;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Echohearts|Binding")
    bool bKindlingComplete = false;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Echohearts|Binding")
    bool bConsentConfirmed = false;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Echohearts|Binding")
    FEHRAttributeMatrix TargetAttributes;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Echohearts|Binding", meta=(ClampMin="0"))
    int32 MinimumPurity = 35;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Echohearts|Binding", meta=(ClampMin="0"))
    int32 HarmonyCost = 10;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Echohearts|Binding", meta=(ClampMin="0.0", ClampMax="1.0"))
    float Stability = 1.0f;
};

USTRUCT(BlueprintType)
struct ECHOHEARTS_API FEHRBindingOutcome
{
    GENERATED_BODY()

    UPROPERTY(BlueprintReadOnly, Category="Echohearts|Binding")
    EEHRBindingResult Result = EEHRBindingResult::InvalidTarget;

    UPROPERTY(BlueprintReadOnly, Category="Echohearts|Binding")
    int32 HarmonySpent = 0;

    UPROPERTY(BlueprintReadOnly, Category="Echohearts|Binding")
    FEHRAttributeMatrix UpdatedTamerAttributes;
};

USTRUCT(BlueprintType)
struct ECHOHEARTS_API FEHRExtractionRequest
{
    GENERATED_BODY()

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Echohearts|Extraction")
    FName EcoKinInstanceId;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Echohearts|Extraction")
    bool bBindingConfirmed = false;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Echohearts|Extraction")
    bool bKindlingComplete = false;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Echohearts|Extraction")
    bool bConsentConfirmed = false;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Echohearts|Extraction")
    bool bSanctuarySpaceAvailable = false;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Echohearts|Extraction", meta=(ClampMin="0"))
    int32 MinimumHarmony = 5;
};

USTRUCT(BlueprintType)
struct ECHOHEARTS_API FEHRAnimaLinkPulse
{
    GENERATED_BODY()

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Echohearts|AnimaLink", meta=(ClampMin="0"))
    int32 DirectTamerVibranceStrain = 0;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Echohearts|AnimaLink", meta=(ClampMin="0"))
    int32 DirectTamerDensityStrain = 0;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Echohearts|AnimaLink", meta=(ClampMin="0"))
    int32 DirectEcoKinVibranceStrain = 0;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Echohearts|AnimaLink", meta=(ClampMin="0"))
    int32 DirectEcoKinDensityStrain = 0;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Echohearts|AnimaLink", meta=(ClampMin="0", ClampMax="10000"))
    int32 TransferBasisPoints = 2500;
};

USTRUCT(BlueprintType)
struct ECHOHEARTS_API FEHRAnimaLinkPulseOutcome
{
    GENERATED_BODY()

    UPROPERTY(BlueprintReadOnly, Category="Echohearts|AnimaLink")
    FEHRAttributeMatrix UpdatedTamerAttributes;

    UPROPERTY(BlueprintReadOnly, Category="Echohearts|AnimaLink")
    FEHRAttributeMatrix UpdatedEcoKinAttributes;

    UPROPERTY(BlueprintReadOnly, Category="Echohearts|AnimaLink")
    int32 TransferredToTamerVibrance = 0;

    UPROPERTY(BlueprintReadOnly, Category="Echohearts|AnimaLink")
    int32 TransferredToTamerDensity = 0;

    UPROPERTY(BlueprintReadOnly, Category="Echohearts|AnimaLink")
    int32 TransferredToEcoKinVibrance = 0;

    UPROPERTY(BlueprintReadOnly, Category="Echohearts|AnimaLink")
    int32 TransferredToEcoKinDensity = 0;
};

USTRUCT(BlueprintType)
struct ECHOHEARTS_API FEHRResidentProfile
{
    GENERATED_BODY()

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Echohearts|Sanctuary")
    FName ResidentId;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Echohearts|Sanctuary")
    FName HousingId;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Echohearts|Sanctuary")
    bool bAssigned = false;
};

USTRUCT(BlueprintType)
struct ECHOHEARTS_API FEHRHousingSlot
{
    GENERATED_BODY()

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Echohearts|Sanctuary")
    FName HousingId;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Echohearts|Sanctuary", meta=(ClampMin="1"))
    int32 Capacity = 1;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Echohearts|Sanctuary", meta=(ClampMin="0"))
    int32 Occupancy = 0;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Echohearts|Sanctuary", meta=(ClampMin="0"))
    int32 RestorationGate = 0;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Echohearts|Sanctuary")
    FEHRAttributeMatrix MinimumSanctuaryAttributes;
};

USTRUCT(BlueprintType)
struct ECHOHEARTS_API FEHRQuestPrerequisites
{
    GENERATED_BODY()

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Echohearts|Quest")
    FName QuestId;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Echohearts|Quest")
    bool bAutoStart = true;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Echohearts|Quest", meta=(ClampMin="0"))
    int32 RequiredRestoration = 0;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Echohearts|Quest", meta=(ClampMin="0"))
    int32 RequiredResidents = 0;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Echohearts|Quest")
    FEHRAttributeMatrix MinimumSanctuaryAttributes;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Echohearts|Quest")
    TArray<FName> RequiredQuestIds;
};

USTRUCT(BlueprintType)
struct ECHOHEARTS_API FEHRCraftingTierRecipe
{
    GENERATED_BODY()

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Echohearts|Crafting")
    FName RecipeId;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Echohearts|Crafting", meta=(ClampMin="1"))
    int32 Tier = 1;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Echohearts|Crafting", meta=(ClampMin="0"))
    int32 RequiredRestoration = 0;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Echohearts|Crafting")
    FEHRAttributeMatrix MinimumSanctuaryAttributes;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Echohearts|Crafting")
    TMap<FName, int32> Materials;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Echohearts|Crafting")
    TMap<FName, int32> Outputs;
};

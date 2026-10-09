#pragma once
#include "CoreMinimal.h"
#include "EchoMorphologyTypes.generated.h"

UENUM(BlueprintType)
enum class EEchoGrowthTier : uint8 { Prime, Vector, Apex };
UENUM(BlueprintType)
enum class EEchoPhenotype : uint8 { Natural, Prismatic, Obsidian };
UENUM(BlueprintType)
enum class EEchoFrequencyBand : uint8 {
 None, Band01, Band02, Band03, Band04, Band05, Band06,
 Band07, Band08, Band09, Band10, Radiant, Void
};

USTRUCT(BlueprintType)
struct FEchoAttributeMatrix {
 GENERATED_BODY()
 UPROPERTY(EditAnywhere, BlueprintReadWrite) float Vibrance = 0.f;
 UPROPERTY(EditAnywhere, BlueprintReadWrite) float Density = 0.f;
 UPROPERTY(EditAnywhere, BlueprintReadWrite) float Harmony = 0.f;
 UPROPERTY(EditAnywhere, BlueprintReadWrite) float Purity = 0.f;
 bool IsValid() const {
  return FMath::IsFinite(Vibrance) && FMath::IsFinite(Density)
   && FMath::IsFinite(Harmony) && FMath::IsFinite(Purity)
   && Vibrance >= 0.f && Density >= 0.f && Harmony >= 0.f && Purity >= 0.f;
 }
};

USTRUCT(BlueprintType)
struct FEchoMorphologyState {
 GENERATED_BODY()
 UPROPERTY(EditAnywhere, BlueprintReadWrite) FName EcoKinId = NAME_None;
 UPROPERTY(EditAnywhere, BlueprintReadWrite) FName HabitatId = NAME_None;
 UPROPERTY(EditAnywhere, BlueprintReadWrite) FName MorphologyId = NAME_None;
 UPROPERTY(EditAnywhere, BlueprintReadWrite) EEchoGrowthTier GrowthTier = EEchoGrowthTier::Prime;
 UPROPERTY(EditAnywhere, BlueprintReadWrite) EEchoPhenotype Phenotype = EEchoPhenotype::Natural;
 UPROPERTY(EditAnywhere, BlueprintReadWrite) EEchoFrequencyBand Overlay = EEchoFrequencyBand::None;
 UPROPERTY(EditAnywhere, BlueprintReadWrite) FEchoAttributeMatrix Attributes;
 UPROPERTY(EditAnywhere, BlueprintReadWrite) float ScaleMultiplier = 1.f;
 UPROPERTY(EditAnywhere, BlueprintReadWrite) int32 MutationRevision = 0;
 bool IsValid() const {
  return !EcoKinId.IsNone() && Attributes.IsValid()
   && FMath::IsFinite(ScaleMultiplier) && ScaleMultiplier >= 0.25f
   && ScaleMultiplier <= 4.f && MutationRevision >= 0
   && static_cast<uint8>(GrowthTier) <= static_cast<uint8>(EEchoGrowthTier::Apex)
   && static_cast<uint8>(Phenotype) <= static_cast<uint8>(EEchoPhenotype::Obsidian)
   && static_cast<uint8>(Overlay) <= static_cast<uint8>(EEchoFrequencyBand::Void);
 }
};

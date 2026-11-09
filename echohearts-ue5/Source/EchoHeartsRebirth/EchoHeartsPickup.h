#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "EchoHeartsPickup.generated.h"

class USphereComponent;

/** A dropped heart (heals 20 HP, +10 score via the character) or star (restores 50 mana). */
UCLASS()
class ECHOHEARTSREBIRTH_API AEchoHeartsPickup : public AActor
{
	GENERATED_BODY()

public:
	AEchoHeartsPickup();

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "EchoHearts")
	TObjectPtr<USphereComponent> Collision;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "EchoHearts")
	bool bIsStar = false;

	UFUNCTION()
	void OnOverlap(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);
};

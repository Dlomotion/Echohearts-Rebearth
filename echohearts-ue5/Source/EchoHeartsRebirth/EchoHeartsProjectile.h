#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "EchoHeartsProjectile.generated.h"

class USphereComponent;
class UProjectileMovementComponent;

/** An Echo Pulse (or Burst): damage with Terraria-style crit + knockback, applied by the target's defence. */
UCLASS()
class ECHOHEARTSREBIRTH_API AEchoHeartsProjectile : public AActor
{
	GENERATED_BODY()

public:
	AEchoHeartsProjectile();

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "EchoHearts")
	TObjectPtr<USphereComponent> Collision;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "EchoHearts")
	TObjectPtr<UProjectileMovementComponent> Movement;

	float Damage = 22.f;
	bool bBurst = false;
	bool bCrit = false;
	TWeakObjectPtr<AActor> OwnerActor;

	void Init(FVector Direction, float InDamage, bool bInBurst, AActor* InOwner);

	UFUNCTION()
	void OnHit(UPrimitiveComponent* HitComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit);
};

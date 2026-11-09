// Copyright EchoHearts Rebirth. MIT License.
#include "EchoHeartsProjectile.h"
#include "EchoHeartsEnemy.h"
#include "EchoHeartsStats.h"
#include "Components/SphereComponent.h"
#include "GameFramework/ProjectileMovementComponent.h"
#include "Kismet/GameplayStatics.h"

AEchoHeartsProjectile::AEchoHeartsProjectile()
{
	PrimaryActorTick.bCanEverTick = false;
	Collision = CreateDefaultSubobject<USphereComponent>(TEXT("Collision"));
	Collision->InitSphereRadius(18.f);
	Collision->SetCollisionProfileName(TEXT("BlockAllDynamic"));
	RootComponent = Collision;

	Movement = CreateDefaultSubobject<UProjectileMovementComponent>(TEXT("Movement"));
	Movement->InitialSpeed = 1400.f;
	Movement->MaxSpeed = 1400.f;
	Movement->bRotationFollowsVelocity = true;
	Movement->ProjectileGravityScale = 0.f;

	InitialLifeSpan = 2.5f;
	Collision->OnComponentHit.AddDynamic(this, &AEchoHeartsProjectile::OnHit);
}

void AEchoHeartsProjectile::Init(FVector Direction, float InDamage, bool bInBurst, AActor* InOwner)
{
	Damage = InDamage;
	bBurst = bInBurst;
	OwnerActor = InOwner;
	bCrit = FMath::FRand() < EchoHeartsStats::CritChance; // 10% — crits deal double (in the enemy's defence calc)
	if (Movement) Movement->Velocity = Direction.GetSafeNormal() * Movement->InitialSpeed;
	if (bBurst) SetActorScale3D(FVector(1.8f));
}

void AEchoHeartsProjectile::OnHit(UPrimitiveComponent* HitComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit)
{
	if (OtherActor && OtherActor != OwnerActor.Get())
	{
		if (AEchoHeartsEnemy* Enemy = Cast<AEchoHeartsEnemy>(OtherActor))
		{
			Enemy->ApplyEchoHit(Damage, bCrit, GetActorForwardVector());
		}
		else
		{
			UGameplayStatics::ApplyDamage(OtherActor, Damage, nullptr, OwnerActor.Get(), nullptr);
		}
	}
	Destroy();
}

// Copyright EchoHearts Rebirth. MIT License.
#include "EchoHeartsPickup.h"
#include "EchoHeartsCharacter.h"
#include "Components/SphereComponent.h"

AEchoHeartsPickup::AEchoHeartsPickup()
{
	PrimaryActorTick.bCanEverTick = false;
	Collision = CreateDefaultSubobject<USphereComponent>(TEXT("Collision"));
	Collision->InitSphereRadius(60.f);
	Collision->SetCollisionProfileName(TEXT("OverlapAllDynamic"));
	RootComponent = Collision;
	Collision->OnComponentBeginOverlap.AddDynamic(this, &AEchoHeartsPickup::OnOverlap);
	InitialLifeSpan = 30.f;
}

void AEchoHeartsPickup::OnOverlap(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if (AEchoHeartsCharacter* Player = Cast<AEchoHeartsCharacter>(OtherActor))
	{
		if (bIsStar) Player->AddStarPickup(); else Player->AddHeartPickup();
		Destroy();
	}
}

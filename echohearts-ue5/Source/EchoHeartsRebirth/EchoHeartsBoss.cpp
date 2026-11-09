// Copyright EchoHearts Rebirth. MIT License.
#include "EchoHeartsBoss.h"
#include "EchoHeartsCharacter.h"
#include "EchoHeartsProjectile.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Kismet/GameplayStatics.h"

AEchoHeartsBoss::AEchoHeartsBoss()
{
	Kind = EEchoEnemyKind::Boss;
	SetActorScale3D(FVector(2.4f));
}

void AEchoHeartsBoss::BeginPlay()
{
	Super::BeginPlay();
	SetupForKind(EEchoEnemyKind::Boss);
	if (GEngine) GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("Heartbreaker has awoken!"));
	UE_LOG(LogTemp, Warning, TEXT("EchoHearts: Heartbreaker has awoken! HP %.0f"), MaxHP);
}

void AEchoHeartsBoss::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);
	if (HP <= 0.f) return;

	OrbTimer -= DeltaSeconds;
	MinionTimer -= DeltaSeconds;
	APawn* PlayerPawn = UGameplayStatics::GetPlayerPawn(this, 0);

	// Void orbs — faster when enraged.
	if (PlayerPawn && OrbClass && OrbTimer <= 0.f)
	{
		OrbTimer = bEnraged ? 0.9f : 1.5f;
		const FVector Spawn = GetActorLocation() + FVector(0, 0, 80);
		const FVector Dir = (PlayerPawn->GetActorLocation() - Spawn).GetSafeNormal();
		if (AEchoHeartsProjectile* Orb = GetWorld()->SpawnActor<AEchoHeartsProjectile>(OrbClass, Spawn, Dir.Rotation()))
		{
			Orb->Init(Dir, 15.f, false, this);
		}
	}
	// Spawn a mischievous imp every ~7 seconds.
	if (MinionTimer <= 0.f)
	{
		MinionTimer = 7.f;
		GetWorld()->SpawnActor<AEchoHeartsEnemy>(AEchoHeartsEnemy::StaticClass(), GetActorLocation() + FVector(220, 0, 0), FRotator::ZeroRotator);
	}
}

float AEchoHeartsBoss::ApplyEchoHit(float RawDamage, bool bCrit, FVector ShotDirection)
{
	const float Dealt = Super::ApplyEchoHit(RawDamage, bCrit, ShotDirection);
	if (!bEnraged && HP > 0.f && HP < MaxHP * 0.25f)
	{
		bEnraged = true;
		GetCharacterMovement()->MaxWalkSpeed *= 1.5f;
		if (GEngine) GEngine->AddOnScreenDebugMessage(-1, 4.f, FColor::Red, TEXT("Heartbreaker ENRAGED!"));
	}
	return Dealt;
}

void AEchoHeartsBoss::OnDeath()
{
	// Rebirth: heal + grow the player who is in the world, then normal drops.
	if (AEchoHeartsCharacter* Player = Cast<AEchoHeartsCharacter>(UGameplayStatics::GetPlayerPawn(this, 0)))
	{
		Player->MaxHP = FMath::Min(200.f, Player->MaxHP + 20.f);
		Player->HP = FMath::Min(Player->MaxHP, Player->HP + 40.f);
		Player->Score += 200;
		if (GEngine) GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Green, TEXT("REBIRTH! +20 Max HP"));
	}
	Super::OnDeath();
}

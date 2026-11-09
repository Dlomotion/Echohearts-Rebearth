// Copyright EchoHearts Rebirth. MIT License.
#include "EchoHeartsEnemy.h"
#include "EchoHeartsCharacter.h"
#include "EchoHeartsPickup.h"
#include "EchoHeartsStats.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Kismet/GameplayStatics.h"

AEchoHeartsEnemy::AEchoHeartsEnemy()
{
	PrimaryActorTick.bCanEverTick = true;
	AutoPossessAI = EAutoPossessAI::PlacedInWorldOrSpawned;
	GetCharacterMovement()->MaxWalkSpeed = 260.f;
}

void AEchoHeartsEnemy::BeginPlay()
{
	Super::BeginPlay();
	SetupForKind(Kind);
}

void AEchoHeartsEnemy::SetupForKind(EEchoEnemyKind InKind, int32 Level, bool bNight)
{
	Kind = InKind;
	switch (Kind)
	{
	case EEchoEnemyKind::Imp:
		MaxHP = EchoHeartsStats::ImpHP; ContactDamage = EchoHeartsStats::ImpDamage;
		Defence = 0; KnockbackResist = 0.2f; ScoreValue = 15; GetCharacterMovement()->MaxWalkSpeed = 420.f; break;
	case EEchoEnemyKind::Monster:
		MaxHP = EchoHeartsStats::MonsterHP * (bNight ? 1.25f : 1.f); ContactDamage = EchoHeartsStats::MonsterDamage;
		Defence = EchoHeartsStats::MonsterDefence; KnockbackResist = 0.5f; ScoreValue = 25; GetCharacterMovement()->MaxWalkSpeed = 260.f; break;
	case EEchoEnemyKind::Boss:
		MaxHP = EchoHeartsStats::BossBaseHP + 60.f * Level; ContactDamage = EchoHeartsStats::BossDamage;
		Defence = EchoHeartsStats::BossDefence; KnockbackResist = 0.95f; ScoreValue = 200; GetCharacterMovement()->MaxWalkSpeed = 200.f; break;
	}
	HP = MaxHP;
}

void AEchoHeartsEnemy::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);
	if (TouchCooldown > 0.f) TouchCooldown -= DeltaSeconds;
	if (HP <= 0.f) return;

	APawn* PlayerPawn = UGameplayStatics::GetPlayerPawn(this, 0);
	if (!PlayerPawn) return;

	const FVector ToPlayer = PlayerPawn->GetActorLocation() - GetActorLocation();
	const float Dist = ToPlayer.Size2D();
	FVector Dir = ToPlayer.GetSafeNormal2D();
	if (Kind == EEchoEnemyKind::Imp)
	{
		// Mischievous: dart sideways as it closes in.
		Dir = (Dir + FVector(-Dir.Y, Dir.X, 0) * FMath::Sin(GetWorld()->TimeSeconds * 5.f) * 0.8f).GetSafeNormal();
	}
	if (Dist > 90.f) AddMovementInput(Dir, 1.f);

	// Contact damage — the player's own i-frames decide whether it lands.
	if (Dist < 110.f && TouchCooldown <= 0.f)
	{
		UGameplayStatics::ApplyDamage(PlayerPawn, ContactDamage, GetController(), this, nullptr);
		TouchCooldown = 0.7f;
	}
}

float AEchoHeartsEnemy::ApplyEchoHit(float RawDamage, bool bCrit, FVector ShotDirection)
{
	const float Dealt = EchoHeartsStats::DamageAfterDefence(RawDamage, Defence, bCrit);
	HP -= Dealt;

	// Knockback scaled by resistance (like Terraria): bosses barely budge.
	const float KB = EchoHeartsStats::PulseKnockback * (1.f - KnockbackResist) * 90.f;
	LaunchCharacter(ShotDirection.GetSafeNormal2D() * KB + FVector(0, 0, 60), true, false);

	UE_LOG(LogTemp, Display, TEXT("EchoHearts: %s hit for %.0f%s (HP %.0f/%.0f)"),
		*GetName(), Dealt, bCrit ? TEXT(" CRIT!") : TEXT(""), HP, MaxHP);

	if (HP <= 0.f) OnDeath();
	return Dealt;
}

void AEchoHeartsEnemy::MaybeDropPickup() const
{
	if (!GetWorld()) return;
	// Spawn as a Blueprint subclass of AEchoHeartsPickup if one is set up in the
	// editor; BP_Pickup_Heart / BP_Pickup_Star are the conventional names.
	const float Roll = FMath::FRand();
	TSubclassOf<AEchoHeartsPickup> Class;
	if (Roll < EchoHeartsStats::DropHeartChance) Class = AEchoHeartsPickup::StaticClass();
	else if (Roll < EchoHeartsStats::DropHeartChance + EchoHeartsStats::DropStarChance) Class = AEchoHeartsPickup::StaticClass();
	if (Class)
	{
		AEchoHeartsPickup* Drop = GetWorld()->SpawnActor<AEchoHeartsPickup>(Class, GetActorLocation() + FVector(0, 0, 60), FRotator::ZeroRotator);
		if (Drop) Drop->bIsStar = (Roll >= EchoHeartsStats::DropHeartChance);
	}
}

void AEchoHeartsEnemy::OnDeath()
{
	MaybeDropPickup();
	Destroy();
}

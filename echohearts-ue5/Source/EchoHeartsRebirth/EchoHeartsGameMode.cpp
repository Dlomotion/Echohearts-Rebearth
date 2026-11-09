// Copyright EchoHearts Rebirth. MIT License.
#include "EchoHeartsGameMode.h"
#include "EchoHeartsBoss.h"
#include "EchoHeartsCharacter.h"
#include "EchoHeartsEnemy.h"
#include "Kismet/GameplayStatics.h"

AEchoHeartsGameMode::AEchoHeartsGameMode()
{
	PrimaryActorTick.bCanEverTick = true;
	DefaultPawnClass = AEchoHeartsCharacter::StaticClass();
}

void AEchoHeartsGameMode::BeginPlay()
{
	Super::BeginPlay();
	if (!EnemyClass) EnemyClass = AEchoHeartsEnemy::StaticClass();
	if (!BossClass) BossClass = AEchoHeartsBoss::StaticClass();
}

void AEchoHeartsGameMode::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);
	WorldTime += DeltaSeconds;
	const float Phase = FMath::Fmod(WorldTime, DayLengthSeconds) / DayLengthSeconds; // 0..1 over a full cycle
	bIsNight = Phase >= 0.5f;

	// Level follows hearts collected, like the other editions (5 hearts = 1 level).
	if (AEchoHeartsCharacter* Player = Cast<AEchoHeartsCharacter>(UGameplayStatics::GetPlayerPawn(this, 0)))
	{
		const int32 NewLevel = Player->HeartsCollected / 5 + 1;
		if (NewLevel != Level) { Level = NewLevel; bBossSpawnedThisLevel = false; }
		BestScore = FMath::Max(BestScore, Player->Score);
	}

	// Spawns: night is twice as busy (Terraria day/night rule).
	SpawnTimer -= DeltaSeconds;
	if (SpawnTimer <= 0.f)
	{
		SpawnTimer = bIsNight ? 2.2f : 4.4f;
		SpawnWaveEnemy();
	}

	// Boss every 3 levels.
	if (Level % 3 == 0 && !bBossSpawnedThisLevel)
	{
		bBossSpawnedThisLevel = true;
		SummonBoss();
	}
}

void AEchoHeartsGameMode::SpawnWaveEnemy()
{
	APawn* PlayerPawn = UGameplayStatics::GetPlayerPawn(this, 0);
	if (!PlayerPawn || !EnemyClass) return;
	const float Angle = FMath::FRand() * 2.f * PI;
	const FVector Loc = PlayerPawn->GetActorLocation() + FVector(FMath::Cos(Angle) * 1400.f, FMath::Sin(Angle) * 1400.f, 80.f);
	AEchoHeartsEnemy* E = GetWorld()->SpawnActor<AEchoHeartsEnemy>(EnemyClass, Loc, FRotator::ZeroRotator);
	if (E) E->SetupForKind(FMath::FRand() < 0.5f ? EEchoEnemyKind::Imp : EEchoEnemyKind::Monster, Level, bIsNight);
}

void AEchoHeartsGameMode::SummonBoss()
{
	APawn* PlayerPawn = UGameplayStatics::GetPlayerPawn(this, 0);
	if (!PlayerPawn || !BossClass) return;
	const FVector Loc = PlayerPawn->GetActorLocation() + FVector(900.f, 0.f, 120.f);
	GetWorld()->SpawnActor<AEchoHeartsBoss>(BossClass, Loc, FRotator::ZeroRotator);
}

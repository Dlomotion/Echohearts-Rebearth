#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "EchoHeartsGameMode.generated.h"

class AEchoHeartsEnemy;
class AEchoHeartsBoss;

/**
 * Owns the world rules: day/night cycle (night = faster, stronger spawns),
 * periodic enemy waves, boss every 3 levels, and the player's Best score.
 * Set this as the GameMode for the EchoHearts level, and place/spawn
 * AEchoHeartsCharacter as the Default Pawn.
 */
UCLASS()
class ECHOHEARTSREBIRTH_API AEchoHeartsGameMode : public AGameModeBase
{
	GENERATED_BODY()

public:
	AEchoHeartsGameMode();

	virtual void Tick(float DeltaSeconds) override;

	UPROPERTY(BlueprintReadOnly, Category = "EchoHearts|World")
	float DayLengthSeconds = 120.f;

	UPROPERTY(BlueprintReadOnly, Category = "EchoHearts|World")
	bool bIsNight = false;

	UPROPERTY(BlueprintReadOnly, Category = "EchoHearts|World")
	int32 Level = 1;

	UPROPERTY(BlueprintReadOnly, Category = "EchoHearts|World")
	int32 BestScore = 0;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "EchoHearts|World")
	TSubclassOf<AEchoHeartsEnemy> EnemyClass;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "EchoHearts|World")
	TSubclassOf<AEchoHeartsBoss> BossClass;

	UFUNCTION(BlueprintCallable, Category = "EchoHearts|World")
	void SummonBoss();

protected:
	virtual void BeginPlay() override;

private:
	float WorldTime = 0.f;
	float SpawnTimer = 0.f;
	bool bBossSpawnedThisLevel = false;
	void SpawnWaveEnemy();
};

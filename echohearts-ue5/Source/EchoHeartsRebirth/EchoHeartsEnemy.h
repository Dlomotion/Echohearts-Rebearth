#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "EchoHeartsEnemy.generated.h"

UENUM(BlueprintType)
enum class EEchoEnemyKind : uint8 { Imp, Monster, Boss };

/**
 * Base enemy. Kinds:
 *  Imp     — mischievous: fast, darts around, 20 HP / 12 contact damage
 *  Monster — void monster: steady chase, 60 HP / 20 damage / 2 defence
 *  Boss    — see AEchoHeartsBoss (subclass): 600+ HP, enrage, Rebirth on defeat
 * Movement is a simple Tick chase of the nearest player — no NavMesh or
 * Behaviour Tree needed, so it works in any test level.
 */
UCLASS()
class ECHOHEARTSREBIRTH_API AEchoHeartsEnemy : public ACharacter
{
	GENERATED_BODY()

public:
	AEchoHeartsEnemy();

	virtual void Tick(float DeltaSeconds) override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "EchoHearts")
	EEchoEnemyKind Kind = EEchoEnemyKind::Monster;

	UPROPERTY(BlueprintReadOnly, Category = "EchoHearts|Stats")
	float HP = 60.f;

	UPROPERTY(BlueprintReadOnly, Category = "EchoHearts|Stats")
	float MaxHP = 60.f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "EchoHearts|Stats")
	float ContactDamage = 20.f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "EchoHearts|Stats")
	int32 Defence = 2;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "EchoHearts|Stats")
	float KnockbackResist = 0.5f; // 0 = full knockback, 1 = immune (boss: 0.95)

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "EchoHearts|Stats")
	int32 ScoreValue = 25;

	/** Apply an Echo Pulse/Burst hit: defence, crit, knockback, death + drops. Returns damage dealt. */
	UFUNCTION(BlueprintCallable, Category = "EchoHearts|Combat")
	virtual float ApplyEchoHit(float RawDamage, bool bCrit, FVector ShotDirection);

	UFUNCTION(BlueprintCallable, Category = "EchoHearts")
	void SetupForKind(EEchoEnemyKind InKind, int32 Level = 1, bool bNight = false);

protected:
	virtual void BeginPlay() override;
	virtual void OnDeath();
	void MaybeDropPickup() const;

	float TouchCooldown = 0.f;
};

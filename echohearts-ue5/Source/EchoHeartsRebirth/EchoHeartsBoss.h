#pragma once

#include "CoreMinimal.h"
#include "EchoHeartsEnemy.h"
#include "EchoHeartsBoss.generated.h"

class AEchoHeartsProjectile;

/**
 * The Heartbreaker boss.
 * Rules: "Heartbreaker has awoken!" on spawn, HP bar data for the HUD,
 * ranged void-orb attacks, spawns imps, ENRAGES below 25% HP,
 * and on defeat grants the player Rebirth (+20 Max HP, +1 defence step is
 * tracked in the GameMode in this C++ version, +200 score).
 */
UCLASS()
class ECHOHEARTSREBIRTH_API AEchoHeartsBoss : public AEchoHeartsEnemy
{
	GENERATED_BODY()

public:
	AEchoHeartsBoss();

	virtual void Tick(float DeltaSeconds) override;
	virtual float ApplyEchoHit(float RawDamage, bool bCrit, FVector ShotDirection) override;

	UPROPERTY(BlueprintReadOnly, Category = "EchoHearts|Boss")
	bool bEnraged = false;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "EchoHearts|Boss")
	TSubclassOf<AEchoHeartsProjectile> OrbClass;

	/** 0..1 for a boss HP bar widget. */
	UFUNCTION(BlueprintCallable, Category = "EchoHearts|Boss")
	float BossHealthPercent() const { return MaxHP > 0.f ? FMath::Clamp(HP / MaxHP, 0.f, 1.f) : 0.f; }

protected:
	virtual void BeginPlay() override;
	virtual void OnDeath() override;

private:
	float OrbTimer = 0.f;
	float MinionTimer = 0.f;
};

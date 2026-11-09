#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "EchoHeartsCharacter.generated.h"

class USpringArmComponent;
class UCameraComponent;
class AEchoHeartsProjectile;
class UInputMappingContext;
class UInputAction;
struct FInputActionValue;

/** The player: a heart-bearer with Terraria-style HP/mana, i-frames, and Echo Pulse attacks. */
UCLASS()
class ECHOHEARTSREBIRTH_API AEchoHeartsCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	AEchoHeartsCharacter();

	virtual void Tick(float DeltaSeconds) override;
	virtual void SetupPlayerInputComponent(UInputComponent* PlayerInputComponent) override;
	virtual float TakeDamage(float DamageAmount, const FDamageEvent& DamageEvent, AController* EventInstigator, AActor* DamageCauser) override;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "EchoHearts")
	TObjectPtr<USpringArmComponent> CameraBoom;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "EchoHearts")
	TObjectPtr<UCameraComponent> FollowCamera;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "EchoHearts|Combat")
	TSubclassOf<AEchoHeartsProjectile> ProjectileClass;

	// Enhanced Input (UE 5.8 path): assign the IMC + actions described in
	// Content/README.md in a Blueprint child. If none are assigned, the
	// legacy axis/action bindings in DefaultInput.ini are used instead.
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "EchoHearts|Input")
	TObjectPtr<UInputMappingContext> DefaultMappingContext;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "EchoHearts|Input")
	TObjectPtr<UInputAction> MoveAction;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "EchoHearts|Input")
	TObjectPtr<UInputAction> LookAction;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "EchoHearts|Input")
	TObjectPtr<UInputAction> JumpAction;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "EchoHearts|Input")
	TObjectPtr<UInputAction> FireAction;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "EchoHearts|Input")
	TObjectPtr<UInputAction> BurstAction;

	UPROPERTY(BlueprintReadOnly, Category = "EchoHearts|Stats")
	float HP = 100.f;

	UPROPERTY(BlueprintReadOnly, Category = "EchoHearts|Stats")
	float MaxHP = 100.f;

	UPROPERTY(BlueprintReadOnly, Category = "EchoHearts|Stats")
	float Mana = 100.f;

	UPROPERTY(BlueprintReadOnly, Category = "EchoHearts|Stats")
	int32 Score = 0;

	UPROPERTY(BlueprintReadOnly, Category = "EchoHearts|Stats")
	int32 HeartsCollected = 0;

	UFUNCTION(BlueprintCallable, Category = "EchoHearts|Combat")
	void FirePulse();

	UFUNCTION(BlueprintCallable, Category = "EchoHearts|Combat")
	void FireBurst();

	UFUNCTION(BlueprintCallable, Category = "EchoHearts|Stats")
	void AddHeartPickup();

	UFUNCTION(BlueprintCallable, Category = "EchoHearts|Stats")
	void AddStarPickup();

protected:
	virtual void BeginPlay() override;

	void MoveForward(float Value);
	void MoveRight(float Value);
	void MoveEnhanced(const FInputActionValue& Value);
	void LookEnhanced(const FInputActionValue& Value);

private:
	float IFramesRemaining = 0.f;
	float SinceHitSeconds = 999.f;
	float FireCooldown = 0.f;
};

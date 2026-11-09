// Copyright EchoHearts Rebirth. MIT License.
#include "EchoHeartsCharacter.h"
#include "EchoHeartsProjectile.h"
#include "EchoHeartsStats.h"
#include "Camera/CameraComponent.h"
#include "Components/CapsuleComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "Engine/World.h"

AEchoHeartsCharacter::AEchoHeartsCharacter()
{
	PrimaryActorTick.bCanEverTick = true;
	GetCapsuleComponent()->InitCapsuleSize(42.f, 96.f);
	bUseControllerRotationYaw = false;

	CameraBoom = CreateDefaultSubobject<USpringArmComponent>(TEXT("CameraBoom"));
	CameraBoom->SetupAttachment(RootComponent);
	CameraBoom->TargetArmLength = 650.f;
	CameraBoom->bUsePawnControlRotation = true;

	FollowCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("FollowCamera"));
	FollowCamera->SetupAttachment(CameraBoom, USpringArmComponent::SocketName);
	FollowCamera->bUsePawnControlRotation = false;

	GetCharacterMovement()->bOrientRotationToMovement = true;
	GetCharacterMovement()->JumpZVelocity = 700.f;
	GetCharacterMovement()->AirControl = 0.35f;
	GetCharacterMovement()->MaxWalkSpeed = 520.f;
}

void AEchoHeartsCharacter::BeginPlay()
{
	Super::BeginPlay();
	HP = MaxHP = EchoHeartsStats::PlayerMaxHP;
	Mana = EchoHeartsStats::PlayerMaxMana;
}

void AEchoHeartsCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	PlayerInputComponent->BindAxis(TEXT("MoveForward"), this, &AEchoHeartsCharacter::MoveForward);
	PlayerInputComponent->BindAxis(TEXT("MoveRight"), this, &AEchoHeartsCharacter::MoveRight);
	PlayerInputComponent->BindAxis(TEXT("Turn"), this, &APawn::AddControllerYawInput);
	PlayerInputComponent->BindAxis(TEXT("LookUp"), this, &APawn::AddControllerPitchInput);
	PlayerInputComponent->BindAction(TEXT("Jump"), IE_Pressed, this, &ACharacter::Jump);
	PlayerInputComponent->BindAction(TEXT("Jump"), IE_Released, this, &ACharacter::StopJumping);
	PlayerInputComponent->BindAction(TEXT("Fire"), IE_Pressed, this, &AEchoHeartsCharacter::FirePulse);
	PlayerInputComponent->BindAction(TEXT("Burst"), IE_Pressed, this, &AEchoHeartsCharacter::FireBurst);
}

void AEchoHeartsCharacter::MoveForward(float Value)
{
	if (Controller && Value != 0.f)
	{
		const FRotator YawRot(0.f, Controller->GetControlRotation().Yaw, 0.f);
		AddMovementInput(FRotationMatrix(YawRot).GetUnitAxis(EAxis::X), Value);
	}
}

void AEchoHeartsCharacter::MoveRight(float Value)
{
	if (Controller && Value != 0.f)
	{
		const FRotator YawRot(0.f, Controller->GetControlRotation().Yaw, 0.f);
		AddMovementInput(FRotationMatrix(YawRot).GetUnitAxis(EAxis::Y), Value);
	}
}

void AEchoHeartsCharacter::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);
	if (IFramesRemaining > 0.f) IFramesRemaining -= DeltaSeconds;
	if (FireCooldown > 0.f) FireCooldown -= DeltaSeconds;
	SinceHitSeconds += DeltaSeconds;

	// Terraria rule: mana regens faster when standing still; HP regens slowly after 5s without a hit.
	const bool bMoving = GetVelocity().SizeSquared2D() > 100.f;
	Mana = FMath::Min(EchoHeartsStats::PlayerMaxMana, Mana + (bMoving ? 0.25f : 0.6f) * DeltaSeconds * 10.f);
	if (SinceHitSeconds > 5.f) HP = FMath::Min(MaxHP, HP + 0.5f * DeltaSeconds);
}

float AEchoHeartsCharacter::TakeDamage(float DamageAmount, const FDamageEvent& DamageEvent, AController* EventInstigator, AActor* DamageCauser)
{
	// Terraria rule: contact damage is ignored entirely during i-frames.
	if (IFramesRemaining > 0.f || HP <= 0.f) return 0.f;

	const float Dealt = EchoHeartsStats::DamageAfterDefence(DamageAmount, EchoHeartsStats::PlayerDefence, false);
	HP -= Dealt;
	IFramesRemaining = EchoHeartsStats::InvincibilitySeconds;
	SinceHitSeconds = 0.f;

	if (HP <= 0.f && GetWorld())
	{
		// "You were slain..." — the GameMode restarts the level; Best score is kept there.
		UE_LOG(LogTemp, Display, TEXT("EchoHearts: You were slain... Score %d"), Score);
		GetWorld()->GetAuthGameMode()->RestartPlayer(GetController());
		HP = MaxHP;
	}
	return Dealt;
}

void AEchoHeartsCharacter::FirePulse()
{
	if (!ProjectileClass || FireCooldown > 0.f || !GetWorld()) return;
	FireCooldown = EchoHeartsStats::PulseDamage > 0 ? 0.27f : 0.27f; // use time, like Terraria

	const FVector Spawn = GetActorLocation() + GetActorForwardVector() * 90.f + FVector(0, 0, 40);
	AEchoHeartsProjectile* P = GetWorld()->SpawnActor<AEchoHeartsProjectile>(ProjectileClass, Spawn, GetActorRotation());
	if (P) P->Init(GetActorForwardVector(), EchoHeartsStats::PulseDamage, false, this);
}

void AEchoHeartsCharacter::FireBurst()
{
	if (!ProjectileClass || !GetWorld() || Mana < EchoHeartsStats::BurstManaCost) return;
	Mana -= EchoHeartsStats::BurstManaCost;

	const FVector Spawn = GetActorLocation() + GetActorForwardVector() * 90.f + FVector(0, 0, 40);
	AEchoHeartsProjectile* P = GetWorld()->SpawnActor<AEchoHeartsProjectile>(ProjectileClass, Spawn, GetActorRotation());
	if (P) P->Init(GetActorForwardVector(), EchoHeartsStats::BurstDamage, true, this);
}

void AEchoHeartsCharacter::AddHeartPickup()
{
	HeartsCollected++;
	Score += 10;
	HP = FMath::Min(MaxHP, HP + 5.f);
}

void AEchoHeartsCharacter::AddStarPickup()
{
	Mana = FMath::Min(EchoHeartsStats::PlayerMaxMana, Mana + EchoHeartsStats::StarMana);
}

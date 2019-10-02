// Fill out your copyright notice in the Description page of Project Settings.

#include "FPCharacter.h"
#include "Components/InputComponent.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "GameFramework/PawnMovementComponent.h"
#include "DrawDebugHelpers.h"
#include "Public/CollisionQueryParams.h"
#include "Engine/World.h"
#include "Public/FPProjectile.h"
#include "Kismet/GameplayStatics.h"
#include "FPS_Project/Public/FPWeapon.h"


// Sets default values
AFPCharacter::AFPCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	/*SpringArmComp = CreateDefaultSubobject<USpringArmComponent>(TEXT("SpringArmComp"));
	SpringArmComp->bUsePawnControlRotation = true;
	SpringArmComp->SetupAttachment(RootComponent);
	*/
	GetMovementComponent()->GetNavAgentPropertiesRef().bCanCrouch = true;



	/*CameraComp = CreateDefaultSubobject<UCameraComponent>(TEXT("CameraComp"));
	CameraComp->SetupAttachment(SpringArmComp);
	*/
	aimFOV = 65.f;
	AimSpeed = 20;
	//defaultFOV = CameraComp->FieldOfView;

}

// Called when the game starts or when spawned
void AFPCharacter::BeginPlay()
{
	Super::BeginPlay();

	//defaultFOV = CameraComp->FieldOfView;
}

// Called every frame
void AFPCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	float TargetFOV = wantsToAim ? aimFOV : defaultFOV;

	/*float NewFOV = FMath::FInterpTo(CameraComp->FieldOfView, TargetFOV, DeltaTime, AimSpeed);
	CameraComp->SetFieldOfView(NewFOV);*/
	
}

// Called to bind functionality to input
void AFPCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	/*PlayerInputComponent->BindAxis("MoveForward", this, &AFPCharacter::MoveForward);
	PlayerInputComponent->BindAxis("MoveRight", this, &AFPCharacter::MoveRight);
	PlayerInputComponent->BindAxis("LookUp", this, &AFPCharacter::AddControllerPitchInput);
	PlayerInputComponent->BindAxis("LookSides", this, &AFPCharacter::AddControllerYawInput);

	
	PlayerInputComponent->BindAction("Jump", IE_Pressed, this, &ACharacter::Jump);*/
	PlayerInputComponent->BindAction("Fire", IE_Pressed, this, &AFPCharacter::StartFire);
	PlayerInputComponent->BindAction("Fire", IE_Released, this, &AFPCharacter::StopFire);
	//PlayerInputComponent->BindAction("Reload", IE_Pressed, this, &AFPCharacter::Reload);
	/*PlayerInputComponent->BindAction("Aiming", IE_Pressed, this, &AFPCharacter::StartAim);
	PlayerInputComponent->BindAction("Aiming", IE_Released, this, &AFPCharacter::EndAim);*/
}

void AFPCharacter::MoveForward(float delta)
{
	AddMovementInput(GetActorForwardVector() * delta);

}


void AFPCharacter::MoveRight(float delta)
{
	AddMovementInput(GetActorRightVector() * delta);

}
void AFPCharacter::StartAim()
{
	wantsToAim = true;

}

void AFPCharacter::EndAim()
{
	wantsToAim = false;

}

FVector AFPCharacter::GetPawnViewLocation() const
{
	/*if (CameraComp) {
		return CameraComp->GetComponentLocation();
	}*/

	return Super::GetPawnViewLocation();
}



void AFPCharacter::StartFire()
{
	if (Weapon && allowFire) {
		Weapon->StartFire();
	}
}
void AFPCharacter::StopFire()
{
	if (Weapon) {
		Weapon->StopFire();
	}
}

void AFPCharacter::Reload()
{
	if (Weapon) {
		Weapon->Reload();
	}
}


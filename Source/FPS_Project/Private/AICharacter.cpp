// Fill out your copyright notice in the Description page of Project Settings.

#include "AICharacter.h"
#include "GameFramework/CharacterMovementComponent.h"

AAICharacter::AAICharacter()
{
	GetCharacterMovement()->bOrientRotationToMovement = true;	
	GetCharacterMovement()->RotationRate = FRotator(0.0f, 600.0f, 0.0f);

}

void AAICharacter::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void AAICharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

// Called to bind functionality to input
void AAICharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
}

void AAICharacter::MoveForward(float delta)
{
	//AddMovementInput(GetActorForwardVector() * delta);
	Super::MoveForward(delta);
}


void AAICharacter::MoveRight(float delta)
{
    Super::MoveRight(delta);
}
void AAICharacter::StartAim()
{
	Super::StartAim();

}

void AAICharacter::EndAim()
{
	Super::EndAim();

}



FVector AAICharacter::GetPawnViewLocation() const
{
   return Super::GetPawnViewLocation();
}



void AAICharacter::StartFire()
{
	Super::StartFire();
}
void AAICharacter::StopFire()
{
	Super::StopFire();
}

void AAICharacter::Reload()
{
	Super::Reload();
}
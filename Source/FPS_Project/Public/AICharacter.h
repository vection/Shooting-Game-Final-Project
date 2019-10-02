// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "FPCharacter.h"
#include "AICharacter.generated.h"

/**
 * 
 */
UCLASS()
class FPS_PROJECT_API AAICharacter : public AFPCharacter
{
	GENERATED_BODY()
	
public: 
	AAICharacter();
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	virtual FVector GetPawnViewLocation() const override;



protected:
	virtual void BeginPlay();

	void MoveForward(float delta);

	void MoveRight(float delta);
	void StartAim();
	void EndAim();
	void StartFire();
	void StopFire();
	void Reload();
	
};

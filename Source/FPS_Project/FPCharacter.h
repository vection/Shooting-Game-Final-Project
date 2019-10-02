// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "FPCharacter.generated.h"


class AFPWeapon;
class UCameraComponent;
class USpringArmComponent;


UCLASS()
class FPS_PROJECT_API AFPCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AFPCharacter();

	void MoveForward(float delta);
	void MoveRight(float delta);

	UFUNCTION(BlueprintCallable, Category = "Functions")
	   void StartAim();

	UFUNCTION(BlueprintCallable, Category = "Functions")
	   void EndAim();

	UFUNCTION(BlueprintCallable, Category = "Functions")
	   void StartFire();

	UFUNCTION(BlueprintCallable, Category = "Functions")
	   void StopFire();

	void Reload();

public:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category ="Player")
	bool wantsToAim;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Player")
	float TargetFOV;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Player")
	float aimFOV;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly,Category = "Player", meta = (ClampMin = 0.1, ClampMax = 100))
	float AimSpeed;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Player")
	float defaultFOV;

	UPROPERTY(BlueprintReadWrite, Category = "Player")
	bool allowFire;

	UPROPERTY(BlueprintReadWrite, Category = "Player")
	bool isHoldingWeapon;

	UPROPERTY(BlueprintReadWrite, Category = "Player")
	bool isDead;





	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Components")
	UCameraComponent * CameraComp;

	// Gun muzzle's offset from the camera location.
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Gameplay)
	FVector MuzzleOffset;

	UPROPERTY(EditDefaultsOnly, Category = Projectile)
	TSubclassOf<class AFPProjectile> ProjectileClass;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Components")
	class AFPWeapon* Weapon;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Components")
	class AFPWeapon* SecondWeapon;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	virtual FVector GetPawnViewLocation() const override;


	//void AttachGun(AFPWeapon Gun);
};

// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "FPS_ProjectGameModeBase.h"
#include "FPCharacter.h"
#include "FPWeapon.generated.h"

class USkeletalMeshComponent;
class UStaticMeshComponent;
class UParticalSystem;
class UAnimMontage;
class UDamageType;




UCLASS()
class FPS_PROJECT_API AFPWeapon : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AFPWeapon();

protected:

	virtual void BeginPlay() override;
	UPROPERTY(VisibleAnyWhere, BlueprintReadOnly, Category="Components")
	USkeletalMeshComponent * MeshComp; // 

	UPROPERTY(VisibleAnyWhere, BlueprintReadOnly, Category = "Components")
	USceneComponent * Mesh; // Body

	UPROPERTY(VisibleAnyWhere, BlueprintReadOnly, Category = "Components")
	UStaticMeshComponent * WeaponMesh;

	UPROPERTY(VisibleAnyWhere, BlueprintReadOnly, Category = "Components")
	UStaticMeshComponent * Flash;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Components")
	UStaticMeshComponent * Mag;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Components")
	UStaticMeshComponent * LeftHand;

	UPROPERTY(VisibleDefaultsOnly, BlueprintReadOnly, Category = "Weapon")
	int weaponIndex;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Effects")
	UParticleSystem * MuzzleEffect;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Effects")
	UParticleSystem * DefaultImpactEffect;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Effects")
	UParticleSystem * FleshImpactEffect;


	UPROPERTY(EditDefaultsOnly, Category = "Weapon")
	float BaseDamage;


	UPROPERTY(VisibleDefaultsOnly, BlueprintReadOnly, Category = "Weapon")
	FName MuzzleSocketName;

	FVector MuzzleLocation;
	FRotator MuzzleRotation;
	FVector LeftHandLocation;

	UFUNCTION(BlueprintCallable, Category = "Weapon")
	void Fire();


	FTimerHandle Delay_TimeBetweenShots;

	UPROPERTY(EditDefaultsOnly, Category = "Weapon")
	float FireRate;

	float LastFire;
	float TimeBetweenShots;


	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Sounds")
	UAudioComponent * soundComponent;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Sounds")
	USoundBase * FireSound;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Sounds")
	USoundBase* MagReleasedSound;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Sounds")
	USoundBase* MagInsideSound;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Sounds")
	USoundBase* ReloadingSound;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Attachments")
	UStaticMeshComponent * Grip;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Attachments")
	UStaticMeshComponent * Scope;

	UPROPERTY(EditDefaultsOnly, Category ="Weapon", meta = (ClampMin = 1.0, ClampMax = 3.0))
	int weaponStatus;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Animations")
	UAnimMontage * ReloadAnimation;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Animations")
	UAnimMontage * FireAnimation;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Animations")
	UAnimMontage * CrouchReloadAnimation;

	UPROPERTY(BlueprintReadWrite, Category = "Weapon")
	bool isReloading;

	UPROPERTY(EditDefaultsOnly,BlueprintReadWrite, Category = "Weapon")
	WeaponType weaponType;

	AFPCharacter * mOwner;

public:	

	FVector GetHiderVector();
	FRotator GetHiderRotator();

	UFUNCTION(BlueprintCallable, Category = "Functions")
	FVector GetLeftHandVector();

	void ShowMuzzleEffect();

	UFUNCTION(BlueprintCallable, Category = "Functions")
	UStaticMeshComponent* getMag();
	UFUNCTION(BlueprintCallable, Category = "Functions")
	void StartFire();
	void StopFire();

	void Reload();


	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Weapon")
	TSubclassOf<UDamageType> DamageType;

	UPROPERTY(EditDefaultsOnly, Category = "Weapon")
	TSubclassOf<UCameraShake> FireShake;
	
	UPROPERTY(VisibleAnyWhere, BlueprintReadOnly, Category = "Weapon")
	bool isFiring;

	UPROPERTY(EditDefaultsOnly, Category = "Weapon")
	int bulletsInMag;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Weapon")
	int currentBullets;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Animations")
	UStaticMeshComponent * MagComponent;

	UPROPERTY(EditDefaultsOnly, Category = "Weapon")
	TSubclassOf<AFPProjectile> ProjectileClass;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Sight")
	TSubclassOf <UClass> SightClass;




};

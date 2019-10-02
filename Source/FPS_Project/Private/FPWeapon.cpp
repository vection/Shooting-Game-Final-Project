// Fill out your copyright notice in the Description page of Project Settings.


#include "Public/FPWeapon.h"
#include "DrawDebugHelpers.h"
#include "Components/SkeletalMeshComponent.h"
#include "Kismet/GameplayStatics.h"
#include "Components/StaticMeshComponent.h"
#include "Camera/CameraComponent.h"
#include "PhysicalMaterials/PhysicalMaterial.h"
#include "TimerManager.h" 


// Sets default values
AFPWeapon::AFPWeapon()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	Mesh = CreateDefaultSubobject<USceneComponent>(TEXT("Mesh"));
	MeshComp = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("MeshComp"));
	RootComponent = Mesh;


	MeshComp->SetupAttachment(RootComponent);

	Flash = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Flash"));
	Flash->SetupAttachment(MeshComp);
	Flash->SetWorldLocation(MuzzleLocation);

	Mag = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mag"));
	Mag->SetupAttachment(MeshComp);

	LeftHand = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("LeftHandSpot"));
	LeftHand->SetupAttachment(MeshComp);

	Grip = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Grip"));
	Grip->SetupAttachment(MeshComp);

	Scope = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Scope"));
	Scope->SetupAttachment(MeshComp);


	MuzzleSocketName = "Muzzle";
	BaseDamage = 20.0f;
	FireRate = 3.0f;
	bulletsInMag = 30;
	currentBullets = 0;
}



void AFPWeapon::BeginPlay()
{
	Super::BeginPlay();

	TimeBetweenShots = 60/FireRate;
}

void AFPWeapon::Fire()
{
	UE_LOG(LogTemp, Warning, TEXT("Start Shooting"));
	AActor* MyOwner = GetOwner();
	// Attempt to fire a projectile.
	if (MyOwner) {
		// Get the camera transform.
		FVector CameraLocation;
		FRotator CameraRotation;
		MyOwner->GetActorEyesViewPoint(CameraLocation, CameraRotation);
		// Transform MuzzleOffset from camera space to world space.
		//FVector MuzzleLocation = CameraLocation + FTransform(CameraRotation).TransformVector(MuzzleOffset);
		FVector MuzzleLocation = GetHiderVector();
		FRotator MuzzleRotation = GetHiderRotator();
		FRotator ScopeRotator = Scope->GetComponentRotation();
		FVector TraceEnd = MuzzleLocation + (ScopeRotator.Vector() * 10000);

		FCollisionQueryParams QueryParms;
		QueryParms.AddIgnoredActor(MyOwner);
		QueryParms.AddIgnoredActor(this);
		QueryParms.bReturnPhysicalMaterial = true;
		QueryParms.bTraceComplex = true;

		FHitResult Hit;
		AFPCharacter* Actor = Cast<AFPCharacter>(MyOwner);
		if (Actor)
		{
			APlayerController* p = Cast<APlayerController>(Actor->GetController());
			if (p)
			{
				p->ClientPlayCameraShake(FireShake);
			}
			//mOwner = Cast<AFPCharacter>(Actor);

		}
		if (GetWorld()->LineTraceSingleByChannel(Hit, MuzzleLocation, TraceEnd, COLLISION_WEAPON))
		{
			AActor* HitActor = Hit.GetActor();



			EPhysicalSurface Surfacetype = UPhysicalMaterial::DetermineSurfaceType(Hit.PhysMaterial.Get());

			float ActualDamage = BaseDamage;
			if (Surfacetype == SurfaceType1) {
				ActualDamage *= 3.0f;
			}
			UGameplayStatics::ApplyPointDamage(HitActor, ActualDamage, MuzzleLocation, Hit, MyOwner->GetInstigatorController(), this, DamageType);
			UGameplayStatics::SpawnEmitterAtLocation(GetWorld(), DefaultImpactEffect, Hit.ImpactPoint, Hit.ImpactNormal.Rotation());
			switch (Surfacetype) {
			      case SurfaceType1:
					  UGameplayStatics::SpawnEmitterAtLocation(GetWorld(), DefaultImpactEffect, Hit.ImpactPoint, Hit.ImpactNormal.Rotation());
					  break;
				  case SurfaceType2:
					  UGameplayStatics::SpawnEmitterAtLocation(GetWorld(), DefaultImpactEffect, Hit.ImpactPoint, Hit.ImpactNormal.Rotation());
					  break;
			}

		}
		//DrawDebugLine(GetWorld(), MuzzleLocation, TraceEnd, FColor::White, false, 1.0f, 0, 1.0f);
		if (MuzzleEffect) {
			UGameplayStatics::SpawnEmitterAttached(MuzzleEffect, MeshComp, MuzzleSocketName);
		}
		LastFire = GetWorld()->TimeSeconds;
		
	}
	UE_LOG(LogTemp, Warning, TEXT("FINUSHED Shooting"));

}

FVector AFPWeapon::GetHiderVector()
{
	//MuzzleLocation = MeshComp->GetSocketLocation("MuzzleFlashSocket");
	MuzzleLocation = Flash->GetComponentLocation();
	return MuzzleLocation;

}

FRotator AFPWeapon::GetHiderRotator()
{
	MuzzleRotation = Flash->GetComponentRotation();
	return MuzzleRotation;

}

FVector AFPWeapon::GetLeftHandVector()
{
	LeftHandLocation = LeftHand->GetComponentLocation();
	return LeftHandLocation;
}

void AFPWeapon::ShowMuzzleEffect()
{
	UGameplayStatics::SpawnEmitterAttached(MuzzleEffect, MeshComp, "MuzzleFlashSocket");
}

void AFPWeapon::StartFire()
{
	isFiring = true;
	float Delay = FMath::Max(LastFire + TimeBetweenShots - GetWorld()->TimeSeconds, 0.0f);

	GetWorldTimerManager().SetTimer(Delay_TimeBetweenShots, this, &AFPWeapon::Fire, TimeBetweenShots, true, Delay);


}

void AFPWeapon::StopFire()
{
	isFiring = false;
	GetWorldTimerManager().ClearTimer(Delay_TimeBetweenShots);
}

void AFPWeapon::Reload()
{
	isReloading = true;
}

UStaticMeshComponent* AFPWeapon::getMag()
{
		return Mag;
}






// Fill out your copyright notice in the Description page of Project Settings.

#include "Public/HealthComponenet.h"
#include "FPCharacter.h"


// Sets default values for this component's properties
UHealthComponenet::UHealthComponenet()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;
	DefaultHealth = 100;

	// ...
}


// Called when the game starts
void UHealthComponenet::BeginPlay()
{
	Super::BeginPlay();


	AActor* MyOwner = GetOwner();
	if (MyOwner) {
		MyOwner->OnTakeAnyDamage.AddDynamic(this, &UHealthComponenet::HandleAnyDamageTaken);
	}

	Health = DefaultHealth;
	
}

void UHealthComponenet::HandleAnyDamageTaken(AActor * DamagedActor, float Damage, const UDamageType * DamageType, AController * InstigatedBy, AActor * DamageCauser)
{
	if (Damage <= 0.0) {
		return;
	}
	Health = FMath::Clamp(Health - Damage, 0.0f, DefaultHealth);	
	UE_LOG(LogTemp, Log, TEXT("Health Changed:  %s"), *FString::SanitizeFloat(Health));
}


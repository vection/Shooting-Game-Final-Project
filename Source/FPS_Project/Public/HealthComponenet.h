// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "HealthComponenet.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class FPS_PROJECT_API UHealthComponenet : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UHealthComponenet();


protected:
	// Called when the game starts
	virtual void BeginPlay() override;

	UPROPERTY(BlueprintReadOnly, Category ="Health Component")
	float Health;

	UPROPERTY(EditAnyWhere, BlueprintReadWrite, Category = "Health Component")
	float DefaultHealth;

	UFUNCTION()
	void HandleAnyDamageTaken(AActor* DamagedActor, float Damage, const class UDamageType* DamageType, class AController* InstigatedBy, AActor* DamageCauser);

		
	
};

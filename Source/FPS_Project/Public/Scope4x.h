// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "FPWeapon.h"
#include "Scope4x.generated.h"

UCLASS()
class FPS_PROJECT_API AScope4x : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AScope4x();

	UPROPERTY(VisibleAnyWhere, BlueprintReadOnly, Category = "Components")
		USceneComponent * Mesh;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Components")
	UCameraComponent * CameraComp;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Components")
	USpringArmComponent * SpringArmComp;

	UPROPERTY(VisibleAnyWhere, BlueprintReadOnly, Category = "Components")
	USkeletalMeshComponent * MeshComp;
		
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Components")
		UStaticMeshComponent * ScopeMesh;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Components")
		UStaticMeshComponent * PlaneView;
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	
	
};

// Fill out your copyright notice in the Description page of Project Settings.

#include "FPS_Project/Public/Scope4x.h"
#include "Components/SkeletalMeshComponent.h"
#include "Kismet/GameplayStatics.h"
#include "Components/StaticMeshComponent.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/SpringArmComponent.h"

// Sets default values
AScope4x::AScope4x()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Mesh = CreateDefaultSubobject<USceneComponent>(TEXT("Mesh"));
	RootComponent = Mesh;
	MeshComp = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("MeshComp"));
	MeshComp->SetupAttachment(RootComponent);

	ScopeMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("ScopeMesh"));
	ScopeMesh->SetupAttachment(MeshComp);

	PlaneView = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("PlaneView"));
	PlaneView->SetupAttachment(MeshComp);

	SpringArmComp = CreateDefaultSubobject<USpringArmComponent>(TEXT("SpringArmComp"));
	SpringArmComp->bUsePawnControlRotation = true;
	SpringArmComp->SetupAttachment(MeshComp);

	CameraComp = CreateDefaultSubobject<UCameraComponent>(TEXT("CameraComp"));
	CameraComp->SetupAttachment(SpringArmComp);

}

// Called when the game starts or when spawned
void AScope4x::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AScope4x::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}


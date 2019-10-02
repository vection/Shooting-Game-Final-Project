// Fill out your copyright notice in the Description page of Project Settings.

#include "MyAIController.h"
#include "Perception/AISense_Sight.h"
#include "Perception/AIPerceptionComponent.h"
#include "Perception/AISense.h"
#include "TimerManager.h"
#include "Engine/World.h"
#include "FPCharacter.h"
#include "Runtime/Engine/Classes/GameFramework/Actor.h"
#include "Runtime/Engine/Classes/Kismet/GameplayStatics.h"
#include "EnvironmentQuery/EnvQueryManager.h"
#include "Perception/AISenseConfig_Sight.h"


AMyAIController::AMyAIController() {

	PrimaryActorTick.bCanEverTick = true;
	SightConfig = CreateDefaultSubobject<UAISenseConfig_Sight>(TEXT("Sight Config"));
	PerceptionComponent = CreateDefaultSubobject<UAIPerceptionComponent>(TEXT("Perception Component"));
	
	SightConfig->SightRadius = AISightRadius;
	SightConfig->LoseSightRadius = AILoseSightRadius;
	SightConfig->PeripheralVisionAngleDegrees = AIFieldOfView;
	SightConfig->SetMaxAge(AISightAge);

	SightConfig->DetectionByAffiliation.bDetectEnemies = true;
	SightConfig->DetectionByAffiliation.bDetectFriendlies = true;
	SightConfig->DetectionByAffiliation.bDetectNeutrals = true;

	PerceptionComponent->SetDominantSense(*SightConfig->GetSenseImplementation());
	PerceptionComponent->OnPerceptionUpdated.AddDynamic(this, &AMyAIController::OnPawnDetected);
	PerceptionComponent->ConfigureSense(*SightConfig);
	
	
	mCharacter = Cast<AFPCharacter>(GetCharacter());
}

void AMyAIController::BeginPlay() {
	Super::BeginPlay();

	if (PerceptionComponent != nullptr) {
		UE_LOG(LogTemp, Warning, TEXT("All Systems Set"));
	}
	else {
		UE_LOG(LogTemp, Warning, TEXT("There is problem with loading the system."));
	}
}

void AMyAIController::Tick(float deltaTime) {
	Super::Tick(deltaTime);
	FocalPoint = Blackboard->GetValueAsVector(FName("Enemy"));
	if (DistanceToPlayer > AISightRadius)
	{
		isPlayerDetected = false;
	}
	if (isPlayerDetected && isFired == false) {
		//AFPCharacter * Owner = Cast<AFPCharacter>(GetCharacter());
		//Owner->StartAim();
		/*AFPCharacter * Player = Cast<AFPCharacter>(UGameplayStatics::GetPlayerCharacter(GetWorld(), 0));
		AFPCharacter * Owner = Cast<AFPCharacter>(GetCharacter());
		//MoveToActor(Player, 5.0f);
		isFired = true;
		SetFocus(Player);
		Owner->StartAim();
		Owner->StartFire();
		//UE_LOG(LogTemp, Warning, TEXT("Player %s "), *Owner->GetActorLabel());
		//Owner->StartAim();
		//Shoot();
		//GetWorldTimerManager().SetTimer(UnusedHandle, this, &AMyAIController::Shoot, 5, false);
		//Owner->AddMovementInput(FVector(1,0,0));*/
	}
}

FRotator  AMyAIController::GetControlRotation() const {
	if (GetPawn() == nullptr) {
		return FRotator(0.0f, 0.0f, 0.0f);
	}
	return FRotator(0.0f, GetPawn()->GetActorRotation().Yaw, 0.0f);
}

void AMyAIController::OnPawnDetected(const TArray<AActor*> &DetectedPawns)
{
	FVector location;
	UE_LOG(LogTemp, Error, TEXT("EnemyTarget"));
	for (int i = 0; i < DetectedPawns.Num(); i++) {
		EnemyActor = DetectedPawns[i];
		AFPCharacter* chara = Cast<AFPCharacter>(EnemyActor);
		if (chara && chara->isDead == false) {
			DistanceToPlayer = GetPawn()->GetDistanceTo(DetectedPawns[i]);
			location = DetectedPawns[i]->GetActorLocation();
			Blackboard->SetValueAsObject(FName("EnemyTarget"), EnemyActor);
			Blackboard->SetValueAsBool(FName("EnemyFound"), true);
			Blackboard->SetValueAsFloat(FName("EnemyHealth"), 100);
			Blackboard->SetValueAsVector(FName("EnemyLocation"), location);
			break;
		}
		else {
			EnemyActor = nullptr;
		}
	}
	//Blackboard->SetValueAsVector(FName("Enemy"), location);
	if (!EnemyActor) {
		Blackboard->SetValueAsBool(FName("EnemyFound"), false);
		Blackboard->SetValueAsFloat(FName("EnemyHealth"), 0);
	}



	isPlayerDetected = true;

}

void AMyAIController::Shoot() {
	AFPCharacter * Owner = Cast<AFPCharacter>(GetOwner());
	Owner->StartFire();
}
void AMyAIController::FindHidingSpot()
{
	FEnvQueryRequest HidingSpotQueryRequest = FEnvQueryRequest(FindHidingSpotEQS, GetPawn());
	HidingSpotQueryRequest.Execute(EEnvQueryRunMode::SingleResult, this, &AMyAIController::MoveToQueryResult);
}

void AMyAIController::MoveToQueryResult(TSharedPtr<FEnvQueryResult> result)
{
	if (result->IsSuccsessful()) {
		MoveToLocation(result->GetItemAsLocation(0));
	}
}
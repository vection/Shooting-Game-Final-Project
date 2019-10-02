// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "FPCharacter.h"
#include "vector"
#include "Perception/AIPerceptionTypes.h"
#include "EnvironmentQuery/EnvQueryTypes.h"
#include "BehaviorTree/BehaviorTree.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "BehaviorTree/BlackboardData.h"
#include "MyAIController.generated.h"

/**
 * 
 */
class UAISenseConfig_Sight;
class UAIPerceptionComponent;
class UEnvQuery;
using namespace std;

UCLASS()
class FPS_PROJECT_API AMyAIController : public AAIController
{
	GENERATED_BODY()

public:

	AMyAIController();


	virtual void BeginPlay() override;


	virtual void Tick(float deltaTime) override;

	virtual FRotator GetControlRotation() const override;

	AFPCharacter * mCharacter;

	UFUNCTION()
		void OnPawnDetected(const TArray<AActor*> &DetectedPawns);

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = AI)
	float AISightRadius = 5000.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = AI)
	float AISightAge = 5.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = AI)
	float AILoseSightRadius = AISightRadius + 50.f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = AI)
	float AIFieldOfView = 180.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = AI)
	UAISenseConfig_Sight* SightConfig;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = AI)
	UAIPerceptionComponent* PreceptionComponent;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = AI)
	float DistanceToPlayer;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = AI)
	bool isPlayerDetected = false;

	UPROPERTY(EditAnywhere, Category = "AI")
		UEnvQuery *FindHidingSpotEQS;

	UFUNCTION(BlueprintCallable)
		void FindHidingSpot();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = AI)
	    class UBehaviorTree* BehaviorTree;

	/*UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = AI)
		class UBlackboardData* AIBlackboard;
		*/
	void MoveToQueryResult(TSharedPtr<FEnvQueryResult> result);

	FVector FocalPoint;
	void moveRight(float delta);
	void moveForward(float delta);
	FTimerHandle UnusedHandle;
	void Shoot();
	bool isFired = false;

	AActor * EnemyActor;

	UPROPERTY(VisibleAnyWhere, BlueprintReadWrite, Category = AI)
		FVector EnemyLocation;
};

// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "FPS_ProjectGameModeBase.generated.h"



#define COLLISION_WEAPON ECC_GameTraceChannel1
/**
 * 
 */
UCLASS()
class FPS_PROJECT_API AFPS_ProjectGameModeBase : public AGameModeBase
{
	GENERATED_BODY()
	
	
	
	
};

UENUM(BlueprintType)
enum class WeaponType : uint8
{
	Rifile 	UMETA(DisplayName = "Rifile"),
	Pistol 	UMETA(DisplayName = "Pistol"),
	Sniper	UMETA(DisplayName = "Sniper")
};

UENUM(BlueprintType)
enum class ScopeType : uint8
{
	IronSight 	UMETA(DisplayName = "IronSight"),
	Redhot 	UMETA(DisplayName = "Redhot"),
	Scope4x	UMETA(DisplayName = "Scope4x")
};

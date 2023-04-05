// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/StaticMeshComponent.h"
#include "TurretComponent.generated.h"

/**
 * 
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class TANKBATTLE_API UTurretComponent : public UStaticMeshComponent
{
	GENERATED_BODY()

private:
	UPROPERTY(EditDefaultsOnly, Category = Setup)
		float RotationDegreesPerSecond = 20;

	UPROPERTY(EditDefaultsOnly, Category = Setup)
		float MaxRotationDegrees = 50;

	UPROPERTY(EditDefaultsOnly, Category = Setup)
		float MinRotationDegrees = 0;

public:
	void TurnRight(float DegreesPerSecond);
	
};

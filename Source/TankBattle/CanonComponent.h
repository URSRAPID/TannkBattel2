// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/StaticMeshComponent.h"
#include "CanonComponent.generated.h"

/**
 * 
 */
UCLASS( ClassGroup = (Custom), meta = (BlueprintSpawnableComponent) )
class TANKBATTLE_API UCanonComponent : public UStaticMeshComponent
{
	GENERATED_BODY()

public:
	//TODO Comment
	void Elevate(float DegreesPerSecond);

private:
	UPROPERTY(EditDefaultsOnly, Category = Setup)
		float MaxDegreesPerSecond = 20;

	UPROPERTY(EditDefaultsOnly, Category = Setup)
		float MaxElevationDegrees = 50;

	UPROPERTY(EditDefaultsOnly, Category = Setup)
		float MinElevationDegrees = 0;
	
};

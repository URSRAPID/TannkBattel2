// Fill out your copyright notice in the Description page of Project Settings.
#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "TankAIController.generated.h"

class UTankAimingComponent;
class ATank; //TODO Delete

/**
 *
 */
UCLASS()
class TANKBATTLE_API ATankAIController : public AAIController
{
	GENERATED_BODY()

protected:
	virtual void BeginPlay() override;

	UFUNCTION(BlueprintImplementableEvent, Category = Setup)
		void FindAimingComponent(UTankAimingComponent* AimingComponentRef);


private:
	//TODO Nommage
	APawn* GetControlledAITank();

public:
	virtual void Tick(float Deltatime) override;

	float AcceptanceRadius = 3.0f;

};

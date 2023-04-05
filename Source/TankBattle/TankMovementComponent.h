// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/NavMovementComponent.h"
#include "TankMovementComponent.generated.h"

class UTrackComponent;
class TrackComponent;

/**
 * 
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class TANKBATTLE_API UTankMovementComponent : public UNavMovementComponent
{
	GENERATED_BODY()

		

public:

	UFUNCTION(BlueprintCallable, Category = Setup)
		void IntendMoveForward(float Throw);

	UFUNCTION(BlueprintCallable, Category = Setup)
		void IntendTurnRight(float Throw);

	UTrackComponent* RightTrack = nullptr;

	UTrackComponent* LeftTrack = nullptr;

	UFUNCTION(BlueprintCallable, Category = Setup)
		void Initialize(UTrackComponent* LeftTrackToSet, UTrackComponent* RightTrackToSet);

	virtual void RequestDirectMove(const FVector& MoveVelocity, bool bForceMaxSpeed) override;
private:
	
};

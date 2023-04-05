// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "TankPlayerController.generated.h"

class UTankAimingComponent;


class ATank;
/**
 * 
 */
UCLASS()
class TANKBATTLE_API ATankPlayerController : public APlayerController
{
	GENERATED_BODY()

protected:

	UFUNCTION(BlueprintCallable, Category = Setup)
		ATank* GetControlledTank() const;

	UFUNCTION(BlueprintImplementableEvent, Category = Setup)
		void FindAimingComponent(UTankAimingComponent* AimingComponentRef);

private:
	void AimTowardCrosshair();

	bool GetSightRayHitLocation(FVector &OutHitLocation) const;

	bool GetLookVectorHitPosition(FVector LookDirection, FVector& HitLocation) const;

	bool GetLookDirection(FVector2D ScreenLocation, FVector& LookDirection) const;



	virtual void BeginPlay() override;

	virtual void Tick(float Deltatime) override;



	UPROPERTY(EditDefaultsOnly)
		float CrosshairPositionX = 0.5f;

	UPROPERTY(EditDefaultsOnly)
		float CrosshairPositionY = 0.33f;

	UPROPERTY(EditDefaultsOnly)
		float RayCastRange = 1000000.f;
	
};

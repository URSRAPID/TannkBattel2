// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "Tank.generated.h"

class UTankAimingComponent;
class UCanonComponent;
class UTurretComponent;
class UTrackComponent;

class AProjectile; 
class UTankMovementComponent;
class UNavMovementComponent;


UCLASS()
class TANKBATTLE_API ATank : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	ATank();

	void AimAt(FVector HitLocation);

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	UPROPERTY(BlueprintReadOnly, Category = Setup)
		UTankAimingComponent* TankAimingComponent = nullptr;

	UNavMovementComponent* MovementComponent = nullptr;

	UFUNCTION(BlueprintCallable, Category = Setup)
		void Fire();

	UCanonComponent* LocalCanon = nullptr;

	
	UPROPERTY(EditDefaultsOnly)
		TSubclassOf<AProjectile> ProjectileBlueprint;
	
	//We can declare a UClass -> Problem is Designer can't set the good class by default
	//Designer can put every class he wants -> Conflicts in our code of the projectile
	//

	UPROPERTY(EditDefaultsOnly)
		float LaunchSpeed = 10000.f;

	double LastTimeFire = 0;


	UPROPERTY(EditDefaultsOnly)
		float ReloadTime = 3.f;
	
	

};

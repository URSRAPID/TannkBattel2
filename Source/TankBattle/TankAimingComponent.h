// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "TankAimingComponent.generated.h"

UENUM()
enum class EAimingState : uint8
{
	Reloading,
	Aiming,
	Locked
};

class UCanonComponent;
class UTurretComponent;
class AProjectile;

UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class TANKBATTLE_API UTankAimingComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	// Sets default values for this component's properties
	UTankAimingComponent();
	void AimAt(FVector HitLocation, float LaunchSpeed);
	float GetLaunchSpeed();

	UFUNCTION(BlueprintCallable, Category = FireSetup)
		void Fire();

	UPROPERTY(EditDefaultsOnly)
		TSubclassOf<AProjectile> ProjectileBlueprint;

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

	UPROPERTY(BlueprintReadOnly, Category = Setup)
		EAimingState AimingState = EAimingState::Aiming;

private:
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;


	UCanonComponent* Canon = nullptr;

	UTurretComponent* Turret = nullptr;


	UFUNCTION(BlueprintCallable, Category = Setup)
		void InitializeAiming(UCanonComponent* CanonReference, UTurretComponent* TurretReference);



	void MoveBarrelTowards(FVector AimDirection);



	UPROPERTY(EditDefaultsOnly)
		float LaunchSpeed = 10000.f;

	double LastTimeFire = 0;


	UPROPERTY(EditDefaultsOnly)
		float ReloadTime = 3.f;


};


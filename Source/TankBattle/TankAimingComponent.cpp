// Fill out your copyright notice in the Description page of Project Settings.


#include "TankAimingComponent.h"
#include "CanonComponent.h"
#include "TurretComponent.h"
#include "Math/Vector.h"
#include <Kismet/GameplayStatics.h>

// Sets default values for this component's properties
UTankAimingComponent::UTankAimingComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UTankAimingComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UTankAimingComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

void UTankAimingComponent::AimAt(FVector TargetLocation, float SpeedProjectile)
{
	if (!ensure(Canon)) { return; }

	FVector OutLaunchVelocity;
	FVector StartLocation = Canon->GetSocketLocation(FName("StartProjectile"));
	bool SolutionAiming = UGameplayStatics::SuggestProjectileVelocity(
		this,
		OutLaunchVelocity,
		StartLocation,
		TargetLocation,
		SpeedProjectile,
		false,
		0,
		0,
		ESuggestProjVelocityTraceOption::DoNotTrace
	);
	if (SolutionAiming)
	{
		//UE_LOG(LogTemp, Warning, TEXT("Aim possible "));
		FVector AimingDirection = OutLaunchVelocity.GetSafeNormal();
		//UE_LOG(LogTemp, Warning, TEXT("Aiming at : %s"), *AimingDirection.ToString());
		MoveBarrelTowards(AimingDirection);
	}
	//else { /*UE_LOG(LogTemp, Warning, TEXT("Aim No Solution "));*/ }
}

void UTankAimingComponent::InitializeAiming(UCanonComponent* CanonReference, UTurretComponent* TurretReference)
{
	//if (!CanonReference || !TurretReference) { return; }

	Canon = CanonReference;
	Turret = TurretReference;
}

void UTankAimingComponent::MoveBarrelTowards(FVector AimDirection)
{

	//Work out difference between current canon rotation, and AimDirection
	FRotator CanonRotation = Canon->GetForwardVector().Rotation();
	FRotator AimAsRotator = AimDirection.Rotation();
	FRotator DeltaRotator = AimAsRotator - CanonRotation;

	//UE_LOG(LogTemp, Warning, TEXT("AimDirection : %s"), *AimDirection.ToString());
	//UE_LOG(LogTemp, Warning, TEXT("Aiming as Rotator : %s"), *AimAsRotator.ToString());
	//UE_LOG(LogTemp, Warning, TEXT("Delta Rotator : %s"), *DeltaRotator.ToString());

	//Move the barrel the right amount this frame
	//Given a max elevation speed, and the frame time
	Canon->Elevate(DeltaRotator.Pitch);
	Turret->TurnRight(DeltaRotator.Yaw);


}

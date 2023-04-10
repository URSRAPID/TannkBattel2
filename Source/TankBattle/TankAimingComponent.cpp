// Fill out your copyright notice in the Description page of Project Settings.


#include "TankAimingComponent.h"
#include "CanonComponent.h"
#include "TurretComponent.h"
#include "Projectile.h"
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
		FVector AimingDirection = OutLaunchVelocity.GetSafeNormal();

		MoveBarrelTowards(AimingDirection);
	}
	
}

float UTankAimingComponent::GetLaunchSpeed()
{
	return LaunchSpeed;
}

void UTankAimingComponent::InitializeAiming(UCanonComponent* CanonReference, UTurretComponent* TurretReference)
{
	if (!CanonReference || !TurretReference) { return; }

	Canon = CanonReference;
	Turret = TurretReference;
}

void UTankAimingComponent::MoveBarrelTowards(FVector AimDirection)
{

	//Work out difference between current canon rotation, and AimDirection
	FRotator CanonRotation = Canon->GetForwardVector().Rotation();
	FRotator AimAsRotator = AimDirection.Rotation();
	FRotator DeltaRotator = AimAsRotator - CanonRotation;

	//TODO Security - Canon / Turret

	//Move the barrel the right amount this frame
	//Given a max elevation speed, and the frame time
	Canon->Elevate(DeltaRotator.Pitch);
	Turret->TurnRight(DeltaRotator.Yaw);


}

void UTankAimingComponent::Fire()
{
	bool IsReloaded = (FPlatformTime::Seconds() - LastTimeFire) > ReloadTime;
	if (!ensure(ProjectileBlueprint)) { return; }
	//TODO Security - Canon
	if (IsReloaded)
	{
	

		FVector SpawnProjectileLocation = Canon->GetSocketLocation(FName("StartProjectile"));
		FRotator SpawnProjectileRotation = Canon->GetSocketRotation(FName("StartProjectile"));

		auto Projectile = GetWorld()->SpawnActor<AProjectile>(
			ProjectileBlueprint,
			SpawnProjectileLocation,
			SpawnProjectileRotation
			);

		Projectile->LaunchProjectile(LaunchSpeed);
		LastTimeFire = FPlatformTime::Seconds();
	}
}




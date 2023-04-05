// Fill out your copyright notice in the Description page of Project Settings.


#include "Tank.h"
#include "CanonComponent.h"
#include "TankAimingComponent.h"
#include "Projectile.h"
#include "TankMovementComponent.h"

// Sets default values
ATank::ATank()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	//TankAimingComponent = CreateDefaultSubobject<UTankAimingComponent>(FName("Aiming Tank"));




}

void ATank::AimAt(FVector HitLocation)
{
	if (!ensure(TankAimingComponent)) { return; }

	TankAimingComponent->AimAt(HitLocation, LaunchSpeed);
	
	//UE_LOG(LogTemp, Warning, TEXT("%s aiming at %s"), *GetName(), *HitLocation.ToString());
}

// Called when the game starts or when spawned
void ATank::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ATank::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ATank::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

void ATank::Fire()
{
	bool IsReloaded = (FPlatformTime::Seconds() - LastTimeFire) > ReloadTime;
	if (!ensure(ProjectileBlueprint)) { return; }

	if (!ensure(LocalCanon)) { return; }


	if (IsReloaded) 
	{
		//UE_LOG(LogTemp, Warning, TEXT("Fire !!"));

		FVector SpawnProjectileLocation = LocalCanon->GetSocketLocation(FName("StartProjectile"));
		FRotator SpawnProjectileRotation = LocalCanon->GetSocketRotation(FName("StartProjectile"));

		auto Projectile = GetWorld()->SpawnActor<AProjectile>(
			ProjectileBlueprint,
			SpawnProjectileLocation,
			SpawnProjectileRotation
		);

		Projectile->LaunchProjectile(LaunchSpeed);
		LastTimeFire = FPlatformTime::Seconds();
	}	
}



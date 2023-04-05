// Fill out your copyright notice in the Description page of Project Settings.


#include "Tank.h"
#include "TankPlayerController.h"
#include "TankAimingComponent.h"


void ATankPlayerController::BeginPlay()
{
	Super::BeginPlay();

	UE_LOG(LogTemp, Warning, TEXT("%s is MY FUCKIN TANK"), *GetControlledTank()->GetActorLabel());

	auto AimingComponent = GetControlledTank()->FindComponentByClass<UTankAimingComponent>();

	if (!ensure(AimingComponent))
	{
		UE_LOG(LogTemp, Warning, TEXT("Aiming Component not found"))
	}
	else
	{
		FindAimingComponent(AimingComponent);
	}


}

void ATankPlayerController::Tick(float Deltatime)
{
	Super::Tick(Deltatime);

	AimTowardCrosshair();
}



APawn* ATankPlayerController::GetControlledTank() const
{

	return GetPawn();
}



void ATankPlayerController::AimTowardCrosshair()
{
	if (!ensure(GetControlledTank())) { return; }
	FVector HitLocation; //Out Parameter

	if (GetSightRayHitLocation(HitLocation))
	{

		auto AimingComponent = GetControlledTank()->FindComponentByClass<UTankAimingComponent>();
		AimingComponent->AimAt(HitLocation, AimingComponent->GetLaunchSpeed());
		//UE_LOG(LogTemp, Warning, TEXT("Aiming location is : %s"), HitLocation)
	}
}

bool ATankPlayerController::GetSightRayHitLocation(FVector& OutHitLocation) const
{

	int VPSizeX, VPSizeY;
	GetViewportSize(VPSizeX, VPSizeY);
	FVector2D CrosshairPositionInScreen = FVector2D(VPSizeX * CrosshairPositionX, VPSizeY * CrosshairPositionY);

	FVector LookDirection;
	if (GetLookDirection(CrosshairPositionInScreen, LookDirection))
	{
		return GetLookVectorHitPosition(LookDirection, OutHitLocation);
	}
	return false;
}

bool ATankPlayerController::GetLookVectorHitPosition(FVector LookDirection, FVector& HitLocation) const
{
	FHitResult HitResult;
	FVector StartLocation = PlayerCameraManager->GetCameraLocation();
	FVector EndLocation = StartLocation + (LookDirection * RayCastRange);
	bool hitSucced = false;
	hitSucced = GetWorld()->LineTraceSingleByChannel
	(
		HitResult,
		StartLocation,
		EndLocation,
		ECollisionChannel::ECC_Visibility
	);
	//DrawDebugLine(GetWorld(), StartLocation, EndLocation, FColor(255, 0, 0, 1), false, 0.f, 0.f, 5.f);

	if (hitSucced)
	{
		HitLocation = HitResult.Location;
		return true;
	}

	HitLocation = FVector(0.f); //Line didn't drew
	return false;


}

bool ATankPlayerController::GetLookDirection(FVector2D ScreenLocation, FVector& LookDirection) const
{
	FVector CameraWorldLocation;
	return DeprojectScreenPositionToWorld(ScreenLocation.X, ScreenLocation.Y, CameraWorldLocation, LookDirection);
}



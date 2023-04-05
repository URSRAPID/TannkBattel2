// Fill out your copyright notice in the Description page of Project Settings.


#include "TankAIController.h"
#include "Tank.h"
#include "TankAimingComponent.h"



APawn* ATankAIController::GetControlledAITank()
{
	//ATank* var = ;
	return GetPawn();
}

void ATankAIController::BeginPlay()
{
	Super::BeginPlay();


}

void ATankAIController::Tick(float Deltatime)
{
	Super::Tick(Deltatime);


	APawn* PlayerTank = GetWorld()->GetFirstPlayerController()->GetPawn();
	APawn* OwnTank = GetPawn();
	auto AimingComponent = GetControlledAITank()->FindComponentByClass<UTankAimingComponent>();

	if (!ensure(PlayerTank)) { return; }

	AimingComponent->AimAt(PlayerTank->GetActorLocation(), AimingComponent->GetLaunchSpeed());
	
	AimingComponent->Fire();

	MoveToActor(PlayerTank, AcceptanceRadius);
}

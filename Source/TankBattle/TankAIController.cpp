// Fill out your copyright notice in the Description page of Project Settings.


#include "TankAIController.h"
#include "Tank.h"

ATank* ATankAIController::GetControlledAITank()
{
	//ATank* var = ;
	return Cast<ATank>(GetPawn());
}

void ATankAIController::BeginPlay()
{
	Super::BeginPlay();
	//GetControlledAITank()->AimAt(GetPlayerTank()->GetActorLocation());
	//UE_LOG(LogTemp, Warning, TEXT("%s is controlled by AI"), *GetControlledAITank()->GetName());
	
}

void ATankAIController::Tick(float Deltatime)
{
	Super::Tick(Deltatime);


	ATank* PlayerTank = Cast<ATank>(GetWorld()->GetFirstPlayerController()->GetPawn());
	ATank* OwnTank = Cast<ATank>(GetPawn());

	if (!ensure(PlayerTank)) { return; }

	OwnTank->AimAt(PlayerTank->GetActorLocation());
	//UE_LOG(LogTemp, Warning, TEXT("tank player pos % s"), *GetPlayerTank()->GetActorLocation().ToString());
	OwnTank->Fire();

	MoveToActor(PlayerTank, AcceptanceRadius);
}

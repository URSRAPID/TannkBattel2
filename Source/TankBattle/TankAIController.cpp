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

	/*ATank* PlayerTank = Cast<ATank>(GetWorld()->GetFirstPlayerController()->GetPawn());*/


	if (!ensure(PlayerTank)) { return; }


	AimingComponent->AimAt(PlayerTank->GetActorLocation(), AimingComponent->GetLaunchSpeed());
	
	AimingComponent->Fire();

	//GetControlledAITank()->AimAt(GetControlledAITank()->GetActorLocation());
	////UE_LOG(LogTemp, Warning, TEXT("tank player pos % s"), *GetPlayerTank()->GetActorLocation().ToString());
	//GetControlledAITank()->Fire();

	//if (!GetControlledAITank()) { return; }

	MoveToActor(PlayerTank, AcceptanceRadius);
}

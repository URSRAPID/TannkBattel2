// Fill out your copyright notice in the Description page of Project Settings.



//TODO Delete - Canon + TankAiming + Projectile
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


}


// Called when the game starts or when spawned
void ATank::BeginPlay()
{
	Super::BeginPlay();

}





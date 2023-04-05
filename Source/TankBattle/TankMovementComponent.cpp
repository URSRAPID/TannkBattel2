// Fill out your copyright notice in the Description page of Project Settings.


#include "TankMovementComponent.h"
#include "TrackComponent.h"

void UTankMovementComponent::IntendMoveForward(float Throw)
{
	if (!ensure(LeftTrack) || !ensure(RightTrack)) { return; }

	//UE_LOG(LogTemp, Warning, TEXT("%s MoveForward : %f"), *GetName(), Throw);

	//TODO:
	// Forward : Put both tracks on POSITIVE value
	// Backward : Put both tracks on NEGATIVE value

	LeftTrack->SetThrottle(Throw);
	RightTrack->SetThrottle(Throw);
}

void UTankMovementComponent::IntendTurnRight(float Throw)
{
	if (!ensure(LeftTrack) || !ensure(RightTrack)) { return; }

	//UE_LOG(LogTemp, Warning, TEXT("%s MoveRight : %f"), *GetName(), Throw);
	//TODO:
	// Left : Put track left on NEGATIVE value, track right on POSITIVE value
	// Right : Put track left on POSITIVE value, track right on NEGATIVE value

	LeftTrack->SetThrottle(Throw);
	RightTrack->SetThrottle(-Throw);
}

void UTankMovementComponent::Initialize(UTrackComponent* LeftTrackToSet, UTrackComponent* RightTrackToSet)
{
	if (!ensure(LeftTrackToSet) || !ensure(RightTrackToSet)) { return; }

	LeftTrack = LeftTrackToSet;
	RightTrack = RightTrackToSet;
}

void UTankMovementComponent::RequestDirectMove(const FVector& MoveVelocity, bool bForceMaxSpeed)
{
	//UE_LOG(LogTemp, Error, TEXT("Request1"));
	//auto TankName = GetOwner()->GetName();
	auto TankForwardVector = GetOwner()->GetActorForwardVector().GetSafeNormal();
	auto AIForwardIntention = MoveVelocity.GetSafeNormal();
	//auto TankMoveVelocity = MoveVelocity.ToString();

	auto ForwardDirection = FVector::DotProduct(TankForwardVector, AIForwardIntention);
	auto RotateDirection = FVector::CrossProduct(TankForwardVector, AIForwardIntention);

	//UE_LOG(LogTemp, Warning, TEXT("Forward Direction : %f, Rotation : %f"), ForwardDirection, RotateDirection.Z);

	IntendMoveForward(ForwardDirection);
	IntendTurnRight(RotateDirection.Z);

	//UE_LOG(LogTemp, Error, TEXT("Request2"));
}

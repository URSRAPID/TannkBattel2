// Fill out your copyright notice in the Description page of Project Settings.


#include "TankMovementComponent.h"
#include "TrackComponent.h"

void UTankMovementComponent::IntendMoveForward(float Throw)
{
	if (!ensure(LeftTrack) || !ensure(RightTrack)) { return; }

	

	//TODO:
	// Forward : Put both tracks on POSITIVE value
	// Backward : Put both tracks on NEGATIVE value

	LeftTrack->SetThrottle(Throw);
	RightTrack->SetThrottle(Throw);
}

void UTankMovementComponent::IntendTurnRight(float Throw)
{
	if (!ensure(LeftTrack) || !ensure(RightTrack)) { return; } //TODO faire une double sécurité pour permettre au ensure de renvoyer le bon log si un des 2 track est nullptr

	
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
	
	auto TankForwardVector = GetOwner()->GetActorForwardVector().GetSafeNormal();
	auto AIForwardIntention = MoveVelocity.GetSafeNormal();


	auto ForwardDirection = FVector::DotProduct(TankForwardVector, AIForwardIntention);
	auto RotateDirection = FVector::CrossProduct(TankForwardVector, AIForwardIntention);

	

	IntendMoveForward(ForwardDirection);
	IntendTurnRight(RotateDirection.Z);

	//UE_LOG(LogTemp, Error, TEXT("Request2"));
}

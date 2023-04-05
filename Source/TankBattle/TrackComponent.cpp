// Fill out your copyright notice in the Description page of Project Settings.


#include "TrackComponent.h"

void UTrackComponent::SetThrottle(float Speed)
{
	//UE_LOG(LogTemp, Warning, TEXT("%s Throttle : %f"), *GetName(), Speed);
	FVector TrackForce = GetForwardVector() * Speed * MaxDrivingForce;
	FVector TrackLocation = GetComponentLocation();

	auto PrimitiveComp = Cast<UPrimitiveComponent>(GetOwner()->GetRootComponent());

	PrimitiveComp->AddForceAtLocation(
		TrackForce,
		TrackLocation,
		NAME_None
	);
}
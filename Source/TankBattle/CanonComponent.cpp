// Fill out your copyright notice in the Description page of Project Settings.


#include "CanonComponent.h"
#include "Math/UnrealMathUtility.h"

void UCanonComponent::Elevate(float DegreesPerSecond)
{

	auto RelativeSpeedClamped = FMath::Clamp<float>(DegreesPerSecond, -1, +1);

	auto ElevationChange = RelativeSpeedClamped * MaxDegreesPerSecond * GetWorld()->DeltaTimeSeconds;
	auto RawNewElevation = GetRelativeRotation().Pitch + ElevationChange;

	auto RawClampedElevation = FMath::Clamp<float>(RawNewElevation, MinElevationDegrees, MaxElevationDegrees);

	//UE_LOG(LogTemp, Warning, TEXT("Elevate at : %f"), RelativeSpeedClamped); //TODO Delete
	SetRelativeRotation(FRotator(RawClampedElevation,0.f, 0.f));
}

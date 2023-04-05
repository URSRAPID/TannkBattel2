// Fill out your copyright notice in the Description page of Project Settings.


#include "TurretComponent.h"
#include "Math/UnrealMathUtility.h"

void UTurretComponent::TurnRight(float DegreesPerSecond)
{

	auto RelativeSpeedRotationClamped = FMath::Clamp(DegreesPerSecond, -1, +1);

	auto RotationChange = RelativeSpeedRotationClamped * MaxRotationDegrees * GetWorld()->DeltaTimeSeconds;
	auto RawNewRotation = GetRelativeRotation().Yaw + RotationChange;

	//UE_LOG(LogTemp, Warning, TEXT("Rotate at : %f"), RelativeSpeedRotationClamped);

	SetRelativeRotation(FRotator(0.f, RawNewRotation, 0.f));
}

// Fill out your copyright notice in the Description page of Project Settings.

#include "TankTurret.h"
#include "Engine/World.h"


void UTankTurret::Rotate(float RelativeSpeed) 
{
	RelativeSpeed = FMath::Clamp(RelativeSpeed, -1.0f, 1.0f);
	float yawDelta = RelativeSpeed * MaxDegreesPerSecond * GetWorld()->DeltaTimeSeconds;
	UE_LOG(LogTemp, Warning, TEXT("Yaw delta: %f"), yawDelta);
	SetRelativeRotation(FRotator(0, RelativeRotation.Yaw + yawDelta, 0));
}


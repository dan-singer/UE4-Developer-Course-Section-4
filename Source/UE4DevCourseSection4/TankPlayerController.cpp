// Fill out your copyright notice in the Description page of Project Settings.

#include "TankPlayerController.h"


void ATankPlayerController::BeginPlay()
{
	Super::BeginPlay();
	UE_LOG(LogTemp, Warning, TEXT("PlayerController Begin Play"));

	ATank* controlledTank = GetControlledTank();
	if (controlledTank) {
		UE_LOG(LogTemp, Warning, TEXT("Tank name: %s"), *controlledTank->GetName());
	}
	else {
		UE_LOG(LogTemp, Warning, TEXT("Tank not found"));
	}
}

void ATankPlayerController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	AimTowardsCrosshair();
}

ATank* ATankPlayerController::GetControlledTank() const 
{
	return Cast<ATank>(GetPawn());
}

void ATankPlayerController::AimTowardsCrosshair()
{
	if (!GetControlledTank())
		return;

	FVector HitLocation; // Out parameter
	if (GetSightRayHitLocation(HitLocation))
	{	
		UE_LOG(LogTemp, Warning, TEXT("HitLocation: %s"), *HitLocation.ToString());
		// If it hits the landscape
		// Tell the control tank to aim at this point

	}

}

// Get world location of linetrace through crosshair, true if hits crosshair
bool ATankPlayerController::GetSightRayHitLocation(FVector &OutHitLocation) const
{
	OutHitLocation = FVector(1.0);
	// Get the position of the crosshair somehow
	// Use that position to raycast into the world
	// If we hit something
		// Set OutHitLocation to that location
		// return true
	return true;
}

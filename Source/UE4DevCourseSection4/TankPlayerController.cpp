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
		//UE_LOG(LogTemp, Warning, TEXT("HitLocation: %s"), *HitLocation.ToString());
		// If it hits the landscape
		// Tell the control tank to aim at this point

	}

}

// Get world location of linetrace through crosshair, true if hits crosshair
bool ATankPlayerController::GetSightRayHitLocation(FVector &OutHitLocation) const
{	
	// Find the crosshair position
	int ViewportSizeX, ViewportSizeY;
	GetViewportSize(ViewportSizeX, ViewportSizeY);
	FVector2D ScreenLocation{ CrosshairXLocation * ViewportSizeX, CrosshairYLocation * ViewportSizeY };
	// Deproject the screen position of the crosshair to a world projection
	// Line trace along that direction, and see what we hit up to some maximum range
	return true;
}

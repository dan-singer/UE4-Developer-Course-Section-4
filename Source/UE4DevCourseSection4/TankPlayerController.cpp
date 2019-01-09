// Fill out your copyright notice in the Description page of Project Settings.

#include "TankPlayerController.h"
#include "Engine/World.h"
#include "TankAimingComponent.h"

void ATankPlayerController::BeginPlay()
{
	Super::BeginPlay();
	auto AimingComponent = GetPawn()->FindComponentByClass<UTankAimingComponent>();
	if (!ensure(AimingComponent)) return;
	FoundAimingComponent(AimingComponent);
}

void ATankPlayerController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	AimTowardsCrosshair();
}


void ATankPlayerController::AimTowardsCrosshair()
{
	auto AimingComponent = GetPawn()->FindComponentByClass<UTankAimingComponent>();
	if (!ensure(AimingComponent)) return;

	FVector HitLocation; // Out parameter
	if (GetSightRayHitLocation(HitLocation))
	{	
		AimingComponent->AimAt(HitLocation);
	}

}

// Get world location of linetrace through crosshair, true if hits land
bool ATankPlayerController::GetSightRayHitLocation(FVector &OutHitLocation) const
{
	// Find the crosshair position
	int ViewportSizeX, ViewportSizeY;
	GetViewportSize(ViewportSizeX, ViewportSizeY);
	FVector2D ScreenLocation{ CrosshairXLocation * ViewportSizeX, CrosshairYLocation * ViewportSizeY };

	// Deproject the screen position of the crosshair to a world projection
	FVector LookVector, CameraWorldLocation;
	if (DeprojectScreenPositionToWorld(ScreenLocation.X, ScreenLocation.Y, CameraWorldLocation, LookVector))
	{
		// Line trace along that LookDirection, and see what we hit up to some maximum range
		return GetLookVectorHitLocation(LookVector, OutHitLocation);
	}
	return false;
}

bool ATankPlayerController::GetLookVectorHitLocation(FVector LookVector, FVector &OutHitLocation) const
{
	FHitResult HitResult;
	FVector StartLocation = PlayerCameraManager->GetCameraLocation();
	FCollisionQueryParams CollQueryParams;
	FCollisionResponseParams CollResParams;
	if (GetWorld()->LineTraceSingleByChannel(
		HitResult, 
		StartLocation,
		StartLocation + LookVector * LineTraceRange,
		ECC_Visibility, 
		CollQueryParams,
		CollResParams
	)) 
	{
		OutHitLocation = HitResult.Location;
		return true;
	}
	return false;
}
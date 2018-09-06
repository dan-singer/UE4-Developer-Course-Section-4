// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAIController.h"
#include "Engine/World.h"

void ATankAIController::BeginPlay()
{
	Super::BeginPlay();
	ATank *playerTank = GetPlayerTank();
	if (playerTank)
	{
		UE_LOG(LogTemp, Warning, TEXT("AI controlling %s"), *playerTank->GetName());
	} 
	else 
	{
		UE_LOG(LogTemp, Warning, TEXT("No player tank found"));
	}
}

ATank* ATankAIController::GetControlledTank() const
{
	return Cast<ATank>(GetPawn());
}

ATank* ATankAIController::GetPlayerTank() const
{
	UWorld *world = GetWorld();
	if (world && world->GetFirstPlayerController()) {
		return Cast<ATank>(world->GetFirstPlayerController()->GetPawn());
	}
	return nullptr;
	
}




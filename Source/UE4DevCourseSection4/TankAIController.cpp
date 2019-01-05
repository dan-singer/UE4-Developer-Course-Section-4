// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAIController.h"
#include "Engine/World.h"
#include "Tank.h"


void ATankAIController::BeginPlay()
{
	Super::BeginPlay();
}

void ATankAIController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	ATank* ControlledTank = Cast<ATank>(GetPawn());
	ATank* PlayerTank = nullptr;

	UWorld* world = GetWorld();
	APlayerController* p1 = world->GetFirstPlayerController();
	if (p1) {
		PlayerTank = Cast<ATank>(p1->GetPawn());
	}

	if (PlayerTank && ControlledTank)
	{
		// Move towards player
		MoveToActor(PlayerTank, AcceptanceRadius);
		// Aim towards player
		FVector target = PlayerTank->GetActorLocation();
		ControlledTank->AimAt(target);
		// Fire if ready
		ControlledTank->Fire(); // TODO don't fire every frame
	}
	
}




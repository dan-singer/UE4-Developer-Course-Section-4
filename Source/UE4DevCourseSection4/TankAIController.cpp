// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAIController.h"
#include "Engine/World.h"
#include "TankAimingComponent.h"
// Depends on movement component via pathfinding system

void ATankAIController::BeginPlay()
{
	Super::BeginPlay();
}

void ATankAIController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	APawn* ControlledTank = GetPawn();
	APawn* PlayerTank = nullptr;

	APlayerController* p1 = GetWorld()->GetFirstPlayerController();
	if (!ensure(p1)) return;

	PlayerTank = p1->GetPawn();

	if (!ensure(PlayerTank && ControlledTank)) return;

	UTankAimingComponent* AimingComponent = ControlledTank->FindComponentByClass<UTankAimingComponent>();
	if (!ensure(AimingComponent)) return;

	// Move towards player
	MoveToActor(PlayerTank, AcceptanceRadius);
	// Aim towards player
	FVector target = PlayerTank->GetActorLocation();
	AimingComponent->AimAt(target);
	// TODO fix firing
	// ControlledTank->Fire(); 
	
}




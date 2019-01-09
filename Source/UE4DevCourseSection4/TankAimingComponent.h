// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "TankAimingComponent.generated.h"


// Enum for aiming state //
UENUM()
enum class EFiringStatus : uint8
{
	Reloading,
	Aiming,
	Locked,
};


class UTankBarrel;
class UTankTurret;

// Handles aiming for the tank
UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) ) 
class UE4DEVCOURSESECTION4_API UTankAimingComponent : public UActorComponent
{
	GENERATED_BODY()

private:
	UTankBarrel* Barrel = nullptr;
	UTankTurret* Turret = nullptr;
	void MoveBarrelTowards(FVector AimDirection);
	void RotateTurretTowards(FVector AimDirection);

protected:
	UPROPERTY(BlueprintReadOnly, Category = "State")
	EFiringStatus FiringStatus = EFiringStatus::Aiming;

	// Pass over data from the blueprint to this component
	UFUNCTION(BlueprintCallable)
	void Initialize(UTankBarrel* TankBarrel, UTankTurret* TankTurret);

public:	
	// Sets default values for this component's properties
	UTankAimingComponent();

	UPROPERTY(EditAnywhere, Category = Fire)
	float LaunchSpeed = 8000; 

	void AimAt(FVector HitLocation);

	const UTankBarrel* GetBarrel() const;
	
};

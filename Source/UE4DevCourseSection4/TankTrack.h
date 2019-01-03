// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/StaticMeshComponent.h"
#include "TankTrack.generated.h"

/**
 * Used to set maximum driving force, and to apply forces to the tank
 */
UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class UE4DEVCOURSESECTION4_API UTankTrack : public UStaticMeshComponent
{
	GENERATED_BODY()
	
public:
	// Sets throttle between -1 and +1
	UFUNCTION(BlueprintCallable, Category = Input)
	void SetThrottle(float throttle);
	
	// Max force per track, in Newtons
	UPROPERTY(EditDefaultsOnly)
	float MaxDrivingForce = 400000;
	
};

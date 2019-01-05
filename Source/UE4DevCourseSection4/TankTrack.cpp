// Fill out your copyright notice in the Description page of Project Settings.

#include "TankTrack.h"
#include "Engine/World.h"

void UTankTrack::SetThrottle(float throttle)
{
	// TODO clamp actual throttle value so player can't overdrive them
	auto Name = GetName();

	auto ForceApplied = GetForwardVector() * throttle * MaxDrivingForce;
	auto ForceLocation = GetComponentLocation();
	auto TankRoot = Cast<UPrimitiveComponent>(GetOwner()->GetRootComponent());
	TankRoot->AddForceAtLocation(ForceApplied, ForceLocation);
}


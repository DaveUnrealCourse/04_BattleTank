// Copyright David Thornton 2016

#include "BattleTank.h"
#include "TankTrack.h"

void UTankTrack::SetThrottle(float Throttle)
{
	//auto Time = GetWorld()->GetTimeSeconds();
	auto Name = GetName();
	UE_LOG(LogTemp, Warning, TEXT("%s Throttle is at %f"), *Name, Throttle);

	//TODO clamp Throttle so player cant change Speeds in the input menu
	auto ForceApplied = GetForwardVector() * Throttle *TrackMaxDrivingFource;
	auto ForceLocation = GetComponentLocation();
	auto TankRoot = Cast<UPrimitiveComponent>(GetOwner()->GetRootComponent());
	TankRoot->AddForceAtLocation(ForceApplied, ForceLocation);
}



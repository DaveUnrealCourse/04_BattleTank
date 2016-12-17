// Copyright David Thornton 2016

#include "BattleTank.h"
#include "TankTrack.h"

UTankTrack::UTankTrack()
{
	PrimaryComponentTick.bCanEverTick = true;//TODO should this really tick
	UE_LOG(LogTemp, Warning, TEXT("Track construct"));
}

void UTankTrack::TickComponent(float DeltaTime, enum ELevelTick TickType, FActorComponentTickFunction *ThisTickFunction)
{
	//calc slipage speed
	auto SlippageSpeed = FVector::DotProduct(GetRightVector(), GetComponentVelocity());
	//Work-out the required acceleration this frame to correct
	auto CorrectionAcceleration = -SlippageSpeed / DeltaTime * GetRightVector();
	//calc and aply side ways for (F = m a
	auto TankRoot = Cast<UStaticMeshComponent>(GetOwner()->GetRootComponent());
	auto CorrectionForce = (TankRoot->GetMass() *CorrectionAcceleration) / 2; // because there is 2 tracks
	TankRoot->AddForce(CorrectionForce);
}//UE_LOG(LogTemp, Warning, TEXT("%s Track"), *SlippageSpeed);

void UTankTrack::SetThrottle(float Throttle)
{
	//auto Time = GetWorld()->GetTimeSeconds();
	//auto Name = GetName();
	//UE_LOG(LogTemp, Warning, TEXT("%s Throttle is at %f"), *Name, Throttle);

	//TODO clamp Throttle so player cant change Speeds in the input menu
	auto ForceApplied = GetForwardVector() * Throttle *TrackMaxDrivingFource;
	auto ForceLocation = GetComponentLocation();
	auto TankRoot = Cast<UPrimitiveComponent>(GetOwner()->GetRootComponent());
	TankRoot->AddForceAtLocation(ForceApplied, ForceLocation);
}



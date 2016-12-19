// Copyright David Thornton 2016

#include "BattleTank.h"
#include "TankTrack.h"

UTankTrack::UTankTrack()
{
	PrimaryComponentTick.bCanEverTick = false;//TODO should this really tick
}
void UTankTrack::BeginPlay()
{
	OnComponentHit.AddDynamic(this, &UTankTrack::OnHit);
}

void UTankTrack::OnHit(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComponent, FVector NormalImpulse, const FHitResult& Hit)
{
	//drive the track
	//Apply the sideways force
	ApplySidewaysForce();
	DriveTrack();
	CurrentThrottle = 0;
}
//void UTankTrack::TickComponent(float DeltaTime, enum ELevelTick TickType, FActorComponentTickFunction *ThisTickFunction){}
void UTankTrack::ApplySidewaysForce()
{
	auto DeltaTime = GetWorld()->GetDeltaSeconds();
	//calc slipage speed
	auto SlippageSpeed = FVector::DotProduct(GetRightVector(), GetComponentVelocity());
	//Work-out the required acceleration this frame to correct
	auto CorrectionAcceleration = -SlippageSpeed / DeltaTime * GetRightVector();
	//calc and aply side ways for (F = m a
	auto TankRoot = Cast<UStaticMeshComponent>(GetOwner()->GetRootComponent());
	auto CorrectionForce = (TankRoot->GetMass() *CorrectionAcceleration) / 2; // because there is 2 tracks
	TankRoot->AddForce(CorrectionForce);
}

void UTankTrack::SetThrottle(float Throttle)
{
	CurrentThrottle = FMath::Clamp<float>(CurrentThrottle + Throttle, -1, 1);
}
void UTankTrack::DriveTrack()
{
	//TODO clamp Throttle so player cant change Speeds in the input menu
	auto ForceApplied = GetForwardVector() * CurrentThrottle *TrackMaxDrivingFource;
	auto ForceLocation = GetComponentLocation();
	auto TankRoot = Cast<UPrimitiveComponent>(GetOwner()->GetRootComponent());
	TankRoot->AddForceAtLocation(ForceApplied, ForceLocation);
}
//auto Time = GetWorld()->GetTimeSeconds();
	//auto Name = GetName();
	//UE_LOG(LogTemp, Warning, TEXT("%s Throttle is at %f"), *Name, Throttle);



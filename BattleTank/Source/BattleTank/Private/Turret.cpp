// Copyright David Thornton 2016

#include "BattleTank.h"
#include "Turret.h"

void UTurret::Azimuth(float RelativeSpeed)
{
	// the right amount this frame 
	//do to same for rotation of the turret
	RelativeSpeed = FMath::Clamp<float>(RelativeSpeed, -5, 5);
	auto AzimuthChange = RelativeSpeed * MaxDegreesPerSecond * GetWorld()->DeltaTimeSeconds;
	auto RawNewAzimuth = RelativeRotation.Yaw + AzimuthChange;
	SetRelativeRotation(FRotator(0, RawNewAzimuth, 0));
}

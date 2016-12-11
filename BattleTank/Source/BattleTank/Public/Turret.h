// Copyright David Thornton 2016

#pragma once

#include "Components/StaticMeshComponent.h"
#include "Turret.generated.h"

UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class BATTLETANK_API UTurret : public UStaticMeshComponent
{
	GENERATED_BODY()

public:
	void Azimuth(float RelativeSpeed);

private:
UPROPERTY(EditDefaultsOnly, Category = "Setup")
	float MaxDegreesPerSecond = 25;
	
	
};

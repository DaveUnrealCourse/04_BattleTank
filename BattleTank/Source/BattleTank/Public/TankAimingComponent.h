// Copyright David Thornton 2016

#pragma once

#include "Components/ActorComponent.h"
#include "TankBarrel.h"
#include "TankAimingComponent.generated.h"

class UTankBarrel;// forward declaration

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class BATTLETANK_API UTankAimingComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	void SetBarrelReference(UTankBarrel* BarrelToSet);

	

	void AimAt(FVector HitLocation, float LaunchSpeed);

		// TODO add set Turret referance

private:
	UTankBarrel* Barrel = nullptr;
	void MoveBarrelTowards(FVector AimDirection);
UTankAimingComponent();
};

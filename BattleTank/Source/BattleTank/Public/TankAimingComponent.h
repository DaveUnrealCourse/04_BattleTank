// Copyright David Thornton 2016

#pragma once

#include "Components/ActorComponent.h"
#include "TankAimingComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class BATTLETANK_API UTankAimingComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UTankAimingComponent();

	void AimAt(FVector HitLocation, float LaunchSpeed);
		void SetBarrelReference(UStaticMeshComponent* BarrelToSet);
		// TODO add set Turret referance

private:
	UStaticMeshComponent* Barrel = nullptr;
	void MoveBarrelTowards(FVector AimDirection);

};

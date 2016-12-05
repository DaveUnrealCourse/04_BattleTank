// Copyright David Thornton 2016

#pragma once
#include "Components/ActorComponent.h"
#include "TankAimingComponent.generated.h"

// forward declaration
class UTankBarrel;
class UTurret;

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class BATTLETANK_API UTankAimingComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	void SetBarrelReference(UTankBarrel* BarrelToSet);
	void SetTurretReference(UTurret* TurretToSet);
	void AimAt(FVector HitLocation, float LaunchSpeed);
		// TODO add set Turret referance

private:
	UTankBarrel* Barrel = nullptr;
	UTurret* Turret = nullptr;
	void MoveBarrelTowards(FVector AimDirection);
	//increase the speed at witch you can move barrel and turret( use decimal to slow)
	UPROPERTY(EditAnywhere, Category = Setup)
	float AimSpeedMultiplier = 1;
	UTankAimingComponent();
};

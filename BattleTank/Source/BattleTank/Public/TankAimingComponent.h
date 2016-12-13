// Copyright David Thornton 2016

#pragma once
#include "Components/ActorComponent.h"
#include "TankAimingComponent.generated.h"
//Enum for Aiming state
UENUM()
enum class EFiringState : uint8
{
	Reloading,
	Aiming,
	Locked
};
// forward declaration
class UTankBarrel;
class UTurret;

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class BATTLETANK_API UTankAimingComponent : public UActorComponent
{
	GENERATED_BODY()

public:	

	// Sets default values for this component's properties
	UFUNCTION(BlueprintCallable, Category = "Setup")
	void Initialise(UTankBarrel* BarrelToSet, UTurret* TurretToSet);
//	void SetBarrelReference(UTankBarrel* BarrelToSet);//delete by video 165 if still working 
//	void SetTurretReference(UTurret* TurretToSet);//delete by video 165 if still working 
	void AimAt(FVector HitLocation, float LaunchSpeed);
		// TODO add set Turret referance
protected:
	UPROPERTY(BlueprintReadOnly, Category = "State")
	EFiringState FiringState = EFiringState::Locked;
private:
	UTankAimingComponent();
	UTankBarrel* Barrel = nullptr;
	UTurret* Turret = nullptr;
	void MoveBarrelTowards(FVector AimDirection);

	//increase the speed at witch you can move barrel and turret( use decimal to slow)
	UPROPERTY(EditAnywhere, Category = "Setup")
	float AimSpeedMultiplier = 1;

};

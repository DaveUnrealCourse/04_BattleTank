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
class AProjectile;
class UTankBarrel;
class UTurret;

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class BATTLETANK_API UTankAimingComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	void BeginPlay();
	// Sets default values for this component's properties
	UFUNCTION(BlueprintCallable, Category = "Setup")
	void Initialise(UTankBarrel* BarrelToSet, UTurret* TurretToSet);
	UFUNCTION(BlueprintCallable, Category = "Setup")
	void Fire();

	void AimAt(FVector HitLocation);

protected:
	UPROPERTY(BlueprintReadOnly, Category = "State")
	EFiringState FiringState = EFiringState::Reloading;
private:
	UTankAimingComponent();

	virtual void TickComponent(float DeltaTime, enum ELevelTick TickType, FActorComponentTickFunction *ThisTickFunction)override;

	UTankBarrel* Barrel = nullptr;
	UTurret* Turret = nullptr;

	UPROPERTY(EditDefaultsOnly, Category = "Firing")
	TSubclassOf<AProjectile> ProjectileBluePrint;
	UPROPERTY(EditAnywhere, Category = "Firing")
	float LaunchSpeed = 600000; //TODO find out if this number is even close
	UPROPERTY(EditAnywhere, Category = "Firing")
	float ReloadTimeInSeconds = 3;

	void MoveBarrelTowards(FVector AimDirection);
	double LastFireTime = 0;
};

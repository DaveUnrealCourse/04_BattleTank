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
	Locked,
	AmmoOut
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
	UFUNCTION(BlueprintCallable, Category = "Setup")
	int32 GetAmmoCount() const;
	UPROPERTY(EditAnywhere, Category = "Setup")// consider EditDefaultsOnly
	int32 Ammo = 8;// how much Ammo you start with

	void AimAt(FVector HitLocation);

	EFiringState GetFiringState() const;

protected:
	UPROPERTY(BlueprintReadOnly, Category = "State")
	EFiringState FiringState = EFiringState::Reloading;
	

private:
	UTankAimingComponent();
	
	virtual void TickComponent(float DeltaTime, enum ELevelTick TickType, FActorComponentTickFunction *ThisTickFunction)override;
	bool IsBarrelMoving();
	UTankBarrel* Barrel = nullptr;
	UTurret* Turret = nullptr;

	UPROPERTY(EditDefaultsOnly, Category = "Firing")
	TSubclassOf<AProjectile> ProjectileBluePrint;
	UPROPERTY(EditAnywhere, Category = "Firing")
	float LaunchSpeed = 60000000; //TODO find out if this number is even close
	UPROPERTY(EditAnywhere, Category = "Firing")
	float ReloadTimeInSeconds = 3;
	FVector CurrentAimDirection;
	void MoveBarrelTowards(FVector AimDirection);
	
	
	double LastFireTime = 0;
	int RoundsLeft = 3;
};

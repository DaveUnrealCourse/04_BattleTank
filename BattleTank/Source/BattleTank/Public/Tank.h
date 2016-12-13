// Copyright David Thornton 2016

#pragma once
#include "GameFramework/Pawn.h"
#include "Tank.generated.h"// keep on the bottom

class UTankBarrel;// forward declaration
class UTankAimingComponent;
class AProjectile;

UCLASS()
class BATTLETANK_API ATank : public APawn
{
	GENERATED_BODY()

public:
	void AimAt(FVector HitLocation);
	void ATank::BeginPlay();
	UFUNCTION(BlueprintCallable, Category = "Setup")
	void Fire();
protected:
	UPROPERTY(BlueprintReadOnly)
		UTankAimingComponent* TankAimingComponent = nullptr;
private:
	// Sets default values for this pawn's properties
	ATank();
	// Called to bind functionality to input
	UPROPERTY(EditDefaultsOnly, Category = Setup)
		TSubclassOf<AProjectile> ProjectileBluePrint;
	UPROPERTY(EditAnywhere, Category = Firing)
		float LaunchSpeed = 600000; //TODO find out if this number is even close
	UPROPERTY(EditAnywhere, Category = Firing)
		float ReloadTimeInSeconds = 3;
	double LastFireTime = 0;
	UTankBarrel* Barrel = nullptr;
};
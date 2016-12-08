// Copyright David Thornton 2016

#pragma once
#include "GameFramework/Pawn.h"
#include "Tank.generated.h"// keep on the bottom

class UTankBarrel;// forward declaration
class UTurret;
class UTankAimingComponent;
class UTankMovementComponent;
class AProjectile;

UCLASS()
class BATTLETANK_API ATank : public APawn
{
	GENERATED_BODY()

public:
	void AimAt(FVector HitLocation);

	UFUNCTION(BlueprintCallable, Category = Setup)
	void SetBarrelReference(UTankBarrel* BarrelToSet);
	UFUNCTION(BlueprintCallable, Category = Setup)
	void SetTurretReference(UTurret* TurretToSet);
	UFUNCTION(BlueprintCallable, Category = Firing)
	void Fire();
protected:
	UTankAimingComponent* TankAimingComponent = nullptr;
	UPROPERTY(BlueprintReadOnly)
	UTankMovementComponent* TankMovementComponent =nullptr;
private:
	// Sets default values for this pawn's properties
	ATank();
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* InputComponent) override;
	UPROPERTY(EditDefaultsOnly, Category = Setup)
		TSubclassOf<AProjectile> ProjectileBluePrint;
	UPROPERTY(EditAnywhere, Category = Firing)
		float LaunchSpeed = 600000; //TODO find out if this number is even close
	UPROPERTY(EditAnywhere, Category = Firing)
		float ReloadTimeInSeconds = 3;
	double LastFireTime = 0;
	UTankBarrel* Barrel = nullptr;
};
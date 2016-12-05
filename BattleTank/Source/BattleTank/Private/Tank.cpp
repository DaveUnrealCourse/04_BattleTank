// Copyright David Thornton 2016

#include "BattleTank.h"
#include "Tank.h"
#include "TankAimingComponent.h"

// Sets default values
ATank::ATank()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;
	//No need To Protect Points as Added At Const
	TankAimingComponent = CreateDefaultSubobject<UTankAimingComponent>(FName("Aiming Component"));
}
void ATank::SetBarrelReference(UTankBarrel* BarrelToSet)
{
	if (!BarrelToSet) {UE_LOG(LogTemp, Warning, TEXT("No Barrel Set"));return; }
	TankAimingComponent->SetBarrelReference(BarrelToSet);
}
void ATank::SetTurretReference(UTurret* TurretToSet)
{
	if (!TurretToSet) {UE_LOG(LogTemp, Warning, TEXT("No Turret Set")); return; }
	TankAimingComponent->SetTurretReference(TurretToSet);
}
void ATank::Fire()
{
	UE_LOG(LogTemp, Warning, TEXT("Fire_Button Pressed!!!"));
}
// Called when the game starts or when spawned
void ATank::BeginPlay()
{
	Super::BeginPlay();
}
// Called to bind functionality to input
void ATank::SetupPlayerInputComponent(class UInputComponent* InputComponent)
{
	Super::SetupPlayerInputComponent(InputComponent);
}
void ATank::AimAt(FVector HitLocation)
{
	TankAimingComponent->AimAt(HitLocation, LaunchSpeed);
}
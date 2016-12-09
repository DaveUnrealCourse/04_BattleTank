// Copyright David Thornton 2016

#include "BattleTank.h"
#include "TankBarrel.h"
#include "Turret.h"
#include "TankAimingComponent.h"

// Sets default values for this component's properties
UTankAimingComponent::UTankAimingComponent()
{
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;//TODO should this really tick
}
void UTankAimingComponent::SetBarrelReference(UTankBarrel* BarrelToSet)
{
	Barrel = BarrelToSet;
}
void UTankAimingComponent::SetTurretReference(UTurret* TurretToSet)
{
	Turret = TurretToSet;
}
void UTankAimingComponent::AimAt(FVector HitLocation, float LaunchSpeed)
{
	if (!Barrel) { UE_LOG(LogTemp, Warning, TEXT("I Have No Barrel")); return;}
	if (!Turret) { UE_LOG(LogTemp, Warning, TEXT("I Have No Turret")); return;}
	FVector OutLaunchVelocity;
	FVector StartLocation = Barrel->GetSocketLocation(FName("Projectile"));
	bool bHaveAimSolution = UGameplayStatics::SuggestProjectileVelocity(
		this,
		OutLaunchVelocity,
		StartLocation,
		HitLocation,
		LaunchSpeed,
		false,
		0,
		0,
		ESuggestProjVelocityTraceOption::DoNotTrace);
	if (bHaveAimSolution)
	{
		auto AimDirection = OutLaunchVelocity.GetSafeNormal();	
		MoveBarrelTowards(AimDirection);
	}
	else
	{
		auto Name = GetOwner()->GetName();
		auto Time = GetWorld()->GetTimeSeconds();
		//UE_LOG(LogTemp, Warning, TEXT("%f %s : I Have No Aim Direction"), Time, Name);
	}
}
void UTankAimingComponent::MoveBarrelTowards(FVector AimDirection)
{
	// get the barrel direction from the suggested project velocity and rase it to mach 
	auto BarrelRotator = Barrel->GetForwardVector().Rotation();
	auto TurretRotator = Turret->GetForwardVector().Rotation();
	auto AimAsRotator = AimDirection.Rotation();
	auto DeltaRotatorBarrel = AimAsRotator - BarrelRotator;
	auto DeltaRotatorTurret = AimAsRotator - TurretRotator;
	Barrel->Elevate(DeltaRotatorBarrel.Pitch * AimSpeedMultiplier); //TODO Remove magic Number
	Turret->Azimuth(DeltaRotatorTurret.Yaw * AimSpeedMultiplier);
}
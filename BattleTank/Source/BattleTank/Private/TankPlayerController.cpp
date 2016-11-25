// Copyright David Thornton 2016
#include "BattleTank.h"
#include "Tank.h"
#include "TankPlayerController.h"


void ATankPlayerController::BeginPlay()
{
	Super::BeginPlay();
	auto ControlledTank = GetControlledTank();
	if (!ControlledTank) 
	{
		UE_LOG(LogTemp, Warning, TEXT("PlayerController Has No Tank!"));
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("PlayerController Has %s in their possession!!"), *(ControlledTank->GetName()));
	}
}

void ATankPlayerController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	AimTowardsCrosshair();
}
	
ATank* ATankPlayerController::GetControlledTank() const
{
	return Cast<ATank>(GetPawn());
}

void ATankPlayerController::AimTowardsCrosshair()
{
	if (!GetControlledTank()) { return; }

	FVector FHitLocation;//OUT Parameter
	if (GetSightRayHitLocation(FHitLocation))// has side efect will ray trace
	{

		UE_LOG(LogTemp, Warning, TEXT("Hit Location %s"), *FHitLocation.ToString());
		//TODO tell controlled tank to aim at this point
			//if it hits landscape
	}

}
//Get world location of linetrace through crosshair true if it hits landscape
bool ATankPlayerController::GetSightRayHitLocation(FVector& HitLocation) const
{
	HitLocation = FVector(1.0);
	return true;
}
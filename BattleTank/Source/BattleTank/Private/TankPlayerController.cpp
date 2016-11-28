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

		//UE_LOG(LogTemp, Warning, TEXT("look direction %s"), *FHitLocation.ToString());
		//TODO tell controlled tank to aim at this point
			//if it hits landscape
	}

}

//Get world location of linetrace through crosshair true if it hits landscape
bool ATankPlayerController::GetSightRayHitLocation(FVector& HitLocation) const
{
	//find the crosshair pos
	int32 ViewportSizeX, ViewportSizeY;
	GetViewportSize(ViewportSizeX, ViewportSizeY);
	auto ScreenLocation = FVector2D(ViewportSizeX * CrossHairXLocation, ViewportSizeY * CrossHairYLocation);
	UE_LOG(LogTemp, Warning, TEXT("Screen Location : %s"), *ScreenLocation.ToString());
	//Deproject the screen pos of the crosshair to world direction
	// line trace along look direction and see what we hit up to a max range
	HitLocation = FVector(1.0);//Gone?
	return true;
}
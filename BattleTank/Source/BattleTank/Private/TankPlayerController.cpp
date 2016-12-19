// Copyright David Thornton 2016
#include "BattleTank.h"
#include "TankAimingComponent.h"
#include "TankPlayerController.h"


void ATankPlayerController::BeginPlay()
{
	Super::BeginPlay();
	auto AimingComponent = GetPawn()->FindComponentByClass<UTankAimingComponent>();
	if (!ensure(AimingComponent)) { return; }
	FoundAimingComponent(AimingComponent);
//	if (!ensure(!ControlledTank)) { UE_LOG(LogTemp, Warning, TEXT("PlayerController Has No Tank!")); return; } causing unreal  to crash
}
void ATankPlayerController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	AimTowardsCrosshair();
}

void ATankPlayerController::AimTowardsCrosshair()
{
	if (!ensure(GetPawn())) { return; }
	auto AimingComponent = GetPawn()->FindComponentByClass<UTankAimingComponent>();
	if (!ensure(AimingComponent)) { return; }
	FVector HitLocation;//OUT Parameter
	bool bGotHitLocation = GetSightRayHitLocation(HitLocation);
	if (bGotHitLocation)// has side efect will ray trace
	{
		AimingComponent->AimAt(HitLocation);
	}
}
//Get world location of linetrace through crosshair true if it hits landscape
bool ATankPlayerController::GetSightRayHitLocation(FVector& HitLocation) const
{
	//find the crosshair pos
	int32 ViewportSizeX, ViewportSizeY;
	GetViewportSize(ViewportSizeX, ViewportSizeY);
	auto ScreenLocation = FVector2D(ViewportSizeX * CrossHairXLocation, ViewportSizeY * CrossHairYLocation);
	FVector LookDirection;
	//Deproject the screen pos of the crosshair to world direction
	if (GetLookDirection(ScreenLocation, LookDirection))
	{
// line trace along look direction and see what we hit up to a max range
		return GetLookVectorHitLocation(LookDirection, HitLocation);
//UE_LOG(LogTemp, Warning, TEXT("Hit Location : %s"), (*HitLocation.ToString()));
	}

	return false;
}
bool ATankPlayerController::GetLookVectorHitLocation(FVector LookDirection, FVector& HitLocation) const
{
	FHitResult HitResult;
	auto StartLocation = PlayerCameraManager->GetCameraLocation();
	auto EndLocation = StartLocation + (LookDirection * LineTraceRange);
	if (GetWorld()->LineTraceSingleByChannel(
		HitResult,
		StartLocation,
		EndLocation,
		ECollisionChannel::ECC_Visibility)
		)
	{
		HitLocation = HitResult.Location;
		// set hit location
		return true;
	}
	HitLocation = FVector(0);
	return false;
}
bool ATankPlayerController::GetLookDirection(FVector2D ScreenLocation, FVector& LookDirection) const
{
	FVector CameraWorldLocation;//Worthless not needed throw it away

	return DeprojectScreenPositionToWorld(
		ScreenLocation.X,
		ScreenLocation.Y,
		CameraWorldLocation, 
		LookDirection
	);
}

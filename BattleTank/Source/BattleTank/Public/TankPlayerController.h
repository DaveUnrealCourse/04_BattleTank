// Copyright David Thornton 2016

#pragma once
#include "GameFramework/PlayerController.h"
#include "TankPlayerController.generated.h"// must be the last include

class ATank;// forward declaration

UCLASS()
class BATTLETANK_API ATankPlayerController : public APlayerController
{
	GENERATED_BODY()

public:

private:
	ATank* GetControlledTank() const;

	virtual void BeginPlay() override;

	virtual void Tick(float DeltaSeconds) override;
	//start the tank moving the barrel so that a shot would hit where the crosshair intersects the world
	void AimTowardsCrosshair();
	//Return a OUT Parmeter ture if hit landscape
	bool GetSightRayHitLocation(FVector& HitLocation) const;
	UPROPERTY(EditAnywhere)
	float CrossHairXLocation = 0.5;
	UPROPERTY(EditAnywhere)
	float CrossHairYLocation = 0.3333;
	UPROPERTY(EditAnywhere)
	float LineTraceRange = 6000000;

	bool GetLookDirection(FVector2D ScreenLocation, FVector& LookDirection) const;
	bool GetLookVectorHitLocation(FVector LookDirection, FVector& HitLocation) const;
};

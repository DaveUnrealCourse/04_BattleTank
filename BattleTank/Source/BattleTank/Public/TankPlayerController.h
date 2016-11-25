// Copyright David Thornton 2016

#pragma once
#include "Tank.h"
#include "GameFramework/PlayerController.h"
#include "TankPlayerController.generated.h"// must be the last include

/**
 * 
 */
UCLASS()
class BATTLETANK_API ATankPlayerController : public APlayerController
{
	GENERATED_BODY()

public:
	ATank* GetControlledTank() const;

	virtual void BeginPlay() override;

	virtual void Tick(float DeltaSeconds) override;
	//start the tank moving the barrel so that a shot would hit wherte the crosshair intersects the world
	void AimTowardsCrosshair();
	FVector FHitResult;

private:
	//Return a OUT Parmeter ture if hit landscape
	bool GetSightRayHitLocation(FVector& HitLocation) const;
};

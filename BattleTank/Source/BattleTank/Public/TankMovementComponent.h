// Copyright David Thornton 2016

#pragma once

#include "GameFramework/NavMovementComponent.h"
#include "TankMovementComponent.generated.h"
class UTankTrack;

/**
 * Responable for moving the tank
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class BATTLETANK_API UTankMovementComponent : public UNavMovementComponent
{
	GENERATED_BODY()
	
public:
	UFUNCTION(BlueprintCallable, Category = "Setup")
	void Initialise(UTankTrack* LeftTrackToSet, UTankTrack* RightTrackToSet);
	UFUNCTION(BlueprintCallable, Category = "Input")
	void IntendMoveForward(float Throw);
	UFUNCTION(BlueprintCallable, Category = "Input")
	void IntendTurnRight(float Throw);
private:
	//Called from the pathfinding logic by the AI Controllers
	virtual void RequestDirectMove(const FVector& MoveVelocity, bool bForceMaxSpeed) override;
	//Tracks
	UTankTrack* LeftTrack = nullptr;
	UTankTrack* RightTrack = nullptr;
};
// Copyright David Thornton 2016

#pragma once
#include "AIController.h"
#include "TankAIController.generated.h"

// forward declaration
class TankAimingComponent;

UCLASS()
class BATTLETANK_API ATankAIController : public AAIController
{
	GENERATED_BODY()
public:
	void BeginPlay();

private:
//	virtual void BeginPlay() override;
	virtual void Tick(float DeltaSeconds) override;
	float AcceptanceRadis = 3000;// how close the AI can Get to the player
};

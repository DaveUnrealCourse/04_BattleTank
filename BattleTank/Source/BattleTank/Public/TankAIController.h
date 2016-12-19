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
protected:
	UPROPERTY(EditAnywhere, Category = "Setup")// consider EditDefaultsOnly
	float AcceptanceRadis = 8000;// how close the AI can Get to the player
private:
//	virtual void BeginPlay() override;
	virtual void Tick(float DeltaSeconds) override;
	
};

// Copyright David Thornton 2016

#pragma once

#include "AIController.h"
#include "Tank.h"
#include "TankAIController.generated.h"

/**
 * 
 */
UCLASS()
class BATTLETANK_API ATankAIController : public AAIController
{
	GENERATED_BODY()
public:

private:

	ATank* GetControlledTank() const;


	virtual void BeginPlay() override;
	
	ATank* GetPlayerTank() const;


	virtual void Tick(float DeltaSeconds) override;
};

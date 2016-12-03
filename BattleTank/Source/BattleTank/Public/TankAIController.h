// Copyright David Thornton 2016

#pragma once
#include "AIController.h"
#include "TankAIController.generated.h"

class ATank;// forward declaration

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

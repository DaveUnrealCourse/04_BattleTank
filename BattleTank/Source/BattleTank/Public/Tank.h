// Copyright David Thornton 2016

#pragma once
#include "GameFramework/Pawn.h"
#include "Tank.generated.h"// keep on the bottom

UCLASS()
class BATTLETANK_API ATank : public APawn
{
	GENERATED_BODY()

public:
	//void ATank::BeginPlay();
private:
	// Sets default values for this pawn's properties
	ATank();
};
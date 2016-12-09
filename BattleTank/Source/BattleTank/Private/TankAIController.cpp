// Copyright David Thornton 2016

#include "BattleTank.h"
#include "tank.h"
#include "TankAIController.h"

//void ATankAIController::BeginPlay(){Super::BeginPlay();}
void ATankAIController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	auto ControlledTank = Cast<ATank>(GetPawn());
	auto PlayerTank = GetWorld()->GetFirstPlayerController()->GetPawn();
	if (PlayerTank) 
	{
		//Move To Player
		MoveToActor(PlayerTank, AcceptanceRadis);//TODO check Radis is in cm
		//Aim Towards player
		ControlledTank->AimAt(PlayerTank->GetActorLocation());
		ControlledTank->Fire();// TODO Limit Fire Rate
	}
}


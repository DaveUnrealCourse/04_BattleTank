// Copyright David Thornton 2016

#include "BattleTank.h"
#include "TankAimingComponent.h"
#include "TankAIController.h"
//depends on movement component via pathfinding system

void ATankAIController::BeginPlay(){Super::BeginPlay();}

void ATankAIController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	auto PlayerTank = GetWorld()->GetFirstPlayerController()->GetPawn();
	auto ControlledTank = GetPawn();
	if (!ensure(PlayerTank && ControlledTank)) { return; }
	
	//Move To Player
	MoveToActor(PlayerTank, AcceptanceRadis);

	//Aim Towards player
	auto AimingComponent = ControlledTank->FindComponentByClass<UTankAimingComponent>();
	AimingComponent->AimAt(PlayerTank->GetActorLocation());
	//TODO  if aiming or locked than fire
	if (AimingComponent->GetFiringState() == EFiringState::Locked) 
	{
		AimingComponent->Fire(); 
	}
}


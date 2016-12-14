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
	MoveToActor(PlayerTank, AcceptanceRadis);//TODO check Radis is in cm

	//Aim Towards player
	auto AimingComponent = ControlledTank->FindComponentByClass<UTankAimingComponent>();
	AimingComponent->AimAt(PlayerTank->GetActorLocation());
	//ControlledTank->Fire();// TODO Fix Fire
	
}


// Copyright David Thornton 2016

#include "BattleTank.h"
#include "tank.h"
#include "TankAIController.h"

//void ATankAIController::BeginPlay(){Super::BeginPlay();}
void ATankAIController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	auto AITank = Cast<ATank>(GetPawn());
	auto PlayerTank = GetWorld()->GetFirstPlayerController()->GetPawn();
	if (!AITank && !PlayerTank) { return; }
	AITank->AimAt(PlayerTank->GetActorLocation());
	AITank->Fire();// TODO Limit Fire Rate
}


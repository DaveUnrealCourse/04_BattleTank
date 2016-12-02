// Copyright David Thornton 2016

#include "BattleTank.h"
#include "tank.h"
#include "TankAIController.h"

void ATankAIController::BeginPlay()
{
	Super::BeginPlay();
	auto PlayerTank = GetPlayerTank();
	auto ControlledTank = GetControlledTank();
	if (!PlayerTank)
	{
		UE_LOG(LogTemp, Warning, TEXT("AI Controller %s  cant find a Player Pawn"), *(ControlledTank->GetName()), *(PlayerTank->GetName()));
	}
	else
	{
		//UE_LOG(LogTemp, Warning, TEXT("AI Controller %s Found Player Pawn %s"), *(ControlledTank->GetName()), *(PlayerTank->GetName()));
	}
}

ATank* ATankAIController::GetControlledTank() const
{
	return Cast<ATank>(GetPawn());
}

ATank* ATankAIController::GetPlayerTank() const
{
	auto PlayerPawn = GetWorld()->GetFirstPlayerController()->GetPawn();
	auto ControlledTank = GetControlledTank();
	if (!PlayerPawn){return nullptr;}
	return Cast<ATank>(PlayerPawn);
}
// Called every frame
void ATankAIController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	if (GetPlayerTank())
	{
		GetControlledTank()->AimAt(GetPlayerTank()->GetActorLocation());
	}
}


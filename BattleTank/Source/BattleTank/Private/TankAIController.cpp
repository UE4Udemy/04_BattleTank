// Fill out your copyright notice in the Description page of Project Settings.

#include "BattleTank.h"
#include "Tank.h"
#include "TankAIController.h"

void ATankAIController::BeginPlay()
{
	Super::BeginPlay();
}

void ATankAIController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	auto AIControlledTank = Cast<ATank>(GetPawn());
	auto PlayerTank = Cast<ATank>(GetWorld()->GetFirstPlayerController()->GetPawn());
	if (PlayerTank)
	{
		// move towards player
		MoveToActor(PlayerTank, AcceptanceRadius); // TODO check radius is in cm

		// aim towards the player
		AIControlledTank->AimAt(PlayerTank->GetActorLocation());

		// fire
		AIControlledTank->Fire(); // TODO limit fire rate
	}
}






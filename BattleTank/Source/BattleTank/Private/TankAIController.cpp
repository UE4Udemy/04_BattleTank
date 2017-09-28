// Copyright Dig Bick

#include "BattleTank.h"
#include "TankAimingComponent.h"
#include "TankAIController.h"
#include "Tank.h"

void ATankAIController::BeginPlay()
{
	Super::BeginPlay();
}

void ATankAIController::SetPawn(APawn* InPawn)
{
	Super::SetPawn(InPawn);
	if (InPawn)
	{
		auto PossessedTank = Cast<ATank>(InPawn);
		if (!ensure(PossessedTank)) { return; }

		PossessedTank->OnDeath.AddUniqueDynamic(this, &ATankAIController::OnPossessedTankDeath);
	}
}

void ATankAIController::OnPossessedTankDeath()
{
	if (!ensure(GetPawn())) { return; }
	GetPawn()->DetachFromControllerPendingDestroy();
}

void ATankAIController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	auto AIControlledTank = GetPawn();
	auto PlayerTank = GetWorld()->GetFirstPlayerController()->GetPawn();
	if (!ensure(PlayerTank && AIControlledTank)) { return; }
	
	// move towards player
	MoveToActor(PlayerTank, AcceptanceRadius); // TODO check radius is in cm

	// aim towards the player
	auto AimingComponent = AIControlledTank->FindComponentByClass<UTankAimingComponent>();
	AimingComponent->AimAt(PlayerTank->GetActorLocation());

	AimingComponent->Fire(); // TODO limit fire rate		
}






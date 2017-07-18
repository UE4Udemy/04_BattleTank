// Fill out your copyright notice in the Description page of Project Settings.

#include "BattleTank.h"
#include "TankPlayerController.h"

void ATankPlayerController::BeginPlay()
{
	Super::BeginPlay();

	auto ControlledTank = GetControlledTank();
	if (!ControlledTank)
	{
		UE_LOG(LogTemp, Warning, TEXT("No possessed tank"));
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("Possessed: %s"), *(ControlledTank->GetName()));
	}
}

ATank* ATankPlayerController::GetControlledTank() const
{
	return Cast<ATank>(GetPawn());
}

void ATankPlayerController::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );
	AimTowardsCrosshair();
}

void ATankPlayerController::AimTowardsCrosshair()
{
	if (!GetControlledTank()) { return; }

	FVector HitLocation; // out param
	if (bGetSightRayHitLocation(HitLocation))
	{
		// UE_LOG(LogTemp, Warning, TEXT("Look Direction: %s"), *HitLocation.ToString());
		// TODO tell controlled tank to aim at this point
	}
	
}

// get world location if linetrace through crosshair, true if landscape hit
bool ATankPlayerController::bGetSightRayHitLocation(FVector& HitLocation) const
{
	// find crosshair position in pixel coords
	int32 ViewportSizeX, ViewortSizeY;
	GetViewportSize(ViewportSizeX, ViewortSizeY);
	auto ScreenLocation = FVector2D(ViewportSizeX * CrossHairXLocation, ViewortSizeY * CrossHairYLocation);
	
	// "de-project" screen position of crosshair to world direction
	// line-trace along that look direction, see what we hit (up to max range)
	return true;
}










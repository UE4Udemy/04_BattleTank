// Fill out your copyright notice in the Description page of Project Settings.

#include "BattleTank.h"
#include "TankPlayerController.h"

void ATankPlayerController::BeginPlay()
{
	Super::BeginPlay();

	auto ControlledTank = GetControlledTank();
	if (!ControlledTank)
	{
		//UE_LOG(LogTemp, Warning, TEXT("No possessed tank"));
	}
	else
	{
		//UE_LOG(LogTemp, Warning, TEXT("Possessed: %s"), *(ControlledTank->GetName()));
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
		GetControlledTank()->AimAt(HitLocation);
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
	FVector LookDirection;
	if (bGetLookDirection(ScreenLocation, LookDirection))
	{
		// line-trace along that look direction, see what we hit (up to max range)
		bGetLookVectorHitLocation(LookDirection, HitLocation);
	}

	// line-trace along that look direction, see what we hit (up to max range)
	return true;
}

bool ATankPlayerController::bGetLookDirection(FVector2D ScreenLocation, FVector& LookDirection) const
{
	FVector CameraWorldLocation; // to be discarded
	return DeprojectScreenPositionToWorld(
		ScreenLocation.X,
		ScreenLocation.Y,
		CameraWorldLocation,
		LookDirection
	);
}

bool ATankPlayerController::bGetLookVectorHitLocation(FVector LookDirection, FVector& HitLocation) const
{
	FHitResult HitResult;
	auto StartLocation = PlayerCameraManager->GetCameraLocation();
	auto EndLocation = StartLocation + (LookDirection * LineTraceRange);
	if (GetWorld()->LineTraceSingleByChannel(
		HitResult,
		StartLocation,
		EndLocation,
		ECollisionChannel::ECC_Visibility)
		)
	{ 
		HitLocation = HitResult.Location;
		return true;
	}
	HitLocation = FVector(0);
	return false; // line trace failed	
}










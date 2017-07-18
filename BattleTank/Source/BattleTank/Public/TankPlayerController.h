// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Tank.h"
#include "GameFramework/PlayerController.h"
#include "TankPlayerController.generated.h"

/**
 * 
 */
UCLASS()
class BATTLETANK_API ATankPlayerController : public APlayerController
{
	GENERATED_BODY()

public:
	ATank* GetControlledTank() const;

	virtual void BeginPlay() override;

	virtual void Tick( float DeltaTime ) override;

	// start the tank moving the barrel, allow shot to hit
	// where crosshair intersects world
	void AimTowardsCrosshair();

private:
	// returns true if landscape hit
	bool bGetSightRayHitLocation(FVector& HitLocation) const;
};

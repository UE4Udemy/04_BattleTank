// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/PlayerController.h"
#include "TankPlayerController.generated.h"

class ATank;

/**
 * 
 */
UCLASS()
class BATTLETANK_API ATankPlayerController : public APlayerController
{
	GENERATED_BODY()

public:
	virtual void BeginPlay() override;

	virtual void Tick(float DeltaTime) override;

private:
	ATank* GetControlledTank() const;

	// start the tank moving the barrel, allow shot to hit
	// where crosshair intersects world
	void AimTowardsCrosshair();

	UPROPERTY(EditAnywhere)
	float CrossHairXLocation = 0.5;

	UPROPERTY(EditAnywhere)
	float CrossHairYLocation = 0.33333;

	UPROPERTY(EditAnywhere)
	float LineTraceRange = 1000000;

	// returns true if landscape hit
	bool bGetSightRayHitLocation(FVector& HitLocation) const;

	bool bGetLookDirection(FVector2D ScreenLocation, FVector& LookDirection) const;

	bool bGetLookVectorHitLocation(FVector LookDirection, FVector& HitLocation) const;
};

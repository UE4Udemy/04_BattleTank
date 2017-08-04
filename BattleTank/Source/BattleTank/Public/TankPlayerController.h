// Copyright Dig Bick

#pragma once

#include "GameFramework/PlayerController.h"
#include "TankPlayerController.generated.h"

class ATank;
class UTankAimingComponent;

/**
 * Responsible for aiming 
 */
UCLASS()
class BATTLETANK_API ATankPlayerController : public APlayerController
{
	GENERATED_BODY()

public:
	virtual void BeginPlay() override;

	virtual void Tick(float DeltaTime) override;

protected:
	UFUNCTION(BlueprintCallable, Category = "Setup")
	ATank* GetControlledTank() const;

	UFUNCTION(BlueprintImplementableEvent, Category = "Setup")
	void FoundAimingComp(UTankAimingComponent* AimCompRef);

private:
	// start the tank moving the barrel, allow shot to hit
	// where crosshair intersects world
	void AimTowardsCrosshair();

	UPROPERTY(EditDefaultsOnly)
	float CrossHairXLocation = 0.5;

	UPROPERTY(EditDefaultsOnly)
	float CrossHairYLocation = 0.33333;

	UPROPERTY(EditDefaultsOnly)
	float LineTraceRange = 1000000;

	// returns true if landscape hit
	bool bGetSightRayHitLocation(FVector& HitLocation) const;

	bool bGetLookDirection(FVector2D ScreenLocation, FVector& LookDirection) const;

	bool bGetLookVectorHitLocation(FVector LookDirection, FVector& HitLocation) const;
};

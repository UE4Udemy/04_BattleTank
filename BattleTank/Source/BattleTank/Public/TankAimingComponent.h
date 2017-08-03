// Copyright Dig Bick

#pragma once

#include "Components/ActorComponent.h"
#include "TankAimingComponent.generated.h"

// enum for firing state
UENUM()
enum class EFiringState : uint8
{
	Aiming,
	Locked,
	Reloading
};

// forward declaration
class UTankTurret;
class UTankBarrel; 

// Holds barrels properties and elevate method
UCLASS(meta = (BlueprintSpawnableComponent))
class BATTLETANK_API UTankAimingComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	UFUNCTION(BlueprintCallable, Category = "Setup")
	void Initialise(UTankBarrel* BarrelToSet, UTankTurret* TurretToSet);

	void AimAt(FVector HitLocation, float LaunchSpeed);

protected:
	UPROPERTY(BlueprintReadOnly, Category = "State")
	EFiringState FiringState = EFiringState::Reloading;

private:	
	// Sets default values for this component's properties
	UTankAimingComponent();

	UTankBarrel* Barrel = nullptr;
	UTankTurret* Turret = nullptr;

	void MoveBarrelTowards(FVector AimDirection);
};

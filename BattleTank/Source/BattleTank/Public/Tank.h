// Copyright Dig Bick

#pragma once

#include "GameFramework/Pawn.h"
#include "Tank.generated.h"

// Forward declarations
class AProjectile;
class UTankTurret;
class UTankBarrel;

UCLASS()
class BATTLETANK_API ATank : public APawn
{
	GENERATED_BODY()

public:

	UFUNCTION(BlueprintCallable)
	void Fire();

private:	
	// Sets default values for this pawn's properties
	ATank();	

	UPROPERTY(EditDefaultsOnly, Category = "Setup")
	TSubclassOf<AProjectile> ProjectileBlueprint;

	// TODO remove once firing is moved to aiming comp
	UPROPERTY(EditDefaultsOnly, Category = "Firing")
	float LaunchSpeed = 14600; 

	UPROPERTY(EditDefaultsOnly, Category = "Firing")
	double LastFireTime = 0;

	UTankBarrel* Barrel = nullptr; // TODO remove

	float ReloadTimeInSeconds = 3;

	virtual void BeginPlay() override;

};

// Copyright Dig Bick

#pragma once

#include "GameFramework/Pawn.h"
#include "Tank.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FTankDelegate);

UCLASS()
class BATTLETANK_API ATank : public APawn
{
	GENERATED_BODY()

public:
	virtual float TakeDamage(float DamageAmount, struct FDamageEvent const & DamageEvent, class AController * EventInstigator, AActor * DamageCauser) override;

	virtual void BeginPlay() override;

	//return as percentage of startinghealth, from 0 to 100
	UFUNCTION(BlueprintPure, Category = "Health")
	float GetHealthPercent();

	FTankDelegate OnDeath;

private:	
	// Sets default values for this pawn's properties
	ATank();	

	UPROPERTY(EditDefaultsOnly, Category = "Setup")
	float StartingHealth = 100.f;

	UPROPERTY(VisibleAnyWhere, Category = "Health")
	float CurrentHealth; // init in Begin Play
};

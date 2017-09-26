// Copyright Dig Bick

#pragma once

#include "GameFramework/Pawn.h"
#include "Tank.generated.h"

UCLASS()
class BATTLETANK_API ATank : public APawn
{
	GENERATED_BODY()

public:
	virtual float TakeDamage(float DamageAmount, struct FDamageEvent const & DamageEvent, class AController * EventInstigator, AActor * DamageCauser) override;

	//return as percentage of startinghealth, from 0 to 100
	UFUNCTION(BlueprintPure, Category = "Health")
	float GetHealthPercent() const;

private:	
	// Sets default values for this pawn's properties
	ATank();	

	UPROPERTY(EditDefaultsOnly, Category = "Setup")
	float StartingHealth = 100.f;

	UPROPERTY(VisibleAnyWhere, Category = "Health")
	float CurrentHealth = StartingHealth;
};

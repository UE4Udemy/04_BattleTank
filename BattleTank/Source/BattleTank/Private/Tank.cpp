// Copyright Dig Bick

#include "BattleTank.h"
#include "Tank.h"


float ATank::GetHealthPercent()
{
	return CurrentHealth / StartingHealth;
}

// Sets default values
ATank::ATank()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;
}

void ATank::BeginPlay()
{
	Super::BeginPlay();
	CurrentHealth = StartingHealth;
}

float ATank::TakeDamage(float DamageAmount, struct FDamageEvent const & DamageEvent, class AController * EventInstigator, AActor * DamageCauser)
{
	
	float DamageToApply = Super::TakeDamage(DamageAmount, DamageEvent, EventInstigator, DamageCauser);
	if (CurrentHealth > 0.f)
	{
		CurrentHealth -= DamageToApply;
	}
	else
	{
		OnDeath.Broadcast();
	}

	return DamageToApply;
}




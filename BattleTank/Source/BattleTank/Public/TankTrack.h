// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Components/StaticMeshComponent.h"
#include "TankTrack.generated.h"

/**
 * Tank track is used to set max driving force, and to apply forces to tank
 */
UCLASS(meta = (BlueprintSpawnableComponent))
class BATTLETANK_API UTankTrack : public UStaticMeshComponent
{
	GENERATED_BODY()
	
public:
	// sets throttle btwn -1 and +1
	UFUNCTION(BluePrintCallable, Category = Input)
	void SetThrottle(float Throttle);
	
	// max force per track, in Newtons
	UPROPERTY(EditDefaultsOnly)
	float TrackMaxDrivingForce = 550200; // assuming 10m/s/s acceleration
};

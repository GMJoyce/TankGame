// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/StaticMeshComponent.h"
#include "TankTurret.generated.h"

/**
 * 
 */


UCLASS(meta = (BlueprintSpawnableComponent))
class TANKBATTLEGAME_API UTankTurret : public UStaticMeshComponent
{
	GENERATED_BODY()
	
public:

	void RotateTurret(float RelativeSpeed);
	
private:

	UPROPERTY(EditAnywhere, Category = Setup)
	float MaxDegreesPerSecond = 90.f;
};

// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/StaticMeshComponent.h"
#include "TankBarrel.generated.h"

/**
 * 
 */
// big ol barrel for blasting some bitches
UCLASS(meta = (BlueprintSpawnableComponent))
class TANKBATTLEGAME_API UTankBarrel : public UStaticMeshComponent
{
	GENERATED_BODY()
	
public:
	void Elevate(float RelativeSpeed);

	
private:
	UPROPERTY(EditAnywhere, Category = Setup)
	float MaxDegreesPerSecond = 45;
	UPROPERTY(EditAnywhere, Category = Setup)
	float MaxElevation = 70.f;
	UPROPERTY(EditAnywhere, Category = Setup)
	float MinElevation = -10.f;
	
};

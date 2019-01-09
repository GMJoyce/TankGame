// Fill out your copyright notice in the Description page of Project Settings.

#pragma once


#include "CoreMinimal.h"
#include "AIController.h"
#include "MyTankAIController.generated.h"

class AMyTank;

/**
 * 
 */

UCLASS()


class TANKBATTLEGAME_API AMyTankAIController : public AAIController
{
	GENERATED_BODY()

private:
	// fires event at the beginning of play or when spawned
	void BeginPlay() override;

	void Tick(float DeltaTime) override;

	// gets the tank controlled by the AI
	
	APawn* PlayerTank = nullptr;

	// How close will the AI Tank move to the player
	float AcceptanceRadius = 3000.0f;

};

// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "MyTank.h"
#include "CoreMinimal.h"
#include "AIController.h"
#include "MyTankAIController.generated.h"

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
	AMyTank* GetPlayerTank() const;
	
	APawn* PlayerTank = nullptr;

	AMyTank* GetControlledTank() const;
};

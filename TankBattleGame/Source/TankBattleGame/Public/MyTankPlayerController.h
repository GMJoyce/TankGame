// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "MyTank.h"
#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "MyTankPlayerController.generated.h"

/**
 * 
 */
UCLASS()
class TANKBATTLEGAME_API AMyTankPlayerController : public APlayerController
{
	GENERATED_BODY()
	
public:
	// gets the tank controlled by the player
	AMyTank * GetControlledTank() const;

	// called when the game starts or actor is spawned
	void BeginPlay() override;
};

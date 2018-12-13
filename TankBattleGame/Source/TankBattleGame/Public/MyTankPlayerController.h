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
	virtual void BeginPlay() override;
	// called each frame of game
	virtual void Tick(float DeltaTime);

private:
	void AimTowardsCrosshair();

	//Return an OUT parameter, true if hit landscape or tank
	bool GetSightRayHitLocation(FVector& OutHitLocation) const;
};

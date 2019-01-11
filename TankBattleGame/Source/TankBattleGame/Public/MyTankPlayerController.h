// Fill out your copyright notice in the Description page of Project Settings.

#pragma once


#include "CoreMinimal.h"
#include "TankAimingComponent.h"
#include "GameFramework/PlayerController.h"
#include "MyTankPlayerController.generated.h"

/**
 * responsible for helping the player aim
 */

class AMyTank;
class UTankAimingComponent;

UCLASS()
class TANKBATTLEGAME_API AMyTankPlayerController : public APlayerController
{
	GENERATED_BODY()
	
protected:
	UFUNCTION(BlueprintCallable, Category = "Setup")
	AMyTank * GetControlledTank() const;

	UFUNCTION(BlueprintImplementableEvent, Category = "Setup")
	void FoundAimingComponent(UTankAimingComponent* AimCompRef);


private:
	// gets the tank controlled by the player
	

	// called when the game starts or actor is spawned
	virtual void BeginPlay() override;
	// called each frame of game
	virtual void Tick(float DeltaTime);

	void AimTowardsCrosshair();

	//Return an OUT parameter, true if hit landscape or tank
	bool GetSightRayHitLocation(FVector& OutHitLocation) const;

	UPROPERTY(EditAnywhere)
	float CrossHairXLocation = 0.5;
	UPROPERTY(EditAnywhere)
	float CrossHairYLocation = 0.3333;
	UPROPERTY(EditAnywhere)
	float LineTraceRange = 50000000;

	FVector2D ScreenLocation;
	bool GetLookDirection(FVector2D ScreenLocation, FVector& LookDirection) const;
	bool GetLookVectorHitLocation(FVector LookDirection, FVector& HitLocation) const;
};

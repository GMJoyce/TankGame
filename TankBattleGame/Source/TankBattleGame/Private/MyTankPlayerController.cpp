// Fill out your copyright notice in the Description page of Project Settings.

#include "MyTankPlayerController.h"


void AMyTankPlayerController::BeginPlay()
{
	Super::BeginPlay();

	auto ControlledTank = GetControlledTank();
	if (!ControlledTank)
	{
		UE_LOG(LogTemp, Warning, TEXT("PlayerController not found tank"))
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("PlayerController BeginPlay, Controlled Tank is %s "), *ControlledTank->GetName())
	}
}

void AMyTankPlayerController::Tick(float DeltaTime)
{
	Super::Tick( DeltaTime );
	AimTowardsCrosshair();
	// UE_LOG(LogTemp, Warning, TEXT("ticking playercontroller"));
}


AMyTank* AMyTankPlayerController::GetControlledTank() const
{
	return Cast<AMyTank>(GetPawn());
}

// start the tank moving the barrel so that a shot would hit where
// the crosshair intersects the worldspace
void AMyTankPlayerController::AimTowardsCrosshair()
{
	if (!GetControlledTank()) { return; }
	
	// Get world location through crosshair by line tracing
	// if it hits the landscape or an enemy tank 
		// Tell controlled tank to aim at this point

}

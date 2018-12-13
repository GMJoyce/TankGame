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


AMyTank* AMyTankPlayerController::GetControlledTank() const
{
	return Cast<AMyTank>(GetPawn());
}



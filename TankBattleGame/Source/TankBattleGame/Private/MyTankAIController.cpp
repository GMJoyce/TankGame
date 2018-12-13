// Fill out your copyright notice in the Description page of Project Settings.


#include "Runtime/Engine/Classes/GameFramework/PlayerController.h"
#include "Runtime/Engine/Classes/Engine/World.h"
#include "MyTankAIController.h"

void AMyTankAIController::BeginPlay()
{
	Super::BeginPlay();

	auto PlayerTank = GetPlayerTank();
	if (!PlayerTank)
	{
		UE_LOG(LogTemp, Warning, TEXT("AIController can't find player pawn"))
	}
	else 
	{
		UE_LOG(LogTemp, Warning, TEXT("AI Controller found player controlled tank at %s "), *PlayerTank->GetName())
	}
}



AMyTank* AMyTankAIController::GetPlayerTank() const
{
	auto PlayerPawn = GetWorld()->GetFirstPlayerController()->GetPawn();
	if (!PlayerPawn) { return nullptr; }
	return Cast<AMyTank>(PlayerPawn);
}
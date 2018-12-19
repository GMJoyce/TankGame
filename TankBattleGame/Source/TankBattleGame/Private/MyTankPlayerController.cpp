// Fill out your copyright notice in the Description page of Project Settings.

#include "MyTankPlayerController.h"
#include "MyTank.h"
#include "Runtime/Engine/Classes/Engine/World.h"




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
	Super::Tick(DeltaTime);
	AimTowardsCrosshair();
	// UE_LOG(LogTemp, Warning, TEXT("ticking playercontroller"));
}


AMyTank* AMyTankPlayerController::GetControlledTank() const
{
	return Cast<AMyTank>(GetPawn());
}


void AMyTankPlayerController::AimTowardsCrosshair()
{
	if (!GetControlledTank()) { return; }
	
	FVector HitLocation;	// Tell controlled tank to aim at this point
	if (GetSightRayHitLocation(HitLocation))
	{ 
		GetControlledTank()->AimAt(HitLocation);
	}
}


// Get world location through crosshair by line tracing
bool AMyTankPlayerController::GetSightRayHitLocation(FVector& HitLocation) const
{
	// find crosshair position
	int32 ViewPortSizeX, ViewPortSizeY;
	GetViewportSize(ViewPortSizeX, ViewPortSizeY);
	auto ScreenLocation = FVector2D(ViewPortSizeX * CrossHairXLocation, ViewPortSizeY * CrossHairYLocation);

	FVector LookDirection;
	if (GetLookDirection(ScreenLocation, LookDirection))
	{
		GetLookVectorHitLocation(LookDirection, HitLocation);
	}
	
	return true;
}


bool AMyTankPlayerController::GetLookVectorHitLocation(FVector LookDirection, FVector& HitLocation) const
{
	FHitResult HitResult;
	auto StartLocation = PlayerCameraManager->GetCameraLocation();
	auto EndLocation = StartLocation + (LookDirection * LineTraceRange);
	 if (GetWorld()->LineTraceSingleByChannel(HitResult, StartLocation, EndLocation,ECollisionChannel::ECC_Visibility))	
	 {
			HitLocation = HitResult.Location;
			return true;
	 }
	 else 
	 {
		 HitLocation = FVector(0);
		 return false;
	 }
		
}
		

bool AMyTankPlayerController::GetLookDirection(FVector2D ScreenLocation, FVector & LookDirection) const
{
	FVector CameraWorldLocation;

	return DeprojectScreenPositionToWorld(
		ScreenLocation.X, 
		ScreenLocation.Y, 
		CameraWorldLocation, 
		LookDirection
	);
}


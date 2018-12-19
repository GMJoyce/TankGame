// Fill out your copyright notice in the Description page of Project Settings.

#include "MyTank.h"
#include "TankAimingComponent.h"
#include "Runtime/Core/Public/Math/Vector.h"

// Sets default values
AMyTank::AMyTank()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	// no need to protect pointers as added at construction
	TankAimingComponent = CreateDefaultSubobject<UTankAimingComponent>(FName("Aiming Component"));
}

// Called when the game starts or when spawned
void AMyTank::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AMyTank::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AMyTank::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
}

void AMyTank::Fire()
{
	UE_LOG(LogTemp, Warning, TEXT("FIRE"))
}


void AMyTank::AimAt(FVector HitLocation)
{
	TankAimingComponent->AimAt(HitLocation, ProjectileSpeed);
}


void AMyTank::SetBarrelReference(UTankBarrel * BarrelToSet)
{
	TankAimingComponent->SetBarrelReference(BarrelToSet);
}

void AMyTank::SetTurretReference(UTankTurret * TurretToSet)
{
	TankAimingComponent->SetTurretReference(TurretToSet);
}

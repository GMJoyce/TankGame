// Fill out your copyright notice in the Description page of Project Settings.

#include "MyTank.h"
#include "TankAimingComponent.h"
#include "TankBarrel.h"
#include "Projectile.h"
#include "Runtime/Core/Public/Math/Vector.h"
#include "Runtime/Engine/Classes/Engine/World.h"


// Sets default values
AMyTank::AMyTank()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void AMyTank::BeginPlay()
{
	Super::BeginPlay();
	TankAimingComponent = FindComponentByClass<UTankAimingComponent>();
}

// Called every frame
void AMyTank::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}



void AMyTank::Fire()
{
	if (!ensure(Barrel)) { return; }
	bool isReloaded = (FPlatformTime::Seconds() - LastFireTime) > ReloadTimeSeconds;
	
	if (isReloaded)
	{
		// spawn a projectile at the socket location on the barrel
		auto Projectile = GetWorld()->SpawnActor<AProjectile>(
			ProjectileBlueprint,
			Barrel->GetSocketLocation(FName("BarrelEnd")),
			Barrel->GetSocketRotation(FName("BarrelEnd"))
			);
		Projectile->LaunchProjectile(ProjectileSpeed);
		LastFireTime = FPlatformTime::Seconds();
	}
}


void AMyTank::AimAt(FVector HitLocation)
{
	if (!ensure(TankAimingComponent)) { return; }
	TankAimingComponent->AimAt(HitLocation, ProjectileSpeed);
}
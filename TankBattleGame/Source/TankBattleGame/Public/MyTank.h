// Fill out your copyright notice in the Description page of Project Settings.

#pragma once


#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "MyTank.generated.h"

class UTankBarrel;				// Forward declaration
class UTankTurret;				// Forward declaration
class UTankAimingComponent;		// Forward declaration
class AProjectile;


UCLASS()
class TANKBATTLEGAME_API AMyTank : public APawn
{
	GENERATED_BODY()

public:
	void AimAt(FVector HitLocation);

	UFUNCTION(BlueprintCallable)
	void Fire();

protected:
	UPROPERTY(BlueprintReadOnly)
	UTankAimingComponent * TankAimingComponent = nullptr;

private:

	// Sets default values for this pawn's properties
	AMyTank();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	// Called every frame
	virtual void Tick(float DeltaTime) override;


	UPROPERTY(EditAnywhere, Category = "Firing")
		float ProjectileSpeed = 10000.f; // Sensible starting value of 1000 m/s

	UPROPERTY(EditAnywhere, Category = "Setup")
		TSubclassOf<AProjectile> ProjectileBlueprint;
	
	// Local barrel reference for spawning projectile
	UTankBarrel* Barrel = nullptr;

	double LastFireTime = -3;

	double ReloadTimeSeconds = 0.25;

};

// Fill out your copyright notice in the Description page of Project Settings.


#include "MyTankAIController.h"
#include "Runtime/Engine/Classes/GameFramework/Actor.h"
#include "Runtime/Engine/Classes/GameFramework/PlayerController.h"
#include "Runtime/Engine/Classes/Engine/World.h"
#include "MyTank.h"

void AMyTankAIController::BeginPlay()
{
	Super::BeginPlay();
}



void AMyTankAIController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	auto PlayerTank = Cast<AMyTank> (GetWorld()->GetFirstPlayerController()->GetPawn());
	auto ControlledTank = Cast<AMyTank>(GetPawn());

	if (PlayerTank)
	{
		MoveToActor(PlayerTank, AcceptanceRadius);

		ControlledTank->AimAt(PlayerTank->GetActorLocation());
		ControlledTank->Fire(); // TODO limit fire rate
	}
		
}


//Stuff Dan was using to explain things
/*
class Fruit
{
	void BeEaten()
	{
		bAmIEaten = true;
	}

	virtual FColor GetColor() const { return FColor::White; }

	Fruit* OtherFruit = 0;

	float a;
	
	double a;

	int a;

	int32 a; < -> int;
	int64 a; < -> LONGLONG;
	int8 a; char;
	int16 a; short;

	uint32; < -> unsigned int;
	uint16; < -> unsigned short;
	uint64; unsigned LONGLONG;
	uint8; unsigned char

	int32 a = 1000;

	int8 b = a;



	FString; <----- unicode!


	std::string; unsigned char* '\0'


	"Hello world" <-- unsigned char*
	TEXT("Hello world") <-- unicode :) wchar_t <- 16 bit <- unsigned short

	void SetAmIEatenToTrue()
	{
		bAmIEaten = true;
	}

	bool GetAmIEaten() const
	{
		return bAmIEaten;
	}

	bool bAmIEaten;
};

class Apple : public Fruit
{
	virtual FColor GetColor() const override { return FColor::Red; }
};


void main()
{
	Apple a;
	a.BeEaten();
}



struct Apple
{
	bool bAmIEaten;
};

void AppleBeEaten(Apple& a)
{
	a.bAmIEaten = true;
}

void main()
{
	Apple a;
	AppleBeEaten(a);
}

*/
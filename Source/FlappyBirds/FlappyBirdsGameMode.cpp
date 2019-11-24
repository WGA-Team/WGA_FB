// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.

#include "FlappyBirdsGameMode.h"
#include "FlappyBirdsCharacter.h"
#include "Tiles\FontTile.h"
#include "Walls\Wall.h"

AFlappyBirdsGameMode::AFlappyBirdsGameMode()
{

	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	// Set default pawn class to our character
	DefaultPawnClass = AFlappyBirdsCharacter::StaticClass();	


}

// Called every frame
void AFlappyBirdsGameMode::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);


	if (bTimeShiftMode)
	{
		Time_TimeShiftMode_On += DeltaTime;
		UE_LOG(LogTemp, Warning, TEXT("Time Shift On, %f"), Time_TimeShiftMode_On);
	}

	if (Time_TimeShiftMode_On > Time_TimeShiftMode)
	{

		TimeShiftOff();
	}
}



void AFlappyBirdsGameMode::SpawnTile()
{
	AFontTile* NewFontTile = GetWorld()->SpawnActor<AFontTile>(FontTile_Blueprint, NewTileSpawnLocation, FRotator::ZeroRotator);
}

void AFlappyBirdsGameMode::SpawnWall()
{
	float Height = FMath::RandRange(NewWallMinHeight, NewWallMaxHeight);
	FVector WallSpawnPosition = FVector(NewWallHorizontal, 0.0f, Height);
	AWall* NewWall = GetWorld()->SpawnActor<AWall>(Wall_Blueprint, WallSpawnPosition, FRotator::ZeroRotator);
}

int32 AFlappyBirdsGameMode::GetScore()
{
	return Score;
}

void AFlappyBirdsGameMode::IncrementScore()
{
	Score++;
}

float AFlappyBirdsGameMode::GetFontSpeed()
{
	return FontSpeed;
}

float AFlappyBirdsGameMode::GetWallSpeed()
{
	return WallSpeed;
}

void AFlappyBirdsGameMode::IncrementSpeed(float AddFontSpeed, float AddWallSpeed)
{
	FontSpeed += AddFontSpeed;
	WallSpeed += AddWallSpeed;
}

void AFlappyBirdsGameMode::TimeShiftOn()
{
	if (TimeShiftEnergy < TimeShiftEnergyCost) { return; }
	FontSpeed /= 2;
	WallSpeed /= 2;
	Time_TimeShiftMode_On = 0.0f;
	bTimeShiftMode = true;
	TimeShiftEnergy -= TimeShiftEnergyCost;
}

void AFlappyBirdsGameMode::TimeShiftOff()
{
	FontSpeed *= 2;
	WallSpeed *= 2;
	Time_TimeShiftMode_On = 0.0f;
	bTimeShiftMode = false;
}

void AFlappyBirdsGameMode::AddTimeShiftEnergy()
{
	
	if (TimeShiftEnergy >= TimeShiftEnergyCost) { return; }
	TimeShiftEnergy += AddTimeShiftEnergyValue;

}

float AFlappyBirdsGameMode::GetTimeShiftEnergy()
{
	return TimeShiftEnergy;
}

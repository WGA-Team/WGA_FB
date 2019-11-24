// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "FlappyBirdsGameMode.generated.h"

/**
 * The GameMode defines the game being played. It governs the game rules, scoring, what actors
 * are allowed to exist in this game type, and who may enter the game.
 *
 * This game mode just sets the default pawn to be the MyCharacter asset, which is a subclass of FlappyBirdsCharacter
 */
class AFontTile;
class AWall;

UCLASS(minimalapi)
class AFlappyBirdsGameMode : public AGameModeBase
{
	GENERATED_BODY()
public:
	AFlappyBirdsGameMode();

	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UFUNCTION(BlueprintCallable, Category = "Spawn")
	void SpawnTile();

	UPROPERTY(EditDefaultsOnly, Category = "Spawn")
	TSubclassOf<AFontTile> FontTile_Blueprint;


	UFUNCTION(BlueprintCallable, Category = "Spawn")
	void SpawnWall();

	UPROPERTY(EditDefaultsOnly, Category = "Spawn")
	TSubclassOf<AWall> Wall_Blueprint;

	UPROPERTY(EditDefaultsOnly, Category = "Spawn")
	FVector NewTileSpawnLocation;

	UPROPERTY(EditDefaultsOnly, Category = "Spawn")
	float NewWallHorizontal;

	UPROPERTY(EditDefaultsOnly, Category = "Spawn")
	float NewWallMinHeight;

	UPROPERTY(EditDefaultsOnly, Category = "Spawn")
	float NewWallMaxHeight;

	UFUNCTION(BlueprintCallable, Category = "Score")
	int32 GetScore();

	UFUNCTION(BlueprintCallable, Category = "Score")
	void IncrementScore();

	UFUNCTION(BlueprintCallable, Category = "Animation")
	float GetFontSpeed();

	UFUNCTION(BlueprintCallable, Category = "Animation")
	float GetWallSpeed();

	UFUNCTION(BlueprintCallable, Category = "Animation")
	void IncrementSpeed(float AddFontSpeed, float AddWallSpeed);

	UFUNCTION(BlueprintCallable, Category = "Animation")
	void TimeShiftOn();

	UFUNCTION(BlueprintCallable, Category = "Animation")
	void TimeShiftOff();

	UFUNCTION(BlueprintCallable, Category = "Animation")
	void AddTimeShiftEnergy();

	UFUNCTION(BlueprintCallable, Category = "States")
	float GetTimeShiftEnergy();
private:
	int32 Score = 0;

	UPROPERTY(EditDefaultsOnly, Category = "Animation")
	float FontSpeed = -300.f;

	UPROPERTY(EditDefaultsOnly, Category = "Animation")
	float WallSpeed = -700.f;

	UPROPERTY(EditDefaultsOnly, Category = "States")
	float TimeShiftEnergy = 0.f;

	UPROPERTY(EditDefaultsOnly, Category = "States")
	float TimeShiftEnergyCost = 100.f;

	UPROPERTY(EditDefaultsOnly, Category = "States")
	float Time_TimeShiftMode = 10.f;

	UPROPERTY(EditDefaultsOnly, Category = "States")
	float AddTimeShiftEnergyValue = 10.f;
	
	float Time_TimeShiftMode_On = 0.f;
	bool bTimeShiftMode = false;

};

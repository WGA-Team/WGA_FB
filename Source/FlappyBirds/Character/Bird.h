// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "PaperCharacter.h"
#include "Bird.generated.h"

/**
 * 
 */
UCLASS()
class FLAPPYBIRDS_API ABird : public APaperCharacter
{
	GENERATED_BODY()
	
public:
	UFUNCTION(BlueprintCallable, Category = "Amimation")
	void MoveUp();
};

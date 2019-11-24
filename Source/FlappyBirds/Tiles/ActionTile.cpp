// Fill out your copyright notice in the Description page of Project Settings.


#include "ActionTile.h"

// Sets default values
AActionTile::AActionTile()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AActionTile::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AActionTile::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}


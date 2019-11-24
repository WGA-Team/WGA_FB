// Fill out your copyright notice in the Description page of Project Settings.


#include "FontTile.h"

// Sets default values
AFontTile::AFontTile()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AFontTile::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AFontTile::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AFontTile::PlaceActors(TSubclassOf<AActor> ToSpawn, int32 MinSpawn, int32 MaxSpawn, FVector MinExtent, FVector MaxExtent, float MinScale, float MaxScale)
{
	int32 SpawnQty = FMath::RandRange(MinSpawn, MaxSpawn);
	for (int32 i = 0; i < SpawnQty; i++)
	{
		FBox Bounds(MinExtent, MaxExtent);
		FVector SpawnPoint = FMath::RandPointInBox(Bounds);
		float SpawnScale = FMath::RandRange(MinScale, MaxScale);
		AActor* Spawned = GetWorld()->SpawnActor<AActor>(ToSpawn, SpawnPoint, FRotator::ZeroRotator);
		if (Spawned)
		{
			Spawned->AttachToActor(this, FAttachmentTransformRules(EAttachmentRule::KeepRelative, false));
			Spawned->SetActorScale3D(FVector(SpawnScale));
			ActorsArray.Add(Spawned);
		}
	}
	
}

void AFontTile::DestroyActorsOnTile()
{
	for (AActor* FoundActor : ActorsArray)
	{
		FoundActor->Destroy();
	}

}

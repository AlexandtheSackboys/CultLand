// Fill out your copyright notice in the Description page of Project Settings.


#include "WaveSpawner.h"



// Sets default values
AWaveSpawner::AWaveSpawner()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

void AWaveSpawner::SpawnWave()
{
	if(CurrentEnemyCount <= 0)
	{
		
		for(int enemiesSpawned = 0; enemiesSpawned < _enemiesPerWave; enemiesSpawned++)
		{
			// selects a rabndom increment to ensure that the enemies do not spawn in the same place
			float SpawnIncrement =  FMath::FRandRange(0, 600.0f);

			// figures out the spawn position for each enemy
			FVector SpawnPos = FVector(GetActorLocation().X + SpawnIncrement, GetActorLocation().Y + SpawnIncrement, GetActorLocation().Z);
			GetWorld()->SpawnActor<AActor>(_enemyActor, SpawnPos, GetActorRotation());

			
		}

		WaveNumber = WaveNumber + 1;
		CurrentEnemyCount = _enemiesPerWave;
		_enemiesPerWave = _enemiesPerWave + 2; // increase the amount of enemies that will spawn in the next wave by 2
	}




}

// Called when the game starts or when spawned
void AWaveSpawner::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AWaveSpawner::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}


// Fill out your copyright notice in the Description page of Project Settings.


#include "WaveSpawner.h"



// Sets default values
AWaveSpawner::AWaveSpawner()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AWaveSpawner::BeginPlay()
{
	Super::BeginPlay();

}

void AWaveSpawner::SpawnWave()
{
	if (CurrentEnemyCount <= 0 && _WaveSpawners.Num() > 0) 
	{
		int SpawnRemainder = _WaveSpawners.Num() - Remainder;

		for (int enemiesSpawned = 0; enemiesSpawned < _enemiesPerWave; enemiesSpawned++)
		{
			TSubclassOf<AActor> EnemyType;
			// Spawns different types of enemies every time this fu
			if (!_enemytypes.IsEmpty())
				EnemyType = _enemytypes[FMath::RandRange(0, std::max(_enemytypes.Num() - 1, 0))];
			else break;

			// Spawns enemies at random spawners in the _WaveSpawners array, which will increase as the player unlocks new areas and more spawners are added to the array
			int SpawnIncrement = FMath::RandRange(0, SpawnRemainder);
			
			AActor* SpawnPoint = _WaveSpawners[SpawnIncrement];	

			if (!SpawnPoint) continue;

			FVector Offset = FVector(FMath::RandRange(-100.f, 100.f), FMath::RandRange(-100.f, 100.f), 0.f); // random offset to spawn enemies in a wider area around the spawn point
	
			// ensures that enemies will spawn even if there are other actors in the way, and will adjust their position to prevent collisions if possible
			FActorSpawnParameters SpawnParams;
			SpawnParams.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AdjustIfPossibleButAlwaysSpawn; 


			// figures out the spawn position for each enemy
			FVector SpawnPos = SpawnPoint->GetActorLocation() + Offset;
			GetWorld()->SpawnActor<AActor>(EnemyType, SpawnPos, GetActorRotation(), SpawnParams);

			UE_LOG(LogTemp, Warning, TEXT("Using Spawner Index: %d"), SpawnIncrement);
		}
		WaveNumber = WaveNumber + 1;
		CurrentEnemyCount = _enemiesPerWave;
		_enemiesPerWave = _enemiesPerWave + 2; // increase the amount of enemies that will spawn in the next wave by 2
		MaxHealthDropValue = MaxHealthDropValue + HealthDropChanceIncrement; // will decrease the chance of a health pickup dropping
		CanPickupWeapon = true;
		
	}

}


// Called every frame
void AWaveSpawner::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}


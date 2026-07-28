// Fill out your copyright notice in the Description page of Project Settings.


#include "WaveSpawner.h"
#include "Kismet/GameplayStatics.h"



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

void AWaveSpawner::SpawnWave(float minSpawnPosition, float maxSpawnPosition)
{
	if (CurrentEnemyCount <= 0 && _WaveSpawners.Num() > 0) 
	{

		//int PreviousSpawnIncrement = 0;

		 UGameplayStatics::PlaySoundAtLocation(this, _spawnerSFX, GetActorLocation(), GetActorRotation(), 0.5f);

		int SpawnRemainder = _WaveSpawners.Num() - Remainder;

		for (int enemiesSpawned = 0; enemiesSpawned < _enemiesPerWave;)
		{
			TSubclassOf<AActor> EnemyType;
			// Spawns different types of enemies every time this fu
			if (!_enemytypes.IsEmpty())
				EnemyType = _enemytypes[FMath::RandRange(0, std::max(0, _enemytypes.Num() - 1))];
			else break;

			// Spawns enemies at random spawners in the _WaveSpawners array, which will increase as the player unlocks new areas and more spawners are added to the array
			int SpawnIncrement = FMath::RandRange(0, SpawnRemainder);
			AActor* SpawnPoint = _WaveSpawners[SpawnIncrement];

			//if(SpawnIncrement == PreviousSpawnIncrement) 
			//{
			//	if (SpawnIncrement == 0)
			//	{
			//		AActor* SpawnPoint = _WaveSpawners[SpawnIncrement + 1];
			//	}
			//	else
			//	{
			//		SpawnPoint = _WaveSpawners[SpawnIncrement - 1];
			//	}
			//}

			if (!SpawnPoint) continue;

			// random offset to spawn enemies in a wider area around the spawn point
			FVector Offset = FVector(FMath::RandRange(minSpawnPosition, maxSpawnPosition), FMath::RandRange(minSpawnPosition, maxSpawnPosition),
				SpawnPoint->GetActorLocation().Z); 
			
			// ensures that enemies will spawn even if there are other actors in the way, and will adjust their position to prevent collisions if possible
			FActorSpawnParameters SpawnParams;
			SpawnParams.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AdjustIfPossibleButAlwaysSpawn;


			// figures out the spawn position for each enemy
			FVector SpawnPos = SpawnPoint->GetActorLocation() + Offset;
			//GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, FString::Printf(TEXT("Spawning enemy at: %s"), *SpawnPos.ToString()));
			GetWorld()->SpawnActor<AActor>(EnemyType, SpawnPos, GetActorRotation(), SpawnParams);

			UE_LOG(LogTemp, Warning, TEXT("Using Spawner Index: %d"), SpawnIncrement);

			//PreviousSpawnIncrement = SpawnIncrement;
			enemiesSpawned++;

		}

		UE_LOG(LogTemp, Warning, TEXT("Current Enemy Count: %d"), CurrentEnemyCount);

		WaveNumber = WaveNumber + 1;
		CurrentEnemyCount = _enemiesPerWave;
		_enemiesPerWave = _enemiesPerWave + 2; // increase the amount of enemies that will spawn in the next wave by 2
	//	_enemiesPerWave = FMath::Clamp(_enemiesPerWave, MinAmountOfEnemies, MaxAmountOfEnemies); // Clamp amount of overall enemies that can be spawned

		MaxHealthDropValue = MaxHealthDropValue + HealthDropChanceIncrement; // will decrease the chance of a health pickup dropping
		CanPickupWeapon = true;
		
	}

}


// Called every frame
void AWaveSpawner::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}


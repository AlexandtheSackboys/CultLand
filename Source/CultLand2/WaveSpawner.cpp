// Fill out your copyright notice in the Description page of Project Settings.


#include "WaveSpawner.h"
#include "Door.h"
#include "Kismet/GameplayStatics.h"
#include <string>



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
	if (CurrentEnemyCount <= 1 && _WaveSpawners.Num() >= 0) 
	{

		//int PreviousSpawnIncrement = 0;

		 UGameplayStatics::PlaySoundAtLocation(this, _spawnerSFX, GetActorLocation(), GetActorRotation(), 0.5f);

		 int SpawnRemainder = _WaveSpawners.Num() - 1;
		TArray<FVector> SpawnLocs;


		for (int enemiesSpawned = 0; enemiesSpawned <= _enemiesPerWave; enemiesSpawned++)
		{

			// Spawns different types of enemies every time this fu
			if (!_enemyTypes.IsEmpty())
				_selectedEnemy = _enemyTypes[FMath::RandRange(0, std::max(0, _enemyTypes.Num() - 1))];
			else break;

			// Spawns enemies at random spawners in the _WaveSpawners array, which will increase as the player unlocks new areas and more spawners are added to the array
			int SpawnIncrement = FMath::RandRange(0, SpawnRemainder);
			UE_LOG(LogTemp, Warning, TEXT("SpawnRemainder: %i"), SpawnRemainder);
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

			FVector Offset;
			// random offset to spawn enemies in a wider area around the spawn point
			Offset = FVector(FMath::RandRange(minSpawnPosition, maxSpawnPosition), FMath::RandRange(minSpawnPosition, maxSpawnPosition),
				SpawnPoint->GetActorLocation().Z);

			// figures out the spawn position for each enemy
			FVector SpawnPos = SpawnPoint->GetActorLocation() + Offset;

			FVector closestSpawn = FVector(9999.f, 9999.f, 9999.f);

			do
			{
				for (auto& i : SpawnLocs)
				{
					if (FVector::Dist(SpawnPos, i) < FVector::Dist(SpawnPos, closestSpawn))
					{
						closestSpawn = i;
					}
				}

				if (FVector::Dist(SpawnPos, closestSpawn) < ExclusionaryRadius)
				{
					auto dir = SpawnPos - closestSpawn;
					dir.Normalize();
					
					if (!dir.Normalize()) 
					{
						dir = FVector(1.f, 0.f, 0.f);            
					}

					SpawnPos += dir * (ExclusionaryRadius - FVector::Dist(SpawnPos, closestSpawn));
				}
			}
			while (FVector::Dist(SpawnPos, closestSpawn) < ExclusionaryRadius);

			//if (FVector::Dist(SpawnPos, closestSpawn) < ExclusionaryRadius)
			//{
			//	for (auto& i : SpawnLocs)
			//	{
			//		if (FVector::Dist(SpawnPos, i) < FVector::Dist(SpawnPos, closestSpawn))
			//		{
			//			closestSpawn = i;
			//		}
			//	}

			//	if (FVector::Dist(SpawnPos, closestSpawn) < ExclusionaryRadius)
			//	{
			//		auto dir = SpawnPos - closestSpawn;
			//		dir.Normalize();

			//		if (!dir.Normalize())
			//		{
			//			dir = FVector(1.f, 0.f, 0.f);
			//		}

			//		SpawnPos += dir * (ExclusionaryRadius - FVector::Dist(SpawnPos, closestSpawn));
			//	}
			//}

			
			if(_canLimitTypes)
			{ 
				LimitEnemyType(_excludeEnemyIndex);

			}

			SpawnLocs.Add(SpawnPos);
			
			// ensures that enemies will spawn even if there are other actors in the way, and will adjust their position to prevent collisions if possible
			FActorSpawnParameters SpawnParams;
			SpawnParams.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AdjustIfPossibleButAlwaysSpawn;


			//GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, FString::Printf(TEXT("Spawning enemy at: %s"), *SpawnPos.ToString()));
			GetWorld()->SpawnActor<AActor>(_selectedEnemy, SpawnPos, GetActorRotation(), SpawnParams);

			UE_LOG(LogTemp, Warning, TEXT("Using Spawner Index: %d"), SpawnIncrement);

			//PreviousSpawnIncrement = SpawnIncrement;
		}

		UE_LOG(LogTemp, Warning, TEXT("Current Enemy Count: %d"), CurrentEnemyCount);

		WaveNumber = WaveNumber + 1;
		CurrentEnemyCount = _enemiesPerWave;
		_enemiesPerWave = _enemiesPerWave + 2; // increase the amount of enemies that will spawn in the next wave by 2
	//	_enemiesPerWave = FMath::Clamp(_enemiesPerWave, MinAmountOfEnemies, MaxAmountOfEnemies); // Clamp amount of overall enemies that can be spawned

		MaxHealthDropValue = MaxHealthDropValue + HealthDropChanceIncrement; // will decrease the chance of a health pickup dropping
		CanPickupWeapon = true;
		_enemyTypeIncrement = 0;
		
		SpawnerAdditionCheck();
	}

}


void AWaveSpawner::LimitEnemyType(int excludeIndex)
{

	// ensures that Chicken demon doesn't spawn more than 5 times in a wave
	if (_selectedEnemy == _enemyTypes[excludeIndex])
	{

		if (_enemyTypeIncrement < _enemyLimiter)
		{
			_enemyTypeIncrement++;
			return;
		}
		else
		{
			// will select the cultist instead
			_selectedEnemy = _enemyTypes[_defaultEnemyIndex];
		}

	}
}

// Called every frame
void AWaveSpawner::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AWaveSpawner::SpawnerAdditionCheck()
{

	if (!bIsDoorOpen && WaveNumber >= LevelDoors[0]->WaveCapacity)
	{

		_WaveSpawners.Append(LevelDoors[0]->SpawnersActivated);

		LevelDoors[0]->OpenDoor();
		LevelDoors.RemoveAt(0);

		bIsDoorOpen = true;

		//DoorIndex++;
		
		return;

	}
	else 
	{
		bIsDoorOpen = false;
	}
	return;
}


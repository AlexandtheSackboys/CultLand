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

void AWaveSpawner::SpawnWave(float minSpawnPosition, float maxSpawnPosition, float spacing)
{
	if (CurrentEnemyCount <= _lastEnemyCount && _WaveSpawners.Num() >= 0) 
	{

		//int PreviousSpawnIncrement = 0;

		 UGameplayStatics::PlaySoundAtLocation(this, _spawnerSFX, GetActorLocation(), GetActorRotation(), 0.5f);

		 int SpawnRemainder = _WaveSpawners.Num() - 1;
		 int enemiesNotSpawned = 0;

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

			// random offset to spawn enemies in a wider area around the spawn point
			FVector Offset = FVector(FMath::RandRange(minSpawnPosition, maxSpawnPosition), FMath::RandRange(minSpawnPosition, maxSpawnPosition),
				0.f);

			// figures out the spawn position for each enemy
			FVector SpawnDir = Offset;

			//Fallback to any offset if there is none
			if ((float)SpawnDir.Size() == 0.f) SpawnDir += FVector(1.f, 0.f, 0.f);

			SpawnDir.Normalize();

			//the distance from SpawnPoint is determined by the number of enemies already spawned
			//Because we are spacing them apart by a set figure, we can guarantee that no enemies will ever spawn in the same place
			FVector SpawnPos = SpawnPoint->GetActorLocation() + (SpawnDir * (spacing * enemiesSpawned));

			SpawnPos.Z = SpawnPoint->GetActorLocation().Z + Offset.Z;
			
			if(_canLimitTypes)
			{ 
				LimitEnemyType(_excludeEnemyIndex);

			}
			
			// ensures that enemies will spawn even if there are other actors in the way, and will adjust their position to prevent collisions if possible
			FActorSpawnParameters SpawnParams;
			SpawnParams.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::DontSpawnIfColliding;


			//GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, FString::Printf(TEXT("Spawning enemy at: %s"), *SpawnPos.ToString()));
			auto spawned = GetWorld()->SpawnActor<AActor>(_selectedEnemy, SpawnPos, GetActorRotation(), SpawnParams);

			if (!spawned) enemiesNotSpawned += 1;
			UE_LOG(LogTemp, Warning, TEXT("Using Spawner Index: %d"), SpawnIncrement);

			//PreviousSpawnIncrement = SpawnIncrement;
		}

		UE_LOG(LogTemp, Warning, TEXT("Current Enemy Count: %d"), CurrentEnemyCount);

		WaveNumber = WaveNumber + 1;
		CurrentEnemyCount = _enemiesPerWave - enemiesNotSpawned;
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


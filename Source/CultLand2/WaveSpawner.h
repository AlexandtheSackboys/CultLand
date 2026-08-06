// Fill out your copyright notice in the Description page of Project Settings.

// ----------------------------------------------------------	
// Script (Header and Source files) Name: [WaveSpawner]
// 
// Author: [Alex Costin]
// 
// Editors: [Charlie Wargent, Mikyle Yakub]
// 
// Description: [the Wave Spawner class responsible for spawning enemy waves]
// 
// creation Date: [20/04/26]
// 
// last edited: [06/08/26 by Mikyle Yakub]
// 
// Editors Contributions: [
// Alex Costin:
// - Making the enemies spawn at different wave spawner objects and get added when unlocking new areas
// - Health Drop stuff
// - Purchase variables for increasing weapon costs
// - Fixing Wave increments
// - limit the amount of an enemy type (Demon chicken)
// 
// Charlie Wargent:
// - Created the Wave spawner that spawns enemies based on a wave system created 
// - Took the function call out of tick to stop it crashing
// - Made Exclusion zone variable a global so it can be edited in the editor 
// 
// Mikyle:
// - Fixed enemies spawning inside of each other sometimes
// - Rewrote enemy spacing system such that all enemies are always spaced at least a specified distance away from each other
// ----------------------------------------------------------	

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Public/DebugLogManager.h"


#include "WaveSpawner.generated.h"

class ADoor;


UCLASS(Blueprintable)
class CULTLAND2_API AWaveSpawner : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties

	AWaveSpawner();

	UFUNCTION(BlueprintCallable, Category = "Setup")
	void SpawnWave(float minSpawnPosition, float maxSpawnPosition);

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Setup")
	TMap<int, TSubclassOf<AActor>> _enemyWaves;

	UPROPERTY(EditInstanceOnly, BlueprintReadWrite, Category = "Setup")
	TArray<AActor*> _WaveSpawners; // array of other wave spawners to spawn enemies at when unlocking new areas

	UPROPERTY(EditInstanceOnly, BlueprintReadWrite, Category = "Setup")
	TArray<TSubclassOf<AActor>> _enemyTypes; // Add the different enemy actors to this array in the editor to spawn them in the waves

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Door Class")
	TArray<ADoor*> LevelDoors;


protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	/*UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Setup")
	TSubclassOf<AActor> _enemyActor;*/

	// determines the amount of enemies that will spawn in each wave
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Wave Values")
	int _enemiesPerWave;

	// the time between the last and next wave
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Wave Values")
	float _spawnDelay;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Wave Values", META = (ClampMin = 0, ClampMax = 1))
	int _lastEnemyCount = 1;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Audio")
	USoundBase* _spawnerSFX;

	int _enemyTypeIncrement = 0;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Enemies")
	int _enemyLimiter = 5;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Enemies", META = (ClampMin = 0, ClampMax = 3))
	int _defaultEnemyIndex = 0;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Enemies", META = (ClampMin = 0, ClampMax = 3))
	int _excludeEnemyIndex = 1;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Enemies")
	bool _canLimitTypes = true;

	// help with SpawnWave function
	TSubclassOf<AActor> _selectedEnemy;
	void LimitEnemyType(int excludeIndex);

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// determines the amount of enemies currently in the wave
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Wave Values")
	int CurrentEnemyCount;
	
	// determines the wave number
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Wave Values")
	int WaveNumber = 1;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Health Drop Values")
	int MaxHealthDropValue = 5;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Health Drop Values")
	int HealthDropChanceIncrement = 2;


	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Wave Values")
	int MinAmountOfEnemies = 0;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Wave Values")
	int MaxAmountOfEnemies = 25;


	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Reset Values")
	bool CanPickupWeapon = true;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Purchasing Values")
	bool _canIncreaseCost = false;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Purchasing Values")
	int _wavePriceDivider = 3;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Purchasing Values")
	int _costIncrease = 5;


	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Purchasing Values")
	int _maxPickupCost = 50;

	UPROPERTY(EditInstanceOnly, BlueprintReadOnly, Category = "Door");
	bool bIsDoorOpen = false;

	UFUNCTION(BlueprintCallable)
	void SpawnerAdditionCheck();



};

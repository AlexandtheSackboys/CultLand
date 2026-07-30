// Fill out your copyright notice in the Description page of Project Settings.

// ----------------------------------------------------------	
// Script (Header and Source files) Name: [WaveSpawner]
// 
// Author: [Alex Costin]
// 
// Editors: [Charlie Wargent]
// 
// Description: [the Wave Spawner class responsible for spawning enemy waves]
// 
// creation Date: [20/04/26]
// 
// last edited: [30/07/26 by Mikyle]
// 
// Editors Contributions: [
// Alex Costin:
// - Making the enemies spawn at different wave spawner objects and get added when unlocking new areas
// - Health Drop stuff
// - Purchase variables for increasing weapon costs
// - Fixing Wave increments
// 
// Charlie Wargent:
// - Took the function call out of tick to stop it crashing
// 
// Mikyle:
// - Fixed enemies spawning inside of each other sometimes
// ----------------------------------------------------------	

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Public/DebugLogManager.h"

#include "WaveSpawner.generated.h"


UCLASS(Blueprintable)
class CULTLAND2_API AWaveSpawner : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties

	 class ADoor;

	AWaveSpawner();

	UFUNCTION(BlueprintCallable, Category = "Setup")
	void SpawnWave(float minSpawnPosition, float maxSpawnPosition);

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Setup")
	TMap<int, TSubclassOf<AActor>> _enemyWaves;

	UPROPERTY(EditInstanceOnly, BlueprintReadWrite, Category = "Setup")
	TArray<AActor*> _WaveSpawners; // array of other wave spawners to spawn enemies at when unlocking new areas

	UPROPERTY(EditInstanceOnly, BlueprintReadWrite, Category = "Setup")
	TArray<TSubclassOf<AActor>> _enemytypes; // Add the different enemy actors to this array in the editor to spawn them in the waves


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


	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Audio")
	USoundBase* _spawnerSFX;

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
	int Remainder = 2;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Wave Values")
	int MinAmountOfEnemies = 0;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Wave Values")
	int MaxAmountOfEnemies = 25;


	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Wave Values")
	TArray<AActor*> _amountOfDoors;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Reset Values")
	bool CanPickupWeapon = true;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Purchasing Values")
	bool _canIncreaseCost = false;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Purchasing Values")
	int _waveDivider = 3;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Purchasing Values")
	int _costIncrease = 5;



};

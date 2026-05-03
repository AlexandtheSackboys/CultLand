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
// last edited: [30/04/26 by Charlie Wargent]
// 
// Editors Contributions: [Making the enemies spawn at different wave spawner objects and get added when unlocking new areas]
// ----------------------------------------------------------	

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "WaveSpawner.generated.h"

UCLASS(Blueprintable)
class CULTLAND2_API AWaveSpawner : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties


	AWaveSpawner();

	UFUNCTION(BlueprintCallable, Category = "Setup")
	void SpawnWave();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Setup")
	TMap<int, TSubclassOf<AActor>> _enemyWaves;

	UPROPERTY(EditInstanceOnly, BlueprintReadWrite, Category = "Setup")
	TArray<AActor*> _WaveSpawners; // array of other wave spawners to spawn enemies at when unlocking new areas

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Setup")
	TSubclassOf<AActor> _enemyActor;

	// determines the amount of enemies that will spawn in each wave
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Wave Values")
	int _enemiesPerWave;

	// the time between the llast and next wave
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Wave Values")
	float _spawnDelay;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// determines the amount of enemies currently in the wave
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Wave Values")
	int CurrentEnemyCount;
	
	// determines the wave number
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Wave Values")
	int WaveNumber = 1;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Wave Values")
	int Remainder = 2;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Wave Values")
	TArray<AActor*> _amountOfDoors;


};

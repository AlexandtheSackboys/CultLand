// Fill out your copyright notice in the Description page of Project Settings.

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
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Setup")
	TSubclassOf<AActor> _enemyActor;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Wave Values")
	int _enemiesPerWave;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Wave Values")
	float _spawnDelay;



public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Wave Values")
	int CurrentEnemyCount;
	
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Wave Values")
	int WaveNumber;



};

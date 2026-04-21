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
		
		while(_enemiesPerWave > 0)
		{
			float SpawnIncrement =  FMath::FRandRange(-600.0f, 600.0f);
			FVector SpawnPos = FVector(GetActorLocation().X + SpawnIncrement, GetActorLocation().Y + SpawnIncrement, GetActorLocation().Z);
			GetWorld()->SpawnActor<AActor>(_enemyActor, SpawnPos, GetActorRotation());

			_enemiesPerWave--;
		}

		WaveNumber = WaveNumber + 1;
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


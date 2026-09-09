// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "SpawnPoint.generated.h"

UCLASS(Blueprintable)
class CULTLAND2_API ASpawnPoint : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ASpawnPoint();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(EditInstanceOnly, BlueprintReadWrite, Category = "Position ranges", META = (ClampMin = -1000, ClampMax = 1000))
	float MinSpawnPosition = -100;

	UPROPERTY(EditInstanceOnly, BlueprintReadWrite, Category = "Position ranges", META = (ClampMin = -1000, ClampMax = 1000))
	float MaxSpawnPosition = 100;

};

// Fill out your copyright notice in the Description page of Project Settings.

// ----------------------------------------------------------	
// Script (Header and Source files) Name: [UDoor]
// 
// Author: [Charlie Wargent]
// 
// Editors: [Alex Costin]
// 
// Description: [Doors that open when a certain round criteria has been met]
// 
// creation Date: [27/4/2026]
// 
// last edited: [04/08/26 by Alex Costin]
// 
// Editors Contributions: [
// 
// Alex Costin: 
// - Destroying the Level Door 
// - DebugLogManager
// ]
// 
// ----------------------------------------------------------	


#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/StaticMeshComponent.h"
#include "Public/DebugLogManager.h"
#include "SpawnPoint.h"
#include "Components/BoxComponent.h"
#include "Sound/SoundBase.h"
#include "Door.generated.h"

UCLASS()
class CULTLAND2_API ADoor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ADoor();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Door")
	int WaveCapacity;

	UFUNCTION(BlueprintCallable, Category = "Door")
	void OpenDoor();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Setup")
	TArray<ASpawnPoint*> SpawnersActivated;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;



	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Door")
	USoundBase* _doorOpenSound;

	UPROPERTY(EditAnywhere)
	TArray<AActor*> _doorsAmount;


	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Door")
	UBoxComponent* _collisionBox;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Door")
	UStaticMeshComponent* _mesh;


private: 
	bool bIsOpen = false;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;








};

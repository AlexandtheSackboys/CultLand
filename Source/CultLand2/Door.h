// Fill out your copyright notice in the Description page of Project Settings.

// ----------------------------------------------------------	
// Script (Header and Source files) Name: [UDoor]
// 
// Author: [Charlie Wargent]
// 
// Editors: []
// 
// Description: [Doors that open when a certain round criteria has been met]
// 
// creation Date: [27/4/2026]
// 
// last edited: [28/04/26 by Charlie Wargent]
// 
// Editors Contributions: []
// ----------------------------------------------------------	


#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/StaticMeshComponent.h"
#include "Components/BoxComponent.h"
#include "WaveSpawner.h"
#include "Door.generated.h"


UCLASS()
class CULTLAND2_API ADoor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ADoor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	void OpenDoor();

private: 
	bool bIsOpen = false;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(EditInstanceOnly, BlueprintReadWrite, Category = "Setup")
	AWaveSpawner* _waveSpawner;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Door")
	UBoxComponent* _collisionBox;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Door")
	UStaticMeshComponent* _mesh;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Door")
	USoundBase* _doorOpenSound;

};

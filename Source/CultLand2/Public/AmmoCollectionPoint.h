// Fill out your copyright notice in the Description page of Project Settings.

// ----------------------------------------------------------	
// Script (Header and Source files) Name: [AmmoCollectionPoint]
// 
// Author: [Alex Costin]
// 
// Editors: []
// 
// Description: [is the Point where the player can collect ammo]
// 
// creation Date: [27/05/26]
// 
// last edited: []
// 
// Editors Contributions: []
// ----------------------------------------------------------	



#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/StaticMeshComponent.h"
#include "DebugLogManager.h"
#include "Components/BoxComponent.h"
#include "AmmoCollectionPoint.generated.h"

UCLASS()
class CULTLAND2_API AAmmoCollectionPoint : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AAmmoCollectionPoint();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ammo")
	int _collectMultiplier = 5;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ammo Box")
	UBoxComponent* _collisionBox;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Ammo Box")
	UStaticMeshComponent* _mesh;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UFUNCTION(BlueprintCallable, Category = "Ammo Box")
	void CollectAmmo(int maxClip);

	UPROPERTY(BlueprintReadOnly, Category = "Ammo")
	int _ammoFull;

};

// Fill out your copyright notice in the Description page of Project Settings.

// ----------------------------------------------------------	
// Script (Header and Source files) Name: [HitScanBase]
// 
// Author: [Alex Costin]
// 
// Editors: []
// 
// Description: [contains random effects for wild revolver]
// 
// creation Date: [22/06/26]
// 
// last edited: [22/06/26 by Alex Costin]
// 
// Editors Contributions: []
// ----------------------------------------------------------	

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "GameFramework/Actor.h"
#include "DebugLogManager.h"
#include "WildEffectsComponent.generated.h"


UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent), Blueprintable)
class CULTLAND2_API UWildEffectsComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	// Sets default values for this component's properties
	UWildEffectsComponent();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Wild Effects Classes")
	TSubclassOf <AActor> _explosionActorClass;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Wild Effects Classes")
	TSubclassOf <AActor> _morphingActorClass;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Wild Effect Values")
	int _maxRandomRange = 3;


public:
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	UFUNCTION(BlueprintCallable)
	void HealthSteal(float damageDealt, float currentHealth);

	UFUNCTION(BlueprintCallable)
	void RandomExplosion();

	UFUNCTION(BlueprintCallable)
	void MorphingSpawn();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Wild Effect Values")
	float RegenOutput;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Wild Effect Values")
	int RandomiserResult;


};

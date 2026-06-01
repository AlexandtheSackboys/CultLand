// Fill out your copyright notice in the Description page of Project Settings.

// ----------------------------------------------------------	
// Script (Header and Source files) Name: [WeaponPickupRandomizer]
// 
// Author: [Alex Costin]
// 
// Editors: []
// 
// Description: [this component allows gives a random weapon pickup based on a set class list]
// 
// creation Date: [01/06/26]
// 
// last edited: [01/06/26 by Alex Costin]
// 
// Editors Contributions: []
// ----------------------------------------------------------	

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Engine/World.h"
#include "DebugLogManager.h"
#include "WeaponPickupRandomizer.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent), Blueprintable )
class CULTLAND2_API UWeaponPickupRandomizer : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UWeaponPickupRandomizer();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	UFUNCTION(BlueprintCallable, Category = "Weapon Pickup")
	void Randomiser(int maxIndex);
	
	UPROPERTY(BlueprintReadOnly, Category = "Weapon Pickup")
	int RandomWeaponIndex;
		
};

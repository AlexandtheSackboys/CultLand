// Fill out your copyright notice in the Description page of Project Settings.

// ----------------------------------------------------------	
// Script (Header and Source files) Name: [HornetRifleComponent]
// 
// Author: [Charlie Wargent]
// 
// Editors: []
// 
// Description: [The base for the Hornet Rifle]
// 
// creation Date: [30/6/2026]
// 
// last edited: [30/6/2026 by Charlie Wargent]
// 
// Editors Contributions: []
// ----------------------------------------------------------	


#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Animation/AnimSequence.h"
#include "DebugLogManager.h"
#include "HornetRifleComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class CULTLAND2_API UHornetRifleComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UHornetRifleComponent();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;


public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

		
};

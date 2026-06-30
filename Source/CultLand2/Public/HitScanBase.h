// Fill out your copyright notice in the Description page of Project Settings.

// ----------------------------------------------------------	
// Script (Header and Source files) Name: [HitScanBase]
// 
// Author: [Alex Costin]
// 
// Editors: []
// 
// Description: [this class is responsible for the base ray casts for hitscan weapons]
// 
// creation Date: [23/04/26]
// 
// last edited: [30/06/26 by Alex Costin]
// 
// Editors Contributions: []
// ----------------------------------------------------------	

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Engine/World.h"
#include "DebugLogManager.h"
#include "DrawDebugHelpers.h"
#include "HitScanBase.generated.h"


UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent), Blueprintable)
class CULTLAND2_API UHitScanBase : public UActorComponent
{
	GENERATED_BODY()

public:
	// Sets default values for this component's properties
	UHitScanBase();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

	FVector _endLocation;

public:
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	UFUNCTION(BlueprintCallable)
	virtual void DrawHitRay(FVector forwardVector, FVector startLocation, bool hit, float rayRange);


	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Prototype Stats")
	float Range = 2000.f;
	
	// toggles the debug line being drawn
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Prototype Stats")
	bool _willDrawDebugLine  = false;

	UPROPERTY(BlueprintReadWrite, Category = "ray cast")
	FHitResult HitResult;

	void DebugLineTrace(FVector lineOrigin);
};

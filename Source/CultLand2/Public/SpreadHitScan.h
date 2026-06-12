// Fill out your copyright notice in the Description page of Project Settings.

// ----------------------------------------------------------	
// Script (Header and Source files) Name: [HitScanBase]
// 
// Author: [Alex Costin]
// 
// Editors: []
// 
// Description: [this class is responsible for the shotguns raycast inherited from HitScanBase]
// 
// creation Date: [02/06/26]
// 
// last edited: [12/06/26 by Alex Costin]
// 
// Editors Contributions: []
// ----------------------------------------------------------	
#pragma once

#include "CoreMinimal.h"
#include "Engine/World.h"
#include "HitScanBase.h"
#include "DrawDebugHelpers.h"
#include "SpreadHitScan.generated.h"

/**
 * 
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent), Blueprintable)
class CULTLAND2_API USpreadHitScan : public UHitScanBase
{
	GENERATED_BODY()

public:
	USpreadHitScan();
	

protected:
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Spread")
	int _pelletAmount = 7;
		
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Spread")
	float _spreadAngle = 10.f;

public:
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
	
	virtual void DrawHitRay(FVector forwardVector, FVector startlocation, bool hit, float rayRange) override;

};

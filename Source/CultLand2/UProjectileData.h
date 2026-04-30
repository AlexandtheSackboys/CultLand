// Fill out your copyright notice in the Description page of Project Settings.

// ----------------------------------------------------------	
// Script (Header and Source files) Name: [UProjectileData]
// 
// Author: [Charlie Wargent]
// 
// Editors: []
// 
// Description: [Projectile data that other classes can use to configure projectile behavior]
// 
// creation Date: [21/4/2026]
// 
// last edited: [22/04/26 by Charlie Wargent]
// 
// Editors Contributions: []
// ----------------------------------------------------------	

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "UProjectileData.generated.h"

/**
 * 
 */
UCLASS(BlueprintType)
class CULTLAND2_API UUProjectileData : public UDataAsset
{
	GENERATED_BODY()
	
public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Projectile Stats")
	int32 Damage;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Projectile Stats")
	float Speed;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Projectile Stats")
	float AreaOfEffectRadius;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Projectile Bools")
	bool bIsHitscan;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Projectile Bools")
	bool bIsProjectile;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Projectile Juice")
	TArray<USoundBase*> FireSound;
};

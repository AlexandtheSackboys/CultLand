// Fill out your copyright notice in the Description page of Project Settings.

// ----------------------------------------------------------	
// Script (Header and Source files) Name: [UWeaponData]
// 
// Author: [Charlie Wargent]
// 
// Editors: []
// 
// Description: [Weapon data that other classes can use to configure weapon behavior]
// 
// creation Date: [21/4/2026]
// 
// last edited: [23/04/26 by Charlie Wargent]
// 
// Editors Contributions: []
// ----------------------------------------------------------	


#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "UProjectileData.h"
#include "UWeaponData.generated.h"

/**
 * 
 */
UCLASS()
class CULTLAND2_API UUWeaponData : public UDataAsset
{
	GENERATED_BODY()
	
public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Weapon Stats")
	float FireRate;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Weapon Stats")
	float Recoil;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Projectile Stats")
	float Range;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Weapon Stats")
	float ReloadTime;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Weapon Ammo")
	int32 MagazineSize;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Weapon Ammo")
	int32 MaxAmmoCount;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Weapon Juice")
	TArray<USoundBase*> ReloadSound;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Weapon Juice")
	TArray<UParticleSystem*> WeaponEffect;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	UUProjectileData* ProjectileData;

};

// Fill out your copyright notice in the Description page of Project Settings.

// ----------------------------------------------------------	
// Script (Header and Source files) Name: [Weapon]
// 
// Author: [Mikyle Yakub]
// 
// Editors: [Alex Costin]
// 
// Description: [Base weapon class]
// 
// creation Date: [21/04/26]
// 
// last edited: [03/06/26 by Alex Costin]
// 
// Editors Contributions: [
// Alex Costin:
// put HitScan in calculations in a separate function from Tick
// fixed Current Endpoint to be more consistent
// 
// Adding Custom Log Manager 
// 
// Adding Hitscan parameter to RayShoot]
// ----------------------------------------------------------	

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "GameFramework/PlayerStart.h"
#include "UWeaponData.h"
#include "DrawDebugHelpers.h"
#include "Public/DebugLogManager.h"
#include "Public/HitScanBase.h"
#include "Camera/CameraComponent.h"
#include "Weapon.generated.h"

class UHitScanBase;

struct EndpointReturnValue 
{
	EndpointReturnValue(FVector endpoint, bool blockingHit) : endpoint(endpoint), blockingHit(blockingHit) {}
	FVector endpoint;
	bool blockingHit;
};

UCLASS()
class CULTLAND2_API AWeapon : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AWeapon();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Data")
	UUWeaponData* WeaponData;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Data")
	FVector ActorOrigin;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Data")
	FVector ShootTarget;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "References")
	UCameraComponent* PlayerCam;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ProjectileType")
	UHitScanBase* WeaponHitScan;


	UPROPERTY(BlueprintReadOnly)
	int currentAmmoCount = 100;

	UPROPERTY(BlueprintReadOnly)
	int currentAmmoInMag = 32;

	UPROPERTY(BlueprintReadOnly)
	FVector CurrentEndPoint = FVector(0.f, 0.f, 0.f);

	UFUNCTION(BlueprintCallable)
	void StartShootingWeapon();

	UFUNCTION(BlueprintCallable)
	void StopShootingWeapon();

	UFUNCTION(BlueprintCallable)
	void ReloadWeapon();

	UFUNCTION(BlueprintCallable)
	void RayShoot(float range, UHitScanBase* hitScanner);

private:
	bool can_fire = true;
	bool buttonDown = false;

	float accumulation = 0.f;

	EndpointReturnValue DetermineEndPoint(const UCameraComponent* const cam);

};

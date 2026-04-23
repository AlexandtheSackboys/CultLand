// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "GameFramework/PlayerStart.h"
#include "UWeaponData.h"
#include "Camera/CameraComponent.h"
#include "Public/HitScanBase.h"
#include "Weapon.generated.h"

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

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "References")
	UCameraComponent* PlayerCam;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ProjectileType")
	UHitScanBase* HitScanner;

	UPROPERTY(BlueprintReadOnly)
	int currentAmmoCount = 100;

	UPROPERTY(BlueprintReadOnly)
	int currentAmmoInMag = 32;

	FVector CurrentEndPoint = FVector(0.f, 0.f, 0.f);

	UFUNCTION(BlueprintCallable)
	void ShootWeapon();

	UFUNCTION(BlueprintCallable)
	void ReloadWeapon();

private:
	bool can_fire = true;

	float accumulation = 0.f;

	FVector DetermineEndPoint(const UCameraComponent* const cam);

};

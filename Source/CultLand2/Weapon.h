// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "GameFramework/PlayerStart.h"
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

	void Shoot();
	void Reload();

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

private:
	bool can_fire = true;
	int ammoCount = 100;
	int ammoPerMag = 32;
	int currentAmmoInMag = 32;
	float accumulation = 0.f;
	float timeBetweenShots = 0.5f;

};

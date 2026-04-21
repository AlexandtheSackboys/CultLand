// Fill out your copyright notice in the Description page of Project Settings.


#include "Weapon.h"

// Sets default values
AWeapon::AWeapon()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AWeapon::BeginPlay()
{
	Super::BeginPlay();
	
}

void AWeapon::Shoot()
{
	if (accumulation < timeBetweenShots) return;
	if (currentAmmoInMag < 0) 
	{
		Reload();
		return;
	}
	currentAmmoInMag -= 1;
	//TO DO: Spawn projectile here
	//GetWorld()->SpawnActor<T>()

}

void AWeapon::Reload()
{
	if (currentAmmoInMag == ammoPerMag) return;
	ammoCount -= ammoPerMag - currentAmmoInMag;

	currentAmmoInMag = ammoPerMag;

	if (ammoCount < 0) 
	{
		currentAmmoInMag -= ammoCount;
		ammoCount = 0;
	}
}

// Called every frame
void AWeapon::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	accumulation += DeltaTime;

}


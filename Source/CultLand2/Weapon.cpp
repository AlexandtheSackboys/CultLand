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
	
	currentAmmoCount = WeaponData->MaxAmmoCount;
}

void AWeapon::StartShootingWeapon()
{
	buttonDown = true;
}

void AWeapon::StopShootingWeapon()
{
	buttonDown = false;
}

void AWeapon::ReloadWeapon()
{
	if (currentAmmoInMag == WeaponData->MagazineSize) return;
	currentAmmoCount -= WeaponData->MagazineSize - currentAmmoInMag;

	currentAmmoInMag = WeaponData->MagazineSize;

	if (currentAmmoCount < 0) 
	{
		currentAmmoInMag -= currentAmmoCount;
		currentAmmoCount = 0;
	}
}

void AWeapon::RayShoot(float range, UHitScanBase* hitScanner)
{
	auto v = DetermineEndPoint(PlayerCam);
	//CurrentEndPoint = v.endpoint;

	FVector	startLocation = PlayerCam->GetComponentLocation() - FVector(1, 1, 10);
	if (buttonDown)
	{
		if (accumulation < WeaponData->FireRate) return;
		if (currentAmmoInMag < 0)
		{
			ReloadWeapon();
			return;
		}

		accumulation = 0;
		currentAmmoInMag -= 1;
		if (WeaponData->ProjectileData->bIsHitscan) hitScanner->DrawHitRay(PlayerCam->GetForwardVector(), startLocation, v.blockingHit, range);
	}
}

// Called every frame
void AWeapon::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	accumulation += DeltaTime;

	//auto v = DetermineEndPoint(PlayerCam);
	//CurrentEndPoint = v.endpoint;

	//if (buttonDown) 
	//{
	//	if (accumulation < WeaponData->FireRate) return;
	//	if (currentAmmoInMag < 0)
	//	{
	//		ReloadWeapon();
	//		return;
	//	}

	//	accumulation = 0;
	//	currentAmmoInMag -= 1;
	//	//if (WeaponData->ProjectileData->bIsHitscan) HitScanner->DrawHitRay(ActorOrigin, CurrentEndPoint, v.blockingHit);
	//}

}

EndpointReturnValue AWeapon::DetermineEndPoint(const UCameraComponent* const cam)
{
	FHitResult result;
	GetWorld()->LineTraceSingleByChannel(result, ActorOrigin, ShootTarget, ECollisionChannel::ECC_Visibility);
	UE_LOG(HitScanError, Error, TEXT("Does Work"), *result.ToString());
	if (result.bBlockingHit) return EndpointReturnValue(result.ImpactPoint, true);
	else return EndpointReturnValue(result.TraceEnd, false);

}
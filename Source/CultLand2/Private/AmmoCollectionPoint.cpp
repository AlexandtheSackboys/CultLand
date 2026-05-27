// Fill out your copyright notice in the Description page of Project Settings.


#include "AmmoCollectionPoint.h"

// Sets default values
AAmmoCollectionPoint::AAmmoCollectionPoint()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	_collisionBox = CreateDefaultSubobject<UBoxComponent>(TEXT("Collision Box"));
	RootComponent = _collisionBox;

	_mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	_mesh->SetupAttachment(RootComponent);


}

// Called when the game starts or when spawned
void AAmmoCollectionPoint::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AAmmoCollectionPoint::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AAmmoCollectionPoint::CollectAmmo(int ammoReserve, int maxClip)
{
	ammoReserve += maxClip * _collectMultiplier;
}


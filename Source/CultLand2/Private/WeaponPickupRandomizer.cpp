// Fill out your copyright notice in the Description page of Project Settings.

#include "WeaponPickupRandomizer.h"

// Sets default values for this component's properties
UWeaponPickupRandomizer::UWeaponPickupRandomizer()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UWeaponPickupRandomizer::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UWeaponPickupRandomizer::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

void UWeaponPickupRandomizer::Randomiser(int maxIndex)
{
	RandomWeaponIndex = FMath::RandRange(0, maxIndex);
	//DebugLogManager::Log("Randomized weapon index: " + FString::FromInt(RandomWeaponIndex));
}


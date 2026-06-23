// Fill out your copyright notice in the Description page of Project Settings.


#include "WildEffectsComponent.h"

// Sets default values for this component's properties
UWildEffectsComponent::UWildEffectsComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UWildEffectsComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UWildEffectsComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

void UWildEffectsComponent::HealthSteal(float damageDealt, float mediumMultiplier, float highMultiplier)
{

	int maxHealthRange = 10;
	int randomSelector = FMath::RandRange(1, maxHealthRange);

	if (randomSelector >= 1 && randomSelector < 7)
	{
		RegenOutput = damageDealt;
	}
	else if (randomSelector >= 7 && randomSelector < 9)
	{
		RegenOutput = damageDealt * mediumMultiplier;
	}
	else
	{
		RegenOutput = damageDealt * highMultiplier;
	}

}

void UWildEffectsComponent::RandomExplosion()
{

	GetWorld()->SpawnActor<AActor>(_explosionActorClass, GetOwner()->GetActorLocation(), FRotator::ZeroRotator);
}

void UWildEffectsComponent::MorphingSpawn()
{
	GetWorld()->SpawnActor<AActor>(_morphingActorClass, GetOwner()->GetActorLocation(), FRotator::ZeroRotator);
}


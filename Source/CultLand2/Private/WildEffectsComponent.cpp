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

void UWildEffectsComponent::HealthSteal(float damageDealt, float currentHealth)
{
	int randomSelector = FMath::RandRange(1, 3);

	if (randomSelector == 1)
	{
		currentHealth += damageDealt;
	}
	else if (randomSelector == 2)
	{
		currentHealth += damageDealt * 10;
	}
	else if (randomSelector == 3)
	{
		currentHealth += damageDealt * 50;
	}

	RegenOutput = currentHealth;
}

void UWildEffectsComponent::RandomExplosion()
{

	GetWorld()->SpawnActor<AActor>(_explosionActorClass, GetOwner()->GetActorLocation(), FRotator::ZeroRotator);
}

void UWildEffectsComponent::MorphingSpawn()
{
	GetWorld()->SpawnActor<AActor>(_morphingActorClass, GetOwner()->GetActorLocation(), FRotator::ZeroRotator);
}


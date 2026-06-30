// Fill out your copyright notice in the Description page of Project Settings.


#include "PickupPurchaseComponent.h"

// Sets default values for this component's properties
UPickupPurchaseComponent::UPickupPurchaseComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UPickupPurchaseComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UPickupPurchaseComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

void UPickupPurchaseComponent::PurchasePickup(int pickupCost, int enemiesKilled)
{

	// sets the left over points after purchase of wacky weapon
	if (enemiesKilled >= pickupCost)
	{
		// Logic for purchasing the pickup
		LeftOverResult = enemiesKilled - pickupCost;
		Purchased = true;
	}
	return;
}
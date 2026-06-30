// Fill out your copyright notice in the Description page of Project Settings.

// ----------------------------------------------------------	
// Script (Header and Source files) Name: [PickupPurchaseComponent]
// 
// Author: [Alex Costin]
// 
// Editors: []
// 
// Description: [a component that deals with pickup purchasing]
// 
// creation Date: [26/06/26]
// 
// last edited: [26/06/26 by Alex Costin]
// 
// Editors Contributions: []
// ----------------------------------------------------------	

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "DebugLogManager.h"
#include "PickupPurchaseComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent), Blueprintable )
class CULTLAND2_API UPickupPurchaseComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UPickupPurchaseComponent();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;


	


public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	UFUNCTION(BlueprintCallable, Category = "Pickup")
	void PurchasePickup(int pickupCost, int enemiesKilled);

	// turns mechanic on or off 
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Pickup")
	bool CanPurchase;


	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Pickup")
	int LeftOverResult;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Pickup")
	bool Purchased = false;


};

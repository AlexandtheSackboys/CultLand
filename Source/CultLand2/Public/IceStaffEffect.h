// Fill out your copyright notice in the Description page of Project Settings.

// ----------------------------------------------------------	
// Script (Header and Source files) Name: [IceStaffEffect]
// 
// Author: [Alex Costin]
// 
// Editors: []
// 
// Description: [Test for the Ice staff effects]
// 
// creation Date: [15/06/26]
// 
// last edited: [17/06/26]
// 
// Editors Contributions: []
// ----------------------------------------------------------	


#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "GameFramework/Character.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "IceStaffEffect.generated.h"


UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent), Blueprintable)
class CULTLAND2_API UIceStaffEffect : public UActorComponent
{
	GENERATED_BODY()

public:
	// Sets default values for this component's properties
	UIceStaffEffect();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;


	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Freeze element")
	float FreezeDuration = 5.0f;

	UFUNCTION(BlueprintCallable)
	void FreezeCharacter(ACharacter* characterFreeze, bool isFrozen);
};
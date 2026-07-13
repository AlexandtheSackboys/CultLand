// Fill out your copyright notice in the Description page of Project Settings.

// ----------------------------------------------------------	
// Script (Header and Source files) Name: [DemonicCreature.h]
// 
// Author: [Charlie Wargent]
// 
// Editors: []
// 
// Description: [This character class acts as the base for the demonic animals]
// 
// creation Date: [13/07/26]
// 
// last edited: [13/07/26 by Charlie Wargent]
// 
// Editors Contributions: []
// ----------------------------------------------------------	

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "../FirstPersonController.h"
#include "DemonicCreature.generated.h"


UCLASS()
class CULTLAND2_API ADemonicCreature : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	ADemonicCreature();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int AttackCooldown;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool IsAttacking;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	UFUNCTION(BlueprintCallable)
	void TargetPlayer(ACharacter* character, FVector position);

};

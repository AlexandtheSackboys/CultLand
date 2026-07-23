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

#include "Runtime/AIModule/Classes/AIController.h"
#include "Runtime/AIModule/Classes/Perception/AIPerceptionComponent.h"
#include <Runtime/AIModule/Classes/Perception/AIPerceptionTypes.h>
#include "Runtime/AIModule/Classes/Perception/AISenseConfig_Sight.h"
#include "Runtime/AIModule/Classes/Perception/AISenseConfig_Hearing.h"
#include "Runtime/AIModule/Classes/Perception/AIPerceptionStimuliSourceComponent.h"

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

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Collision")
	float LineTraceRange = 1000.0f;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	float GetDelayTime;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool IsAttacking;

	FTimerHandle AttackTimerHandle;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "AI")
	AAIController* AIController;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "AI")
	UAIPerceptionComponent* AIPerceptionComponent;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "AI")
	UAIPerceptionStimuliSourceComponent* AIStimuliSourceComponent;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "AI")
	UAISenseConfig_Sight* AISightConfig;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "AI")
	UAISenseConfig_Hearing* AIHearingConfig;

	TSubclassOf<UAISense> SenseType;

	UPROPERTY(EditAnywhere, Category = "Collision")
	TEnumAsByte<ECollisionChannel> TraceChannelProperty = ECC_Pawn;

	UFUNCTION(BlueprintCallable)
	void OnPerceptionUpdated(const TArray<AActor*>& UpdatedActors);

	UFUNCTION(BlueprintCallable)
	void OnTargetPerceptionUpdated(AActor* Actor, FAIStimulus Stimulus);

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	UFUNCTION(BlueprintCallable)
	void CheckforLineTraceHit();

	UFUNCTION(BlueprintCallable)
	void TargetPlayer(ACharacter* character, FVector position);

};

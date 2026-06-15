// Fill out your copyright notice in the Description page of Project Settings.

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
	float FreezeDuration;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Freeze element")

	bool IsFrozen = false;

	UFUNCTION(BlueprintCallable)
	void FreezeCharacter(ACharacter* ActorToFreeze);
};
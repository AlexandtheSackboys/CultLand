// Fill out your copyright notice in the Description page of Project Settings.


#include "IceStaffEffect.h"
#include "TimerManager.h"

// Sets default values for this component's properties
UIceStaffEffect::UIceStaffEffect()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UIceStaffEffect::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UIceStaffEffect::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

void UIceStaffEffect::FreezeCharacter(ACharacter* enemyToFreeze, bool isFrozen)
{
	if(isFrozen == true)
	{
		enemyToFreeze->GetCharacterMovement()->StopMovementImmediately();
	}

	else
	{
		enemyToFreeze->GetCharacterMovement()->SetMovementMode(EMovementMode::MOVE_Walking);
	}


}


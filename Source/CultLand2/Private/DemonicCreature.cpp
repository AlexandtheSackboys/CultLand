// Fill out your copyright notice in the Description page of Project Settings.


#include "DemonicCreature.h"

// Sets default values
ADemonicCreature::ADemonicCreature()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ADemonicCreature::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ADemonicCreature::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ADemonicCreature::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

void ADemonicCreature::TargetPlayer(ACharacter* character, FVector position)
{


}


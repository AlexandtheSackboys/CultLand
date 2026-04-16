// Fill out your copyright notice in the Description page of Project Settings.

// ----------------------------------------------------------	
// Script (Header and Source files) Name: [FirstPersonController]
// 
// Author: [Alex Costin]
// 
// Editors: []
// 
// Description: [A simple first person controller class that uses the enhanced input system.]
// 
// creation Date: [25/03/26]
// 
// last edited: [25/03/26 by Alex Costin]
// 
// Editors Contributions: []
// ----------------------------------------------------------	

#pragma once

#include "CoreMinimal.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/Character.h"
#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h" 
#include "InputActionValue.h"
#include "Components/CapsuleComponent.h"
#include "GameFramework/PlayerStart.h"
#include "FirstPersonController.generated.h"


class UAnimBlueprint;
class UInputMappingContext;
class UInputAction;
class UInputComponent;
class UCameraComponent;

UCLASS()
class CULTLAND2_API AFirstPersonController : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AFirstPersonController();

	UPROPERTY(VisibleAnywhere, meta = (AllowPrivateAccess = true))
	UCameraComponent* Camera;

	// Input Map
	UPROPERTY(EditAnywhere, Category = Input)
	UInputMappingContext* FirstPersonMapping;
	// Look Input Actions
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input)
	UInputAction* MouseLookAction;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input)
	UInputAction* MoveAction;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input)
	UInputAction* JumpAction;



	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input)
	UInputAction* SprintAction;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	UFUNCTION()
	void Move(const FInputActionValue& Value);

	UFUNCTION()
	void Look(const FInputActionValue& Value);

	void Jump() override;

	UFUNCTION()
	void Sprint();
	UFUNCTION()
	void StopSprint();

	bool bIsSprinting = false;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Input, meta = (ClampMin = 1, ClampMax = 2, UIMin = 1, UIMax = 2))
	float SprintIncrease = 1;

private:

	float _ogMaxWalkSpeed;

	FVector2D _moveAxisValue;

};

// Fill out your copyright notice in the Description page of Project Settings.


#include "FirstPersonController.h"
#include "GameFramework/CharacterMovementComponent.h"


// Sets default values
AFirstPersonController::AFirstPersonController()
{
	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Camera = CreateDefaultSubobject<UCameraComponent>("First Person Camera");

	Camera->SetupAttachment(RootComponent);

	Camera->bUsePawnControlRotation = true;

}

// Called when the game starts or when spawned
void AFirstPersonController::BeginPlay()
{
	Super::BeginPlay();
	// Add input mapping context

	_ogMaxWalkSpeed = GetCharacterMovement()->MaxWalkSpeed;
	if (APlayerController* playerController = Cast<APlayerController>(Controller))
	{
		// get local player subsystem
		if (UEnhancedInputLocalPlayerSubsystem* PlayerSubsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(playerController->GetLocalPlayer()))
		{

			PlayerSubsystem->AddMappingContext(FirstPersonMapping, 0);
		}
	}

}

// Called every frame
void AFirstPersonController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AFirstPersonController::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);


	// Check the UInputComponent passed to this function and cast it to an UEnhancedInputComponent
	if (UEnhancedInputComponent* EnhancedInputComponent = CastChecked<UEnhancedInputComponent>(PlayerInputComponent))
	{




		// Bind Movement Actions
		EnhancedInputComponent->BindAction(MoveAction, ETriggerEvent::Triggered, this, &AFirstPersonController::Move);

		// Bind Sprint Actions
		EnhancedInputComponent->BindAction(SprintAction, ETriggerEvent::Started, this, &AFirstPersonController::Sprint);
		EnhancedInputComponent->BindAction(SprintAction, ETriggerEvent::Completed, this, &AFirstPersonController::StopSprint);

		// Bind Jump Action
		EnhancedInputComponent->BindAction(JumpAction, ETriggerEvent::Triggered, this, &ACharacter::Jump);

		// Bind Look Actions
		EnhancedInputComponent->BindAction(MouseLookAction, ETriggerEvent::Triggered, this, &AFirstPersonController::Look);



	}

}

void AFirstPersonController::Move(const FInputActionValue& Value)
{




	// Add movement in the forward and right direction based on the input values
	if (IsValid(Controller))
	{
		_moveAxisValue = Value.Get<FVector2D>();
		// Get the forward and right vector of the character
		const FVector Forward = GetActorForwardVector();
		const FVector Right = GetActorRightVector();
		AddMovementInput(Forward, _moveAxisValue.Y);
		AddMovementInput(Right, _moveAxisValue.X);
	}

}

void AFirstPersonController::Look(const FInputActionValue& Value)
{
	const FVector2D LookAxisValue = Value.Get<FVector2D>();

	if (IsValid(Controller))
	{
		AddControllerYawInput(LookAxisValue.X);


		AddControllerPitchInput(LookAxisValue.Y);
	}

}

void AFirstPersonController::Jump()
{
	ACharacter::Jump();
}

void AFirstPersonController::Sprint()
{

	GetCharacterMovement()->MaxWalkSpeed = _ogMaxWalkSpeed * SprintIncrease;


}

void AFirstPersonController::StopSprint()
{
	GetCharacterMovement()->MaxWalkSpeed = _ogMaxWalkSpeed;
}


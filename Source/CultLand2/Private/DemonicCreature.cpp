// Fill out your copyright notice in the Description page of Project Settings.


#include "DemonicCreature.h"

// Sets default values
ADemonicCreature::ADemonicCreature()
{
	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	AIPerceptionComponent = CreateDefaultSubobject<UAIPerceptionComponent>(TEXT("AIPerceptionComponent"));
	AIStimuliSourceComponent = CreateDefaultSubobject<UAIPerceptionStimuliSourceComponent>(TEXT("AIStimulaSourceComponent"));
	AISightConfig = CreateDefaultSubobject<UAISenseConfig_Sight>(TEXT("AISightConfig"));
	AIHearingConfig = CreateDefaultSubobject<UAISenseConfig_Hearing>(TEXT("AIHearingConfig"));

}

// Called when the game starts or when spawned
void ADemonicCreature::BeginPlay()
{
	Super::BeginPlay();

	IsAttacking = false;
	AttackCooldown = 5; // in seconds

}

void ADemonicCreature::OnPerceptionUpdated(const TArray<AActor*>& UpdatedActors)
{


}

void ADemonicCreature::OnTargetPerceptionUpdated(AActor* Actor, FAIStimulus Stimulus)
{
}


// Called every frame
void ADemonicCreature::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	// CheckforLineTraceHit();
}

// Called to bind functionality to input
void ADemonicCreature::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

void ADemonicCreature::CheckforLineTraceHit()
{
	FHitResult Hit;

	FVector TraceStart = GetActorLocation();
	FVector TraceEnd = GetActorLocation() + GetActorForwardVector() * LineTraceRange; // Lines traces until 1000cm infront of the enemy

	FCollisionQueryParams QueryParams;
	QueryParams.AddIgnoredActor(this);

		GetWorld()->LineTraceSingleByChannel(Hit, TraceStart, TraceEnd, TraceChannelProperty, QueryParams);

		// Visual Debugging Line Trace
		DrawDebugLine(GetWorld(), TraceStart, TraceEnd, Hit.bBlockingHit ? FColor::White : FColor::Red, false, 5.0f, 0, 10.0f);
		// UE_LOG(LogTemp, Log, TEXT("Tracing Line: %s to %s"), *TraceStart.ToCompactString(), *TraceEnd.ToCompactString());

		if (Hit.bBlockingHit && IsValid(Hit.GetActor()) && Hit.GetActor()->Tags.Contains(FName("Player")) && !IsAttacking)
		{
			TargetPlayer(Cast<ACharacter>(Hit.GetActor()), Hit.ImpactPoint);
		}
		else
		{
			// UE_LOG(LogTemp, Log, TEXT("No Actors were hit"));
		}
}

void ADemonicCreature::TargetPlayer(ACharacter* character, FVector position)
{

	if(IsValid(character))
	{
		
		targetLocation = position;
		 Speed = 10.0f; // Adjust the speed as needed

		float distanceToTarget = FVector::Dist(GetActorLocation(), targetLocation);

		GetDelayTime = GetWorld()->GetDeltaSeconds() * Speed;
		FVector ChargeAtEnemy = FMath::Lerp(GetActorLocation(), targetLocation, GetDelayTime);
		SetActorLocation(ChargeAtEnemy);

		if (GetActorLocation() == targetLocation)
		{
			Speed = 0;
		}

	}
	else
	{
		UE_LOG(LogTemp, Log, TEXT("No valid player character to target"));
	}



}

// Fill out your copyright notice in the Description page of Project Settings.


#include "HitScanBase.h"

// Sets default values for this component's properties
UHitScanBase::UHitScanBase()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UHitScanBase::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UHitScanBase::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

void UHitScanBase::DrawHitRay(FVector end)
{
	FVector start;

	start = GetOwner()->GetActorLocation();
	end = start + (GetOwner()->GetActorForwardVector() * Range);
	//FCollisionQueryParams hitParameters = FCollisionQueryParams(FName(TEXT("HitScanTrace")), true, GetOwner());

	// creates a line when from the components owner location
	GetWorld()->LineTraceSingleByChannel(HitResult, start, end, ECC_Visibility);

	if (HitResult.bBlockingHit)
	{
		// draws the red line when it hits
		DrawDebugLine(GetWorld(), start, HitResult.Location, FColor::Red, false, 1.f, 0, 1.f);
	}
	else
	{
		// draws the yellow line when it doesn't hit anything
		DrawDebugLine(GetWorld(), start, end, FColor::Yellow, false, 1.f, 0, 1.f);
	}
}


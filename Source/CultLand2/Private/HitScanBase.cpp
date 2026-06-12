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

void UHitScanBase::DrawHitRay(FVector forwardVector,FVector startLocation, bool hit, float rayRange)
{
	//FCollisionQueryParams hitParameters = FCollisionQueryParams(FName(TEXT("HitScanTrace")), true, GetOwner());

	// calculates the end location 
	FVector endLocation = (forwardVector * rayRange) + startLocation;
	// creates a line from the components owner location
	GetWorld()->LineTraceSingleByChannel(HitResult, startLocation, endLocation, ECC_Visibility);

	if (HitResult.bBlockingHit)
	{
		// draws the red line when it hits
		DrawDebugLine(GetWorld(), startLocation, HitResult.Location, FColor::Red, false, 1.f, 0, 1.f);
	}
	else
	{
		// draws the yellow line when it doesn't hit anything
		DrawDebugLine(GetWorld(), startLocation, endLocation, FColor::Yellow, false, 1.f, 0, 1.f);
	}

	UE_LOG(HitScanError, Error, TEXT("hit ray is drawn"));

}


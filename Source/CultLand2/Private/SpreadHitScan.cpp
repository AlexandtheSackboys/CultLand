// Fill out your copyright notice in the Description page of Project Settings.


#include "SpreadHitScan.h"

USpreadHitScan::USpreadHitScan()
{
}

void USpreadHitScan::BeginPlay()
{
	Super::BeginPlay();
}

void USpreadHitScan::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
	
}

void USpreadHitScan::DrawHitRay(FVector forwardVector,FVector startLocation , bool hit, float rayRange)
{
	Super::DrawHitRay(forwardVector.Rotation().Vector(), startLocation, hit, rayRange);

	for(int pelletShot = 1; pelletShot < _pelletAmount; pelletShot++)
	{
		const float randomSpread = FMath::FRandRange(0, _maxSpreadAngle);

		// calculates the end location with the  random spread angle for each pellet
		FVector pelletDirection = FMath::VRandCone(forwardVector.Rotation().Vector(), FMath::DegreesToRadians(randomSpread));

		// calls the parent class DrawHitRay function
		Super::DrawHitRay(pelletDirection, startLocation, hit, rayRange);


		/* original code without calling the base class DrawHitRay function
		FVector endLocation = (pelletDirection * rayRange) + startLocation;
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
		*/

	}
}




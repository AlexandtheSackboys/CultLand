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

void USpreadHitScan::DrawHitRay(FVector start, FVector end, bool hit, float rayRange)
{
	for(int pelletShot = 0; pelletShot < _pelletPoints; pelletShot++)
	{

		const float randomVertical = FMath::FRandRange(-_spreadAngle, _spreadAngle);
		const float randomHorizontal = FMath::FRandRange(-_spreadAngle, _spreadAngle);
		FVector pelletDirection = FMath::VRandCone(start.Rotation().Vector(), FMath::DegreesToRadians(_spreadAngle));

		end = start + (pelletDirection * rayRange);
		if (hit)
		{
			// draws the red line when it hits
			DrawDebugLine(GetWorld(), start, HitResult.Location, FColor::Red, false, 1.f, 0, 1.f);
		}
		else
		{
			// draws the yellow line when it doesn't hit anything
			DrawDebugLine(GetWorld(), start, end, FColor::Yellow, false, 1.f, 0, 1.f);
		}
		UE_LOG(HitScanError, Error, TEXT("hit ray is drawn"));
	}
}




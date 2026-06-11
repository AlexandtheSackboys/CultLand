// Fill out your copyright notice in the Description page of Project Settings.

// ----------------------------------------------------------	
// Script (Header and Source files) Name: [HealthPickup]
// 
// Author: [Alex Costin]
// 
// Editors: []
// 
// Description: [is the Point where the player can increase their health again]
// 
// creation Date: [05/06/26]
// 
// last edited: []
// 
// Editors Contributions: []
// ----------------------------------------------------------	

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/StaticMeshComponent.h"
#include "DebugLogManager.h"
#include "Components/BoxComponent.h"
#include "HealthPickup.generated.h"

class UBoxComponent;
class UStaticMeshComponent;
UCLASS()
class CULTLAND2_API AHealthPickup : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AHealthPickup();

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Collectable")

	UStaticMeshComponent* CollectableMesh;

	UPROPERTY(EditAnywhere, Category = "Collectable")
	UBoxComponent* CollectableCollider;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UFUNCTION()
	void OnCollisionEnter(class UPrimitiveComponent* OverlappedComp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

	UPROPERTY(EditAnywhere,BlueprintReadWrite, Category = "Collectable")
	float HealthRecovery;

	UFUNCTION()
	void DestroyPickup();

	UFUNCTION(BlueprintCallable, Category = "Collectable")
	void DelayDestroy(float DelayTime);


};

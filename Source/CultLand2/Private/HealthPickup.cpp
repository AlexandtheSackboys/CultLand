// Fill out your copyright notice in the Description page of Project Settings.


#include "HealthPickup.h"

// Sets default values
AHealthPickup::AHealthPickup()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	CollectableMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));

	CollectableMesh->SetupAttachment(RootComponent);

	CollectableCollider = CreateDefaultSubobject<UBoxComponent>(TEXT("Collider"));
	CollectableCollider->SetupAttachment(CollectableMesh);
	CollectableCollider->OnComponentBeginOverlap.AddDynamic(this, &AHealthPickup::OnCollisionEnter);// set up a notification for when this component overlaps something

}

// Called when the game starts or when spawned
void AHealthPickup::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AHealthPickup::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AHealthPickup::OnCollisionEnter(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if (OtherActor->ActorHasTag(FName("Player")) && (OtherActor != this) && OtherComp)
	{


		SetActorEnableCollision(false);
		CollectableMesh->SetVisibility(false);

		DelayDestroy(0.2f);
	}
}

// allows the destroy function to be after a delay
void AHealthPickup::DestroyPickup()
{
	Destroy();
}

void AHealthPickup::DelayDestroy(float DelayTime)
{
	
	FTimerHandle DestroyObjectHandler;
	GetWorldTimerManager().SetTimer(DestroyObjectHandler, this, &AHealthPickup::DestroyPickup, DelayTime, false);
}




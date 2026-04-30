// Fill out your copyright notice in the Description page of Project Settings.

#include "Door.h"
#include "Kismet/GameplayStatics.h"

// Sets default values
ADoor::ADoor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	_collisionBox = CreateDefaultSubobject<UBoxComponent>(TEXT("Collision Box"));
	RootComponent = _collisionBox;

	_mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	_mesh->SetupAttachment(RootComponent);

}

// Called when the game starts or when spawned
void ADoor::BeginPlay()
{
	Super::BeginPlay();


	
}

void ADoor::OpenDoor()
{
	bIsOpen = true;
	UGameplayStatics::PlaySoundAtLocation(_mesh, _doorOpenSound, GetActorLocation(), GetActorRotation());

	UE_LOG(LogTemp, Warning, TEXT("Door opened"));

	_collisionBox->SetCollisionEnabled(ECollisionEnabled::NoCollision); // disable collision to allow passthrough

	Destroy(); // destroy the door actor to open the path for the player

	_waveSpawner->Remainder--;
}

// Called every frame
void ADoor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (!bIsOpen && _waveSpawner) // check if the door is already open && null check to prevent crashes if the wave spawner is not set 
	{
		if (_waveSpawner->WaveNumber >= WaveCapacity)
		{
			OpenDoor();
		}
	}

}


// Fill out your copyright notice in the Description page of Project Settings.

#include "UECourse.h"
#include "PickupSpawner.h"
#include "PickUp.h"

// Sets default values
APickupSpawner::APickupSpawner()
{
	SpawnLocation = CreateDefaultSubobject<USceneComponent>(TEXT("SpawnLocation"));
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void APickupSpawner::BeginPlay()
{
	Super::BeginPlay();

	SpawnPickup();
	
}

void APickupSpawner::PickupCollected()
{
	GetWorld()->GetTimerManager().SetTimer(MyTimer, this, &APickupSpawner::SpawnPickup, 10, false);
	CurrentPickup->OnPickedUp.Unbind();
	CurrentPickup->Destroy();
}

void APickupSpawner::SpawnPickup()
{
	UWorld *world = GetWorld();
	if (world)
	{
		CurrentPickup = world->SpawnActor<APickUp>(APickUp::StaticClass(), GetTransform());
		CurrentPickup->OnPickedUp.BindUObject(this, &APickupSpawner::PickupCollected);
	}
}

// Called every frame
void APickupSpawner::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}


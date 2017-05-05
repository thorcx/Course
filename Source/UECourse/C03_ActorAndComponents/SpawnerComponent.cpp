// Fill out your copyright notice in the Description page of Project Settings.

#include "UECourse.h"
#include "SpawnerComponent.h"


// Sets default values for this component's properties
USpawnerComponent::USpawnerComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;
	//bWantsBeginPlay = true;
	// ...
}


// Called when the game starts
void USpawnerComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void USpawnerComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

void USpawnerComponent::SpawnStaticMeshActor()
{
	UWorld* world = GetWorld();
	if (world)
	{
		FTransform ComponentTransform(this->GetComponentTransform());
		
		world->SpawnActor(MeshActorToSpawn, &ComponentTransform);
	}
}


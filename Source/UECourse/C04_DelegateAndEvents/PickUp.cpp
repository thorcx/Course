// Fill out your copyright notice in the Description page of Project Settings.

#include "UECourse.h"
#include "PickUp.h"


// Sets default values
APickUp::APickUp()
{
	Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("PickUpMesh"));
	RotatingComponent = CreateDefaultSubobject<URotatingMovementComponent>(TEXT("RotatingComponent"));
	RootComponent = Mesh;

	ConstructorHelpers::FObjectFinder<UStaticMesh> meshAsset(TEXT("StaticMesh'/Game/Assets/GodLikeIt.GodLikeIt'"));

	if (meshAsset.Object)
	{
		Mesh->SetStaticMesh(meshAsset.Object);
	}
	Mesh->SetCollisionProfileName(TEXT("OverlapAll"));
	RotatingComponent->RotationRate = FRotator(0, 10, 0);
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void APickUp::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void APickUp::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void APickUp::NotifyActorBeginOverlap(AActor* OtherActor)
{
	OnPickedUp.ExecuteIfBound();
}

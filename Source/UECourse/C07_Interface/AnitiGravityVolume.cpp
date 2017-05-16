// Fill out your copyright notice in the Description page of Project Settings.

#include "UECourse.h"
#include "AnitiGravityVolume.h"
#include "GravityInterface.h"

// Sets default values
AAnitiGravityVolume::AAnitiGravityVolume()
{
	CollisionComponent = CreateDefaultSubobject<UBoxComponent>(TEXT("CollisionBox"));
	CollisionComponent->SetBoxExtent(FVector(200, 200, 400));
	RootComponent = CollisionComponent;
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AAnitiGravityVolume::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AAnitiGravityVolume::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AAnitiGravityVolume::NotifyActorBeginOverlap(AActor* OtherActor)
{
	IGravityInterface *gI = Cast<IGravityInterface>(OtherActor);
	if (gI)
	{
		gI->DisableGravity();
	}
}

void AAnitiGravityVolume::NotifyActorEndOverlap(AActor* OtherActor)
{
	IGravityInterface *gI = Cast<IGravityInterface>(OtherActor);
	if (gI)
	{
		gI->EnableGravity();
	}
}


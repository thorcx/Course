// Fill out your copyright notice in the Description page of Project Settings.

#include "UECourse.h"
#include "EnemyBase_C08.h"


// Sets default values
AEnemyBase_C08::AEnemyBase_C08()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AEnemyBase_C08::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AEnemyBase_C08::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AEnemyBase_C08::DoSomeTestAnimal(FVector pos)
{
	GEngine->AddOnScreenDebugMessage(-1, 5, FColor::Red, TEXT("test"));
	SetActorLocation(pos);
}


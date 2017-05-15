// Fill out your copyright notice in the Description page of Project Settings.

#include "UECourse.h"
#include "Door.h"

ADoor::ADoor()
{
	ConstructorHelpers::FObjectFinder<UStaticMesh> meshAsset(TEXT("StaticMesh'/Engine/BasicShapes/Cube.Cube'"));
	if (meshAsset.Object)
	{
		GetStaticMeshComponent()->SetStaticMesh(meshAsset.Object);
		GetStaticMeshComponent()->bGenerateOverlapEvents = true;
	}
	GetStaticMeshComponent()->SetMobility(EComponentMobility::Movable);
	GetStaticMeshComponent()->SetWorldScale3D(FVector(0.3f, 2.0f, 3.0f));
	SetActorEnableCollision(true);
}

bool ADoor::CanInteract_Implementation()
{
	return true;
}

void ADoor::PerformInteract_Implementation()
{
	GEngine->AddOnScreenDebugMessage(-1, 5, FColor::Red, TEXT("门开不开，也许有开关"));
}

void ADoor::Open_Implementation()
{
	AddActorLocalOffset(FVector(0.f, 0.f, 200.0f));
}


// Fill out your copyright notice in the Description page of Project Settings.

#include "UECourse.h"
#include "DoorBell.h"
#include "OpenableInterface.h"

ADoorBell::ADoorBell()
{
	HasBeenPushed = false;

	ConstructorHelpers::FObjectFinder<UStaticMesh> meshAsset(TEXT("StaticMesh'/Engine/BasicShapes/Cube.Cube'"));
	if (meshAsset.Object)
	{
		GetStaticMeshComponent()->SetStaticMesh(meshAsset.Object);
		GetStaticMeshComponent()->bGenerateOverlapEvents = true;
	}
	GetStaticMeshComponent()->SetMobility(EComponentMobility::Movable);
	GetStaticMeshComponent()->SetWorldScale3D(FVector(0.5f, 0.5f, 0.5f));
	SetActorEnableCollision(true);

	DoorToOpen = nullptr;
}

bool ADoorBell::CanInteract_Implementation()
{
	return !HasBeenPushed;
}

void ADoorBell::PerformInteract_Implementation()
{
	HasBeenPushed = true;
	//这里演示没指定后，程序不判断出现的崩溃
	if (DoorToOpen->GetClass()->ImplementsInterface(UOpenableInterface::StaticClass()))
	{
		IOpenableInterface::Execute_Open(DoorToOpen);
	}
}



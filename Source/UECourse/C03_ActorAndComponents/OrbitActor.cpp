// Fill out your copyright notice in the Description page of Project Settings.

#include "UECourse.h"
#include "OrbitActor.h"


AOrbitActor::AOrbitActor()
{
	ChildMesh1 = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("ChildMeshComponent_01"));

	ConstructorHelpers::FObjectFinder<UStaticMesh> ballAsset = ConstructorHelpers::FObjectFinder<UStaticMesh>(TEXT("StaticMesh'/Game/Assets/SM_Ball.SM_Ball'"));

	if (ballAsset.Object != nullptr)
	{
		ChildMesh1->SetStaticMesh(ballAsset.Object);
	}
	ChildMesh1->AttachTo(GetRootComponent());
	ChildMesh1->SetRelativeLocation(FVector(-200.0f, 0.f, 0.f));
}


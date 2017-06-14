// Fill out your copyright notice in the Description page of Project Settings.

#include "UECourse.h"
#include "TalkingMesh.h"




ATalkingMesh::ATalkingMesh()
:Super()
{
	ConstructorHelpers::FObjectFinder<UStaticMesh> mesh(TEXT("StaticMesh'/Game/StarterContent/Props/SM_Rock.SM_Rock'"));
	if (mesh.Object)
	{
		GetStaticMeshComponent()->SetStaticMesh(mesh.Object);
		GetStaticMeshComponent()->bGenerateOverlapEvents = true;
	}
	GetStaticMeshComponent()->SetMobility(EComponentMobility::Movable);
	SetActorEnableCollision(true);
}

void ATalkingMesh::StartTalking_Implementation()
{
	GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Purple, TEXT("Hello, i'm from C++"));
}

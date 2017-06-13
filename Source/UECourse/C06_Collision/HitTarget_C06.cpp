// Fill out your copyright notice in the Description page of Project Settings.

#include "UECourse.h"
#include "HitTarget_C06.h"




AHitTarget_C06::AHitTarget_C06()
{
	ConstructorHelpers::FObjectFinder<UStaticMesh> mesh(TEXT("StaticMesh'/Game/Assets/Meshes/SM_Platform.SM_Platform'"));
	if (mesh.Object)
	{
		GetStaticMeshComponent()->SetStaticMesh(mesh.Object);
	}

}

// Fill out your copyright notice in the Description page of Project Settings.

#include "UECourse.h"
#include "ConstructionDemoC08.h"




AConstructionDemoC08::AConstructionDemoC08()
{
	ConstructorHelpers::FObjectFinder<UStaticMesh> meshAsset(TEXT("StaticMesh'/Game/Assets/C05/SM_UFO.SM_UFO'"));
	if (meshAsset.Object)
	{
		GetStaticMeshComponent()->SetStaticMesh(meshAsset.Object);
	}

}

void AConstructionDemoC08::OnConstruction(const FTransform& Transform)
{
	FLinearColor color(FMath::RandRange(0.0f, 1.0f), FMath::RandRange(0.0f, 1.0f), FMath::RandRange(0.0f, 1.0f), 1);
	
	UFO_DMI = GetStaticMeshComponent()->CreateAndSetMaterialInstanceDynamic(0);
	
	
	UFO_DMI->SetVectorParameterValue(FName(TEXT("DiffuseColor")), color);
}

void AConstructionDemoC08::PostInitializeComponents()
{
	if(!UFO_DMI)
		GetStaticMeshComponent()->CreateAndSetMaterialInstanceDynamic(0);
	Super::PostInitializeComponents();
}

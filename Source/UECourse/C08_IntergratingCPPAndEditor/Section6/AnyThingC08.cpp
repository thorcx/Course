// Fill out your copyright notice in the Description page of Project Settings.

#include "UECourse.h"
#include "AnyThingC08.h"




AAnyThingC08::AAnyThingC08()
	:ShapeType(AnyThingShapeType::Shape_Ball)
{
	ConstructorHelpers::FObjectFinder<UStaticMesh> Shape1(TEXT("StaticMesh'/Game/Assets/SM_Ball.SM_Ball'"));
	if(Shape1.Object)
	{
		MeshArray.Add(Shape1.Object);
	}
	
	ConstructorHelpers::FObjectFinder<UStaticMesh> Shape2(TEXT("StaticMesh'/Game/Assets/SM_EvilMinion.SM_EvilMinion'"));
	if (Shape2.Object)
	{
		MeshArray.Add(Shape2.Object);
	}
	
	ConstructorHelpers::FObjectFinder<UStaticMesh> Shape3(TEXT("StaticMesh'/Game/Assets/GodLikeIt.GodLikeIt'"));
	if (Shape3.Object)
	{
		MeshArray.Add(Shape3.Object);
	}
	GetStaticMeshComponent()->SetStaticMesh(MeshArray[ShapeType]);
	

}

void AAnyThingC08::BeginPlay()
{
	Super::BeginPlay();
	if (!bUseInEditorRefresh)
	{
		RefreshShape();
	}

}
//[c8-31]
void AAnyThingC08::PostEditChangeProperty(FPropertyChangedEvent& PropertyChangedEvent)
{
	if (PropertyChangedEvent.Property != nullptr)
	{
		const FName pName(PropertyChangedEvent.Property->GetFName());
		if (pName == GET_MEMBER_NAME_CHECKED(AAnyThingC08, ShapeType) && bUseInEditorRefresh)
		{
			RefreshShape();
		}
	}
	Super::PostEditChangeProperty(PropertyChangedEvent);

}

void AAnyThingC08::RefreshShape()
{	
	switch (ShapeType)
	{
	case Shape_Ball:
		GetStaticMeshComponent()->SetStaticMesh(MeshArray[Shape_Ball]);
		break;
	case Shape_Pillar:
		GetStaticMeshComponent()->SetStaticMesh(MeshArray[Shape_Pillar]);
		break;
	case Shape_Cake:
		GetStaticMeshComponent()->SetStaticMesh(MeshArray[Shape_Cake]);
		break;
	default:
		break;
	}
}


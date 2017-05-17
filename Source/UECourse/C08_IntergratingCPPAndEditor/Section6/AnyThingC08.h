// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Engine/StaticMeshActor.h"
#include "AnyThingC08.generated.h"

//Óë9¹²ÏíÀý×Ó
/**
 * 
 */

UENUM(BlueprintType)
enum AnyThingShapeType
{
	Shape_Ball,
	Shape_Pillar,
	Shape_Cake
};


UCLASS()
class UECOURSE_API AAnyThingC08 : public AStaticMeshActor
{
	GENERATED_BODY()
	
	AAnyThingC08();

	//~Begin AActor Interface

	virtual void BeginPlay() override;

	//~End AActor Interface
public:
	
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category=ShapeType)
	TEnumAsByte<AnyThingShapeType>  ShapeType;

private:
	UPROPERTY(Transient)
	TArray<class UStaticMesh*>	MeshArray;
};

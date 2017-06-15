// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Engine/StaticMeshActor.h"
#include "ConstructionDemoC08.generated.h"

/**
 * 
 */
UCLASS()
class UECOURSE_API AConstructionDemoC08 : public AStaticMeshActor
{
	GENERATED_BODY()
	
	AConstructionDemoC08();

	//~Begin AActor Interface
	//[c8-33]
	virtual void OnConstruction(const FTransform& Transform) override;

	virtual void PostInitializeComponents() override;
	//~End  AActor Interface


	UPROPERTY(Transient)
	UMaterialInstanceDynamic *UFO_DMI;
public:
	UPROPERTY(EditAnywhere)
	bool ShowStaticMesh;
	
};

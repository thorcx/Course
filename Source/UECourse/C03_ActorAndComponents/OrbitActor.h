// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Engine/StaticMeshActor.h"
#include "OrbitActor.generated.h"

/**
 * [ppt10-11]
 */
UCLASS()
class UECOURSE_API AOrbitActor : public AStaticMeshActor
{
	GENERATED_BODY()
	
public:
	AOrbitActor();
	
public:

	//[c3.17]建另一个Component体现子父关系
	UPROPERTY()
	UStaticMeshComponent *ChildMesh1;
	
	
};

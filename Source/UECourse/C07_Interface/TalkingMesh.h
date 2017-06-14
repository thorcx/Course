// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Engine/StaticMeshActor.h"
#include "TalkerInterface.h"
#include "TalkingMesh.generated.h"

/**
 * 
 */
//[c7-34]
UCLASS()
class UECOURSE_API ATalkingMesh : public AStaticMeshActor, public ITalker
{
	GENERATED_BODY()
	
	ATalkingMesh();
public:

	virtual void StartTalking_Implementation() override;
	
	
};

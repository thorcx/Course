// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Engine/StaticMeshActor.h"
#include "HitTarget_C06.generated.h"

/**
 * 
 */
//[c6-4]
UCLASS()
class UECOURSE_API AHitTarget_C06 : public AStaticMeshActor
{
	GENERATED_BODY()
	
public:
	AHitTarget_C06();
	
	UFUNCTION(BlueprintImplementableEvent, Category="UECourse|CollisionTest")
	void OnRaycastHit();
};

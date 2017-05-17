// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Animation/SkeletalMeshActor.h"
#include "PropertyDemoCharacterC08.generated.h"

/**
 * 
 */
UCLASS()
class UECOURSE_API APropertyDemoCharacterC08 : public ASkeletalMeshActor
{
	GENERATED_BODY()
	
	
	APropertyDemoCharacterC08();
public:

	//值在蓝图原型内可编辑
	UPROPERTY(EditDefaultsOnly)
	bool DefaultValue;
	//值在场景实例可编辑
	UPROPERTY(EditInstanceOnly)
	bool InstanceValue;
	//值在原型或实例内都可编辑
	UPROPERTY(EditAnywhere)
	bool AnywhereValue;

	//值在蓝图原型内可见
	UPROPERTY(VisibleDefaultsOnly)
	int32 VisibleDefaultValue;
	//值在场景实例可见
	UPROPERTY(VisibleInstanceOnly)
	int32 VisibleInstanceValue;
	//值在原型或实例内都可见
	UPROPERTY(VisibleAnywhere)
	int32 VisibleAnywhereValue;

	UPROPERTY(BlueprintReadWrite)
	float Health;

	UPROPERTY(BlueprintReadOnly)
	float Tall;

};

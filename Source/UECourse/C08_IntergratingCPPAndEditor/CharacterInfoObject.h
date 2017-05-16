// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "UObject/NoExportTypes.h"
#include "CharacterInfoObject.generated.h"

/**
 * [ppt8章-1]
 */

//UCLASS()

UCLASS(BlueprintType)
class UECOURSE_API UCharacterInfoObject : public UObject
{
	GENERATED_BODY()
	
	
public:
	//角色的名称
	UPROPERTY()
	FString	CharacterName;

	//最大可携带道具上限
	UPROPERTY()
	int32	MaxItem;
	
};

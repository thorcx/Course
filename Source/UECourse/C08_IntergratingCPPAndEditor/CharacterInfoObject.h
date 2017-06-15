// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "UObject/NoExportTypes.h"
#include "CharacterInfoObject.generated.h"

/**
 * [ppt8章-1]
 */

//UCLASS()

//[c8-02]
USTRUCT(BlueprintType)
struct FAnotherInfo
{
	GENERATED_BODY()
	
public:
	//结构体内BlueprintReadWrite没效果
	UPROPERTY(BlueprintReadWrite)
	float Cost;

	UPROPERTY(EditAnywhere)
	int32 index;
};
//[c8-01]
UCLASS(BlueprintType)
class UECOURSE_API UCharacterInfoObject : public UObject
{
	GENERATED_BODY()
	
	
public:
	//角色的名称
	UPROPERTY()
	FString	CharacterName;

	//最大可携带道具上限
	UPROPERTY(BlueprintReadWrite)
	int32	MaxItem;
	
	//后面蓝图自定义Pin的时候用到，代表选择的颜色
	UPROPERTY(BlueprintReadWrite)
	FString ColorName;
};

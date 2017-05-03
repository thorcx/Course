// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "UObject/NoExportTypes.h"
#include "UserProfile.generated.h"

/**
 * 
 */
UCLASS(Blueprintable)
class UECOURSE_API UUserProfile : public UObject
{
	GENERATED_BODY()
	
public:

	//定义一个护甲值
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category=UserData)
	float Armor;
	
	//定义一个玩家的颜色,可见不可改,蓝图内无法get,set,默认折叠不显示
	UPROPERTY(VisibleAnywhere,AdvancedDisplay, Category=UserData)
	FColor PlayerColor;

	
	
};

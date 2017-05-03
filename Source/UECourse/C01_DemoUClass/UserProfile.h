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

	//����һ������ֵ
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category=UserData)
	float Armor;
	
	//����һ����ҵ���ɫ,�ɼ����ɸ�,��ͼ���޷�get,set,Ĭ���۵�����ʾ
	UPROPERTY(VisibleAnywhere,AdvancedDisplay, Category=UserData)
	FColor PlayerColor;

	
	
};

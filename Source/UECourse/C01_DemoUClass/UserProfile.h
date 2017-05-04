// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "UObject/NoExportTypes.h"
#include "UserProfile.generated.h"

//��������һ����ͨC++��
//�������û�д�UObject�̳У����治���������������
class FDataStorage
{
public:
	FDataStorage() 
	{
		RawData = new int32[3]{ 0,1,2 };
	};
	~FDataStorage()
	{
		if (RawData)
		{
			delete[] RawData;
		}
	};

private:
	int32* RawData;
};

/**
 * 
 */

//[ppt1-3]
UCLASS(Blueprintable)
class UECOURSE_API UUserProfile : public UObject
{
	GENERATED_BODY()
	
	UUserProfile();
	
public:
	//[ppt-9]
	//UUserProfile�����ٺ�����������ִ���ͷ��ڴ�Ĳ���
	virtual void BeginDestroy() override;

	//����һ������ֵ
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category=UserData)
	float Armor;
	
	//����һ����ҵ���ɫ,�ɼ����ɸ�,��ͼ���޷�get,set,Ĭ���۵�����ʾ
	UPROPERTY(VisibleAnywhere,AdvancedDisplay, Category=UserData)
	FColor PlayerColor;

	
private:
	FDataStorage* DataStorage;
	
};

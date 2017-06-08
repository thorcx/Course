// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "UObject/NoExportTypes.h"

//①注意这里向导生成的generated.h,注意这里是必须的而且必须是最后一个#include(尝试颠倒位置)
#include "UserProfile.generated.h"

//这里声明一个普通C++类
//这里的类没有从UObject继承，引擎不会管理其生命周期
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
/*②UCLASS宏声明，定义一个Uclass,注意这里首先的Blueprintable表明了这个类型暴露给蓝图系统使用
继承自UObject，继承的类型必须是U打头*/

UCLASS(Blueprintable)
class UECOURSE_API UUserProfile : public UObject
{
	GENERATED_BODY()
	
	UUserProfile();
	
public:
	//[ppt-9]
	//UUserProfile的销毁函数，在这里执行释放内存的操作
	virtual void BeginDestroy() override;

	//定义一个护甲值
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category=UserData)
	float Armor;

	//定义一个最大生命,可以使用中文
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="血量")
	float HpMax;
	
	//定义一个玩家的颜色,可见不可改,蓝图内无法get,set,默认折叠不显示
	UPROPERTY(VisibleAnywhere,AdvancedDisplay, Category=UserData)
	FColor PlayerColor;

	
private:
	FDataStorage* DataStorage;
	
};

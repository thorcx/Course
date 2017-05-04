#pragma once

#include "GameFramework/GameModeBase.h"
#include "MDGameMode.generated.h"


//这里创建一个全局的GameMode在游戏内指定
//并从这里生成一个UAction的对象来展示NewObject<>用法

UCLASS()
class AMDGameMode : public AGameModeBase
{
	GENERATED_BODY()
	
	//明确指定构造函数,cpp中必须实现,阻止引擎自动生成的空构造函数
	AMDGameMode();
	
public:
	//覆写BeginPlay方法
	virtual void BeginPlay() override;


public:
	UPROPERTY(EditAnywhere)
	TSubclassOf<class UAction>	ActionClass;

	//UPROPERTY()修饰，用来保存对UObject的引用，防止被GC
	//UPROPERTY()
	UAction *MyAction;
	
	//一个普通指针，不能阻止被GC
	UAction* RawActionPtr;

	//[ppt-3]
	//创建UAction实例
	//NewObject的各种情况
	void CreateActionInstance();

	void DeleteActionInstance();
};

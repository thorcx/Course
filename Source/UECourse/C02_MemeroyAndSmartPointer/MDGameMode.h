#pragma once

#include "GameFramework/GameModeBase.h"
#include "MDGameMode.generated.h"

//自定义一个c++ Class
class FGameData
{
public:
	FGameData() {
		UE_LOG(LogTemp, Warning, TEXT("GameData Init!"));
	};
	FGameData(int32 n) :NumberOfPlayer(n)
	{
		
	}
	~FGameData() {
		UE_LOG(LogTemp, Warning, TEXT("GameData Destroyed!"));
	};

	int32 GetNumber() const
	{
		return NumberOfPlayer;
	}

private:
	int32 NumberOfPlayer = 123;
};



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
	virtual void EndPlay(const EEndPlayReason::Type EndPlayReason) override;

public:
	UPROPERTY(EditAnywhere)
	TSubclassOf<class UAction>	ActionClass;

	//UPROPERTY()修饰，用来保存对UObject的引用，防止被GC
	//UPROPERTY()
	UAction *MyAction;
	
	//一个普通指针，不能阻止被GC
	UAction* RawActionPtr;

	//一个指向自定义非UObject继承C++类的智能指针
	TSharedPtr<FGameData> GameDataPtr;

	//一个弱引用指针，不会增加引用计数
	TWeakPtr<FGameData>	GameDataWeakPtr;

	//[ppt-8]非UObject类型不能用UPROPERTY标记
	//UPROPERTY()
	//FGameData *rawPtr;

	TArray<FGameData*>	GameDataArray;
	
	//这里保存的指针如果不用UPROPERTY()会被垃圾回收掉
	UPROPERTY()
	TArray<class UAction*>	ActionArray;

public:
	//[ppt-3]
	//创建UAction实例
	//NewObject的各种情况
	void CreateActionInstance();

	//[ppt4-5]
	//Destroy
	void DeleteActionInstance();

	//[ppt-6-8]
	//智能指针TSharedPtr
	void SmartPointerTest();

	//[ppt-9]
	//TWeakPtr
	void WeakPointerTest();

	//[ppt-10]
	//垃圾回收 
	void RawArrayPointerTest();
};

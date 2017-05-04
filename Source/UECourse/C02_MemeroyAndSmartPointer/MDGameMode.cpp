#include "UECourse.h"
#include "MDGameMode.h"
#include "MemoryDemo.h"

AMDGameMode::AMDGameMode()
{
	//默认指定
	ActionClass = UAction::StaticClass();
}

void AMDGameMode::BeginPlay()
{
	Super::BeginPlay();
	CreateActionInstance();
}


void AMDGameMode::CreateActionInstance()
{
	//临时指向，会被GC
	//UAction *actiomTemp = NewObject<UAction>(GetTransientPackage(), ActionClass);
	
	//临时指向不被回收的方式
	//UAction *actiomTemp = NewObject<UAction>(GetTransientPackage(), ActionClass, NAME_None, RF_MarkAsRootSet);

	//普通指针

	//UPROPERTY()修饰指针,不会被GC
	//MyAction = NewObject<UAction>(GetTransientPackage(), ActionClass);

	//普通指针，会被GC
	//RawActionPtr = NewObject<UAction>(GetTransientPackage(), ActionClass);
	//加入RootSet，不会被GC
	//RawActionPtr->AddToRoot();

	//-----NewObject参数的解释-----//
	//不指定GetTransientPackage(),直接生成UAction类对象
	//MyAction = NewObject<UAction>();

	//指定生成蓝图类对象
	MyAction = NewObject<UAction>(GetTransientPackage(), ActionClass);
	DeleteActionInstance();
}

void AMDGameMode::DeleteActionInstance()
{
	//检查指针是否为空
	if (MyAction)
	{
		MyAction->ConditionalBeginDestroy();
		//强制立即进行一次垃圾回收
		//GetWorld()->ForceGarbageCollection(true);
		MyAction = nullptr;
	}
}
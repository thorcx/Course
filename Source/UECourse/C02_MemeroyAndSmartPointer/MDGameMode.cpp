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
	//CreateActionInstance();
	//DeleteActionInstance();
	SmartPointerTest();
	//WeakPointerTest();
	//RawArrayPointerTest();
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


void AMDGameMode::SmartPointerTest()
{
	//使用MakeShareable声明智能指针指向对象
	GameDataPtr = MakeShareable( new FGameData);
	UE_LOG(LogTemp, Warning, TEXT("Ref count = %d"), GameDataPtr.GetSharedReferenceCount());

	//声明一个作用域
	{
		//声明一个临时智能指针变量
		TSharedPtr<FGameData> tmpData = GameDataPtr;
		
		//观察引用计数的增加
		UE_LOG(LogTemp, Warning, TEXT("Ref count = %d"), GameDataPtr.GetSharedReferenceCount());
	}
	//退出作用域
	UE_LOG(LogTemp, Warning, TEXT("Ref count = %d"), GameDataPtr.GetSharedReferenceCount());

	//使用智能指针
	UE_LOG(LogTemp, Warning, TEXT("GameData Number = %d"), GameDataPtr->GetNumber());

	//智能指针是否指向有效对象可以被解引用
	UE_LOG(LogTemp, Warning, TEXT("GameDataPtr is valid ? %s"), GameDataPtr.IsValid() ? TEXT("Yes") : TEXT("No"));

	//解引用
	FGameData &dataRef = *GameDataPtr;

	//获得正常C++指针
	FGameData *raw = GameDataPtr.Get();

	//注意这里不会对Ref产生影响
	UE_LOG(LogTemp, Warning, TEXT("Ref count = %d"), GameDataPtr.GetSharedReferenceCount());


	//强制解除此智能指针对对象的索引，如果对象没有被其他智能指针引用，则被销毁
	GameDataPtr.Reset();

	//注意在这之前析构函数被调用
	UE_LOG(LogTemp, Warning, TEXT("GameDataPtr is valid ? %s"), GameDataPtr.IsValid() ? TEXT("Yes") : TEXT("No"));

	
}

void AMDGameMode::WeakPointerTest()
{
	GameDataPtr = MakeShareable(new FGameData);
	GameDataWeakPtr = GameDataPtr;
	//弱引用对智能指针索引数不产生影响
	UE_LOG(LogTemp, Warning, TEXT("Ref count = %d"), GameDataPtr.GetSharedReferenceCount());

	//首先检查是WeakPtr是否有效
	//TWeakPtr不是直接能像指针一样使用->索引指向的对象的成员或者方法
	//必须使用Pin()来转成一个SharedPtr再使用
	if (GameDataWeakPtr.IsValid())
	{
		UE_LOG(LogTemp, Warning, TEXT("GameData Number = %d"), GameDataWeakPtr.Pin()->GetNumber());
	}

	//智能指针释放资源
	GameDataPtr.Reset();

	//弱引用指向的对象无效了，IsValid返回false
	UE_LOG(LogTemp, Warning, TEXT("GameDataWeakPtr is valid ? %s"), GameDataWeakPtr.IsValid() ? TEXT("Yes") : TEXT("No"));
}


void AMDGameMode::RawArrayPointerTest()
{

	//动态创建
	GameDataArray.Add(new FGameData(1));
	GameDataArray.Add(new FGameData(2));
	GameDataArray.Add(new FGameData(3));
	GameDataArray.Add(new FGameData(4));

	ActionArray.Add(NewObject<UAction>());
	ActionArray.Add(NewObject<UAction>());
	ActionArray.Add(NewObject<UAction>());
}

//在结束的时候销毁
void AMDGameMode::EndPlay(const EEndPlayReason::Type EndPlayReason)
{
	for (auto i : GameDataArray)
	{
		if (i)
		{
			delete i;
		}
	}

	Super::EndPlay(EndPlayReason);
}
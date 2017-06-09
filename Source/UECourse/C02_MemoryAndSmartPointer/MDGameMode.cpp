#include "UECourse.h"
#include "MDGameMode.h"
#include "MemoryDemo.h"


AMDGameMode::AMDGameMode()
{
	//Ĭ��ָ��
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
	//��ʱָ�򣬻ᱻGC
	//UAction *actiomTemp = NewObject<UAction>(GetTransientPackage(), ActionClass);
	
	//��ʱָ�򲻱����յķ�ʽ
	//UAction *actiomTemp = NewObject<UAction>(GetTransientPackage(), ActionClass, NAME_None, RF_MarkAsRootSet);

	//��ָͨ��

	//UPROPERTY()����ָ��,���ᱻGC
	//MyAction = NewObject<UAction>(GetTransientPackage(), ActionClass);

	//��ָͨ�룬�ᱻGC
	//RawActionPtr = NewObject<UAction>(GetTransientPackage(), ActionClass);
	//����RootSet�����ᱻGC
	//RawActionPtr->AddToRoot();

	//-----NewObject�����Ľ���-----//
	//��ָ��GetTransientPackage(),ֱ������UAction�����
	//MyAction = NewObject<UAction>();

	//ָ��������ͼ�����
	MyAction = NewObject<UAction>(GetTransientPackage(), ActionClass);
	
}

void AMDGameMode::DeleteActionInstance()
{
	//���ָ���Ƿ�Ϊ��
	if (MyAction)
	{
		MyAction->ConditionalBeginDestroy();
		//ǿ����������һ����������
		//GetWorld()->ForceGarbageCollection(true);
		MyAction = nullptr;
	}
}


void AMDGameMode::SmartPointerTest()
{
	//ʹ��MakeShareable��������ָ��ָ�����
	GameDataPtr = MakeShareable( new FGameData);
	UE_LOG(LogTemp, Warning, TEXT("Ref count = %d"), GameDataPtr.GetSharedReferenceCount());

	//����һ��������
	{
		//����һ����ʱ����ָ�����
		TSharedPtr<FGameData> tmpData = GameDataPtr;
		
		//�۲����ü���������
		UE_LOG(LogTemp, Warning, TEXT("Ref count = %d"), GameDataPtr.GetSharedReferenceCount());
	}
	//�˳�������
	UE_LOG(LogTemp, Warning, TEXT("Ref count = %d"), GameDataPtr.GetSharedReferenceCount());

	//ʹ������ָ��
	UE_LOG(LogTemp, Warning, TEXT("GameData Number = %d"), GameDataPtr->GetNumber());

	//����ָ���Ƿ�ָ����Ч������Ա�������
	UE_LOG(LogTemp, Warning, TEXT("GameDataPtr is valid ? %s"), GameDataPtr.IsValid() ? TEXT("Yes") : TEXT("No"));

	//������
	FGameData &dataRef = *GameDataPtr;

	//�������C++ָ��
	FGameData *raw = GameDataPtr.Get();

	//ע�����ﲻ���Ref����Ӱ��
	UE_LOG(LogTemp, Warning, TEXT("Ref count = %d"), GameDataPtr.GetSharedReferenceCount());


	//ǿ�ƽ��������ָ��Զ�����������������û�б���������ָ�����ã�������
	GameDataPtr.Reset();

	//ע������֮ǰ��������������
	UE_LOG(LogTemp, Warning, TEXT("GameDataPtr is valid ? %s"), GameDataPtr.IsValid() ? TEXT("Yes") : TEXT("No"));

	
}

void AMDGameMode::WeakPointerTest()
{
	GameDataPtr = MakeShareable(new FGameData);
	GameDataWeakPtr = GameDataPtr;
	//�����ö�����ָ��������������Ӱ��
	UE_LOG(LogTemp, Warning, TEXT("Ref count = %d"), GameDataPtr.GetSharedReferenceCount());

	//���ȼ����WeakPtr�Ƿ���Ч
	//TWeakPtr����ֱ������ָ��һ��ʹ��->����ָ��Ķ���ĳ�Ա���߷���
	//����ʹ��Pin()��ת��һ��SharedPtr��ʹ��
	if (GameDataWeakPtr.IsValid())
	{
		UE_LOG(LogTemp, Warning, TEXT("GameData Number = %d"), GameDataWeakPtr.Pin()->GetNumber());
	}

	//����ָ���ͷ���Դ
	GameDataPtr.Reset();

	//������ָ��Ķ�����Ч�ˣ�IsValid����false
	UE_LOG(LogTemp, Warning, TEXT("GameDataWeakPtr is valid ? %s"), GameDataWeakPtr.IsValid() ? TEXT("Yes") : TEXT("No"));
}


void AMDGameMode::RawArrayPointerTest()
{

	//��̬����
	GameDataArray.Add(new FGameData(1));
	GameDataArray.Add(new FGameData(2));
	GameDataArray.Add(new FGameData(3));
	GameDataArray.Add(new FGameData(4));

	ActionArray.Add(NewObject<UAction>());
	ActionArray.Add(NewObject<UAction>());
	ActionArray.Add(NewObject<UAction>());
}

//�ڽ�����ʱ������
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
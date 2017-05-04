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
	CreateActionInstance();
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
	DeleteActionInstance();
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
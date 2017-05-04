#include "UECourse.h"
#include "MemoryDemo.h"

UAction::UAction(const FObjectInitializer &ObjInit)
	:Super(ObjInit),
	Text(TEXT("Default Action")),
	ShortcutKey(EKeys::A)
{
}

//��������������ConditionalBeginDestroy������ִ��
void UAction::BeginDestroy()
{
	Super::BeginDestroy();
	UE_LOG(LogTemp, Warning, TEXT("UAction BeginDestroy!"));
}

//����ֻ��GCִ�е�ʱ��ŵ��ã�ConditionalBeginDestroy�󲻻�����ִ�У����ǵȵ�����GC����ʱ��ִ��
//�������ConditionalBeginDestroy֮����������GetWorld()->ForceGarbageCollection(true);ǿ���������һ���������գ�����Ҳ����������
void UAction::FinishDestroy()
{
	//���Լ�����Դ����
	
	//������Super::FinishDestroy()
	Super::FinishDestroy();
}
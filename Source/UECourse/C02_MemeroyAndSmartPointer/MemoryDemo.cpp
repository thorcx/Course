#include "UECourse.h"
#include "MemoryDemo.h"

UAction::UAction(const FObjectInitializer &ObjInit)
	:Super(ObjInit),
	Text(TEXT("Default Action")),
	ShortcutKey(EKeys::A)
{
}

//这里如果你调用了ConditionalBeginDestroy，立刻执行
void UAction::BeginDestroy()
{
	Super::BeginDestroy();
	UE_LOG(LogTemp, Warning, TEXT("UAction BeginDestroy!"));
}

//这里只在GC执行的时候才调用，ConditionalBeginDestroy后不会立刻执行，而是等到真正GC来的时候执行
//如果你在ConditionalBeginDestroy之后立即调用GetWorld()->ForceGarbageCollection(true);强制引擎进行一次垃圾回收，这里也会立即调用
void UAction::FinishDestroy()
{
	//你自己的资源销毁
	
	//最后呼叫Super::FinishDestroy()
	Super::FinishDestroy();
}
#include "UECourse.h"

#include "CoolObject.h"

void ACoolObject::DoSomething()
{
	GEngine->AddOnScreenDebugMessage(-1, 100.0f, FColor::Green, TEXT("Hello Unreal!"));
}
#include "UECourse.h"

#include "CoolObject.h"
#include "UserProfile.h"
void ACoolObject::DoSomething()
{
	GEngine->AddOnScreenDebugMessage(-1, 10.0f, FColor::Green, TEXT("Hello Unreal!"));
}

void ACoolObject::BeginPlay()
{
	//注意这里忘记写Super的后果，蓝图不调用BeginPlay了
	Super::BeginPlay();
	
}

void ACoolObject::ShowUserProfile()
{
	if (!UserProfile)
	{
		UserProfile = NewObject<UUserProfile>(GetTransientPackage(), UserProfileClass);
	}
	
	GEngine->AddOnScreenDebugMessage(-1, 10.0f, FColor::Green, FString::Printf(TEXT("BP_UserProfile==>Armor=%f"), UserProfile->Armor));

}
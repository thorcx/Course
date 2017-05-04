#include "UECourse.h"

#include "CoolObject.h"
#include "UserProfile.h"

void ACoolObject::SayHelloToUnreal()
{
	GEngine->AddOnScreenDebugMessage(-1, 10.0f, FColor::Green, TEXT("Hello Unreal!"));
}

void ACoolObject::BeginPlay()
{
	//ע����������дSuper�ĺ������ͼ������BeginPlay��
	Super::BeginPlay();
}

void ACoolObject::CreateUserProfile()
{
	if (!UserProfile)
	{
		UserProfile = NewObject<UUserProfile>(GetTransientPackage(), UserProfileClass);
	}
	
	GEngine->AddOnScreenDebugMessage(-1, 10.0f, FColor::Green, FString::Printf(TEXT("BP_UserProfile Address =%p\n Armor=%f"),UserProfile, UserProfile->Armor));

}

void ACoolObject::DeleteUserProfile()
{
	if (UserProfile)
	{
		UserProfile->ConditionalBeginDestroy();
		UserProfile = nullptr;
	}
}


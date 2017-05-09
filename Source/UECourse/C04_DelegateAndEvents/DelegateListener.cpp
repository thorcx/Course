#include "UECourse.h"
#include "DelegateListener.h"
#include "DelegateGameMode.h"

ADelegateListener::ADelegateListener()
{
	PointLight = CreateDefaultSubobject<UPointLightComponent>(TEXT("PointLight01"));
	RootComponent = PointLight;
	PointLight->SetVisibility(false);
}

void ADelegateListener::EnableLight()
{
	PointLight->SetVisibility(true);
}

void ADelegateListener::SetLightColor(FLinearColor LightColor)
{
	PointLight->SetLightColor(LightColor);
}

void ADelegateListener::SetLightColorWithPayload(FLinearColor LightColor, bool isEnable)
{
	PointLight->SetLightColor(LightColor);
	PointLight->SetVisibility(isEnable);
}

void ADelegateListener::BeginPlay()
{
	Super::BeginPlay();

	UWorld *world = GetWorld();
	if (world)
	{
		AGameModeBase *gm = UGameplayStatics::GetGameMode(world);
		
		ADelegateGameMode* delegateGM = Cast<ADelegateGameMode>(gm);
		if (delegateGM)
		{
			delegateGM->StandardDelegate.BindUObject(this, &ADelegateListener::EnableLight);
			//delegateGM->ParamDelegate.BindUObject(this, &ADelegateListener::SetLightColor);
			
			//绑定带payload
			//这里的参数在绑定期就传值进去了
			delegateGM->ParamDelegate.BindUObject(this, &ADelegateListener::SetLightColorWithPayload, IsEnable);
		}
	}
}

void ADelegateListener::EndPlay(EEndPlayReason::Type EndPlayReason)
{
	Super::EndPlay(EndPlayReason);
	UWorld *world = GetWorld();
	if (world)
	{
		AGameModeBase *gm = UGameplayStatics::GetGameMode(world);

		ADelegateGameMode* delegateGM = Cast<ADelegateGameMode>(gm);
		if (delegateGM)
		{
			delegateGM->StandardDelegate.Unbind();
			delegateGM->ParamDelegate.Unbind();
		}
	}
}
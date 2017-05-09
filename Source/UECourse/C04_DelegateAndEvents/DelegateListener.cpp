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
		}
	}
}
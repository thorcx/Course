#include "UECourse.h"
#include "HeroBase.h"

AHeroBase::AHeroBase()
{
	
}

int32 AHeroBase::GetTeamNum() const
{
	return 0;
}

FString AHeroBase::GetTeamName_Implementation() const
{
	return TEXT("My Hero In CPP!");
}

void AHeroBase::BeginPlay()
{
	Super::BeginPlay();
	
	//�ֶ���һ������Actor�� 
	APlayerController* PC = UGameplayStatics::GetPlayerController(this, 0);
	if (PC)
	{
		EnableInput(PC);
		if (InputComponent)
		{
			//ֱ�Ӱ�һ������
			InputComponent->BindKey(EKeys::K, EInputEvent::IE_Pressed, this, &AHeroBase::DoKeyAction);
		}

	}
}

void AHeroBase::DoKeyAction()
{
	int32 count = ITeamInterface::Execute_GetTeamMemberCount(this);
	GEngine->AddOnScreenDebugMessage(-1, 10.0f, FColor::Cyan, FString::Printf(TEXT("Team Count is %d"), count));
}
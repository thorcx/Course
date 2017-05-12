#include "UECourse.h"
#include "InterfaceGameMode.h"
#include "HeroBase.h"
#include "TeamInterface.h"
void AInterfaceGameMode::BeginPlay()
{
	//[c_07 ppt5]
	//FTransform SpawnLocation;
	//AHeroBase* hero = GetWorld()->SpawnActor<AHeroBase>(AHeroBase::StaticClass(), SpawnLocation);

	//if (hero->GetClass()->ImplementsInterface(UTeamInterface::StaticClass()))
	//{
	//	GEngine->AddOnScreenDebugMessage(-1, 10.0f, FColor::Red, TEXT("Hero Implement TeamInterface"));
	//}


	for (TActorIterator<AActor> It(GetWorld(), AActor::StaticClass()); It; ++It)
	{
		AActor *actor = *It;
		ITeamInterface *teamInterface = Cast<ITeamInterface>(actor);
		if (teamInterface)
		{
			Count++;
		}
	}
	GEngine->AddOnScreenDebugMessage(-1, 1, FColor::Red, FString::Printf(TEXT("%d actors implement TeamInterface"),Count));
}
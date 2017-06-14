#include "UECourse.h"
#include "InterfaceGameMode.h"
#include "HeroBase.h"
#include "TeamInterface.h"
void AInterfaceGameMode::BeginPlay()
{
	//[ppt 12-5]
	//FTransform SpawnLocation;
	//AHeroBase* hero = GetWorld()->SpawnActor<AHeroBase>(AHeroBase::StaticClass(), SpawnLocation);

	//if (hero->GetClass()->ImplementsInterface(UTeamInterface::StaticClass()))
	//{
	//	GEngine->AddOnScreenDebugMessage(-1, 10.0f, FColor::Red, TEXT("Hero Implement TeamInterface"));
	//}

	
	
}



void AInterfaceGameMode::ShowActorInterfaceInfo()
{
	//[ppt 12-6]
	for (TActorIterator<AActor> It(GetWorld(), AActor::StaticClass()); It; ++It)
	{
		AActor *actor = *It;
		if (actor->GetClass()->ImplementsInterface(UTeamInterface::StaticClass()))
		{
			GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Red, FString::Printf(TEXT("%s actors implement TeamInterface"), *actor->GetName()));
		}

		ITeamInterface *teamInterface = Cast<ITeamInterface>(actor);
		if (teamInterface)
		{
			Count++;
		}
	}
	GEngine->AddOnScreenDebugMessage(-1, 1, FColor::Red, FString::Printf(TEXT("%d actors implement TeamInterface"), Count));
}

void AInterfaceGameMode::CallActorTeamInterface()
{
	for (TActorIterator<AActor> It(GetWorld(), AActor::StaticClass()); It; ++It)
	{
		AActor *actor = *It;
		if (actor->GetClass()->ImplementsInterface(UTeamInterface::StaticClass()))
		{
			ITeamInterface *teamInterface = Cast<ITeamInterface>(actor);
			if (teamInterface)
			{

				GEngine->AddOnScreenDebugMessage(-1, 10.0f, FColor::Red, FString::Printf(TEXT("%s TeamNum is %d"),*actor->GetName(), 
					teamInterface->GetTeamNum()));
			}
		}
	}
}

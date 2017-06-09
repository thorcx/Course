#include "UECourse.h"
#include "SpawnActorGameMode.h"
#include "FirstActor.h"

void ASpawnActorGameMode::BeginPlay()
{
	Super::BeginPlay();
	
	//[ppt-5]
	//创建定时器
	FTimerHandle timeHandler;
	FTimerManager &timeManager = GetWorldTimerManager();
	timeManager.SetTimer(timeHandler, this, &ASpawnActorGameMode::DestroyActorFunction, 10.0f);

	//[ppt-6]
	//MyActor->SetLifeSpan(5.0f);
}

void ASpawnActorGameMode::DestroyActorFunction()
{
	if (MyActor != nullptr)
	{
		MyActor->Destroy();
	}
}

void ASpawnActorGameMode::SpawnActor(FTransform SpawnTransform)
{
	GEngine->AddOnScreenDebugMessage(-1, 10.0f, FColor::Blue, TEXT("Actor Spawning!"));
	MyActor = GetWorld()->SpawnActor<AFirstActor>(AFirstActor::StaticClass(), SpawnTransform);
}

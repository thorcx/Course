#pragma once

#include "GameFramework/GameModeBase.h"
#include "SpawnActorGameMode.generated.h"


//[c3.7]
UCLASS()
class ASpawnActorGameMode : public AGameModeBase
{
	GENERATED_BODY()

public:
	//[c3.8]����Actor������麯��BeginPlay(),Spawn���߼���д��������������������GameMode,BeginPlay()�ͻ�ִ��
	virtual void BeginPlay() override;

	UPROPERTY()
	class AFirstActor *MyActor;

public:
	UFUNCTION()
	void DestroyActorFunction();

	UFUNCTION(BlueprintCallable, Category=ActorSpawn)
	void SpawnActor(FTransform SpawnTransform);
};

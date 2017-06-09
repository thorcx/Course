#pragma once

#include "GameFramework/GameModeBase.h"
#include "SpawnActorGameMode.generated.h"


//[c3.7]
UCLASS()
class ASpawnActorGameMode : public AGameModeBase
{
	GENERATED_BODY()

public:
	
	virtual void BeginPlay() override;

	UPROPERTY()
	class AFirstActor *MyActor;

public:
	//[c3.8]SpawnActor模板函数的使用
	UFUNCTION(BlueprintCallable, Category=ActorSpawn)
	void SpawnActor(FTransform SpawnTransform);

	//[c3.10]销毁Actor函数
	UFUNCTION(BlueprintCallable, Category=ActorSpawn)
	void DestroyActor();

	//[c3.13]使用定时器销毁
	UFUNCTION(BlueprintCallable, Category = ActorSpawn)
	void DestroyActorUseTimer(float LiveTime=1.0f);
};

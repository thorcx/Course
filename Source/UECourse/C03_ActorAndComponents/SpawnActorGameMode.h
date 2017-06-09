#pragma once

#include "GameFramework/GameModeBase.h"
#include "SpawnActorGameMode.generated.h"


//[c3.7]
UCLASS()
class ASpawnActorGameMode : public AGameModeBase
{
	GENERATED_BODY()

public:
	//[c3.8]覆盖Actor基类的虚函数BeginPlay(),Spawn的逻辑就写在这里，这样当引用了这个GameMode,BeginPlay()就会执行
	virtual void BeginPlay() override;

	UPROPERTY()
	class AFirstActor *MyActor;

public:
	UFUNCTION()
	void DestroyActorFunction();

	UFUNCTION(BlueprintCallable, Category=ActorSpawn)
	void SpawnActor(FTransform SpawnTransform);
};

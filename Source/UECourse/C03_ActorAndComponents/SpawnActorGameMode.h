#pragma once

#include "GameFramework/GameModeBase.h"
#include "SpawnActorGameMode.generated.h"

UCLASS()
class ASpawnActorGameMode : public AGameModeBase
{
	GENERATED_BODY()

public:
	virtual void BeginPlay() override;

	UPROPERTY()
	class AFirstActor *MyActor;

public:
	UFUNCTION()
	void DestroyActorFunction();
};

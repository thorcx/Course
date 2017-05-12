#pragma once
#include "GameFramework/Actor.h"
#include "TeamInterface.h"
#include "InterfaceGameMode.generated.h"

UCLASS()
class AInterfaceGameMode : public AGameModeBase
{
	GENERATED_BODY()
public:

	virtual void BeginPlay() override;

public:
	UPROPERTY()
	int32 Count;
};

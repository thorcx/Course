#pragma once
#include "GameFramework/Actor.h"
#include "TeamInterface.h"
#include "BattleInterface.h"
#include "HeroBase.generated.h"



UCLASS()
class AHeroBase : public AActor, public ITeamInterface, public IKillable
{
	GENERATED_BODY()
public:
	int32 GetTeamNum() const override;
	FString GetTeamName_Implementation() const override;
};

#pragma once
#include "GameFramework/Actor.h"
#include "TeamInterface.h"
#include "BattleInterface.h"
#include "HeroBase.generated.h"


//[c7-05]
UCLASS()
class AHeroBase : public AActor, public ITeamInterface, public IKillable
{
	GENERATED_BODY()
	
public:
	AHeroBase();
public:
	//[ppt12-4]
	//[c7-06]
	int32 GetTeamNum() const override;

	FString GetTeamName_Implementation() const override;


	virtual void BeginPlay() override;

	void DoKeyAction();
};

#pragma once
#include "GameFramework/Actor.h"
#include "TeamInterface.h"
#include "UndeadInterface.h"
#include "MonsterBase.generated.h"

//[c7-07]
//[c7-26]
UCLASS()
class AMonsterBase : public AActor, public ITeamInterface, public IUndead
{
	GENERATED_BODY()
	
public:
	//[ppt12-4]
	//[c7-08]
	virtual int32 GetTeamNum() const override;

	//注意这里如果接口是UFUNCTION()
	//加virtual和_Implementation
	virtual FString GetTeamName_Implementation() const override;
};
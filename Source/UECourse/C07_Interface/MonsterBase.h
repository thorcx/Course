#pragma once
#include "GameFramework/Actor.h"
#include "TeamInterface.h"
#include "MonsterBase.generated.h"

UCLASS()
class AMonsterBase : public AActor, public ITeamInterface
{
	GENERATED_BODY()
	
public:
	virtual int32 GetTeamNum() const override;

	//ע����������ӿ���UFUNCTION()
	//��virtual��_Implementation
	virtual FString GetTeamName_Implementation() const override;
};
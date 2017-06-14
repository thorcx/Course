#pragma once
#include "BattleInterface.generated.h"

//[ppt 12-8]
//ע�������meta
//��Ϊ����ĺ�����UFUNCTION(BlueprintCallable),UBTҪ�������BlueprintImplementableEvent����BlueprintNativeEvent
//[c7-21]
UINTERFACE(meta=(CannotImplementInterfaceInBlueprint))
class UKillable : public UInterface
{
	GENERATED_BODY()
};


class IKillable
{
	GENERATED_BODY()
public:

	//[c7-22]
	UFUNCTION(BlueprintCallable, Category=Killable)
	virtual bool IsDead();

	UFUNCTION(BlueprintCallable, Category=Killable)
	virtual void Die();
};


#pragma once
#include "BattleInterface.generated.h"

//[ppt 12-8]
//注意这里的meta
//因为下面的函数是UFUNCTION(BlueprintCallable),UBT要求必须是BlueprintImplementableEvent或者BlueprintNativeEvent
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


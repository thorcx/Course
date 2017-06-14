#pragma once
#include "UndeadInterface.generated.h"

//[ppt 12-8]
//注意多個接口声明不能写在一个头文件，UBT报错，定义可以合在一处,这里的定义在BattleInterface.cpp中
//从接口继承接口 
//[c7-24]
UINTERFACE(meta = (CannotImplementInterfaceInBlueprint))
class UUndead : public UKillable
{
	GENERATED_BODY()
	};

class IUndead : public IKillable
{
	GENERATED_BODY()
	//[c7-25]
	public:
	virtual bool IsDead() override;
	virtual void Die() override;
	//转身逃跑
	UFUNCTION(BlueprintCallable, Category = Killable)
	virtual void Turn();
	//放逐,用来杀死Undead
	UFUNCTION(BlueprintCallable, Category = Killable)
	virtual void Banish();
};

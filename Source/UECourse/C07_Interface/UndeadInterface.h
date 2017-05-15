#pragma once
#include "UndeadInterface.generated.h"

//[ppt 12-8]
//注意声明不能写在一个头文件，UBT报错，定义可以 
//从接口继承接口 
UINTERFACE()
class UUndead : public UKillable
{
	GENERATED_BODY()
	};

class IUndead : public IKillable
{
	GENERATED_BODY()
	public:
	virtual bool IsDead() override;
	virtual void Die() override;
	virtual void Turn();
	virtual void Banish();
};

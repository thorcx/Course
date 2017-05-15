#pragma once
#include "UndeadInterface.generated.h"

//[ppt 12-8]
//ע����������д��һ��ͷ�ļ���UBT����������� 
//�ӽӿڼ̳нӿ� 
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

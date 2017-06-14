#pragma once
#include "UndeadInterface.generated.h"

//[ppt 12-8]
//ע������ӿ���������д��һ��ͷ�ļ���UBT����������Ժ���һ��,����Ķ�����BattleInterface.cpp��
//�ӽӿڼ̳нӿ� 
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
	//ת������
	UFUNCTION(BlueprintCallable, Category = Killable)
	virtual void Turn();
	//����,����ɱ��Undead
	UFUNCTION(BlueprintCallable, Category = Killable)
	virtual void Banish();
};

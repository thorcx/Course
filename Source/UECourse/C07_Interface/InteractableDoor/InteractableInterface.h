#pragma once
#include "InteractableInterface.generated.h"

//���İ���Ҳ��ϰ����ҵ
//��ҵ
//1.Ϊ���ػ�ģ�ͣ����ݿ��ص���״����������ʱ���ʵ�ת������
//2.�Ŵ򿪵ĸ߶ȱ�¶�ɲ������ڹؿ��ڿ��������
//3.Ϊ����д����Ĺض��������ж����Ѿ��򿪺��ٰ��¿��ؽ��Ź���
//4.�����ͼ�̳У�ʵ���ſ����رյĶ���Ч��
//[c7-36]
UINTERFACE()
class UInteractable : public UInterface
{
	GENERATED_BODY()
};


class IInteractable
{
	GENERATED_BODY()
public:

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = Interactable)
		bool CanInteract();

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = Interactable)
		void PerformInteract();
};
#pragma once
#include "SGraphPin.h"


/*
*�������һ����ͼ�ڵ����������ӿ�(Pin)���������Զ�����ɫ��չʾ
*
*/

class UECOURSEEDITOR_API SGraphPinCustomAsset : public SGraphPin
{
	SLATE_BEGIN_ARGS(SGraphPinCustomAsset) {}
	SLATE_END_ARGS()

	void Construct(const FArguments& args, UEdGraphPin* pin);

protected:
	virtual FSlateColor GetPinColor() const override
	{
		return FSlateColor(FColor::Black);
	}

	//�����������ͼ�ڵ�����ʱ���Զ�������ص�������Ҫ�ṩһ�����ص�SWidget����ʾ
	virtual TSharedRef<SWidget> GetDefaultValueWidget() override;

	//������ColorPicker�ؼ���OnColorCommitted�¼��Ļص�
	void ColorPicked(FLinearColor selectColor);
};

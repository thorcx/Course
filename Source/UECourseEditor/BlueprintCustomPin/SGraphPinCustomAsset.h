#pragma once
#include "SGraphPin.h"


/*
*�������һ����ͼ�ڵ����������ӿ�(Pin)���������Զ�����ɫ��չʾ
*
*/
//[c8-73]
class UECOURSEEDITOR_API SGraphPinCustomAsset : public SGraphPin
{
	//[c8-74]
	SLATE_BEGIN_ARGS(SGraphPinCustomAsset) {}
	SLATE_END_ARGS()
	//[c8-75]
	void Construct(const FArguments& args, UEdGraphPin* pin);

protected:
	//[c8-76]
	//����Pin����ɫ
	virtual FSlateColor GetPinColor() const override
	{
		return FSlateColor(FColor::White);
	}
	//[c8-77]
	//�����������ͼ�ڵ�����ʱ���Զ�������ص�������Ҫ�ṩһ�����ص�SWidget����ʾ
	virtual TSharedRef<SWidget> GetDefaultValueWidget() override;

	//[c8-78]
	//������ColorPicker�ؼ���OnColorCommitted�¼��Ļص�
	void ColorPicked(FLinearColor selectColor);
};

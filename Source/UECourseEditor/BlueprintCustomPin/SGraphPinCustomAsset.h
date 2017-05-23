#pragma once
#include "SGraphPin.h"


/*
*这个类是一个蓝图节点的输入输入接口(Pin)，这里用自定义颜色来展示
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

	//这个函数当蓝图节点生成时候自动被引擎回调，你需要提供一个返回的SWidget供显示
	virtual TSharedRef<SWidget> GetDefaultValueWidget() override;

	//绑定上面ColorPicker控件的OnColorCommitted事件的回调
	void ColorPicked(FLinearColor selectColor);
};

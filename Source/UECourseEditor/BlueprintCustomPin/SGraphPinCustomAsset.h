#pragma once
#include "SGraphPin.h"


/*
*这个类是一个蓝图节点的输入输入接口(Pin)，这里用自定义颜色来展示
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
	//返回Pin的颜色
	virtual FSlateColor GetPinColor() const override
	{
		return FSlateColor(FColor::White);
	}
	//[c8-77]
	//这个函数当蓝图节点生成时候自动被引擎回调，你需要提供一个返回的SWidget供显示
	virtual TSharedRef<SWidget> GetDefaultValueWidget() override;

	//[c8-78]
	//绑定上面ColorPicker控件的OnColorCommitted事件的回调
	void ColorPicked(FLinearColor selectColor);
};

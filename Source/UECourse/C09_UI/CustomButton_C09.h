#pragma once
#include "SCompoundWidget.h"

/*
*一个复合控件的写法
*
*/

class SCustomButton : public SCompoundWidget
{
public:
	SLATE_BEGIN_ARGS(SCustomButton)
		: _CustomLabel(TEXT("Default Value"))
		,_ButtonClicked()
	{}

	SLATE_ATTRIBUTE(FString, CustomLabel)
	SLATE_EVENT(FOnClicked, ButtonClicked)
	SLATE_END_ARGS()

public:
	
	//* Slate构造 */
	void Construct(const FArguments &InArgs);


	TAttribute<FString>	CustomLabel;
	FOnClicked ButtonClicked;
};
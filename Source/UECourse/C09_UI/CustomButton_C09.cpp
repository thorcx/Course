#include "UECourse.h"
#include "CustomButton_C09.h"



void SCustomButton::Construct(const FArguments &InArgs)
{
	CustomLabel = InArgs._CustomLabel;
	ButtonClicked = InArgs._ButtonClicked;

	ChildSlot.VAlign(VAlign_Center)
	.HAlign(HAlign_Center)
	[
		SNew(SButton)
		.OnClicked(ButtonClicked)
		.Content()
		[
			SNew(STextBlock)
			.Text_Lambda([this] {return
			FText::FromString(CustomLabel.Get());
			})
		]
	];
}

#include "UECourse.h"
#include "CustomButtonWidget_C09.h"



UCustomButtonWidget::UCustomButtonWidget()
	:Label(TEXT("Default value"))
{

}

FReply UCustomButtonWidget::OnButtonClicked()
{
	ButtonClicked.Broadcast();
	return FReply::Handled();
}

void UCustomButtonWidget::SynchronizeProperties()
{
	Super::SynchronizeProperties();
	TAttribute<FString> LabelBinding = OPTIONAL_BINDING(FString, Label);
	MyButton->CustomLabel = LabelBinding;
}

TSharedRef<SWidget> UCustomButtonWidget::RebuildWidget()
{
	MyButton = SNew(SCustomButton)
		.ButtonClicked(BIND_UOBJECT_DELEGATE(FOnClicked, OnButtonClicked));

	return MyButton.ToSharedRef();
}

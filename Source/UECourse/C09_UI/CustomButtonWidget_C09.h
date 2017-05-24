#pragma once
#include "Components/Widget.h"
#include "CustomButton_C09.h"
#include "SlateDelegates.h"
#include "CustomButtonWidget_C09.generated.h"

DECLARE_DYNAMIC_DELEGATE_RetVal(FString, FGetString);
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FButtonClicked);

UCLASS()
class UCustomButtonWidget : public UWidget
{
	GENERATED_BODY()
	
public:

	UCustomButtonWidget();

	UPROPERTY(BlueprintAssignable)
	FButtonClicked	ButtonClicked;

	FReply OnButtonClicked();

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString Label;

	UPROPERTY()
	FGetString LabelDelegate;

	virtual void SynchronizeProperties() override;

protected:
	
	virtual TSharedRef<SWidget> RebuildWidget() override;
	
	TSharedPtr<SCustomButton>	MyButton;

};
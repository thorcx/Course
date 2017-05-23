#include "UECourseEditor/UECourseEditor.h"
#include "Widgets/Colors/SColorPicker.h"
#include "SGraphPinCustomAsset.h"
#include "CustomAsset.h"




void SGraphPinCustomAsset::Construct(const FArguments& args, UEdGraphPin* pin)
{
	SGraphPin::Construct(SGraphPin::FArguments(), pin);

}


TSharedRef<SWidget> SGraphPinCustomAsset::GetDefaultValueWidget()
{
	return SNew(SColorPicker)
		.OnColorCommitted(this, &SGraphPinCustomAsset::ColorPicked);
}

void SGraphPinCustomAsset::ColorPicked(FLinearColor selectColor)
{
	UCustomAsset* asset = NewObject<UCustomAsset>(GetTransientPackage(), NAME_None, RF_Transient);
	asset->Name			= selectColor.ToFColor(false).ToHex();
	GraphPinObj->GetSchema()->TrySetDefaultObject(*GraphPinObj, asset);
}

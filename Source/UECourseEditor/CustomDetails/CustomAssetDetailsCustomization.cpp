#include "UECourseEditor.h"
#include "IDetailsView.h"
#include "DetailLayoutBuilder.h"
#include "DetailCategoryBuilder.h"
#include "SColorPicker.h"
#include "SBoxPanel.h"
#include "DetailWidgetRow.h"
#include "CustomAssetDetailsCustomization.h"



void FCoolCustomAssetDetailsCustomization::CustomizeDetails(IDetailLayoutBuilder& DetailBuilder)
{

	const TArray<TWeakObjectPtr<UObject>>& SelectedObjects = DetailBuilder.GetDetailsView().GetSelectedObjects();
	//[c8-83]这里获得操作的对象
	for (int32 i = 0; i<SelectedObjects.Num(); ++i)
	{
		const TWeakObjectPtr<UObject>& currentObject = SelectedObjects[i];
		if (currentObject.IsValid())
		{
			MyAsset = Cast<UCustomAsset>(currentObject.Get());
			break;
		}
	}
	//[c8-84]这里添加自定义的Slate控件
	auto &categoryBuilder = DetailBuilder.EditCategory("CustomAsset", FText::GetEmpty(), ECategoryPriority::Important);
	categoryBuilder.AddCustomRow(FText::GetEmpty())
		[
			SNew(SVerticalBox)
			+SVerticalBox::Slot()
			.VAlign(VAlign_Center)
			[
				SNew(SColorPicker)
				.OnColorCommitted(this, &FCoolCustomAssetDetailsCustomization::ColorPicked)
			]
		];
}
//[c8-85]
void FCoolCustomAssetDetailsCustomization::ColorPicked(FLinearColor SelectedColor)
{
	if (MyAsset.IsValid())
	{
		MyAsset.Get()->Name = SelectedColor.ToFColor(false).ToHex();
	}
}

#pragma once
#include "../CustomAsset.h"
#include "DetailLayoutBuilder.h"
#include "IDetailCustomization.h"
#include "IPropertyTypeCustomization.h"

/*
*����ʵ�ֶ��Ƶ���������ϸ�������ʾ
*
*/
//[c8-79]
class FCoolCustomAssetDetailsCustomization : public IDetailCustomization
{
public:
	//[c8-81]
	virtual void CustomizeDetails(IDetailLayoutBuilder& DetailBuilder) override;

	void ColorPicked(FLinearColor SelectedColor);

	//[c8-80]
	static TSharedRef<IDetailCustomization> MakeInstance()
	{
		return MakeShareable(new FCoolCustomAssetDetailsCustomization);
	}

	TWeakObjectPtr<class UCustomAsset>	MyAsset;
};




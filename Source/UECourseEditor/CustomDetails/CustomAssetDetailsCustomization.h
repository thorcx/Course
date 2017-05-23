#pragma once
#include "../CustomAsset.h"
#include "DetailLayoutBuilder.h"
#include "IDetailCustomization.h"
#include "IPropertyTypeCustomization.h"

/*
*����ʵ�ֶ��Ƶ���������ϸ�������ʾ
*
*/

class FCoolCustomAssetDetailsCustomization : public IDetailCustomization
{
public:
	virtual void CustomizeDetails(IDetailLayoutBuilder& DetailBuilder) override;

	void ColorPicked(FLinearColor SelectedColor);

	static TSharedRef<IDetailCustomization> MakeInstance()
	{
		return MakeShareable(new FCoolCustomAssetDetailsCustomization);
	}

	TWeakObjectPtr<class UCustomAsset>	MyAsset;
};




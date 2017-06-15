#pragma once
#include "EdGraphUtilities.h"
#include "SGraphPinCustomAsset.h"
#include "CustomAsset.h"

//[c8-71]
struct UECOURSEEDITOR_API FCoolCustomAssetPinFactory : public FGraphPanelPinFactory
{
public:
	//��д��������ṩһ���Զ����SGraphPin
	virtual TSharedPtr<class SGraphPin> CreatePin(class UEdGraphPin* pin) const override
	{
		if (pin->PinType.PinSubCategoryObject == UCustomAsset::StaticClass())
		{
			return SNew(SGraphPinCustomAsset, pin);
		}
		else
		{
			return nullptr;
		}
	}
};


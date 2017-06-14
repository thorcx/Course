#pragma once

#include "WearableInterface.generated.h"

//[c7-30]
UINTERFACE()
class UWearable : public UInterface
{
	GENERATED_BODY()
};


class IWearable
{
	GENERATED_BODY()
	
public:
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category=Wearable)
	int32 GetStrengthRequirement();

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = Wearable)
	bool CanEquip(APawn* Wearer);

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = Wearable)
	void OnEquip(APawn* Wearer);
};

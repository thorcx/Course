#pragma once
#include "OpenableInterface.generated.h"
//[c7-]
UINTERFACE()
class UOpenableInterface : public UInterface
{
	GENERATED_BODY()
};


class IOpenableInterface
{
	GENERATED_BODY()
	
public:

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category=Openable)
	void Open();

};
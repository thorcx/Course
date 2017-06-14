#pragma once

#include "TalkerInterface.generated.h"

//[c7-33]
UINTERFACE()
class UTalker : public UInterface
{
	GENERATED_BODY()
};


class ITalker
{
	GENERATED_BODY()
public:

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category=Talk)
	void StartTalking();


};
﻿#pragma once

#include "TeamInterface.generated.h"

UINTERFACE()
class UTeamInterface : public UInterface
{
	GENERATED_BODY()
};

//实际的定义写在这里
class ITeamInterface
{
	GENERATED_IINTERFACE_BODY()
public:
	//[ppt12-1]
	virtual int32 GetTeamNum() const = 0;

	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable, Category=TeamInfo)
	int32 GetTeamMemberCount() const;

	//[ppt12-11]
	//UFUNCTION定义的不能是virtual
	//这里实现native是为了蓝图能覆写
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category=TeamInfo)
	FString GetTeamName() const;

	
};

	

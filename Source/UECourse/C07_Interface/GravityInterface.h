#pragma once
#include "GravityInterface.generated.h"

//[c7-16]
UINTERFACE()
class UGravityInterface : public UInterface
{
	GENERATED_BODY()
};


class IGravityInterface
{
	GENERATED_BODY()
	
public:
	virtual void EnableGravity();
	virtual void DisableGravity();
};

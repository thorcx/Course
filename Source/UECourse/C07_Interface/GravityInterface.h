#pragma once
#include "GravityInterface.generated.h"

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

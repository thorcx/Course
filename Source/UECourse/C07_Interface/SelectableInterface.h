#pragma once
#include "SelectableInterface.generated.h"

UINTERFACE()
class USelectable : public UInterface
{
	GENERATED_BODY()
};

class ISelectable
{
	GENERATED_BODY()
public:
	
	virtual bool IsCubeSelectable();

	virtual bool TrySelect();

	virtual void Deselect();
};

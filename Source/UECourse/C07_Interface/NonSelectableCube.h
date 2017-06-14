#pragma once
#include "SelectableCube.h"
#include "NonSelectableCube.generated.h"

//[c7-29]
UCLASS()
class ANonSelectableCube : public ASelectableCube
{
	GENERATED_BODY()
public:

	virtual bool IsCubeSelectable() override;

	virtual bool TrySelect() override;

	virtual void Deselect() override;
};
#include "UECourse.h"
#include "SelectableInterface.h"

bool ISelectable::IsCubeSelectable()
{
	GEngine->AddOnScreenDebugMessage(-1, 10, FColor::Red, TEXT("Selectable"));
	return true;
}

bool ISelectable::TrySelect()
{
	GEngine->AddOnScreenDebugMessage(-1, 10, FColor::Red, TEXT("Accepting Selection"));
	return true;
}

void ISelectable::Deselect()
{
	unimplemented();
}
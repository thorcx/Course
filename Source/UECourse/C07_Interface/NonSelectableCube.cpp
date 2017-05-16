#include "UECourse.h"
#include "NonSelectableCube.h"

bool ANonSelectableCube::IsCubeSelectable()
{
	GEngine->AddOnScreenDebugMessage(-1, 1, FColor::Green, "Not Selectable!");
	return false;
}

bool ANonSelectableCube::TrySelect()
{
	GEngine->AddOnScreenDebugMessage(-1, 1, FColor::Green, "Refusing Selection");
	return false;
}

void ANonSelectableCube::Deselect()
{
	unimplemented();
}
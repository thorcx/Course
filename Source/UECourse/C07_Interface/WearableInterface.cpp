#include "UECourse.h"
#include "WearableInterface.h"

int32 IWearable::GetStrengthRequirement_Implementation()
{
	return 0;
}

bool IWearable::CanEquip_Implementation(APawn* Wearer)
{
	return true;
}

void IWearable::OnEquip_Implementation(APawn* Wearer)
{
	GEngine->AddOnScreenDebugMessage(-1, 5, FColor::Green, TEXT("On Equip Default Implement"));
}
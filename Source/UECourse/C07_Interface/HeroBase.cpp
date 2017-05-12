#include "UECourse.h"
#include "HeroBase.h"

int32 AHeroBase::GetTeamNum() const
{
	return 0;
}

FString AHeroBase::GetTeamName_Implementation() const
{
	return TEXT("My Hero!");
}
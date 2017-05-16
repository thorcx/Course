#include "UECourse.h"
#include "MonsterBase.h"

int32 AMonsterBase::GetTeamNum() const
{
	return 1;
}

FString AMonsterBase::GetTeamName_Implementation() const
{
	return FString("Monster!");
}
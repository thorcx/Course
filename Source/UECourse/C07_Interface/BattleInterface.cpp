#include "UECourse.h"
#include "BattleInterface.h"
#include "UndeadInterface.h"
//----------IKillable----------//
bool IKillable::IsDead()
{
	return false;
}

void IKillable::Die()
{
	GEngine->AddOnScreenDebugMessage(-1, 10, FColor::Purple, "ARRRRR Dead");
	AActor* self = Cast<AActor>(this);
	if (self)
	{
		self->Destroy();
	}
}

//----------IUndead----------//
//±à¼­Æ÷levelbpÀïµ÷ÓÃ

bool IUndead::IsDead()
{
	return true;
}

void IUndead::Die()
{
	GEngine->AddOnScreenDebugMessage(-1, 10, FColor::Black, TEXT("You can not kill undead"));
}


void IUndead::Turn()
{
	GEngine->AddOnScreenDebugMessage(-1, 10, FColor::Black, TEXT("Turning~"));
}

void IUndead::Banish()
{
	AActor* self = Cast<AActor>(this);
	if (self)
	{
		self->Destroy();
	}
}

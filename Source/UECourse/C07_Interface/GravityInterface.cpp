#include "UECourse.h"
#include "GravityInterface.h"


void IGravityInterface::EnableGravity()
{
	AActor* asActor = Cast<AActor>(this);
	if (asActor)
	{
		TArray<UPrimitiveComponent*> Components;
		asActor->GetComponents(Components);
		for (UPrimitiveComponent* comp : Components)
		{
			comp->SetEnableGravity(true);
		}
	}
}

void IGravityInterface::DisableGravity()
{
	AActor* asActor = Cast<AActor>(this);
	if (asActor)
	{
		TArray<UPrimitiveComponent*> Components;
		asActor->GetComponents(Components);
		for (UPrimitiveComponent* comp : Components)
		{
			comp->SetEnableGravity(false);
		}
	}
}
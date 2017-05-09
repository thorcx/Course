#include "UECourse.h"
#include "TimeOfDayHandler.h"

ATimeOfDayHandler::ATimeOfDayHandler()
	:TimeScale(60)
	,Hours(0)
	,Minutes(0)
	,ElapsedSeconds(0.0f)
{
	PrimaryActorTick.bCanEverTick = true;
}


void ATimeOfDayHandler::Tick(float DeltaTime)
{
	ElapsedSeconds += (DeltaTime * TimeScale);

	if (ElapsedSeconds > 60)
	{
		ElapsedSeconds -= 60;
		Minutes++;
		if (Minutes > 60)
		{
			Minutes -= 60;
			Hours++;
		}
	}
	OnTimeChanged.Broadcast(Hours, Minutes);
}
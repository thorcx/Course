#pragma once
#include "GameFramework/Actor.h"
#include "TimeOfDayHandler.generated.h"

//[ppt7-8]

DECLARE_MULTICAST_DELEGATE_TwoParams(FOnTimeChangedSignature, int32, int32)

UCLASS()
class ATimeOfDayHandler : public AActor
{
	GENERATED_BODY()

	ATimeOfDayHandler();


public:
	virtual void Tick(float DeltaTime) override;

public:

	//系数
	UPROPERTY()
	int32 TimeScale;

	//小时
	UPROPERTY()
	int32 Hours;

	//分钟
	UPROPERTY()
	int32 Minutes;

	//经过时间 
	UPROPERTY()
	float ElapsedSeconds;

	FOnTimeChangedSignature OnTimeChanged;
};

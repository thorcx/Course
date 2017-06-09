#pragma once
#include "GameFramework/Actor.h"
#include "DelegateListener.generated.h"

//[ppt7-3]监听事件的类
//[c4.7]
UCLASS()
class ADelegateListener : public AActor
{
	GENERATED_BODY()
	
	ADelegateListener();
	
public:
	virtual void BeginPlay() override;

	//[ppt7-5]
	//在这个Actor从场景中去掉时候解除与代理的绑定
	//作业，用定时器在Actor被开启后的一定时间后解除与代理的绑定
	//[4.11]
	virtual void EndPlay(EEndPlayReason::Type EndPlayReason) override;


	//[ppt7-6]
	//[c4.15]
	UFUNCTION()
	void SetLightColor(FLinearColor LightColor);

	//[c4.18]
	UFUNCTION()
	void SetLightColorWithPayload(FLinearColor LightColor, bool isEnable);

	//[c4.8]
	UFUNCTION()
	void EnableLight();

public:
	UPROPERTY()
	UPointLightComponent* PointLight;

	bool IsEnable = false;
};
#pragma once
#include "GameFramework/Actor.h"
#include "DelegateListener.generated.h"

//[ppt7-3]监听事件的类

UCLASS()
class ADelegateListener : public AActor
{
	GENERATED_BODY()
	
	ADelegateListener();
	
public:
	virtual void BeginPlay() override;

	UFUNCTION()
	void EnableLight();

public:
	UPROPERTY()
	UPointLightComponent* PointLight;
};
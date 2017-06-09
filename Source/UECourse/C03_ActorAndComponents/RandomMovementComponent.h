// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Components/ActorComponent.h"
#include "RandomMovementComponent.generated.h"

//[c3.18]ClassGroup������ͼ����ʱ����ʾ���meta���������Component������ͼ�д���
//��ʼ�Զ��������ƶ�Component
UCLASS( ClassGroup=(Custom) ,meta=(BlueprintSpawnableComponent))
class UECOURSE_API URandomMovementComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	URandomMovementComponent();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	//[c3.20]����ִ���ƶ��߼�
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

public:
	//[c3.19]����ƶ���Χ�޶�
	UPROPERTY()
	float MovementRadius;
	
};

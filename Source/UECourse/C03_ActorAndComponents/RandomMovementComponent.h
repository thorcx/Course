// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Components/ActorComponent.h"
#include "RandomMovementComponent.generated.h"

//[c3.18]ClassGroup控制蓝图生成时的显示类别，meta部分让这个Component可在蓝图中创建
//开始自定义的随机移动Component
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
	//[c3.20]具体执行移动逻辑
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

public:
	//[c3.19]随机移动范围限定
	UPROPERTY()
	float MovementRadius;
	
};

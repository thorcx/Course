// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Components/SceneComponent.h"
#include "OrbitMovementComponent.generated.h"

//[c3.31]
UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class UECOURSE_API UOrbitMovementComponent : public USceneComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UOrbitMovementComponent();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	//[c3.31]是否朝向旋转中心
	UPROPERTY(EditAnywhere, Category=OrbitProperties)
	bool RotateToFaceOutwards;

	//[c3.32]旋转速度
	UPROPERTY(EditAnywhere, Category = OrbitProperties)
	float RotationSpeed;
	//轨道距离
	UPROPERTY(EditAnywhere, Category = OrbitProperties)
	float OrbitDistance;
	//[c3.33]
	//当前绕园旋转的角度
	float CurrentValue;
	
};

// Fill out your copyright notice in the Description page of Project Settings.

#include "UECourse.h"
#include "OrbitMovementComponent.h"


// Sets default values for this component's properties
UOrbitMovementComponent::UOrbitMovementComponent()
	:RotationSpeed(5)
	,OrbitDistance(100)
	,CurrentValue(0)
	,RotateToFaceOutwards(true)
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;
	
	// ...
}


// Called when the game starts
void UOrbitMovementComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UOrbitMovementComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	float currentValueInRadius = FMath::DegreesToRadians(CurrentValue);
	
	SetRelativeLocation(FVector(OrbitDistance * FMath::Cos(currentValueInRadius),
								OrbitDistance * FMath::Sin(currentValueInRadius),
								RelativeLocation.Z));
	
	if (RotateToFaceOutwards)
	{
		//根据相对位置，直接得到朝向
		FVector LookDir = RelativeLocation.GetSafeNormal();
		//得到旋转
		FRotator LookAtRot = LookDir.Rotation();
		SetRelativeRotation(LookAtRot);
	}

	CurrentValue = FMath::Fmod(CurrentValue + (RotationSpeed *DeltaTime), 360);

}


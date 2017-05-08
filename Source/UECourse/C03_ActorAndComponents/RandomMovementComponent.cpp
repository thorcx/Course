// Fill out your copyright notice in the Description page of Project Settings.

#include "UECourse.h"
#include "RandomMovementComponent.h"


// Sets default values for this component's properties
URandomMovementComponent::URandomMovementComponent()
	:MovementRadius(50.f)
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void URandomMovementComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void URandomMovementComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
	AActor *ownerActor = GetOwner();
	
	//չ��д��֤����
	//if (ownerActor)
	//{
	//	float r1 = FMath::FRandRange(-1, 1) * MovementRadius;
	//	float r2 = FMath::FRandRange(-1, 1) * MovementRadius;
	//	float r3 = FMath::FRandRange(-1, 1) * MovementRadius;

	//	FVector currentLocation = ownerActor->GetActorLocation();
	//	ownerActor->SetActorLocation(currentLocation + FVector(r1, r2, r3));
	//}

	//����д����Ϊ��Tick�����ڣ�����Ҫ��Ч��,ʡ����ʱ����
	//��չ��ҵ����timerʵ��һ����ʱ����ƶ�
	if (ownerActor)
	{
		ownerActor->SetActorLocation(ownerActor->GetActorLocation() +
									 FVector(
									  FMath::FRandRange(-1, 1) * MovementRadius,
									  FMath::FRandRange(-1, 1) * MovementRadius,
									  FMath::FRandRange(-1, 1) * MovementRadius)
									);
	}
}

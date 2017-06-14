// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Actor.h"
#include "AntiGravityVolume.generated.h"

//[ppt12-7 ��һ������]
//һ��������Volume
//��ײ�жϵ�һ��ʵ����GravityInterface��Actor������
//����GravityInterface�ķ���ʵ��0����
//[c7-12]
UCLASS()
class UECOURSE_API AAntiGravityVolume : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AAntiGravityVolume();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	//[c7-14]
	virtual void NotifyActorBeginOverlap(AActor* OtherActor) override;
	virtual void NotifyActorEndOverlap(AActor* OtherActor) override;

	// Called every frame
	virtual void Tick(float DeltaTime) override;

public:
	//[c7-13]
	UPROPERTY(VisibleAnywhere)
	UBoxComponent*	CollisionComponent;	
};

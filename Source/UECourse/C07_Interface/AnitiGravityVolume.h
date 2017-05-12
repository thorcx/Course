// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Actor.h"
#include "AnitiGravityVolume.generated.h"

//一个反重力Volume
//碰撞判断当一个实现了GravityInterface的Actor碰到它
//调用GravityInterface的方法实现0重力

UCLASS()
class UECOURSE_API AAnitiGravityVolume : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AAnitiGravityVolume();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	

	virtual void NotifyActorBeginOverlap(AActor* OtherActor) override;
	virtual void NotifyActorEndOverlap(AActor* OtherActor) override;

	// Called every frame
	virtual void Tick(float DeltaTime) override;

public:
	UPROPERTY(VisibleAnywhere)
	UBoxComponent*	CollisionComponent;	
};

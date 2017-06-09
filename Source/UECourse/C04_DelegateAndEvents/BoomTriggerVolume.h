// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Actor.h"
#include "BoomTriggerVolume.generated.h"


//[ppt7-7]
//Event

DECLARE_EVENT(ABoomTriggerVolume, FPlayerEnteredEvent)

//[c4.1]
UCLASS()
class UECOURSE_API ABoomTriggerVolume : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ABoomTriggerVolume();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	//[c4.3]
	virtual void NotifyActorBeginOverlap(AActor* OtherActor) override;
	virtual void NotifyActorEndOverlap(AActor* OtherActor) override;

public:
	//触发碰撞盒子
	//[c4.2]
	UPROPERTY()
	UBoxComponent* TriggerBox;

	UPROPERTY()
	UParticleSystem* BoomParticle;
	
	//当玩家走入后的EventDispatcher
	FPlayerEnteredEvent OnPlayerEntered;
};

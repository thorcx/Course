// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Actor.h"
#include "BoomTriggerVolume.generated.h"

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
	virtual void NotifyActorBeginOverlap(AActor* OtherActor) override;
	virtual void NotifyActorEndOverlap(AActor* OtherActor) override;


	//触发碰撞盒子
	UPROPERTY()
	UBoxComponent* TriggerBox;

	UPROPERTY()
	UParticleSystem* BoomParticle;
	
};

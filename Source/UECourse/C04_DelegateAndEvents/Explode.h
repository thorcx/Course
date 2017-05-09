// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Actor.h"
#include "Explode.generated.h"

UCLASS()
class UECOURSE_API AExplode : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AExplode();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	virtual void EndPlay(EEndPlayReason::Type EndPlayReason) override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	void KaBoom() const;

	

	//作业:
	//加入一个计数器，当爆炸被播放了几次以后，解除与代理的绑定，让其不能再被触发

public:

	FDelegateHandle	EnterVolumnHandle;

	UPROPERTY()
	UParticleSystemComponent* ParticleComp;
	
	UPROPERTY()
	UBillboardComponent* BillBoard;
};

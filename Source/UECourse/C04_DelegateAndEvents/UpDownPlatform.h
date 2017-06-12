// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Actor.h"

#include "UpDownPlatform.generated.h"

//[ppt7-7]
//如何实现一个Event
//这里实现一个移动的平板
//[c4.31]

UCLASS()
class UECOURSE_API AUpDownPlatform : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AUpDownPlatform();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	//[c4.35]
	void Move();


public:
	//作业
	//这里的例子只是让平板在接到事件通知后瞬间移动过去
	//改写这个例子，让平板按你想要的速度移动过去
	virtual void Tick(float DeltaTime) override;



public:
	//[c4.32]
	UPROPERTY(EditAnywhere)
	UStaticMeshComponent* PlatformMesh;

	

private:

	

	//[c4.33]
	UPROPERTY(EditAnywhere, Category = Destination, meta = (AllowPrivateAccess = true))
	class ABoomTriggerVolume* TriggerVolumn;

	
	//[c4.34]
	UPROPERTY(EditAnywhere, Category = Destination, meta = (AllowPrivateAccess = true, MakeEditWidget = true))
	FVector TargetLocation;

	FVector BeginLocation;
};

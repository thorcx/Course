// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Actor.h"
#include "DemoClock.generated.h"

UCLASS()
class UECOURSE_API ADemoClock : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ADemoClock();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UFUNCTION()
	void TimeChanged(int32 Hours, int32 Minutes);

public:
	
	UPROPERTY()
	USceneComponent*	RootSceneComponent;

	UPROPERTY()
	UStaticMeshComponent*	ClockFace;
	
	UPROPERTY()
	USceneComponent*		HourHandle;

	UPROPERTY()
	UStaticMeshComponent*	HourHand;
	

	UPROPERTY()
	USceneComponent*		MinuteHandle;

	UPROPERTY()
	UStaticMeshComponent*	MinuteHand;


	//
	FDelegateHandle		DelegateHandle;
};

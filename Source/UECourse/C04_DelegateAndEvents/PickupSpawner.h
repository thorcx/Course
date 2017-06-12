// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Actor.h"
#include "PickupSpawner.generated.h"
//[c4.56]
UCLASS()
class UECOURSE_API APickupSpawner : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	APickupSpawner();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	//[c4.57]
	UFUNCTION()
	void PickupCollected();
	//[c4.58]
	UFUNCTION()
	void SpawnPickup();

public:
	//[c4.59]
	UPROPERTY()
	USceneComponent* SpawnLocation;
	
	UPROPERTY()
	class UBillboardComponent* Indicator;

	UPROPERTY()
	class APickUp* CurrentPickup;

	FTimerHandle	MyTimer;
};

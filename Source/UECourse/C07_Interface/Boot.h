// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Actor.h"
#include "WearableInterface.h"
#include "Boot.generated.h"
//[c7-31]
UCLASS()
class UECOURSE_API ABoot : public AActor, public IWearable
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ABoot();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	//[c7-32]
	//~ Begin IWearable Interface
	virtual void OnEquip_Implementation(APawn* Wearer) override;
	
	virtual bool CanEquip_Implementation(APawn* Wearer) override;

	virtual int32 GetStrengthRequirement_Implementation() override;
	
	//~ End IWearable Interface
	
	
};

// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Engine/StaticMeshActor.h"
#include "InteractableInterface.h"
#include "DoorBell.generated.h"

/**
 * 
 */
//[c7-38]
UCLASS()
class UECOURSE_API ADoorBell : public AStaticMeshActor, public IInteractable
{
	GENERATED_BODY()
	
public:
	ADoorBell();

	virtual bool CanInteract_Implementation() override;
	virtual void PerformInteract_Implementation() override;
	
	//* 指定与哪个对象产生交互 */
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category=OpenDoor)
	AActor* DoorToOpen;

private:
	bool HasBeenPushed;
};

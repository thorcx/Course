// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Engine/StaticMeshActor.h"
#include "InteractableInterface.h"
#include "DoorBell.generated.h"

/**
 * 
 */
UCLASS()
class UECOURSE_API ADoorBell : public AStaticMeshActor, public IInteractable
{
	GENERATED_BODY()
	
public:
	ADoorBell();

	virtual bool CanInteract_Implementation() override;
	virtual void PerformInteract_Implementation() override;
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category=OpenDoor)
	AActor* DoorToOpen;

private:
	bool HasBeenPushed;
};

// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Engine/StaticMeshActor.h"
#include "InteractableInterface.h"
#include "OpenableInterface.h"
#include "Door.generated.h"

/**
 * 
 */
UCLASS()
class UECOURSE_API ADoor : public AStaticMeshActor, public IInteractable, public IOpenableInterface
{
	GENERATED_BODY()
	
public:

	ADoor();

	UFUNCTION()
	virtual bool CanInteract_Implementation() override;

	UFUNCTION()
	virtual void PerformInteract_Implementation() override;

	UFUNCTION()
	virtual void Open_Implementation() override;
	
	
};

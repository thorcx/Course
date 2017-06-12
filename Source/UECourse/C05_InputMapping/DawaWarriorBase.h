// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Character.h"
#include "DawaWarriorBase.generated.h"

UCLASS()
class UECOURSE_API ADawaWarriorBase : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	ADawaWarriorBase();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	//[c5.4]
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	//[c5.3]
	void MoveForward(float amount);
	
	//[c5.8]
	void MoveRight(float amount);

	void Turn(float amount);

	void LookUp(float amount);

	void OnStartRunning();
	void OnStopRunning();

};

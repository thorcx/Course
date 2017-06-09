// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Character.h"
#include "DwarfBaseCharacter.generated.h"

//[c3.38]
//一个基础的小怪
UCLASS()
class UECOURSE_API ADwarfBaseCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	ADwarfBaseCharacter();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	//[c3.39]Tick内移动
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to inputz
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	
	
};

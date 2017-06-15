// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/PlayerController.h"
#include "ConsoleCommandPlayerController.generated.h"

/**
 * 
 */
//[c8-69]
UCLASS()
class UECOURSE_API AConsoleCommandPlayerController : public APlayerController
{
	GENERATED_BODY()
	
	
public:
	//[c8-70]
	//Execֻ������GameMode����PlayerController��
	UFUNCTION(Exec)
	void TestGo(float x, float y, float z);
	
};

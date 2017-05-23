// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/HUD.h"
#include "CustomHUD.generated.h"

/**
 * 
 */
UCLASS()
class UECOURSE_API ACustomHUD : public AHUD
{
	GENERATED_BODY()
	
	
public:
	//~ Begin AHUD 

	virtual void DrawHUD() override;
	
	//~ End AHUD 
};

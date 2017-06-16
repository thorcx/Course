// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/HUD.h"
#include "CustomHUD_C09.generated.h"

/**
 * 
 */
//[c09-01]
UCLASS()
class UECOURSE_API ACustomHUD_C09 : public AHUD
{
	GENERATED_BODY()
	
	
public:
	//~ Begin AHUD 
	//[C09-02]
	virtual void DrawHUD() override;
	
	//~ End AHUD 
};

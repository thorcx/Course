// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/GameModeBase.h"
#include "C00_LogGameMode.generated.h"

/**
 * 
 */

DECLARE_LOG_CATEGORY_EXTERN(LogCoolGameMode, Log, All);

UCLASS()
class UECOURSE_API AC00_LogGameMode : public AGameModeBase
{
	GENERATED_BODY()
	
protected:
	//~ Begin AActor

	//* BeginPlay */
	virtual void BeginPlay() override;

	//~ End AActor
	
	//* ʹ��UE_Log��� */
	void OutputLog();

	//* ʹ��Console��� */
	void OutputConsole();

	//* ����Ļ��� */
	void OutputScreen();

	//* ʹ���Զ���Log������� */
	void OutputCustomLog();
};

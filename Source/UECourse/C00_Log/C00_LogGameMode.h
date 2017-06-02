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
	
public:
	AC00_LogGameMode();
protected:
	//~ Begin AActor

	//* BeginPlay */
	virtual void BeginPlay() override;

	//~ End AActor
	
	//* 使用UE_Log输出 */
	void OutputLog();

	//* 使用Console输出 */
	void OutputConsole();

	//* 向屏幕输出 */
	void OutputScreen();

	//* 使用自定义Log类型输出 */
	void OutputCustomLog();

	//* 初始化MessageLog类型 */
	void InitMessageLogType(FName loggerName);

	//* 向MessageLog输出 */
	void OutputMessageLog();



};

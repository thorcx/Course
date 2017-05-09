// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/GameModeBase.h"
#include "DelegateGameMode.generated.h"

//[ppt7.3]创建一个无参数代理
DECLARE_DELEGATE(FStandardDelegateSignature)

/**
 * C04: Delegate And Event
 * 第四章使用的GameMode
 */
UCLASS()
class  ADelegateGameMode : public AGameModeBase
{
	GENERATED_BODY()
	
public:
	FStandardDelegateSignature	StandardDelegate;
	
};

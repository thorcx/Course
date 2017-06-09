// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/GameModeBase.h"
#include "DelegateGameMode.generated.h"

//[ppt7.3]创建一个无参数代理
//[c4.5]
DECLARE_DELEGATE(FStandardDelegateSignature)

//[ppt7.6]
//[c4.13]
DECLARE_DELEGATE_OneParam(FParamDelegateSignature, FLinearColor)

//[ppt7.6]
//[c4.21]
DECLARE_MULTICAST_DELEGATE(FMulticastDelegateSignature)



/**[c4.4]
 * C04: Delegate And Event
 * 第四章使用的GameMode
 */
UCLASS()
class  ADelegateGameMode : public AGameModeBase
{
	GENERATED_BODY()
	
public:
	//[c4.6]定义代理对象
	FStandardDelegateSignature	StandardDelegate;
	//[c4.14]
	FParamDelegateSignature     ParamDelegate;
	//[c4.22]
	FMulticastDelegateSignature MultiDelegate;

	
	
};

﻿#pragma once

#include "MemoryDemo.generated.h"

//①这里定义一个UAction
//在GameModeBase中创建
UCLASS(Blueprintable, BlueprintType, meta=(ShortTooltip="Base Class for any Action type."))
class UAction : public UObject
{
	GENERATED_UCLASS_BODY()
	
public:
	virtual void BeginDestroy() override;
	
	virtual void FinishDestroy() override;

public:

	//* Action的名称 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category=Properties)
	FString Text;

	//* Action对应的快捷键② */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Properties)
	FKey ShortcutKey;

	
};

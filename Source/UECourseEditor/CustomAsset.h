// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "UObject/NoExportTypes.h"
#include "CustomAsset.generated.h"

/**
 * 
 */
UCLASS(BlueprintType)
class UECOURSEEDITOR_API UCustomAsset : public UObject
{
	GENERATED_BODY()
	
public:
	UPROPERTY( EditAnywhere, BlueprintReadWrite,Category=CustomAsset)
	FString Name;
};



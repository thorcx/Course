#pragma once


#include "CoolObject.generated.h"

UCLASS()
class ACoolObject : public AActor
{
	GENERATED_BODY()
	
public:

	
	UPROPERTY(EditAnywhere, Category = Texture)
	class UTexture	*Texture;

	UPROPERTY(EditAnywhere, Category = Color)
	FLinearColor	Color;

	UFUNCTION(BlueprintCallable, Category="Cool|CoolFunction")
	void DoSomething();
};

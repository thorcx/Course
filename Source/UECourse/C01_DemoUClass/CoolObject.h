#pragma once


#include "CoolObject.generated.h"

UCLASS()
class ACoolObject : public AActor
{
	GENERATED_BODY()
	
public:

	virtual void BeginPlay() override;

	
	UPROPERTY(VisibleAnywhere, Category = Player)
	FLinearColor	Color;

	UPROPERTY(EditAnywhere, Category = Player)
	class UTexture	*Texture;

	//注意这里的冲突以及编译器的报错
	UPROPERTY(/*VisibleAnywhere,*/ EditInstanceOnly, BlueprintReadOnly, Category = Player)
	int32	PlayerNumber;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Player)
	float	Health;

	UFUNCTION(BlueprintCallable, Category="Cool|CoolFunction")
	void DoSomething();
	
	
	//[ppt-6]
	//展示如何实例化UUserProfile,这里指定一个UUserProfile的子类型，可以是蓝图继承下来的UserProfile子类型
	UPROPERTY(EditAnywhere, Category=Profile)
	TSubclassOf<class UUserProfile>	UserProfileClass;
	
	UPROPERTY()
	class UUserProfile*	UserProfile;

	//生成UserProile实例
	UFUNCTION(BlueprintCallable, Category = "Cool|CoolFunction")
	void ShowUserProfile();
};

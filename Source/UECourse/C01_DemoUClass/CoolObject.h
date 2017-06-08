#pragma once


#include "CoolObject.generated.h"

//[ppt11]
UENUM(BlueprintType)
enum EStatus
{
	SAYHELLO		UMETA(DisplayName = "Say hello"),
	CREATEUOBJECT   UMETA(DisplayName = "Create a UserProfile"),
	PRINTUSTRUCT	UMETA(DisplayName = "Print UStruct members"),
};

//[ppt10]
//⑦使用USTRUCT
USTRUCT(BlueprintType)
struct FPlayerInfo
{
	GENERATED_USTRUCT_BODY()
	
	//* 玩家编号 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int32 PlayerNumber;

	//* 玩家颜色 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FColor PlayerColor;
};


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
	
	//玩家编号
	UPROPERTY(/*VisibleAnywhere,*/ EditInstanceOnly, BlueprintReadOnly, Category = Player)
	int32	PlayerNumber;

	//玩家血量
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Player)
	float	Health;

	//这里使用结构体表示玩家的信息集合
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category=Player)
	FPlayerInfo	PlayerInfo;

	//使用UENUM
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category=PlayerSelection)
	TEnumAsByte<EStatus>	CurrentStatus;

	//[ppt-6]
	//向屏幕输出信息
	UFUNCTION(BlueprintCallable, Category="Cool|CoolFunction")
	void SayHelloToUnreal();
	
	
	//[ppt-7]
	//展示如何实例化UUserProfile,这里指定一个UUserProfile的子类型，可以是蓝图继承下来的UserProfile子类型
	UPROPERTY(EditAnywhere, Category=Profile)
	TSubclassOf<class UUserProfile>	UserProfileClass;
	
	UPROPERTY()
	class UUserProfile*	UserProfile;



	

	//[ppt-8]
	//⑤生成UserProile实例
	UFUNCTION(BlueprintCallable, Category = "UserProfile")
	void CreateUserProfile();

	//[ppt-9]
	//⑥销毁UserProfile
	UFUNCTION(BlueprintCallable, Category = "UserProfile")
	void DeleteUserProfile();

};

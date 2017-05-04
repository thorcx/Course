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
//ʹ��USTRUCT
USTRUCT(BlueprintType)
struct FPlayerInfo
{
	GENERATED_USTRUCT_BODY()
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int32 PlayerNumber;

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

	//ע������ĳ�ͻ�Լ��������ı���
	
	//��ұ��
	UPROPERTY(/*VisibleAnywhere,*/ EditInstanceOnly, BlueprintReadOnly, Category = Player)
	int32	PlayerNumber;

	//���Ѫ��
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Player)
	float	Health;

	//����ʹ�ýṹ���ʾ��ҵ���Ϣ����
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category=Player)
	FPlayerInfo	PlayerInfo;

	//ʹ��UENUM
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category=PlayerSelection)
	TEnumAsByte<EStatus>	CurrentStatus;

	//[ppt-6]
	//����Ļ�����Ϣ
	UFUNCTION(BlueprintCallable, Category="Cool|CoolFunction")
	void SayHelloToUnreal();
	
	
	//[ppt-7]
	//չʾ���ʵ����UUserProfile,����ָ��һ��UUserProfile�������ͣ���������ͼ�̳�������UserProfile������
	UPROPERTY(EditAnywhere, Category=Profile)
	TSubclassOf<class UUserProfile>	UserProfileClass;
	
	UPROPERTY()
	class UUserProfile*	UserProfile;

	//[ppt-8]
	//����UserProileʵ��
	UFUNCTION(BlueprintCallable, Category = "UserProfile")
	void CreateUserProfile();

	//[ppt-9]
	//����UserProfile
	UFUNCTION(BlueprintCallable, Category = "UserProfile")
	void DeleteUserProfile();

};

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

	//ע������ĳ�ͻ�Լ��������ı���
	UPROPERTY(/*VisibleAnywhere,*/ EditInstanceOnly, BlueprintReadOnly, Category = Player)
	int32	PlayerNumber;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Player)
	float	Health;

	UFUNCTION(BlueprintCallable, Category="Cool|CoolFunction")
	void DoSomething();
	
	
	//[ppt-6]
	//չʾ���ʵ����UUserProfile,����ָ��һ��UUserProfile�������ͣ���������ͼ�̳�������UserProfile������
	UPROPERTY(EditAnywhere, Category=Profile)
	TSubclassOf<class UUserProfile>	UserProfileClass;
	
	UPROPERTY()
	class UUserProfile*	UserProfile;

	//����UserProileʵ��
	UFUNCTION(BlueprintCallable, Category = "Cool|CoolFunction")
	void ShowUserProfile();
};

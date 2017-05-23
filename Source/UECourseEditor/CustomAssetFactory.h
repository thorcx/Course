#pragma once
#include "Factories/Factory.h"
#include "Developer/AssetTools/Public/AssetTypeActions_Base.h"
#include "CustomAssetFactory.generated.h"

/*
*Ϊһ���Զ�����Դ�����˵�������
*��FAssetTypeactions_Base�̳�
*/

class FCustomAssetAction : public FAssetTypeActions_Base
{

	virtual bool HasActions(const TArray<UObject *>& InObjects) const override;

	//* �˻ص������˵������Ҽ��˵�ʱ��ִ�еĶ�����ע�������ﴫ���FMenuBuiler���� */
	virtual void GetActions(const TArray<UObject *>& InObjects, FMenuBuilder& MenuBuilder) override;

	virtual FText GetName() const override;
	
	virtual uint32 GetCategories() override;

	//* ������ص��ĺ������������Action��ʲô���͵���Դ��ִ�в���Ч */
	virtual UClass* GetSupportedClass() const override;

	virtual FColor GetTypeColor() const override;

	void CustomAssetContext_Clicked();
	
};



UCLASS()
class UCustomAssetFactory : public UFactory
{
	GENERATED_BODY()
	
public:
	UCustomAssetFactory();

	virtual UObject* FactoryCreateNew(UClass* InClass, UObject* InParent, FName InName, EObjectFlags Flags, UObject* Context, FFeedbackContext* Warn, FName CallingContext) override;
};
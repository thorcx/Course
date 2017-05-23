#pragma once
#include "Factories/Factory.h"
#include "Developer/AssetTools/Public/AssetTypeActions_Base.h"
#include "CustomAssetFactory.generated.h"

/*
*为一个自定义资源关联菜单上下文
*从FAssetTypeactions_Base继承
*/

class FCustomAssetAction : public FAssetTypeActions_Base
{

	virtual bool HasActions(const TArray<UObject *>& InObjects) const override;

	//* 此回调决定了当呼出右键菜单时，执行的动作，注意在这里传入的FMenuBuiler引用 */
	virtual void GetActions(const TArray<UObject *>& InObjects, FMenuBuilder& MenuBuilder) override;

	virtual FText GetName() const override;
	
	virtual uint32 GetCategories() override;

	//* 这个被回调的函数决定了这个Action在什么类型的资源上执行才有效 */
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
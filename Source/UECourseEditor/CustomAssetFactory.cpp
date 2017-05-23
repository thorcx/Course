#include "UECourseEditor.h"
#include "CustomAsset.h"
#include "CustomAssetFactory.h"
#include "Editor/MainFrame/Public/MainFrame.h"


UCustomAssetFactory::UCustomAssetFactory()
	:Super()
{
	bCreateNew = true;
	bEditAfterNew = true;
	SupportedClass = UCustomAsset::StaticClass();
}

UObject* UCustomAssetFactory::FactoryCreateNew(UClass* InClass, UObject* InParent, FName InName, EObjectFlags Flags, UObject* Context, FFeedbackContext* Warn, FName CallingContext)
{

	auto NewObjectAsset = NewObject<UCustomAsset>(InParent, InClass, InName, Flags);
	
	return NewObjectAsset;
}

//-----------FCustomAssetAction Implement-----------//

bool FCustomAssetAction::HasActions(const TArray<UObject *>& InObjects) const
{
	//这个Action是否能执行
	return true;
}

void FCustomAssetAction::GetActions(const TArray<UObject *>& InObjects, FMenuBuilder& MenuBuilder)
{
	/** 注意AddMenuEntry参数跟菜单项的对应关系
	*额外提到一点，图标都是保存在Engin/Content/Editor/Slate/Icons/目录内
	*在SlateEditorStyle.cpp的SetupLevelEditorStyle()函数内注册了路径与字符串的对应关系
	*/
	MenuBuilder.AddMenuEntry(
		FText::FromString("CustomAssetAction"),
		FText::FromString("Action From DAWA Course"),
		FSlateIcon(FEditorStyle::GetStyleSetName(), "LevelEditor.ViewOptions"),
		FUIAction(
			FExecuteAction::CreateRaw(this, &FCustomAssetAction::CustomAssetContext_Clicked),
			FCanExecuteAction()
		)
	);
}

FText FCustomAssetAction::GetName() const
{
	// 菜单上显示的名字
	return FText::FromString("CCCCCCool");
}

uint32 FCustomAssetAction::GetCategories()
{
	//菜单上显示的类别
	return EAssetTypeCategories::Misc;
}

UClass* FCustomAssetAction::GetSupportedClass() const
{
	//返回具体的对象类型
	return UCustomAsset::StaticClass();
}

FColor FCustomAssetAction::GetTypeColor() const
{
	//图标颜色
	return FColor::Red;
}

//菜单项被按下的回调事件
void FCustomAssetAction::CustomAssetContext_Clicked()
{
	TSharedRef<SWindow> window = SNew(SWindow)
		.Title(FText::FromString(TEXT("UECourse Window")))
		.ClientSize(FVector2D(800, 400))
		.SupportsMaximize(false)
		.SupportsMinimize(false);
								

	IMainFrameModule &mainFrameModule = FModuleManager::LoadModuleChecked<IMainFrameModule>(TEXT("MainFrame"));

	if (mainFrameModule.GetParentWindow().IsValid())
	{
		FSlateApplication::Get().AddWindowAsNativeChild(window, mainFrameModule.GetParentWindow().ToSharedRef());
	}
	else
	{
		FSlateApplication::Get().AddWindow(window);
	}
}



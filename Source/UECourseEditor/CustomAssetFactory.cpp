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
	//���Action�Ƿ���ִ��
	return true;
}

void FCustomAssetAction::GetActions(const TArray<UObject *>& InObjects, FMenuBuilder& MenuBuilder)
{
	/** ע��AddMenuEntry�������˵���Ķ�Ӧ��ϵ
	*�����ᵽһ�㣬ͼ�궼�Ǳ�����Engin/Content/Editor/Slate/Icons/Ŀ¼��
	*��SlateEditorStyle.cpp��SetupLevelEditorStyle()������ע����·�����ַ����Ķ�Ӧ��ϵ
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
	// �˵�����ʾ������
	return FText::FromString("CCCCCCool");
}

uint32 FCustomAssetAction::GetCategories()
{
	//�˵�����ʾ�����
	return EAssetTypeCategories::Misc;
}

UClass* FCustomAssetAction::GetSupportedClass() const
{
	//���ؾ���Ķ�������
	return UCustomAsset::StaticClass();
}

FColor FCustomAssetAction::GetTypeColor() const
{
	//ͼ����ɫ
	return FColor::Red;
}

//�˵�����µĻص��¼�
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



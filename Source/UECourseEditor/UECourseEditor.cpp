#include "UECourseEditor.h"
#include "LevelEditor.h"
#include "SlateBasics.h"
#include "MultiBoxExtender.h"
#include "Editor/MainFrame/Public/MainFrame.h"
#include "Developer/AssetTools/Public/AssetToolsModule.h"
#include "CoolCommand.h"
#include "CustomAssetFactory.h"
#include "BlueprintCustomPin/CustomAssetPinFactory.h"
#include "PropertyEditorModule.h"
#include "CustomDetails/CustomAssetDetailsCustomization.h"


IMPLEMENT_GAME_MODULE(FUECourseEditorModule, UECourseEditor)

void FUECourseEditorModule::StartupModule()
{
	FCoolCommands::Register();

	TSharedPtr<FUICommandList> commandList = MakeShareable(new FUICommandList());
	
	commandList->MapAction(FCoolCommands::Get().CoolCommandButton, FExecuteAction::CreateRaw(this,
		&FUECourseEditorModule::CoolCommandButton_Clicked)
		, FCanExecuteAction());

	ToolbarExtender = MakeShareable(new FExtender());
	
	ToolbarExtension = ToolbarExtender->AddToolBarExtension("Compile", EExtensionHook::Before, commandList,
		FToolBarExtensionDelegate::CreateRaw(this, &FUECourseEditorModule::AddToolbarExtension));

	MenuEntryExtender = MakeShareable(new FExtender());

	MenuExtension = MenuEntryExtender->AddMenuExtension("LevelEditor", EExtensionHook::Before, commandList,
		FMenuExtensionDelegate::CreateRaw(this, &FUECourseEditorModule::AddMenuExtension));

	FLevelEditorModule& levelEditorModule = FModuleManager::LoadModuleChecked<FLevelEditorModule>("LevelEditor");
	levelEditorModule.GetToolBarExtensibilityManager()->AddExtender(ToolbarExtender);
	levelEditorModule.GetMenuExtensibilityManager()->AddExtender(MenuEntryExtender);

	

	//���������Ĳ˵�ע��ע��ͷ�ļ�����
	IAssetTools& assetTools = FModuleManager::LoadModuleChecked<FAssetToolsModule>("AssetTools").Get();
	auto customAssetActions = MakeShareable(new FCustomAssetAction);
	assetTools.RegisterAssetTypeActions(customAssetActions);
	CreatedAssetTypeActions.Add(customAssetActions);

	//ע���Զ���ConsoleCommand
	RegisterCustomConsoleCommand();
	
	RegisterCustomPinFactory();

	RegisterCustomDetail();
}

void FUECourseEditorModule::ShutdownModule()
{
	ToolbarExtender->RemoveExtension(ToolbarExtension.ToSharedRef());
	MenuEntryExtender->RemoveExtension(MenuExtension.ToSharedRef());
	ToolbarExtension.Reset();
	MenuExtension.Reset();
	ToolbarExtender.Reset();
	MenuEntryExtender.Reset();

	IAssetTools& assetTools = FModuleManager::LoadModuleChecked<FAssetToolsModule>("AssetTools").Get();
	for (auto action : CreatedAssetTypeActions)
	{
		assetTools.UnregisterAssetTypeActions(action.ToSharedRef());
	}
	
	if (DisplayTestCommand)
	{
		IConsoleManager::Get().UnregisterConsoleObject(DisplayTestCommand);
		DisplayTestCommand = nullptr;
	}

	UnRegisterCustomPinFactory();

	UnRegisterCustomDetail();
}

void FUECourseEditorModule::CoolCommandButton_Clicked()
{
	TSharedRef<SWindow> window = SNew(SWindow)
		.Title(FText::FromString(TEXT("Cool Window")))
		.ClientSize(FVector2D(800.0f, 400.0f))
		.SupportsMaximize(false)
		.SupportsMinimize(false)
		[
			SNew(SVerticalBox)
			+SVerticalBox::Slot()
			.HAlign(HAlign_Center)
			.VAlign(VAlign_Center)
			[
				SNew(STextBlock)
				.Text(FText::FromString(TEXT("Hello world!")))
			]
		];

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

void FUECourseEditorModule::AddToolbarExtension(FToolBarBuilder &builder)
{
	FSlateIcon iconBrush = FSlateIcon(FEditorStyle::GetStyleSetName(), "LevelEditor.ViewOptions", "LevelEditor.ViewOptions.Small");

	builder.AddToolBarButton(FCoolCommands::Get().CoolCommandButton, NAME_None, FText::FromString("Cool Button"),
		FText::FromString("Click Here!"), iconBrush, NAME_None);
}

void FUECourseEditorModule::AddMenuExtension(FMenuBuilder& builder)
{
	FSlateIcon iconBrush = FSlateIcon(FEditorStyle::GetStyleSetName(), "LevelEditor.ViewOptions", "LevelEditor.ViewOptions.Small");

	builder.AddMenuEntry(FCoolCommands::Get().CoolCommandButton);
}

void FUECourseEditorModule::RegisterCustomConsoleCommand()
{
	//ע�����ﴴ����CreateRaw����ʹ��PayLoad�����������ص�����
	DisplayTestCommand = IConsoleManager::Get().RegisterConsoleCommand(TEXT("DisplayTestCommandWindow"),
		TEXT("test"),
		FConsoleCommandDelegate::CreateRaw(this, &FUECourseEditorModule::DisplayWindow, FString(TEXT("Test Command Window"))),
		ECVF_Default);

	//��һ��ʹ��lambda���ʽ�����ķ�ʽ��ע��ʹ���˴������Ĵ���FConsoleCommandWithArgsDelegate
	DisplayUserSpecifiedWindow = IConsoleManager::Get().RegisterConsoleCommand(TEXT("DisplayWindow"), TEXT("test"),
		FConsoleCommandWithArgsDelegate::CreateLambda(
			[&](const TArray<FString>& Args) 
			{
				FString windowTitle;
				for (FString Arg : Args)
				{
					windowTitle += Arg;
					windowTitle.AppendChar(' ');
				}
				this->DisplayWindow(windowTitle);
			}
		), ECVF_Default);
}

//�����в˵��Ļص�����
void FUECourseEditorModule::DisplayWindow(FString WindowTitle)
{
	TSharedRef<SWindow> window = SNew(SWindow)
		.Title(FText::FromString(WindowTitle))
		.ClientSize(FVector2D(800.0f, 400.0f))
		.SupportsMaximize(false)
		.SupportsMinimize(false)
		[
			SNew(SVerticalBox)
			+ SVerticalBox::Slot()
		.HAlign(HAlign_Center)
		.VAlign(VAlign_Center)
		[
			SNew(STextBlock)
			.Text(FText::FromString(TEXT("Hello Console!")))
		]
		];

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


//��ͼpin����ע�ắ��
void FUECourseEditorModule::RegisterCustomPinFactory()
{
	PinFactory = MakeShareable(new FCoolCustomAssetPinFactory());
	FEdGraphUtilities::RegisterVisualPinFactory(PinFactory);
}

void FUECourseEditorModule::UnRegisterCustomPinFactory()
{
	FEdGraphUtilities::UnregisterVisualPinFactory(PinFactory);
	PinFactory.Reset();
}

void FUECourseEditorModule::RegisterCustomDetail()
{
	FPropertyEditorModule& PropertyModule = FModuleManager::LoadModuleChecked<FPropertyEditorModule>("PropertyEditor");

	PropertyModule.RegisterCustomClassLayout(UCustomAsset::StaticClass()->GetFName(),
		FOnGetDetailCustomizationInstance::CreateStatic(&FCoolCustomAssetDetailsCustomization::MakeInstance
		));
}

void FUECourseEditorModule::UnRegisterCustomDetail()
{
	FPropertyEditorModule& PropertyModule = FModuleManager::LoadModuleChecked<FPropertyEditorModule>("PropertyEditor");

	PropertyModule.UnregisterCustomClassLayout(UCustomAsset::StaticClass()->GetFName());
}


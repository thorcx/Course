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

//[c8-35]
IMPLEMENT_GAME_MODULE(FUECourseEditorModule, UECourseEditor)

//[c8-43]
void FUECourseEditorModule::StartupModule()
{
	//[c8-44]
	FCoolCommands::Register();
	//[c8-45]
	TSharedPtr<FUICommandList> commandList = MakeShareable(new FUICommandList());
	
	commandList->MapAction(FCoolCommands::Get().CoolCommandButton, FExecuteAction::CreateRaw(this,
		&FUECourseEditorModule::CoolCommandButton_Clicked)
		, FCanExecuteAction());

	ToolbarExtender = MakeShareable(new FExtender());
	//这里的添加第一个参数是位置锚点，第二个是在锚点前或锚点后
	ToolbarExtension = ToolbarExtender->AddToolBarExtension("Compile", EExtensionHook::Before, commandList,
		FToolBarExtensionDelegate::CreateRaw(this, &FUECourseEditorModule::AddToolbarExtension));

	//[c8-54]
	MenuEntryExtender = MakeShareable(new FExtender());

	MenuExtension = MenuEntryExtender->AddMenuExtension("LevelEditor", EExtensionHook::Before, commandList,
		FMenuExtensionDelegate::CreateRaw(this, &FUECourseEditorModule::AddMenuExtension));

	//[c8-47]
	FLevelEditorModule& levelEditorModule = FModuleManager::LoadModuleChecked<FLevelEditorModule>("LevelEditor");
	levelEditorModule.GetToolBarExtensibilityManager()->AddExtender(ToolbarExtender);
	levelEditorModule.GetMenuExtensibilityManager()->AddExtender(MenuEntryExtender);

	

	//增加上下文菜单注册注意头文件引用
	IAssetTools& assetTools = FModuleManager::LoadModuleChecked<FAssetToolsModule>("AssetTools").Get();
	auto customAssetActions = MakeShareable(new FCustomAssetAction);
	assetTools.RegisterAssetTypeActions(customAssetActions);
	CreatedAssetTypeActions.Add(customAssetActions);

	//注册自定义ConsoleCommand
	RegisterCustomConsoleCommand();
	
	RegisterCustomPinFactory();

	RegisterCustomDetail();
}
//[c8-48]
void FUECourseEditorModule::ShutdownModule()
{
	//[c8-49]
	ToolbarExtender->RemoveExtension(ToolbarExtension.ToSharedRef());
	ToolbarExtension.Reset();
	ToolbarExtender.Reset();
	
	//[c8-55]
	MenuEntryExtender->RemoveExtension(MenuExtension.ToSharedRef());
	MenuExtension.Reset();
	MenuEntryExtender.Reset();

	IAssetTools& assetTools = FModuleManager::LoadModuleChecked<FAssetToolsModule>("AssetTools").Get();
	for (auto action : CreatedAssetTypeActions)
	{
		assetTools.UnregisterAssetTypeActions(action.ToSharedRef());
	}
	//[c8-68]
	if (DisplayTestCommand)
	{
		IConsoleManager::Get().UnregisterConsoleObject(DisplayTestCommand);
		DisplayTestCommand = nullptr;
	}

	UnRegisterCustomPinFactory();

	UnRegisterCustomDetail();
}

//[c8.56]
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
	//[c8-68]
	
	//注意这里创建的CreateRaw代理使用PayLoad将参数传给回调函数
	DisplayTestCommand = IConsoleManager::Get().RegisterConsoleCommand(TEXT("DisplayTestCommandWindow"),
		TEXT("test"),
		FConsoleCommandDelegate::CreateRaw(this, &FUECourseEditorModule::DisplayWindow, FString(TEXT("Test Command Window"))),
		ECVF_Default);

	//另一种使用lambda表达式来做的方式，注意使用了带参数的代理FConsoleCommandWithArgsDelegate
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

//命令行菜单的回调函数
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


//蓝图pin工程注册函数
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


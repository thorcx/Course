#pragma once
#include "Engine.h"
#include "ModuleManager.h"
#include "unrealEd.h"


//IConsoleCommand* DisplayUserSpecifiedWindow;


class FUECourseEditorModule : public IModuleInterface
{

public:

	virtual void StartupModule() override;

	virtual void ShutdownModule() override;

	void CoolCommandButton_Clicked();

	void AddToolbarExtension(FToolBarBuilder &builder);

	void AddMenuExtension(FMenuBuilder& builder);

	//* 注册命令行 */
	void RegisterCustomConsoleCommand();

	//* 命令行回调 */
	void DisplayWindow(FString WindowTitle);
	
	//* 添加Toolbar菜单按钮的Extension指针 */
	TSharedPtr<FExtender>				ToolbarExtender;
	TSharedPtr<const FExtensionBase>	ToolbarExtension;
	
	//* 添加Menu菜单按钮的Extension指针 */
	TSharedPtr<FExtender>				MenuEntryExtender;
	TSharedPtr<const FExtensionBase>	MenuExtension;

	//保存new出来的Action，卸载模块时要释放资源
	TArray<TSharedPtr<class IAssetTypeActions>> CreatedAssetTypeActions;

	IConsoleCommand* DisplayTestCommand;
	IConsoleCommand* DisplayUserSpecifiedWindow;

	//蓝图自定义Pin工厂
	TSharedPtr<struct FCoolCustomAssetPinFactory> PinFactory;

	//注册函数
	void RegisterCustomPinFactory();

	//取消注册函数
	void UnRegisterCustomPinFactory();

	//注册CustomDetail
	void RegisterCustomDetail();

	//取消注册CustomDetail
	void UnRegisterCustomDetail();
};
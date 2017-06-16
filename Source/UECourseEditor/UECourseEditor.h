#pragma once
#include "Engine.h"
#include "ModuleManager.h"
#include "unrealEd.h"


//IConsoleCommand* DisplayUserSpecifiedWindow;

//[c8-34]
class FUECourseEditorModule : public IModuleInterface
{

public:
	//[c8-34]
	virtual void StartupModule() override;
	//[c8-34]
	virtual void ShutdownModule() override;

	//[c8-42]
	void CoolCommandButton_Clicked();

	//[c8-41]
	void AddToolbarExtension(FToolBarBuilder &builder);

	//[c8-51]
	void AddMenuExtension(FMenuBuilder& builder);

	//[c8-66]
	//* 注册命令行 */
	void RegisterCustomConsoleCommand();

	//[c8-67]
	//* 命令行回调 */
	void DisplayWindow(FString WindowTitle);
	
	//[c8-40]
	//* 添加Toolbar菜单按钮的Extension指针 */
	TSharedPtr<FExtender>				ToolbarExtender;
	TSharedPtr<const FExtensionBase>	ToolbarExtension;
	
	//[c8-52]
	//* 添加Menu菜单按钮的Extension指针 */
	TSharedPtr<FExtender>				MenuEntryExtender;
	TSharedPtr<const FExtensionBase>	MenuExtension;

	//保存new出来的Action，卸载模块时要释放资源
	TArray<TSharedPtr<class IAssetTypeActions>> CreatedAssetTypeActions;
	
	//[c8-65]
	IConsoleCommand* DisplayTestCommand;
	IConsoleCommand* DisplayUserSpecifiedWindow;

	//蓝图自定义Pin工厂
	TSharedPtr<struct FCoolCustomAssetPinFactory> PinFactory;

	//[c8-79]
	//注册函数
	void RegisterCustomPinFactory();

	//取消注册函数
	void UnRegisterCustomPinFactory();

	//[c8-86]
	//注册CustomDetail
	void RegisterCustomDetail();

	//取消注册CustomDetail
	void UnRegisterCustomDetail();
};
#pragma once
#include "SlateBasics.h"
#include "SlateExtras.h"

/*
*这里创建一个自定义纯C++类，注意不需要generated.h了，因为不要继承UObject，也没有反射，序列化，垃圾回收支持
*这类型引擎不可见，不管理
*/
//[c09-14]
class FCustomSytle_C09
{
public:
	static void Initialize();

	static void Shutdown();

	static void ReloadTextures();

	static const ISlateStyle& Get();

	static FName GetStyleSetName();

private:
	//[c09-15]
	static TSharedRef<class FSlateStyleSet> Create();

	static TSharedPtr<class FSlateStyleSet> CustomStyleInstance;
};
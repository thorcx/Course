#include "UECourse.h"
#include "CustomStyle_C09.h"
#include "SlateGameResources.h"

void FCustomSytle_C09::Initialize()
{
	if (!CustomStyleInstance.IsValid())
	{
		CustomStyleInstance = Create();
		FSlateStyleRegistry::RegisterSlateStyle(*CustomStyleInstance);
	}
}



void FCustomSytle_C09::Shutdown()
{
	FSlateStyleRegistry::UnRegisterSlateStyle(*CustomStyleInstance);
	ensure(CustomStyleInstance.IsUnique());
	CustomStyleInstance.Reset();
}

void FCustomSytle_C09::ReloadTextures()
{
	FSlateApplication::Get().GetRenderer()->ReloadTextureResources();
}

const ISlateStyle& FCustomSytle_C09::Get()
{
	return *CustomStyleInstance;
}

FName FCustomSytle_C09::GetStyleSetName()
{
	static FName StyleSetName(TEXT("CustomStyle_C09"));
	return StyleSetName;
}



TSharedRef<class FSlateStyleSet> FCustomSytle_C09::Create()
{
	TSharedRef<FSlateStyleSet> styleRef = FSlateGameResources::New(FCustomSytle_C09::GetStyleSetName(), "Game/Slate", "/Game/Slate");
	
	FSlateStyleSet &style = styleRef.Get();
	//找到Button.png
	FSlateBoxBrush boxBrush(FPaths::GameContentDir() / "Slate" / "Button.png", FVector2D(54,54), FMargin(14.0f/54.0f));

	//给样式赋予名称
	//这里使用模版函数，FButtonStyle.SetNormal设置的是按钮平常状态的样子
	style.Set("NormalButtonBrush", FButtonStyle().SetNormal(boxBrush));
	style.Set("NormalButtonText", 
			  FTextBlockStyle(FTextBlockStyle::GetDefault()).SetColorAndOpacity(FSlateColor(FLinearColor(1,0,0,1)))
			  );

	return styleRef;
}

//静态成员变量初始化
TSharedPtr<FSlateStyleSet> FCustomSytle_C09::CustomStyleInstance = nullptr;







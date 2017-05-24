#pragma once
#include "SlateBasics.h"
#include "SlateExtras.h"

/*
*���ﴴ��һ���Զ��崿C++�࣬ע�ⲻ��Ҫgenerated.h�ˣ���Ϊ��Ҫ�̳�UObject��Ҳû�з��䣬���л�����������֧��
*���������治�ɼ���������
*/
class FCustomSytle_C09
{
public:
	static void Initialize();

	static void Shutdown();

	static void ReloadTextures();

	static const ISlateStyle& Get();

	static FName GetStyleSetName();

private:
	static TSharedRef<class FSlateStyleSet> Create();

	static TSharedPtr<class FSlateStyleSet> CustomStyleInstance;
};
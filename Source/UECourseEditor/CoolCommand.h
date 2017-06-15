#pragma once
#include "Commands.h"
#include "EditorStyleSet.h"
//[c8-36]
class FCoolCommands : public TCommands<FCoolCommands>
{
public:
	FCoolCommands()
		:TCommands<FCoolCommands>(FName("UECourse"), 
			FText::FromString("A Cool Command"), 
			NAME_None, 
			FEditorStyle::GetStyleSetName())
	{

	};

	//[c8-37]
	virtual void RegisterCommands() override;
	//[c8-38]
	TSharedPtr<FUICommandInfo> CoolCommandButton;
};
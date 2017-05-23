#pragma once
#include "Commands.h"
#include "EditorStyleSet.h"

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

	virtual void RegisterCommands() override;

	TSharedPtr<FUICommandInfo> CoolCommandButton;
};
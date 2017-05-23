#include "UECourseEditor.h"
#include "Commands.h"
#include "CoolCommand.h"

void FCoolCommands::RegisterCommands()
{
#define LOCTEXT_NAMESPACE ""

	UI_COMMAND(CoolCommandButton, "Cool", "This Demostrate Customize Tool", EUserInterfaceActionType::Button, FInputChord());

#undef LOCTEXT_NAMESPACE
}
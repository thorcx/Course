#pragma once
//#include "UECourse.h"

//[c5.10]
namespace GameGlobal
{
	//注意这里的映射不会出现在蓝图内
	static FInputAxisKeyMapping forwardKey("CodeMoveForward", EKeys::W, 1.0f);
	static FInputAxisKeyMapping backKey("CodeMoveForward",    EKeys::S, -1.0f);
	static FInputActionKeyMapping fireKey("CodeFire", EKeys::LeftMouseButton, 0, 0, 0, 0);
};
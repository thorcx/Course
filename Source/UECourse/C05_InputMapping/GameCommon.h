#pragma once
//#include "UECourse.h"

//[c5.10]
namespace GameGlobal
{
	//ע�������ӳ�䲻���������ͼ��
	static FInputAxisKeyMapping forwardKey("CodeMoveForward", EKeys::W, 1.0f);
	static FInputAxisKeyMapping backKey("CodeMoveForward",    EKeys::S, -1.0f);
	static FInputActionKeyMapping fireKey("CodeFire", EKeys::LeftMouseButton, 0, 0, 0, 0);
};
// Fill out your copyright notice in the Description page of Project Settings.

#include "UECourse.h"
#include "C09_UI/CustomStyle_C09.h"

//

class FUECourseModule :public FDefaultGameModuleImpl
{
	virtual void StartupModule() override
	{
		FCustomSytle_C09::Initialize();
	}

	virtual void ShutdownModule() override
	{
		FCustomSytle_C09::Shutdown();
	}
};
//
IMPLEMENT_PRIMARY_GAME_MODULE(FUECourseModule, UECourse, "UECourse")

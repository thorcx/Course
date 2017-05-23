// Fill out your copyright notice in the Description page of Project Settings.

#include "UECourse.h"
#include "CustomHUDGameMode_C09.h"
#include "CustomHUD_C09.h"



ACustomHUDGameMode_C09::ACustomHUDGameMode_C09()
{
	HUDClass = ACustomHUD_C09::StaticClass();
}

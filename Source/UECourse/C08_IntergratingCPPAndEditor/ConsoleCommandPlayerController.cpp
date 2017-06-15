// Fill out your copyright notice in the Description page of Project Settings.

#include "UECourse.h"
#include "ConsoleCommandPlayerController.h"




void AConsoleCommandPlayerController::TestGo(float x, float y, float z)
{

	GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Red, FString::Printf(TEXT("%f, %f, %f"), x, y, z));
}

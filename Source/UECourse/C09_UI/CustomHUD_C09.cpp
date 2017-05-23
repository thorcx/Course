// Fill out your copyright notice in the Description page of Project Settings.

#include "UECourse.h"
#include "CustomHUD_C09.h"




void ACustomHUD_C09::DrawHUD()
{
	Super::DrawHUD();
	
	Canvas->DrawText(GEngine->GetLargeFont(), TEXT("来一段中文"), 0, 200, 2, 2);

	FCanvasBoxItem ProgressBar(FVector2D(150.0f, 150.0f), FVector2D(100.0f, 5.0f));

	Canvas->DrawItem(ProgressBar);

	DrawRect(FLinearColor::Blue, 150.0f, 150.0f, 100.0f, 5.0f);
}

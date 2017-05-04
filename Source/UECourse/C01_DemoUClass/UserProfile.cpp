// Fill out your copyright notice in the Description page of Project Settings.

#include "UECourse.h"
#include "UserProfile.h"

UUserProfile::UUserProfile()
{
	DataStorage = new FDataStorage;

}

void UUserProfile::BeginDestroy()
{
	Super::BeginDestroy();
	if (DataStorage)
	{
		delete DataStorage;
		DataStorage = nullptr;
	}
	UE_LOG(LogTemp, Warning, TEXT("User Profile GCed"));
}





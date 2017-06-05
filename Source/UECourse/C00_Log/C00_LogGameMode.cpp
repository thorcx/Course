// Fill out your copyright notice in the Description page of Project Settings.

#include "UECourse.h"
#include "C00_LogGameMode.h"
#include "Developer/MessageLog/Public/MessageLogModule.h"

#define LOCTEXT_NAMESPACE "DAWA_CoolGameLog"

DEFINE_LOG_CATEGORY(LogCoolGameMode);

#define FTEXT(x) LOCTEXT(x,x)
FName LoggerName("DAWA_CoolGameLog");



AC00_LogGameMode::AC00_LogGameMode()
{
	InitMessageLogType(LoggerName);
	
	FMessageLog(LoggerName).Warning(FTEXT("A warning message from gamemode ctor"));
	
}


void AC00_LogGameMode::BeginPlay()
{
	Super::BeginPlay();
	
	UE_LOG(LogTemp, SetColor, TEXT("%s"), COLOR_CYAN);

	UE_LOG(LogTemp, Display, TEXT("�����㶫�������"));

	UE_LOG(LogTemp, Warning, TEXT("������ƻƵ�~~"));

	UE_LOG(LogTemp, Error, TEXT("�����ɫ�ģ�"));

	//UE_LOG(LogTemp, Fatal, TEXT("�����ǳ����������⣬�ߵ����������"));

	OutputLog();

	OutputConsole();

	OutputScreen();

	OutputCustomLog();

	OutputMessageLog();
	
}

void AC00_LogGameMode::OutputLog()
{
	UE_LOG(LogTemp, Warning, TEXT("int��� %d"), 123);

	UE_LOG(LogTemp, Warning, TEXT("�ַ���� %s"), TEXT("gogo"));

	UE_LOG(LogTemp, Warning, TEXT("������� %f"), 3.14f);

	FVector vec(1, 2, 3);
	UE_LOG(LogTemp, Warning, TEXT("������� %s"), *vec.ToString());


}

void AC00_LogGameMode::OutputConsole()
{
	GetWorld()->GetFirstPlayerController()->ClientMessage(TEXT("Console ����!"));
}

void AC00_LogGameMode::OutputScreen()
{
	GEngine->AddOnScreenDebugMessage(-1, 10.0f, FColor::Red, TEXT("����Ļ�����Ϣ"));
	GEngine->AddOnScreenDebugMessage(-1, 10.0f, FColor::Red, TEXT("����Ļ�����Ϣ2"));
}

void AC00_LogGameMode::OutputCustomLog()
{
	UE_LOG(LogCoolGameMode, Warning, TEXT("�Լ�������"));
}

void AC00_LogGameMode::InitMessageLogType(FName loggerName)
{
	FMessageLogModule& MessageLogModule = FModuleManager::LoadModuleChecked<FMessageLogModule>("MessageLog");

	FMessageLogInitializationOptions	InitOptions;
	InitOptions.bShowPages = true;
	InitOptions.bShowFilters = true;

	FText LogListingName = FTEXT("CoolGame's Log Listing");

	MessageLogModule.RegisterLogListing(loggerName, LogListingName, InitOptions);
}

void AC00_LogGameMode::OutputMessageLog()
{
	FMessageLog(LoggerName).Error(FTEXT("��Ŷ�����ش���"));
}

#undef LOCTEXT_NAMESPACE
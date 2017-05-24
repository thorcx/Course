// Fill out your copyright notice in the Description page of Project Settings.

#include "UECourse.h"
#include "CustomPlayerController_C09.h"
#include "SlateBasics.h"
#include "SButton.h"
#include "STextBlock.h"
#include "CustomStyle_C09.h"


void ACustomPlayerController_C09::BeginPlay()
{
	Super::BeginPlay();

	bShowMouseCursor = true;
	
}

void ACustomPlayerController_C09::AddSlateButton()
{
		Widget = SNew(SVerticalBox)
		+ SVerticalBox::Slot()
		.HAlign(HAlign_Center)
		.VAlign(VAlign_Center)
		[
			SNew(SButton)
			.Content()
		[
			SNew(STextBlock)
			.Text(FText::FromString(TEXT("Test Button")))
		]
		];

	GEngine->GameViewport->AddViewportWidgetForPlayer(GetLocalPlayer(), Widget.ToSharedRef(), 1);
}

void ACustomPlayerController_C09::RemoveSlateButton()
{
	GEngine->GameViewport->RemoveViewportWidgetForPlayer(GetLocalPlayer(), Widget.ToSharedRef());
}

void ACustomPlayerController_C09::AddAndShowSlateButton()
{
	if (!HideShowWidget.IsValid())
	{
		HideShowWidget = SNew(SVerticalBox)
			+ SVerticalBox::Slot()
			.HAlign(HAlign_Center)
			.VAlign(VAlign_Center)
			[
				SNew(SButton)
				.Content()
			[
				SNew(STextBlock)
				.Text(FText::FromString(TEXT("Show Hide Button")))
			]
			];
		GEngine->GameViewport->AddViewportWidgetForPlayer(GetLocalPlayer(), HideShowWidget.ToSharedRef(), 1);
	}
	HideShowWidget->SetVisibility(EVisibility::Visible);
}

void ACustomPlayerController_C09::HideSlateButton()
{
	HideShowWidget->SetVisibility(EVisibility::Hidden);
}

void ACustomPlayerController_C09::AddAndShowClickableButton()
{
	if (!ClickableWidget.IsValid())
	{
		ClickableWidget = SNew(SVerticalBox)
			+ SVerticalBox::Slot()
			.HAlign(HAlign_Center)
			.VAlign(VAlign_Center)
			[
				SNew(SButton)
				.OnClicked(FOnClicked::CreateUObject(this, &ACustomPlayerController_C09::ButtonClicked))
				.Content()
				[
					SAssignNew(ButtonLabel, STextBlock)
					.Text(FText::FromString(TEXT("µãÎÒ°¡£¡£¡")))
				]
			];
		
		GEngine->GameViewport->AddViewportWidgetForPlayer(GetLocalPlayer(), ClickableWidget.ToSharedRef(), 1);
	}
	
	ClickableWidget->SetVisibility(EVisibility::Visible);
}

void ACustomPlayerController_C09::HideClickableButton()
{
	ClickableWidget->SetVisibility(EVisibility::Hidden);
}

void ACustomPlayerController_C09::AddAndShowDataBindingButton()
{
	if (!PositionWidget.IsValid())
	{
		PositionWidget = SNew(SVerticalBox)
						+SVerticalBox::Slot()
						.HAlign(HAlign_Center)
						.VAlign(VAlign_Center)
						[
							SNew(SButton)
							.Content()
							[
								SNew(STextBlock)
								.Text(TAttribute<FText>::Create(TAttribute<FText>::FGetter::CreateUObject(this,
																		&ACustomPlayerController_C09::GetButtonLabel)))
							]
						];
		
		GEngine->GameViewport->AddViewportWidgetForPlayer(GetLocalPlayer(), PositionWidget.ToSharedRef(), 1);
	}

	PositionWidget->SetVisibility(EVisibility::Visible);
}

void ACustomPlayerController_C09::HideDataBindingButton()
{
	PositionWidget->SetVisibility(EVisibility::Hidden);
}

void ACustomPlayerController_C09::AddAndShowStyleButton()
{
	if (!CustomStyleWidget.IsValid())
	{
		CustomStyleWidget = SNew(SVerticalBox)
			+ SVerticalBox::Slot()
			.HAlign(HAlign_Center)
			.VAlign(VAlign_Center)
			[
				SNew(SButton)
				.ButtonStyle(FCustomSytle_C09::Get(), "NormalButtonBrush")
				.ContentPadding(FMargin(16))
				.Content()
				[
					SNew(STextBlock)
					.TextStyle(FCustomSytle_C09::Get(), "NormalButtonText")
					.Text(FText::FromString(TEXT("ºÃÍæ")))
				]

			];

		GEngine->GameViewport->AddViewportWidgetForPlayer(GetLocalPlayer(), CustomStyleWidget.ToSharedRef(), 1);
	}
	CustomStyleWidget->SetVisibility(EVisibility::Visible);
}

void ACustomPlayerController_C09::HideStyleButton()
{
	CustomStyleWidget->SetVisibility(EVisibility::Hidden);
}

FReply ACustomPlayerController_C09::ButtonClicked()
{
	ButtonLabel->SetText(FString(TEXT("¹þ¹þ¹þ~")));
	return FReply::Handled();
}

FText ACustomPlayerController_C09::GetButtonLabel() const
{
	FVector actorLocation = GetPawn()->GetActorLocation();

	return FText::FromString(FString::Printf(TEXT("%f, %f, %f"), actorLocation.X, actorLocation.Y, actorLocation.Z));
}


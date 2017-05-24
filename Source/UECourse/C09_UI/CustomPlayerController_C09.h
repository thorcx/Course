// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/PlayerController.h"
#include "CustomPlayerController_C09.generated.h"

/**
 * 
 */
UCLASS()
class UECOURSE_API ACustomPlayerController_C09 : public APlayerController
{
	GENERATED_BODY()
	
	
public:
	//~ Begin AActor interface
	
	virtual void BeginPlay() override;
	
	//~ End AActor interface

	//* 添加Slate到屏幕 */
	UFUNCTION(BlueprintCallable, Category=UIControl)
	void AddSlateButton();

	//* 取消添加Slate到屏幕 */
	UFUNCTION(BlueprintCallable, Category = UIControl)
	void RemoveSlateButton();

	//* 添加并显示Slate到屏幕 */
	UFUNCTION(BlueprintCallable, Category = UIControl)
	void AddAndShowSlateButton();

	//* 隐藏Slate */
	UFUNCTION(BlueprintCallable, Category = UIControl)
	void HideSlateButton();

	//* 添加并显示ClickableButton到屏幕 */
	UFUNCTION(BlueprintCallable, Category = UIControl)
	void AddAndShowClickableButton();

	//* 隐藏ClickableButton */
	UFUNCTION(BlueprintCallable, Category = UIControl)
	void HideClickableButton();

	//* 添加并显示数据绑定Button到屏幕 */
	UFUNCTION(BlueprintCallable, Category = UIControl)
	void AddAndShowDataBindingButton();

	//* 隐藏数据绑定Button */
	UFUNCTION(BlueprintCallable, Category = UIControl)
	void HideDataBindingButton();


	//* 添加并显示自定义StyleButton到屏幕 */
	UFUNCTION(BlueprintCallable, Category = UIControl)
	void AddAndShowStyleButton();

	//* 隐藏自定义StyleButton */
	UFUNCTION(BlueprintCallable, Category = UIControl)
	void HideStyleButton();

	//* Click事件回调 */
	FReply	ButtonClicked();

	//* 数据绑定回调 */
	FText	GetButtonLabel() const;


protected:
	TSharedPtr<SVerticalBox>	Widget;
	TSharedPtr<SVerticalBox>	HideShowWidget;

	//* 可点击按钮及内部的文字引用 */
	TSharedPtr<SVerticalBox>	ClickableWidget;
	TSharedPtr<STextBlock>		ButtonLabel;
	
	//* 显示玩家位置按钮 */
	TSharedPtr<SVerticalBox>	PositionWidget;

	//* 显示自定义Style按钮 */
	TSharedPtr<SVerticalBox>	CustomStyleWidget;
	
};

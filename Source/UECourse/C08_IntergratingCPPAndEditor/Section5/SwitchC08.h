// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Engine/StaticMeshActor.h"
#include "SwitchC08.generated.h"
//[c8-19]
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnSwitchTouchedSignature, ASwitchC08*, touchedSwitch);

/**
 * 
 */
//[c8-18]
UCLASS()
class UECOURSE_API ASwitchC08 : public AStaticMeshActor
{
	GENERATED_BODY()
	
	ASwitchC08();
public:
	
	//~Begin AActor Interface

	virtual void BeginPlay() override;

	//~End AActor Interface

public:
	//在这里初始化SwitchDMI而不是在构造函数内！！！否则无效
	virtual void PostInitializeComponents() override;
	//[c8-22]
	UFUNCTION(BlueprintNativeEvent, Category = "Switch|Collision")
	void OnSwitchTriggerOverlapped(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult & SweepResult);

	UFUNCTION(BlueprintNativeEvent, Category = "Switch|Collision")
	void OnSwitchTriggerEndOverlapped(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);

	//[c8-21]
	UPROPERTY()
	class UBoxComponent* BoxTrigger;

	//使用强引用，但是注意因为动态创建，所以不需要序列化，这里用Transient关键字，是这个对象不被序列化，否则保存地图会出报错
	UPROPERTY(Transient)
	UMaterialInstanceDynamic* SwitchDMI;

	//[c8-20]
	UPROPERTY(BlueprintAssignable)
	FOnSwitchTouchedSignature	OnSwitchTouched;
};

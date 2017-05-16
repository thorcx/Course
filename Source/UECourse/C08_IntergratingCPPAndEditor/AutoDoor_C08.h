// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Actor.h"
#include "AutoDoor_C08.generated.h"

UCLASS()
class UECOURSE_API AAutoDoor_C08 : public AActor
{
	GENERATED_BODY()
	
	class UTimelineComponent *DoorTimeLine;
	
public:	
	// Sets default values for this actor's properties
	AAutoDoor_C08();
	
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	//~Begin Door Timeline 回调函数开始
	UFUNCTION()
	void TML_DoorMovementReturn(float value);

	UFUNCTION()
	void TML_DoorLockRotationReturn(float value);

	UFUNCTION()
	void TML_Finished();
	//~End Door Timeline 回调函数结束

	//** 门打开函数，可被蓝图内调用*/
	UFUNCTION(BlueprintCallable, Category="Door|Actions")
	void OpenDoor();

	//** 门关闭函数，可被蓝图内调用*/
	UFUNCTION(BlueprintCallable, Category = "Door|Actions")
	void CloseDoor();



public:
	//**Timeline代理类对象，在TimelineComponent.h中定义的代理类型，这里要与上面写的回调函数绑定,来获取update和timelinefinish事件 */
	FOnTimelineFloat OnInterpDoorMovement;
	
	FOnTimelineFloat OnInterpDoorLockRotation;
	
	FOnTimelineEvent OnTimelineFinished;

public:
	UPROPERTY(EditAnywhere, Category=DoorTimeLine)
	class UCurveFloat*	DoorMovmentCurve;

	UPROPERTY(EditAnywhere, Category = DoorTimeLine)
	class UCurveFloat*	DoorLockRotationCurve;

	//左边门模型
	UPROPERTY(VisibleDefaultsOnly, Category=DoorMesh)
	UStaticMeshComponent *LeftDoorMesh;

	//右边门模型
	UPROPERTY(VisibleDefaultsOnly, Category = DoorMesh)
	UStaticMeshComponent *RightDoorMesh;

	//门中间锁模型
	UPROPERTY(VisibleDefaultsOnly, Category = DoorMesh)
	UStaticMeshComponent *DoorLockMesh;

	//根节点
	UPROPERTY()
	USceneComponent	*SceneRoot;
	
};

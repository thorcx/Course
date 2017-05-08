// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Actor.h"
#include "BarrackBase.generated.h"

//出生小怪的兵营

UCLASS()
class UECOURSE_API ABarrackBase : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ABarrackBase();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	virtual void EndPlay(const EEndPlayReason::Type EndPlayReason) override;

	//执行出生逻辑
	UFUNCTION()
	void SpawnUnit();


	//建筑模型
	UPROPERTY()
	UStaticMeshComponent*		BuildingMesh;

	//出生点
	UPROPERTY()
	UParticleSystemComponent*	SpawnPoint;

	//生出的小怪类型
	//作业，使之可以蓝图指定子类
	UPROPERTY()
	UClass*						ClassToSpawn;

	//生成间隔
	UPROPERTY()
	float						SpawnInterval;

	//定时器句柄
	UPROPERTY()
	FTimerHandle				SpawnTimerHandler;
	
};

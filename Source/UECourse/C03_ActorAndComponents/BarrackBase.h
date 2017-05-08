// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Actor.h"
#include "BarrackBase.generated.h"

//����С�ֵı�Ӫ

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

	//ִ�г����߼�
	UFUNCTION()
	void SpawnUnit();


	//����ģ��
	UPROPERTY()
	UStaticMeshComponent*		BuildingMesh;

	//������
	UPROPERTY()
	UParticleSystemComponent*	SpawnPoint;

	//������С������
	//��ҵ��ʹ֮������ͼָ������
	UPROPERTY()
	UClass*						ClassToSpawn;

	//���ɼ��
	UPROPERTY()
	float						SpawnInterval;

	//��ʱ�����
	UPROPERTY()
	FTimerHandle				SpawnTimerHandler;
	
};

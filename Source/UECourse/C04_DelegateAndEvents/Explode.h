// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Actor.h"
#include "Explode.generated.h"

UCLASS()
class UECOURSE_API AExplode : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AExplode();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	virtual void EndPlay(EEndPlayReason::Type EndPlayReason) override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	void KaBoom() const;

	

	//��ҵ:
	//����һ��������������ը�������˼����Ժ󣬽�������İ󶨣����䲻���ٱ�����

public:

	FDelegateHandle	EnterVolumnHandle;

	UPROPERTY()
	UParticleSystemComponent* ParticleComp;
	
	UPROPERTY()
	UBillboardComponent* BillBoard;
};

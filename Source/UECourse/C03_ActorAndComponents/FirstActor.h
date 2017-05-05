// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Actor.h"
#include "FirstActor.generated.h"

UCLASS()
class UECOURSE_API AFirstActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AFirstActor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	virtual void BeginDestroy() override;

	//注意这里覆写的Actor的Destroy函数在SetLifeSpan到期后立刻被调用，并不会等到垃圾回收，跟上面的BeginDestroy要区别开
	virtual void Destroyed() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

public:
	//注意这里要加UPROPERTY防止被GC
	UPROPERTY()
	UStaticMeshComponent* Mesh;

	
};

// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Actor.h"
#include "EnemyBase_C08.generated.h"
//[ppt8章-2]

//注意这里从Actor继承默认是Blueprintable的，也可以显式指定
//UObject默认是NotBlueprintable
//[c8-03]
UCLASS(Blueprintable)
class UECOURSE_API AEnemyBase_C08 : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AEnemyBase_C08();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UFUNCTION(Exec)
	void DoSomeTestAnimal(FVector pos);

	//* 敌人携带的武器名称 */
	UPROPERTY(BlueprintReadOnly)
	FString WeaponName;

	//* 敌人最大血量 */
	UPROPERTY(BlueprintReadWrite)
	int32 MaximumHealth;
	
};

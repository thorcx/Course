// Fill out your copyright notice in the Description page of Project Settings.
//[c3.1]确保头文件只被引用一次
#pragma once

//[c3.2]因为是继承自AActor,我们需要包含AActor的声明
#include "GameFramework/Actor.h"
//[c3.3]每一个UCLASS类型都需要在最后有这样形式的包含语句
#include "FirstActor.generated.h"

//[c3.4]这里是类声明开始,UECOURSE_API是引擎自动生成，目的是当我们的模块如果作为导出模块被其他模块使用，确保这个类被正确导出.
UCLASS()
class UECOURSE_API AFirstActor : public AActor
{
	// [c3.5]这个宏在UCLASS()声明的类内必定要定义，目的是通过UHT插入额外的代码来支持蓝图可见.
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

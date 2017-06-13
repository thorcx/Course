// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Engine/StaticMeshActor.h"
#include "RayCastCamera_C06.generated.h"

UCLASS()
class UECOURSE_API ARayCastCamera_C06 : public AStaticMeshActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ARayCastCamera_C06();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	//[c6-3]
	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category=CollisionTest)
	void DoSingleTrace();

public:
	class UStaticMeshComponent	*CameraMesh;
	
	UPROPERTY(EditAnywhere, Category="CollisionDemo")
	float SingleTraceLineLength;
};

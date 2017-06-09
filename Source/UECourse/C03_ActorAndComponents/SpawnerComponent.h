// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Components/SceneComponent.h"
#include "SpawnerComponent.generated.h"

//[c3.21]�̳���SceneComponent�߱�λ����Ϣ,�ܱ�Attach������Component��Actor��
UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class UECOURSE_API USpawnerComponent : public USceneComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	USpawnerComponent();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	//[c3.23]
	UFUNCTION(BlueprintCallable, Category=Spawner)
	void SpawnStaticMeshActor();

public:
	//[c3.22]ָ��Ҫ���ɵ�Actor�Ļ�����
	UPROPERTY(EditAnywhere, Category=SpawnClass)
	TSubclassOf<AStaticMeshActor> MeshActorToSpawn;
	
	
};

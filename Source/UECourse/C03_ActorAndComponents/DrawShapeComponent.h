// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Components/MeshComponent.h"
#include "DrawShapeComponent.generated.h"

/**
 * һ������Ļ�ϻ�ͼ�ε�Component
 *�˴��Ǹ߽���ѧ���ݣ���ͼ��APIʹ�þ���Ŀ��Բο�����������Թ�
 */
UCLASS(ClassGroup=Experimental, meta = (BlueprintSpawnableComponent))
class UECOURSE_API UDrawShapeComponent : public UMeshComponent
{
	GENERATED_BODY()
	
	UDrawShapeComponent();
public:
	virtual FPrimitiveSceneProxy* CreateSceneProxy() override;
	TArray<int32> Indices;
	TArray<FVector> Vertices;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category=DrawShapMaterial)
	UMaterial*	ShapeMaterial;
	
	
};
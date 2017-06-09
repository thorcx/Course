// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Components/MeshComponent.h"
#include "DrawShapeComponent.generated.h"

//[c3.24]
/**
 * 一个在屏幕上画图形的Component
 *此处是高阶自学内容，有图形API使用经验的可以参考，否则可以略过
 */
UCLASS(ClassGroup=Experimental, meta = (BlueprintSpawnableComponent))
class UECOURSE_API UDrawShapeComponent : public UMeshComponent
{
	GENERATED_BODY()
	
	UDrawShapeComponent();
public:
	//[c3.25]
	virtual FPrimitiveSceneProxy* CreateSceneProxy() override;
	
	//[c3.26] 顶点缓冲与索引缓冲
	TArray<int32> Indices;
	TArray<FVector> Vertices;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category=DrawShapMaterial)
	UMaterial*	ShapeMaterial;
	
	
};

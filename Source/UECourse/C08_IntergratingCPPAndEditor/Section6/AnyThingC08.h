// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Engine/StaticMeshActor.h"
#include "AnyThingC08.generated.h"

//与9共享例子
/**
 * 
 */
//[c8-25]
UENUM(BlueprintType)
enum AnyThingShapeType
{
	Shape_Ball,
	Shape_Pillar,
	Shape_Cake
};

//[c8-24]
UCLASS()
class UECOURSE_API AAnyThingC08 : public AStaticMeshActor
{
	GENERATED_BODY()
	
	AAnyThingC08();

	//~Begin AActor Interface
	
	virtual void BeginPlay() override;
	
	//~End AActor Interface

	//[c8-30]
#if WITH_EDITOR
	virtual void PostEditChangeProperty(FPropertyChangedEvent& PropertyChangedEvent) override;

#endif
	
protected:
	//[c8-28]
	//* 根据枚举值刷新根节点的Mesh */
	virtual void RefreshShape();
	
	

public:
	
	//是否让枚举值可以在Editor内随时刷新
	UPROPERTY(EditAnywhere, Category=EditorControll)
	bool bUseInEditorRefresh;

	//[c8-26]
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category=ShapeType)
	TEnumAsByte<AnyThingShapeType>  ShapeType;

private:
	//[c8-28]
	UPROPERTY(Transient)
	TArray<class UStaticMesh*>	MeshArray;
};

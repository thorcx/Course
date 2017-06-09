// Fill out your copyright notice in the Description page of Project Settings.

#include "UECourse.h"
#include "DrawShapeComponent.h"
#include <VertexFactory.h>
#include "DynamicMeshBuilder.h"

//Build.cs ×¢Òâ¼Ó"ShaderCore", "RHI", "RenderCore"
//[c3.27]
class FCustomVertexBuffer : public FVertexBuffer
{
public:
	TArray<FVector> Vertices;

	virtual void InitRHI() override
	{
		FRHIResourceCreateInfo createInfo;

		VertexBufferRHI = RHICreateVertexBuffer(Vertices.Num()* sizeof(FVector), BUF_Static, createInfo);
		void* VertexBufferData = RHILockVertexBuffer(VertexBufferRHI, 0, Vertices.Num()*sizeof(FVector),RLM_WriteOnly);
		FMemory::Memcpy(VertexBufferData, Vertices.GetData(), Vertices.Num()*sizeof(FVector));
		RHIUnlockVertexBuffer(VertexBufferRHI);
	}
};

class FCustomIndexBuffer : public FIndexBuffer
{
public:
	TArray<int32> Indices;

	virtual void InitRHI() override
	{
		FRHIResourceCreateInfo createInfo;
		IndexBufferRHI = RHICreateIndexBuffer(sizeof(int32), Indices.Num() * sizeof(int32), BUF_Static, createInfo);
		void* Buffer = RHILockIndexBuffer(IndexBufferRHI, 0, Indices.Num()*sizeof(int32), RLM_WriteOnly);
		FMemory::Memcpy(Buffer, Indices.GetData(), Indices.Num()*sizeof(int32));
		RHIUnlockIndexBuffer(IndexBufferRHI);
	}
};

//[c3.28]
class FMySceneProxy : public FPrimitiveSceneProxy
{
public:
	FMySceneProxy(UDrawShapeComponent* Component)
	:FPrimitiveSceneProxy(Component),Indices(Component->Indices),
	TheMaterial(Component->ShapeMaterial)
	{
		VertexBuffer = FCustomVertexBuffer();
		IndexBuffer  = FCustomIndexBuffer();
		for (FVector Vertex : Component->Vertices)
		{
			Vertices.Add(FDynamicMeshVertex(Component->GetComponentLocation() + Vertex));
		}
	};

	virtual FPrimitiveViewRelevance GetViewRelevance(const FSceneView* View) const override
	{
		FPrimitiveViewRelevance result;
		result.bDynamicRelevance = true;
		result.bDrawRelevance = true;
		result.bNormalTranslucencyRelevance = true;
		return result;
	}

	virtual void GetDynamicMeshElements(const TArray<const FSceneView*>& Views, const FSceneViewFamily& ViewFamily, uint32 VisibilityMap, class FMeshElementCollector& Collector) const override
	{
		for (int32 ViewIndex = 0; ViewIndex < Views.Num(); ViewIndex++)
		{
			FDynamicMeshBuilder meshBuilder;
			if (Vertices.Num() == 0)
			{
				return;
			}
			meshBuilder.AddVertices(Vertices);
			meshBuilder.AddTriangles(Indices);

			meshBuilder.GetMesh(FMatrix::Identity, new FColoredMaterialRenderProxy(TheMaterial->GetRenderProxy(false), FLinearColor::Gray),
								GetDepthPriorityGroup(Views[ViewIndex]),true, true, ViewIndex,Collector);

		}
	}

	virtual void OnTransformChanged() override
	{
		VertexBuffer.ReleaseResource();
		IndexBuffer.ReleaseResource();
	}
	//virtual void OnActorPositionChanged() 
	//{
	//	VertexBuffer.ReleaseResource();
	//	IndexBuffer.ReleaseResource();
	//}

	uint32 GetMemoryFootprint() const override
	{
		return sizeof(*this);
	}

	virtual ~FMySceneProxy(){};

	UPROPERTY()
	UMaterial* TheMaterial;
private:
	TArray<FDynamicMeshVertex>	Vertices;
	TArray<int32>				Indices;
	FCustomVertexBuffer			VertexBuffer;
	FCustomIndexBuffer			IndexBuffer;

};

//[c3.29]
FPrimitiveSceneProxy* UDrawShapeComponent::CreateSceneProxy()
{
	FPrimitiveSceneProxy *proxy = new FMySceneProxy(this);
	return proxy;
}

//[c3.30]
UDrawShapeComponent::UDrawShapeComponent()
{
	static ConstructorHelpers::FObjectFinder<UMaterial> matAsset(TEXT("Material'/Engine/BasicShapes/BasicShapeMaterial.BasicShapeMaterial'"));
	if (matAsset.Object != nullptr)
	{
		ShapeMaterial = (UMaterial*)matAsset.Object;
	}

	Vertices.Add(FVector(10,0,0));
	Vertices.Add(FVector(0, 10, 0));
	Vertices.Add(FVector(0, 0, 10));

	Indices.Add(0);
	Indices.Add(1);
	Indices.Add(2);
}



// Fill out your copyright notice in the Description page of Project Settings.

#include "UECourse.h"
#include "FirstActor.h"


// Sets default values
AFirstActor::AFirstActor()
{
 	//设置是否允许Actor执行Tick函数
	PrimaryActorTick.bCanEverTick = true;
	
	//[c3.15]
	//[ppt-8]
	//注意这里创建的第一个组件默认为RootComponent
	Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("BaseMeshComponent"));
	
	//显示指定RootComponent为Mesh
	RootComponent = Mesh;
	
	//[ppt-9]
	//可以使用auto 让编译器推导(deduce)实际的返回类型
	//这里写明是为了明确具体类型
	//资源的字符串可以在编辑器内实际的asset右键鼠标，Copy Reference得到，注意要整段用""包起来
	//尝试输入错误的路径然后看OutputLog输出
	//[c3.16]
	ConstructorHelpers::FObjectFinder<UStaticMesh> MeshAsset = ConstructorHelpers::FObjectFinder<UStaticMesh>(TEXT("StaticMesh'/Engine/EditorMeshes/ArcadeEditorSphere.ArcadeEditorSphere'"));
	
	//一定要检查是否为空，有可能会加载失败
	if (MeshAsset.Object != nullptr)
	{
		Mesh->SetStaticMesh(MeshAsset.Object);
	}
	else
	{
		UE_LOG(LogTemp, Error, TEXT("Can't Load mesh!"));
	}
}

// Called when the game starts or when spawned
void AFirstActor::BeginPlay()
{
	Super::BeginPlay();
	
}

void AFirstActor::BeginDestroy()
{
	GEngine->AddOnScreenDebugMessage(-1, 10.0f, FColor::Blue, TEXT("Actor GC Destroyed!"));
	Super::BeginDestroy();
}

void AFirstActor::Destroyed()
{
	GEngine->AddOnScreenDebugMessage(-1, 10.0f, FColor::Blue, TEXT("Actor Mark Destroyed!"));
	Super::Destroyed();
}


// Called every frame
void AFirstActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}


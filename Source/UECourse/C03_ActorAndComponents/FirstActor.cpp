// Fill out your copyright notice in the Description page of Project Settings.

#include "UECourse.h"
#include "FirstActor.h"


// Sets default values
AFirstActor::AFirstActor()
{
 	//�����Ƿ�����Actorִ��Tick����
	PrimaryActorTick.bCanEverTick = true;
	
	//[c3.15]
	//[ppt-8]
	//ע�����ﴴ���ĵ�һ�����Ĭ��ΪRootComponent
	Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("BaseMeshComponent"));
	
	//��ʾָ��RootComponentΪMesh
	RootComponent = Mesh;
	
	//[ppt-9]
	//����ʹ��auto �ñ������Ƶ�(deduce)ʵ�ʵķ�������
	//����д����Ϊ����ȷ��������
	//��Դ���ַ��������ڱ༭����ʵ�ʵ�asset�Ҽ���꣬Copy Reference�õ���ע��Ҫ������""������
	//������������·��Ȼ��OutputLog���
	//[c3.16]
	ConstructorHelpers::FObjectFinder<UStaticMesh> MeshAsset = ConstructorHelpers::FObjectFinder<UStaticMesh>(TEXT("StaticMesh'/Engine/EditorMeshes/ArcadeEditorSphere.ArcadeEditorSphere'"));
	
	//һ��Ҫ����Ƿ�Ϊ�գ��п��ܻ����ʧ��
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


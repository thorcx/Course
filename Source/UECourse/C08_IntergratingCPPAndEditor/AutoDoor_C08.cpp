// Fill out your copyright notice in the Description page of Project Settings.

#include "UECourse.h"
#include "AutoDoor_C08.h"
#include "Components/TimelineComponent.h"

//�������ʾ��C++�������ʵ��TimeLine��

// Sets default values
AAutoDoor_C08::AAutoDoor_C08()
{
	//�������ø��ڵ�
	SceneRoot = CreateDefaultSubobject<USceneComponent>(TEXT("SceneRoot"));
	RootComponent = SceneRoot;
	
	//TimeLineComponent����Ҫ����Attachment
	DoorTimeLine	= CreateDefaultSubobject<UTimelineComponent>(TEXT("DoorTimeLine"));
 	
	//����������
	LeftDoorMesh	= CreateDefaultSubobject<UStaticMeshComponent>(TEXT("LeftDoorMesh"));
	RightDoorMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("RightDoorMesh"));

	//��������Դ
	ConstructorHelpers::FObjectFinder<UStaticMesh> meshAsset(TEXT("StaticMesh'/Game/DemoRoom/Meshes/SM_Door.SM_Door'"));
	if (meshAsset.Object)
	{
		LeftDoorMesh->SetStaticMesh(meshAsset.Object);
		RightDoorMesh->SetStaticMesh(meshAsset.Object);
		LeftDoorMesh->SetRelativeRotation(FRotator(0.0f, 180.0f, 0.0f));
	}
	//��������Ϊ�����ӽڵ�
	LeftDoorMesh->SetupAttachment(GetRootComponent());
	RightDoorMesh->SetupAttachment(GetRootComponent());
	
	DoorLockMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("DoorLockMesh"));
	ConstructorHelpers::FObjectFinder<UStaticMesh> lockAsset(TEXT("StaticMesh'/Game/DemoRoom/Meshes/SM_DoorLock.SM_DoorLock'"));
	if (lockAsset.Object)
	{
		DoorLockMesh->SetStaticMesh(lockAsset.Object);
		DoorLockMesh->SetupAttachment(RightDoorMesh);
		DoorLockMesh->SetRelativeLocation(FVector(0.0f, 0.0f, 150.0f));
	}

	OnInterpDoorMovement.BindUFunction(this, FName("TML_DoorMovementReturn"));
	OnInterpDoorLockRotation.BindUFunction(this, FName("TML_DoorLockRotationReturn"));
	OnTimelineFinished.BindUFunction(this, FName("TML_Finished"));

	PrimaryActorTick.bCanEverTick = true;
	
}



//[c8-13]
//������������ã���Editor��ע��Ҫָ����Ӧ��Curve����Ȼ�Ų��ᶯ
void AAutoDoor_C08::BeginPlay()
{
	Super::BeginPlay();
	if (DoorMovmentCurve)
		DoorTimeLine->AddInterpFloat(DoorMovmentCurve, OnInterpDoorMovement, FName("DoorMovement"));
	if (DoorLockRotationCurve)
		DoorTimeLine->AddInterpFloat(DoorLockRotationCurve, OnInterpDoorLockRotation, FName("DoorRotation"));

	DoorTimeLine->SetTimelineFinishedFunc(OnTimelineFinished);

	//timeline�Ĳ���
	DoorTimeLine->SetLooping(false);

}

// Called every frame
void AAutoDoor_C08::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}
//[c8-14]
void AAutoDoor_C08::TML_DoorMovementReturn(float value)
{
	RightDoorMesh->SetRelativeLocation(FVector(0, value, 0));
	
	LeftDoorMesh->SetRelativeLocation(FVector(0, -value, 0));
}

void AAutoDoor_C08::TML_DoorLockRotationReturn(float value)
{
	DoorLockMesh->SetRelativeRotation(FRotator(0.0f, 0.0f, value));
}

void AAutoDoor_C08::TML_Finished()
{

}

void AAutoDoor_C08::OpenDoor()
{
	DoorTimeLine->Play();
}

void AAutoDoor_C08::CloseDoor()
{
	DoorTimeLine->Reverse();
}


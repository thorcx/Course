// Fill out your copyright notice in the Description page of Project Settings.

#include "UECourse.h"
#include "UpDownPlatform.h"
#include "BoomTriggerVolume.h"
#include "Kismet/KismetMathLibrary.h"
// Sets default values
AUpDownPlatform::AUpDownPlatform()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("sceneroot"));
	PlatformMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh0"));
	PlatformMesh->SetupAttachment(RootComponent);
	
	ConstructorHelpers::FObjectFinder<UStaticMesh> meshAsset(TEXT("StaticMesh'/Game/Assets/Meshes/SM_Platform.SM_Platform'"));
	if (meshAsset.Object)
	{
		PlatformMesh->SetStaticMesh(meshAsset.Object);
		PlatformMesh->SetRelativeScale3D(FVector(1, 1, 0.1));
	}

}
//[c4.36]
// Called when the game starts or when spawned
void AUpDownPlatform::BeginPlay()
{
	Super::BeginPlay();
	//��¼��ƽ̨��ʼλ�ã�Ϊ�������ƶ�
	BeginLocation = GetActorLocation();
	//TargetLocation = UKismetMathLibrary::TransformLocation(GetActorTransform(), TargetLocation);
	//ע��������Ҫ��¼��Ŀ��λ����LocalPosition������Ҫ����ת��WorldPostion
	TargetLocation = GetActorTransform().TransformPosition(TargetLocation);
	//����ͨ���ڳ�����ָ���ķ�ʽ��ȡӵ��Event�Ķ���
	if (TriggerVolumn)
	{
		ABoomTriggerVolume *trigger = Cast<ABoomTriggerVolume>(TriggerVolumn);
		if (trigger)
		{
			trigger->OnPlayerEntered.AddUObject(this, &AUpDownPlatform::Move);

			
		}
	}
}

void AUpDownPlatform::Move()
{
	FVector curLoc = GetActorLocation();
	if(curLoc.Equals(TargetLocation))
	{
		SetActorLocation(BeginLocation);
	}
	else {
		SetActorLocation(TargetLocation);
	}
	
}

// Called every frame
void AUpDownPlatform::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	
}




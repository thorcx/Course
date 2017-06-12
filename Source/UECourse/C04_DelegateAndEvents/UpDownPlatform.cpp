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
	//记录下平台开始位置，为了来回移动
	BeginLocation = GetActorLocation();
	//TargetLocation = UKismetMathLibrary::TransformLocation(GetActorTransform(), TargetLocation);
	//注意这里需要记录的目标位置是LocalPosition，我们要把他转成WorldPostion
	TargetLocation = GetActorTransform().TransformPosition(TargetLocation);
	//这里通过在场景中指定的方式获取拥有Event的对象
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




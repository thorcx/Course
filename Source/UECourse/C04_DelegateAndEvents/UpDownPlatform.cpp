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

	PlatformMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh0"));
	RootComponent = PlatformMesh;
	ConstructorHelpers::FObjectFinder<UStaticMesh> meshAsset(TEXT("StaticMesh'/Game/StarterContent/Shapes/Shape_Cube.Shape_Cube'"));
	if (meshAsset.Object)
	{
		PlatformMesh->SetStaticMesh(meshAsset.Object);
		PlatformMesh->SetRelativeScale3D(FVector(1, 1, 0.1));
	}

}

// Called when the game starts or when spawned
void AUpDownPlatform::BeginPlay()
{
	Super::BeginPlay();
	BeginLocation = GetActorLocation();

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




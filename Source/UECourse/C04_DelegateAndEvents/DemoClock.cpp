// Fill out your copyright notice in the Description page of Project Settings.

#include "UECourse.h"
#include "DemoClock.h"
#include "TimeOfDayHandler.h"

// Sets default values
ADemoClock::ADemoClock()
{
	//[c4.45]
	RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("SceneRoot"));
	ClockFace	= CreateDefaultSubobject<UStaticMeshComponent>(TEXT("ClockFace"));
	HourHand	= CreateDefaultSubobject<UStaticMeshComponent>(TEXT("HourHand"));
	MinuteHand	= CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MinuteHand"));

	HourHandle	= CreateDefaultSubobject<USceneComponent>(TEXT("HourHandle"));
	MinuteHandle= CreateDefaultSubobject<USceneComponent>(TEXT("MinuteHandle"));

	ConstructorHelpers::FObjectFinder<UStaticMesh> meshAsset(TEXT("StaticMesh'/Engine/BasicShapes/Cylinder.Cylinder'"));
	if (meshAsset.Object)
	{
		ClockFace->SetStaticMesh(meshAsset.Object);
		HourHand->SetStaticMesh(meshAsset.Object);
		MinuteHand->SetStaticMesh(meshAsset.Object);
	}


	ClockFace->SetupAttachment(RootComponent);
	ClockFace->SetRelativeTransform(FTransform(FRotator(0, 0, 90), FVector(0, 0, 0), FVector(2, 2, 1)));



	HourHand->AttachToComponent(HourHandle, FAttachmentTransformRules::KeepRelativeTransform);
	MinuteHand->AttachToComponent(MinuteHandle, FAttachmentTransformRules::KeepRelativeTransform);

	HourHandle->SetupAttachment(RootComponent);
	MinuteHandle->SetupAttachment(RootComponent);
 	
	HourHand->SetRelativeTransform(FTransform(FRotator(0, 0, 0), FVector(0, 55, 25), FVector(0.1, 0.1, 0.5)));
	MinuteHand->SetRelativeTransform(FTransform(FRotator(0, 0, 0), FVector(0, 60, 50), FVector(0.1, 0.1, 1)));
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	
	


	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ADemoClock::BeginPlay()
{
	Super::BeginPlay();
	
	//获取场景中其他物体的方式1
	TArray<AActor*> TimeOfDayHandlers;
	UGameplayStatics::GetAllActorsOfClass(GetWorld(), ATimeOfDayHandler::StaticClass(), TimeOfDayHandlers);
	if (TimeOfDayHandlers.Num() != 0)
	{
		auto timeOfDayHandler = Cast<ATimeOfDayHandler>(TimeOfDayHandlers[0]);
		DelegateHandle = timeOfDayHandler->OnTimeChanged.AddUObject(this, &ADemoClock::TimeChanged);
	}

}

// Called every frame
void ADemoClock::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ADemoClock::TimeChanged(int32 Hours, int32 Minutes)
{
	HourHandle->SetRelativeRotation(FRotator(-30 * Hours, 0 , 0));

	MinuteHandle->SetRelativeRotation(FRotator(-6 * Minutes, 0 , 0));
}


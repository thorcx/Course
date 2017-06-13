// Fill out your copyright notice in the Description page of Project Settings.

#include "UECourse.h"
#include "RayCastCamera_C06.h"
#include "HitTarget_C06.h"

// Sets default values
//[c6-2]
ARayCastCamera_C06::ARayCastCamera_C06()
	:SingleTraceLineLength(500.0f)
{
 
	CameraMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("CamMesh"));

	ConstructorHelpers::FObjectFinder<UStaticMesh> camMesh(TEXT("StaticMesh'/Game/Assets/Meshes/SM_Security_Camera_Lens.SM_Security_Camera_Lens'"));
	if (camMesh.Object)
	{
		CameraMesh->SetStaticMesh(camMesh.Object);
	}

	ConstructorHelpers::FObjectFinder<UStaticMesh> baseMesh(TEXT("StaticMesh'/Game/Assets/Meshes/SM_Security_Camera_Base.SM_Security_Camera_Base'"));
	if (baseMesh.Object)
	{
		GetStaticMeshComponent()->SetStaticMesh(baseMesh.Object);
	}
	CameraMesh->SetupAttachment(GetRootComponent());
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ARayCastCamera_C06::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ARayCastCamera_C06::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	
}

void ARayCastCamera_C06::DoSingleTrace_Implementation()
{
	UWorld *world = GetWorld();
	if (world)
	{
		FHitResult hitResult;
		const TArray<AActor*> ignoreActors;
		FVector end = GetActorForwardVector() * SingleTraceLineLength + GetActorLocation();
		bool isHit = UKismetSystemLibrary::LineTraceSingle(world, GetActorLocation(), end,UEngineTypes::ConvertToTraceType(ECC_Visibility), false, ignoreActors, EDrawDebugTrace::ForDuration, hitResult, true);
	
		if (isHit)
		{
			AActor *hitActor = hitResult.GetActor();
			if (hitActor)
			{
				AHitTarget_C06 *target = Cast<AHitTarget_C06>(hitActor);
				if (target)
				{
					target->OnRaycastHit();
				}
			}
		}
	}
}


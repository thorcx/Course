// Fill out your copyright notice in the Description page of Project Settings.

#include "UECourse.h"
#include "SecurityCameraC08.h"






ASecurityCameraC08::ASecurityCameraC08()
{
	ConstructorHelpers::FObjectFinder<UStaticMesh> cameraBaseMeshAsset(TEXT("StaticMesh'/Game/Assets/Meshes/SM_Security_Camera_Base.SM_Security_Camera_Base'"));

	if (cameraBaseMeshAsset.Object)
	{
		GetStaticMeshComponent()->SetStaticMesh(cameraBaseMeshAsset.Object);
	}

	CameraMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("CameraMesh"));

	ConstructorHelpers::FObjectFinder<UStaticMesh> cameraMeshAsset(TEXT("StaticMesh'/Game/Assets/Meshes/SM_Security_Camera_Lens.SM_Security_Camera_Lens'"));

	if (cameraMeshAsset.Object)
	{
		CameraMesh->SetStaticMesh(cameraMeshAsset.Object);
	}

	CameraMesh->SetupAttachment(GetRootComponent());

	PrimaryActorTick.bCanEverTick = true;
}

void ASecurityCameraC08::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);

	FVector endLocation = CameraMesh->GetComponentLocation() + CameraMesh->GetForwardVector() * 600;
	
	FHitResult hitResult;
	GetWorld()->SweepSingleByObjectType(hitResult, CameraMesh->GetComponentLocation(), endLocation, FQuat::Identity, ECC_Pawn,
		FCollisionShape::MakeSphere(25), FCollisionQueryParams("Spot", true, this));
	
	APawn *spottedPlayer = Cast<APawn>(hitResult.Actor.Get());
	if (spottedPlayer != nullptr)
	{
		OnPlayerSpotted(spottedPlayer);
	}

	//从Component的根发出的射线，不是很准确
	//作业，在Camera的StaticMesh上做一个Socket，精确对准摄像头镜片位置，再做射线检测
	DrawDebugLine(GetWorld(), CameraMesh->GetComponentLocation(), endLocation, FColor::Red);

}

//getter
class UStaticMeshComponent* ASecurityCameraC08::GetCameraMeshComponent() const
{
	return CameraMesh;
}

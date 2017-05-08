// Fill out your copyright notice in the Description page of Project Settings.

#include "UECourse.h"
#include "BarrackBase.h"
#include "DwarfBaseCharacter.h"

// Sets default values
ABarrackBase::ABarrackBase()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	//生成组件并填充资源
	BuildingMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("BuildMesh"));

	SpawnPoint = CreateDefaultSubobject<UParticleSystemComponent>(TEXT("SpawnPoint"));

	RootComponent = BuildingMesh;
	SpawnPoint->AttachToComponent(RootComponent, FAttachmentTransformRules::KeepRelativeTransform);
	SpawnPoint->SetRelativeLocation(FVector(0, 20, 0));
	ConstructorHelpers::FObjectFinder<UStaticMesh> meshAsset(TEXT("StaticMesh'/Game/Environment/Meshes/Sm_TD_Brewery_01.Sm_TD_Brewery_01'"));
	if (meshAsset.Object)
	{
		BuildingMesh->SetStaticMesh(meshAsset.Object);
		BuildingMesh->SetCollisionProfileName(UCollisionProfile::Pawn_ProfileName);
	}

	ConstructorHelpers::FObjectFinder<UParticleSystem> particleAsset(TEXT("ParticleSystem'/Engine/Tutorial/SubEditors/TutorialAssets/TutorialParticleSystem.TutorialParticleSystem'"));
	if (particleAsset.Object)
	{
		SpawnPoint->SetTemplate(particleAsset.Object);
	}
	SpawnPoint->SetRelativeScale3D(FVector(0.2, 0.2, 0.2));
	SpawnPoint->SetRelativeRotation(FRotator(0, 90, 0));

	SpawnInterval = 5.0f;

	ClassToSpawn = ADwarfBaseCharacter::StaticClass();
}

// Called when the game starts or when spawned
void ABarrackBase::BeginPlay()
{
	Super::BeginPlay();

	//BeginPlay内设置定时器
	GetWorld()->GetTimerManager().SetTimer(SpawnTimerHandler, this, &ABarrackBase::SpawnUnit, SpawnInterval, true);

}

// Called every frame
void ABarrackBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ABarrackBase::EndPlay(const EEndPlayReason::Type EndPlayReason)
{
	Super::EndPlay(EndPlayReason);
	GetWorld()->GetTimerManager().ClearTimer(SpawnTimerHandler);
}

void ABarrackBase::SpawnUnit()
{
	FVector spawnLoc = SpawnPoint->GetComponentLocation();
	FRotator spawnRot = SpawnPoint->GetComponentRotation();

	GetWorld()->SpawnActor(ClassToSpawn, &spawnLoc, &spawnRot);
}


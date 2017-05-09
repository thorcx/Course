// Fill out your copyright notice in the Description page of Project Settings.

#include "UECourse.h"
#include "Explode.h"
#include "DelegateGameMode.h"

// Sets default values
AExplode::AExplode()
{

	ParticleComp = CreateDefaultSubobject<UParticleSystemComponent>(TEXT("Particles"));

	BillBoard = CreateDefaultSubobject<UBillboardComponent>(TEXT("BoardBoom!"));

	RootComponent = BillBoard;

	ParticleComp->AttachToComponent(GetRootComponent(),FAttachmentTransformRules::KeepRelativeTransform);
	ConstructorHelpers::FObjectFinder<UTexture2D> boardAsset(TEXT("Texture2D'/Engine/EngineResources/AICON-Red.AICON-Red'"));
	if (boardAsset.Object)
	{
		BillBoard->SetSprite(boardAsset.Object);
	}

	ConstructorHelpers::FObjectFinder<UParticleSystem> particleAsset(TEXT("ParticleSystem'/Game/StarterContent/Particles/P_Explosion.P_Explosion'"));

	if (particleAsset.Object)
	{
		ParticleComp->SetTemplate(particleAsset.Object);
		ParticleComp->bAutoActivate = false;
	}

 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;



}

// Called when the game starts or when spawned
void AExplode::BeginPlay()
{
	Super::BeginPlay();
	
	UWorld *world = GetWorld();
	if (world)
	{
		AGameModeBase *gm = UGameplayStatics::GetGameMode(world);
		if (gm)
		{
			ADelegateGameMode *delegateGM = Cast<ADelegateGameMode>(gm);
			if (delegateGM)
			{
				EnterVolumnHandle = delegateGM->MultiDelegate.AddUObject(this, &AExplode::KaBoom);
			}
		}
	}
}

void AExplode::EndPlay(EEndPlayReason::Type EndPlayReason)
{
	Super::EndPlay(EndPlayReason);
	UWorld *world = GetWorld();
	if (world)
	{
		AGameModeBase *gm = UGameplayStatics::GetGameMode(world);
		if (gm)
		{
			ADelegateGameMode *delegateGM = Cast<ADelegateGameMode>(gm);
			if (delegateGM)
			{
				delegateGM->MultiDelegate.Remove(EnterVolumnHandle);
				
			}
		}
	}
}


void AExplode::KaBoom() const
{
	ParticleComp->ActivateSystem(false);
}



// Called every frame
void AExplode::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}


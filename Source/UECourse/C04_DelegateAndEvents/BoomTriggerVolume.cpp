// Fill out your copyright notice in the Description page of Project Settings.

#include "UECourse.h"
#include "BoomTriggerVolume.h"
#include "DelegateGameMode.h"

// Sets default values
ABoomTriggerVolume::ABoomTriggerVolume()
{
 	//创建一个Collision
	PrimaryActorTick.bCanEverTick = true;
	TriggerBox = CreateDefaultSubobject<UBoxComponent>(TEXT("TriggerBox01"));
	//设置大小
	TriggerBox->SetBoxExtent(FVector(200, 200, 100));


	//作业部分
	//ConstructorHelpers::FObjectFinder<UParticleSystem> particleAsset(TEXT(""));
}

// Called when the game starts or when spawned
void ABoomTriggerVolume::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ABoomTriggerVolume::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

//作业
//结合C03学习过的内容
//实现在这里使用UGamePlayStatics::SpawnEmitterAtLocation()
//当进入触发区播放一个粒子特效
void ABoomTriggerVolume::NotifyActorBeginOverlap(AActor* OtherActor)
{
	//[ppt7-4]
	//如何拿到代理句柄并执行
	UWorld *world = GetWorld();
	AGameModeBase *gm = UGameplayStatics::GetGameMode(world);
	ADelegateGameMode *delegateGM = Cast<ADelegateGameMode>(gm);
	if (delegateGM)
	{
		delegateGM->StandardDelegate.ExecuteIfBound();
		delegateGM->ParamDelegate.ExecuteIfBound(FLinearColor(1, 0, 0, 1));

		delegateGM->MultiDelegate.Broadcast();
		
	}

	GEngine->AddOnScreenDebugMessage(-1, 5, FColor::Red, FString::Printf(TEXT("%s Boom~~! "), *OtherActor->GetName()));

	OnPlayerEntered.Broadcast();

}

void ABoomTriggerVolume::NotifyActorEndOverlap(AActor* OtherActor)
{
	GEngine->AddOnScreenDebugMessage(-1, 5, FColor::Red, FString::Printf(TEXT("%s Leave Boom Zone! "), *OtherActor->GetName()));
}
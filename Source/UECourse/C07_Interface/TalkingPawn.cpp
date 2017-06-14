// Fill out your copyright notice in the Description page of Project Settings.

#include "UECourse.h"
#include "TalkingPawn.h"
#include "TalkerInterface.h"




ATalkingPawn::ATalkingPawn()
{
	PrimaryActorTick.bCanEverTick = false;

	TalkCollider = CreateDefaultSubobject<UBoxComponent>("TalkCollider");
	TalkCollider->SetBoxExtent(FVector(200.0f, 200.0f, 200.0f));
	TalkCollider->OnComponentBeginOverlap.AddDynamic(this, &ATalkingPawn::OnTalkOverlap);
	TalkCollider->SetupAttachment(RootComponent);
}

void ATalkingPawn::OnTalkOverlap(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult &SweepResult)
{
	
	if (OtherActor->GetClass()->ImplementsInterface(UTalker::StaticClass()))
	{
		ITalker::Execute_StartTalking(OtherActor);
	}
}

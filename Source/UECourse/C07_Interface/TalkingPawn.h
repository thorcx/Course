// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/DefaultPawn.h"
#include "TalkingPawn.generated.h"

/**
 * 
 */
UCLASS()
class UECOURSE_API ATalkingPawn : public ADefaultPawn
{
	GENERATED_BODY()
	
	ATalkingPawn();
public:
	UPROPERTY()
	class UBoxComponent* TalkCollider;

	UFUNCTION()
	void OnTalkOverlap(UPrimitiveComponent* OverlappedComp,AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult &SweepResult);
	
};

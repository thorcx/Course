// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Actor.h"
#include "PickUp.generated.h"

DECLARE_DELEGATE(FPickedupEventSignature)


UCLASS()
class UECOURSE_API APickUp : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	APickUp();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	virtual void NotifyActorBeginOverlap(AActor* OtherActor) override;


public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

public:
	UPROPERTY()
	UStaticMeshComponent* Mesh;

	UPROPERTY()
	URotatingMovementComponent* RotatingComponent;

	FPickedupEventSignature	OnPickedUp;
	
};

// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Actor.h"
#include "PickUp.generated.h"
//[c4.49]
DECLARE_DELEGATE(FPickedupEventSignature)

//[c4.48]
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
	//[c4.51]
	virtual void NotifyActorBeginOverlap(AActor* OtherActor) override;


public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

public:
	//[c4.51]
	UPROPERTY()
	UStaticMeshComponent* Mesh;
	//[c4.52]
	UPROPERTY()
	URotatingMovementComponent* RotatingComponent;
	//[c4.53]
	FPickedupEventSignature	OnPickedUp;
	
};

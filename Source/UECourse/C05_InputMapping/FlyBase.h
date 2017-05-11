// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Pawn.h"
#include "FlyBase.generated.h"

UCLASS()
class UECOURSE_API AFlyBase : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	AFlyBase();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	void MoveForward(float val);
	void MoveRight(float val);
	void MoveUp(float val);

	void Fire();
	
public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
	
	
public:
	UPROPERTY(VisibleDefaultsOnly, BlueprintReadOnly, Category=Mesh, meta = (AllowPrivateAccess = "true"))
	UStaticMeshComponent*	BodyMesh;

	UPROPERTY(VisibleDefaultsOnly, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	USpringArmComponent*	SpringArm;

	UPROPERTY(VisibleDefaultsOnly, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	UCameraComponent*		Camera;

	UPROPERTY(EditAnywhere)
	float BoostFactor;

	UPROPERTY(EditAnywhere)
	TSubclassOf<AActor>	BulletClass;

	UPROPERTY(EditAnywhere, Category=FireControl)
	FVector	ProjectileSpawnLocation;

	float CurrentForwardSpeed;
	
	float CurrentFlankSpeed;
	float CurrentVerticalSpeed;


};

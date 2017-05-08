// Fill out your copyright notice in the Description page of Project Settings.

#include "UECourse.h"
#include "DwarfBaseCharacter.h"


// Sets default values
ADwarfBaseCharacter::ADwarfBaseCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	GetCapsuleComponent()->SetCapsuleHalfHeight(68);
	GetCapsuleComponent()->SetCapsuleRadius(50);

	ConstructorHelpers::FObjectFinder<USkeletalMesh> meshAsset(TEXT("SkeletalMesh'/Game/Characters/DwarfGrunt/SkelMesh/DwarfGrunt_R_new.DwarfGrunt_R_new'"));
	if (meshAsset.Object)
	{
		GetMesh()->SetSkeletalMesh(meshAsset.Object);
		GetMesh()->SetRelativeLocation(FVector(0, 0, -68));
		GetMesh()->SetRelativeRotation(FRotator(0, -90, 0));
	}

}

// Called when the game starts or when spawned
void ADwarfBaseCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ADwarfBaseCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	//作业，自定义前进方向,速度
	SetActorLocation(GetActorLocation() + FVector(0,1,0));
}

// Called to bind functionality to input
void ADwarfBaseCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}


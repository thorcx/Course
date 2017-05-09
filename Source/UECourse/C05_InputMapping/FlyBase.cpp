// Fill out your copyright notice in the Description page of Project Settings.

#include "UECourse.h"
#include "FlyBase.h"


// Sets default values
AFlyBase::AFlyBase()
	:CurrentForwardSpeed(0.f)
{

	BodyMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("BodyMesh"));

	ConstructorHelpers::FObjectFinder<UStaticMesh> meshAsset(TEXT("StaticMesh'/Game/Assets/C05/SM_UFO.SM_UFO'"));
	if (meshAsset.Object)
	{
		BodyMesh->SetStaticMesh(meshAsset.Object);
	}
	RootComponent = BodyMesh;

	SpringArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("SprintArm0"));
	SpringArm->SetupAttachment(RootComponent);
	SpringArm->TargetArmLength = 300.0f;
	SpringArm->SocketOffset = FVector(0.f, 0.f, 60.f);
	SpringArm->bEnableCameraLag = false;
	
	Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera0"));
	Camera->SetupAttachment(SpringArm, USpringArmComponent::SocketName);
	Camera->bUsePawnControlRotation = false;
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AFlyBase::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AFlyBase::Tick(float DeltaTime)
{
	const FVector LocalMove = FVector(CurrentForwardSpeed * DeltaTime, 0.f, 0.f);

	AddActorLocalOffset(LocalMove, true);
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AFlyBase::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	check(PlayerInputComponent);
	PlayerInputComponent->BindAxis("MoveForward", this, &AFlyBase::MoveForward);
	//Super::SetupPlayerInputComponent(PlayerInputComponent);

}

void AFlyBase::MoveForward(float val)
{

	CurrentForwardSpeed += val;
	CurrentForwardSpeed = FMath::Clamp(CurrentForwardSpeed, 0.f, 1000.f);
	GEngine->AddOnScreenDebugMessage(-1, 1, FColor::Red, FString::Printf(TEXT("speed is %f"), CurrentForwardSpeed));
}


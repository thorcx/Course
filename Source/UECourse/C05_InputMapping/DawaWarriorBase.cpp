// Fill out your copyright notice in the Description page of Project Settings.

#include "UECourse.h"
#include "DawaWarriorBase.h"
#include "Kismet/KismetMathLibrary.h"

// Sets default values
ADawaWarriorBase::ADawaWarriorBase()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	//[c5.5]
	//关闭使用Controller的Rotatation来控制角色
	bUseControllerRotationYaw = false;
	//开启让玩家角色移动的时候朝向运动方向
	GetCharacterMovement()->bOrientRotationToMovement = true;
}

// Called when the game starts or when spawned
void ADawaWarriorBase::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ADawaWarriorBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ADawaWarriorBase::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	check(PlayerInputComponent);
	//Axis绑定
	PlayerInputComponent->BindAxis("MoveForward", this, &ADawaWarriorBase::MoveForward);
	PlayerInputComponent->BindAxis("MoveRight", this, &ADawaWarriorBase::MoveRight);
	//[c5.9]
	PlayerInputComponent->BindAxis("Turn", this, &ADawaWarriorBase::Turn);
	PlayerInputComponent->BindAxis("LookUp", this, &ADawaWarriorBase::LookUp);

	//Action绑定
	PlayerInputComponent->BindAction("Sprint", IE_Pressed, this, &ADawaWarriorBase::OnStartRunning);
	PlayerInputComponent->BindAction("Sprint", IE_Released, this, &ADawaWarriorBase::OnStopRunning);
}

void ADawaWarriorBase::MoveForward(float amount)
{
	FRotator controllerRotation(0.0f, GetControlRotation().Yaw, 0.0f);
	//UE_LOG(LogTemp, Warning, TEXT("Yaw is, %f"), GetControlRotation().Yaw);
	AddMovementInput(UKismetMathLibrary::GetForwardVector(controllerRotation), amount);
}

void ADawaWarriorBase::MoveRight(float amount)
{
	FRotator controllerRotation(0.0f, GetControlRotation().Yaw, 0.0f);
	AddMovementInput(UKismetMathLibrary::GetRightVector(controllerRotation), amount);
}

void ADawaWarriorBase::Turn(float amount)
{
	AddControllerYawInput(amount);
}

void ADawaWarriorBase::LookUp(float amount)
{
	AddControllerPitchInput(amount);
}

void ADawaWarriorBase::OnStartRunning()
{
	GetCharacterMovement()->MaxWalkSpeed = 600.0f;
}

void ADawaWarriorBase::OnStopRunning()
{
	GetCharacterMovement()->MaxWalkSpeed = 100.0f;
}


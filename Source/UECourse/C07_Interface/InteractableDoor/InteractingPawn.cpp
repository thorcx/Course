// Fill out your copyright notice in the Description page of Project Settings.

#include "UECourse.h"
#include "InteractingPawn.h"
#include "InteractableInterface.h"

void AInteractingPawn::TryInteract()
{
	//获取Pawn内的控制器，看是不是一个PlayerController
	//Pawn是有可能没有Controller或者是AIController的
	APlayerController *PC = Cast<APlayerController>(Controller);
	if (PC)
	{
		//获取跟PC绑定的相机控制类，这里是为了获取Ray trace的起终点
		APlayerCameraManager* camManager = PC->PlayerCameraManager;

		FVector startLoc = camManager->GetCameraLocation();
		FVector endLoc = startLoc + (camManager->GetActorForwardVector() * 100);

		//这里展示了如何使用Ray Cast 一族函数的一般典型形式
		//先声明一个FHitResult
		FHitResult hitResult;

		//使用按物体类型的ray cast
		//声明一个FCollisionObjectQueryParams
		FCollisionObjectQueryParams objectQueryParams(FCollisionObjectQueryParams::AllObjects);
		FCollisionShape shape = FCollisionShape::MakeSphere(25.0f);
		FCollisionQueryParams queryParams(FName("Interaction"), true, this);

		GetWorld()->SweepSingleByObjectType(hitResult, startLoc, endLoc, FQuat::Identity, objectQueryParams, shape, queryParams);
		if (hitResult.Actor != nullptr)
		{
			if (hitResult.Actor->GetClass()->ImplementsInterface(UInteractable::StaticClass()))
			{
				if (IInteractable::Execute_CanInteract(hitResult.Actor.Get()))
				{
					IInteractable::Execute_PerformInteract(hitResult.Actor.Get());
				}
			}
		}
	}
}

//别忘了编辑器map Interace
void AInteractingPawn::SetupPlayerInputComponent(UInputComponent* InInputComponent)
{
	Super::SetupPlayerInputComponent(InInputComponent);
	InInputComponent->BindAction("Interact", IE_Released, this, &AInteractingPawn::TryInteract);
}




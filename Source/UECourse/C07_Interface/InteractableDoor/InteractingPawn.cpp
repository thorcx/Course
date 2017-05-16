// Fill out your copyright notice in the Description page of Project Settings.

#include "UECourse.h"
#include "InteractingPawn.h"
#include "InteractableInterface.h"

void AInteractingPawn::TryInteract()
{
	//��ȡPawn�ڵĿ����������ǲ���һ��PlayerController
	//Pawn���п���û��Controller������AIController��
	APlayerController *PC = Cast<APlayerController>(Controller);
	if (PC)
	{
		//��ȡ��PC�󶨵���������࣬������Ϊ�˻�ȡRay trace�����յ�
		APlayerCameraManager* camManager = PC->PlayerCameraManager;

		FVector startLoc = camManager->GetCameraLocation();
		FVector endLoc = startLoc + (camManager->GetActorForwardVector() * 100);

		//����չʾ�����ʹ��Ray Cast һ�庯����һ�������ʽ
		//������һ��FHitResult
		FHitResult hitResult;

		//ʹ�ð��������͵�ray cast
		//����һ��FCollisionObjectQueryParams
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

//�����˱༭��map Interace
void AInteractingPawn::SetupPlayerInputComponent(UInputComponent* InInputComponent)
{
	Super::SetupPlayerInputComponent(InInputComponent);
	InInputComponent->BindAction("Interact", IE_Released, this, &AInteractingPawn::TryInteract);
}




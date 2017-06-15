// Fill out your copyright notice in the Description page of Project Settings.

#include "UECourse.h"
#include "SwitchC08.h"




ASwitchC08::ASwitchC08()
{
	ConstructorHelpers::FObjectFinder<UStaticMesh> switchMeshAsset(TEXT("StaticMesh'/Game/DemoRoom/Meshes/SM_Button.SM_Button'"));
	if (switchMeshAsset.Object)
	{
		GetStaticMeshComponent()->SetStaticMesh(switchMeshAsset.Object);
	}
	
	BoxTrigger = CreateDefaultSubobject<UBoxComponent>(TEXT("BoxTrigger"));
	BoxTrigger->bGenerateOverlapEvents = true;
	BoxTrigger->SetCollisionProfileName(FName("OverlapAllDynamic"));
	BoxTrigger->SetupAttachment(GetRootComponent());

	BoxTrigger->SetRelativeLocation(FVector(0.0f, 50.0f, 100.0f));

	

	//UMaterialInterface *mat = GetStaticMeshComponent()->GetMaterial(2);
	//SwitchDMI = UMaterialInstanceDynamic::Create(mat, this, FName("SwitchDMIFFFF"));
	//GetStaticMeshComponent()->SetMaterial(2, SwitchDMI);
}

void ASwitchC08::BeginPlay()
{
	Super::BeginPlay();
	
	
	//SwitchDMI = GetStaticMeshComponent()->CreateAndSetMaterialInstanceDynamic(2);

	BoxTrigger->OnComponentBeginOverlap.AddDynamic(this, &ASwitchC08::OnSwitchTriggerOverlapped);
	BoxTrigger->OnComponentEndOverlap.AddDynamic(this, &ASwitchC08::OnSwitchTriggerEndOverlapped);
}


void ASwitchC08::PostInitializeComponents()
{
	//别忘了调父类
	Super::PostInitializeComponents();

	//这里可以用这种形式
	/*UMaterialInterface *mat = GetStaticMeshComponent()->GetMaterial(2);
	SwitchDMI = UMaterialInstanceDynamic::Create(mat, this);
	GetStaticMeshComponent()->SetMaterial(2, SwitchDMI);*/

	//也可以用这种形式
	SwitchDMI = GetStaticMeshComponent()->CreateAndSetMaterialInstanceDynamic(2);
}
//[c8-23]
void ASwitchC08::OnSwitchTriggerOverlapped_Implementation(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult & SweepResult)
{
	OnSwitchTouched.Broadcast(this);
	SwitchDMI->SetScalarParameterValue(FName("state"), 1.0f);
}

void ASwitchC08::OnSwitchTriggerEndOverlapped_Implementation(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
	SwitchDMI->SetScalarParameterValue(FName("state"), 0.0f);
}

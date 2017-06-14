// Fill out your copyright notice in the Description page of Project Settings.

#include "UECourse.h"
#include "Boot.h"


// Sets default values
ABoot::ABoot()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("Root"));
}

// Called when the game starts or when spawned
void ABoot::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ABoot::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ABoot::OnEquip_Implementation(APawn* Wearer)
{
	IWearable::OnEquip_Implementation(Wearer);
}

bool ABoot::CanEquip_Implementation(APawn* Wearer)
{
	return IWearable::CanEquip_Implementation(Wearer);
}

int32 ABoot::GetStrengthRequirement_Implementation()
{
	return IWearable::GetStrengthRequirement_Implementation();
}


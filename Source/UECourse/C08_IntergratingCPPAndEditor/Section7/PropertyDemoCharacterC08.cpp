// Fill out your copyright notice in the Description page of Project Settings.

#include "UECourse.h"
#include "PropertyDemoCharacterC08.h"




APropertyDemoCharacterC08::APropertyDemoCharacterC08()
{
	ConstructorHelpers::FObjectFinder<USkeletalMesh> meshAsset(TEXT("SkeletalMesh'/Game/Characters/DwarfGrunt/SkelMesh/DwarfGrunt_R_new.DwarfGrunt_R_new'"));
	if (meshAsset.Object)
	{
		GetSkeletalMeshComponent()->SetSkeletalMesh(meshAsset.Object);
	}
}

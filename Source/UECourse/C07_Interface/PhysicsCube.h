#pragma once

#include "GameFramework/Actor.h"
#include "GravityInterface.h"
#include "PhysicsCube.generated.h"

//[c7-19]
UCLASS()
class APhysicsCube : public AActor, public IGravityInterface
{
	GENERATED_BODY()
public:
	APhysicsCube();
public:
	UPROPERTY()
	UStaticMeshComponent*	Cube;
};

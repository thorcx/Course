#pragma once

#include "GameFramework/Actor.h"
#include "GravityInterface.h"
#include "PhysicsCube.generated.h"

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

#include "UECourse.h"
#include "PhysicsCube.h"

APhysicsCube::APhysicsCube()
{
	Cube = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("CubeMesh"));
	ConstructorHelpers::FObjectFinder<UStaticMesh> meshAsset(TEXT("StaticMesh'/Game/StarterContent/Shapes/Shape_Cube.Shape_Cube'"));
	if (meshAsset.Object)
	{
		Cube->SetStaticMesh(meshAsset.Object);
	}

	RootComponent = Cube;
	Cube->SetMobility(EComponentMobility::Movable);
	Cube->SetSimulatePhysics(true);
	SetActorEnableCollision(true);
}
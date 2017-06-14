#pragma once
#include "PhysicsCube.h"
#include "SelectableInterface.h"
#include "SelectableCube.generated.h"

//[ppt-12-9]
//[c7-28]
UCLASS()
class ASelectableCube : public APhysicsCube, public ISelectable
{
	GENERATED_BODY()
	
public:
	ASelectableCube();

	virtual void NotifyHit(class UPrimitiveComponent* MyComp, AActor* Other, class UPrimitiveComponent* OtherComp, bool bSelfMoved, FVector HitLocation, FVector HitNormal, FVector NormalImpulse, const FHitResult& Hit) override;

	
};

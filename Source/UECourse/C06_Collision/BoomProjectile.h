#pragma once

#include "GameFramework/Actor.h"
#include "BoomProjectile.generated.h"




UCLASS()
class ABoomProjectile : public AActor
{
	GENERATED_BODY()
	
public:
	ABoomProjectile();

	virtual void PostInitializeComponents() override;

	//自定义的处理球体碰撞BeginOverlap事件，蓝图可覆写
	//注意这里在Cpp实现时候要加OnProjectileBeginOverlap_Implementation
	UFUNCTION(BlueprintNativeEvent, Category=Collision)
	void OnProjectileBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult &SweepResult);
public:

	UPROPERTY(VisibleDefaultsOnly)
		USphereComponent*		SphereCollisionComponent;

	UPROPERTY(VisibleDefaultsOnly)
		UStaticMeshComponent*	BoomMeshComponent;

	UPROPERTY(VisibleDefaultsOnly)
		UProjectileMovementComponent*	ProjectileMoveComponent;

	
};
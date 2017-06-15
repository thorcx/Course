// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Engine/StaticMeshActor.h"
#include "SecurityCameraC08.generated.h"

/**
 * 
 */
//[c6-1]
//[c8-15]
UCLASS()
class UECOURSE_API ASecurityCameraC08 : public AStaticMeshActor
{
	GENERATED_BODY()
	
	UPROPERTY(VisibleDefaultsOnly, BlueprintReadOnly, Category=CameraMesh, meta=(AllowPrivateAccess=true))
	class UStaticMeshComponent *CameraMesh;
	
public:

	ASecurityCameraC08();
	
	//[c8-16]
	//* …‰œﬂºÏ≤‚ */
	virtual void Tick(float DeltaSeconds) override;

	//[c8-17]
	UFUNCTION(BlueprintImplementableEvent, Category=SecurityCamera)
	void OnPlayerSpotted(APawn* Player);

	class UStaticMeshComponent* GetCameraMeshComponent() const;
	
};

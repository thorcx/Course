#pragma once
#include "GameFramework/Actor.h"
#include "TeamInterface.h"
#include "InterfaceGameMode.generated.h"
//[c7-09]
UCLASS()
class AInterfaceGameMode : public AGameModeBase
{
	GENERATED_BODY()
public:

	virtual void BeginPlay() override;

	//[c7-10]
	UFUNCTION(BlueprintCallable, Category="UECourse|InterfaceDemo")
	void ShowActorInterfaceInfo();

	//[c7-11]
	UFUNCTION(BlueprintCallable, Category = "UECourse|InterfaceDemo")
	void CallActorTeamInterface();

public:
	UPROPERTY()
	int32 Count;
};

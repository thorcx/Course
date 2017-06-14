#pragma once
#include "InteractableInterface.generated.h"

//最后的案例也是习题作业
//作业
//1.为开关换模型，根据开关的形状，当开启的时候，适当转动开关
//2.门打开的高度暴露成参数，在关卡内可输入调整
//3.为开关写额外的关动作，当判断门已经打开后，再按下开关将门关上
//4.配合蓝图继承，实现门开启关闭的动画效果
//[c7-36]
UINTERFACE()
class UInteractable : public UInterface
{
	GENERATED_BODY()
};


class IInteractable
{
	GENERATED_BODY()
public:

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = Interactable)
		bool CanInteract();

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = Interactable)
		void PerformInteract();
};
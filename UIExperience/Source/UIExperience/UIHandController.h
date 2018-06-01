// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "HandControllerBase.h"

#include "Components/WidgetInteractionComponent.h"

#include "UIHandController.generated.h"

/**
 * 
 */
UCLASS()
class UIEXPERIENCE_API AUIHandController : public AHandControllerBase
{
	GENERATED_BODY()

public:
	AUIHandController();
	void RightTriggerPressed() override;
	void RightTriggerReleased() override;

private:
	// Components
	UPROPERTY(VisibleAnywhere)
	UWidgetInteractionComponent* WidgetInteractionComponent;
	
	
};

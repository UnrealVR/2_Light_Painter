// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/WidgetInteractionComponent.h"
#include "WidgetTouchingComponent.generated.h"

/**
 * 
 */
UCLASS(meta = (BlueprintSpawnableComponent))
class LIGHTPAINTER_API UWidgetTouchingComponent : public UWidgetInteractionComponent
{
	GENERATED_BODY()
	
public:
	void TickComponent(
		float DeltaTime,
		enum ELevelTick TickType,
		FActorComponentTickFunction * ThisTickFunction
	) override;
	
private:
	// State
	bool bIsClicked = false;
};

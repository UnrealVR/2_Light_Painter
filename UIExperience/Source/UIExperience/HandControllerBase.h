// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"

#include "MotionControllerComponent.h"

#include "HandControllerBase.generated.h"

/**
 * Base for all hand controllers.
 *
 * Provides hand controller tracking and trigger callbacks.
 */
UCLASS()
class UIEXPERIENCE_API AHandControllerBase : public AActor
{
	GENERATED_BODY()
	
public:	
	AHandControllerBase();

	virtual void RightTriggerPressed() {}
	virtual void RightTriggerReleased() {}

private:
	// Components
	UPROPERTY(VisibleAnywhere)
	UMotionControllerComponent* MotionController;

};

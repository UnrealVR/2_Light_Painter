// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"

#include "MotionControllerComponent.h"

#include "HandControllerBase.generated.h"

UCLASS()
class LIGHTPAINTER_API AHandControllerBase : public AActor
{
	GENERATED_BODY()

public:	
	// Sets default values for this actor's properties
	AHandControllerBase();

	virtual void TriggerPressed() {}
	virtual void TriggerReleased() {}

	void SetHand(EControllerHand Hand);

private:

	// Components
	UPROPERTY(VisibleAnywhere)
	UMotionControllerComponent* MotionController;

};

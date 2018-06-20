// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"

#include "MotionControllerComponent.h"

#include "PaintBrushHandController.generated.h"

UCLASS()
class LIGHTPAINTER_API APaintBrushHandController : public AActor
{
	GENERATED_BODY()
	
public:	
	APaintBrushHandController();
	virtual void Tick(float DeltaTime) override;

protected:
	virtual void BeginPlay() override;

private:
	// Components
	UPROPERTY()
	UMotionControllerComponent* MotionController;
	
};

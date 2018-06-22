// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"

#include "MotionControllerComponent.h"
#include "Stroke.h"

#include "PaintBrushHandController.generated.h"

UCLASS()
class LIGHTPAINTER_API APaintBrushHandController : public AActor
{
	GENERATED_BODY()
	
public:	
	APaintBrushHandController();
	virtual void Tick(float DeltaTime) override;

	void TriggerPressed();
	void TriggerReleased();

protected:
	virtual void BeginPlay() override;

private:
	// Components
	UPROPERTY()
	UMotionControllerComponent* MotionController;

	// Config
	UPROPERTY(EditAnywhere)
	TSubclassOf<AStroke> StrokeClass;

	// State
	AStroke* CurrentStroke;
	
	FVector LastFrameLocation;
};

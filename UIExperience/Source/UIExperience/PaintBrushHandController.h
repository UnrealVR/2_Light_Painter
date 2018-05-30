// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"

#include "MotionControllerComponent.h"
#include "Stroke.h"

#include "PaintBrushHandController.generated.h"

UCLASS()
class UIEXPERIENCE_API APaintBrushHandController : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	APaintBrushHandController();
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	void RightTriggerPressed();
	void RightTriggerReleased();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

private:
	UPROPERTY(VisibleAnywhere)
	UMotionControllerComponent* MotionController;

	UPROPERTY(VisibleAnywhere)
	AStroke* CurrentStroke;

	UPROPERTY(EditDefaultsOnly)
	TSubclassOf<AStroke> StrokeClass;
};

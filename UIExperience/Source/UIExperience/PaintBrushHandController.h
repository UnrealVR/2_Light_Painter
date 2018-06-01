// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "HandControllerBase.h"

#include "Stroke.h"

#include "PaintBrushHandController.generated.h"

UCLASS()
class UIEXPERIENCE_API APaintBrushHandController : public AHandControllerBase
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	APaintBrushHandController();
	virtual void Tick(float DeltaTime) override;

	void RightTriggerPressed() override;
	void RightTriggerReleased() override;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

private:
	// Config
	UPROPERTY(EditDefaultsOnly)
	TSubclassOf<AStroke> StrokeClass;

	// State
	UPROPERTY(VisibleAnywhere)
	AStroke* CurrentStroke;

	FVector LastLocation;

};

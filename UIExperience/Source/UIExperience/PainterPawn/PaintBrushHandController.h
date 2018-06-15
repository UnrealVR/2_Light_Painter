// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "HandControllerBase.h"

#include "Components/WidgetInteractionComponent.h"

#include "Stroke.h"

#include "PaintBrushHandController.generated.h"

UENUM()
enum class EBrushState
{
	Painting,
	Erasing
};

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

	EBrushState GetState() const { return State; }
	void SetState(const EBrushState& NewState) { State = NewState; }

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

private:

	void TickStrokeUpdate(float DeltaTime);
	void TickButtonPressDetection();

	// Components
	UPROPERTY(VisibleAnywhere)
	USceneComponent* StrokeSpawnPoint;

	UPROPERTY(VisibleAnywhere)
	UWidgetInteractionComponent* WidgetInteractionComponent;

	// Config
	UPROPERTY(EditDefaultsOnly)
	TSubclassOf<AStroke> StrokeClass;

	// State
	UPROPERTY(VisibleAnywhere)
	AStroke* CurrentStroke;

	EBrushState State;

	FVector LastLocation;

	bool ButtonIsPressed = false;

};

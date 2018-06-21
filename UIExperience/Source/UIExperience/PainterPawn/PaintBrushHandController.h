// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "HandControllerBase.h"

#include "Components/WidgetInteractionComponent.h"

#include "Brushes/VRBrushInterface.h"

#include "PaintBrushHandController.generated.h"

/**
 * Hand controller for painting in the world.
 *
 * Will use the currently active brush to paint, erase, etc. Also furnished
 * with UI selection by touching.
 */
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

	EBrushMode GetState() const;
	void SetState(EBrushMode NewState);

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

private:

	void TickUIButtonPressDetection();

	// Config
	UPROPERTY(EditAnywhere)
	float ClickDistance = 9;

	// Components
	UPROPERTY(VisibleAnywhere)
	UWidgetInteractionComponent* WidgetInteractionComponent;

	// State
	IVRBrushInterface* CurrentBrush;

	bool UIButtonIsPressed = false;

};
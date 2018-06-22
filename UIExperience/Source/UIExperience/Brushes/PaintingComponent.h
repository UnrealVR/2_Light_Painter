// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/SceneComponent.h"

#include "VRBrushBase.h"
#include "Canvas/Stroke.h"

#include "PaintingComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class UIEXPERIENCE_API UPaintingComponent : public UVRBrushBase
{
	GENERATED_BODY()

public:	

	UPaintingComponent();
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	// Brushing Interface
	virtual EBrushMode GetState() const override { return EBrushMode::Painting; }
	virtual void StartBrushing() override;
	virtual void StopBrushing() override;

private:

	// Config
	UPROPERTY(EditDefaultsOnly)
	TSubclassOf<AStroke> StrokeClass;

	// State
	UPROPERTY(VisibleAnywhere)
	AStroke* CurrentStroke;

	FVector LocationLastFrame;
	
};

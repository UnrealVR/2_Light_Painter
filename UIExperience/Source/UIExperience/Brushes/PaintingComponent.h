// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/SceneComponent.h"

#include "VRBrushInterface.h"
#include "Canvas/Stroke.h"

#include "PaintingComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class UIEXPERIENCE_API UPaintingComponent : public USceneComponent, public IVRBrushInterface
{
	GENERATED_BODY()

public:	

	UPaintingComponent();
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
	virtual EBrushMode GetState() const override { return EBrushMode::Painting; }
	virtual void StartBrushing() override;
	virtual void StopBrushing() override;
	virtual void Activate(bool bNewActive) override { SetActive(bNewActive); }

private:

	// Config
	UPROPERTY(EditDefaultsOnly)
	TSubclassOf<AStroke> StrokeClass;

	// State
	UPROPERTY(VisibleAnywhere)
	AStroke* CurrentStroke;

	FVector LastLocation;
	
};

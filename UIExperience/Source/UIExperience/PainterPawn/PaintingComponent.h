// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/SceneComponent.h"

#include "VRBrushInterface.h"
#include "Stroke.h"

#include "PaintingComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class UIEXPERIENCE_API UPaintingComponent : public USceneComponent, public IVRBrushInterface
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UPaintingComponent();
	virtual EBrushState GetState() const override { return EBrushState::Painting; }
	virtual void StartBrushing() override;
	virtual void StopBrushing() override;
	virtual void Activate(bool bNewActive) override { SetActive(bNewActive); }

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

private:

	// Config
	UPROPERTY(EditDefaultsOnly)
	TSubclassOf<AStroke> StrokeClass;

	// State
	UPROPERTY(VisibleAnywhere)
	AStroke* CurrentStroke;

	FVector LastLocation;
	
};

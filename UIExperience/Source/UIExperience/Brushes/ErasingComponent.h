// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/SceneComponent.h"

#include "VRBrushInterface.h"

#include "ErasingComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class UIEXPERIENCE_API UErasingComponent : public USceneComponent, public IVRBrushInterface
{
	GENERATED_BODY()

public:	

	UErasingComponent();

	// Brush Interface
	virtual EBrushMode GetState() const override { return EBrushMode::Erasing; }
	virtual void StartBrushing() override;
	virtual void StopBrushing() override;
	virtual void SetBrushActive(bool bNewActive) override { SetActive(bNewActive); }

};

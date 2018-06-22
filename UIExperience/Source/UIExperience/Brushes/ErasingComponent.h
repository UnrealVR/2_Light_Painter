// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/SceneComponent.h"

#include "VRBrushBase.h"

#include "ErasingComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class UIEXPERIENCE_API UErasingComponent : public UVRBrushBase
{
	GENERATED_BODY()

public:	

	UErasingComponent();

	// Brush Interface
	virtual EBrushMode GetState() const override { return EBrushMode::Erasing; }
	virtual void StartBrushing() override;

};

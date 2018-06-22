// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/SceneComponent.h"
#include "VRBrushBase.generated.h"


//TODO: Eliminate
UENUM()
enum class EBrushMode
{
	Painting,
	Erasing,
	NONE
};

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class UIEXPERIENCE_API UVRBrushBase : public USceneComponent
{
	GENERATED_BODY()

public:	
	UVRBrushBase();

	virtual EBrushMode GetState() const { return EBrushMode::NONE; }
	virtual void StartBrushing() {}
	virtual void StopBrushing() {}
	
};

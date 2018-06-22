// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "VRBrushInterface.generated.h"

//TODO: Eliminate
UENUM()
enum class EBrushMode
{
	Painting,
	Erasing,
	NONE
};

// This class does not need to be modified.
UINTERFACE(MinimalAPI)
class UVRBrushInterface : public UInterface
{
	GENERATED_BODY()
};

/**
 * A generic interface for different painting brushes.
 * 
 * The brush is a component that conforms to this interface.
 */
class UIEXPERIENCE_API IVRBrushInterface
{
	GENERATED_BODY()

	// Add interface functions to this class. This is the class that will be inherited to implement this interface.
public:
	
	virtual EBrushMode GetState() const = 0;
	virtual void StartBrushing() = 0;
	virtual void StopBrushing() = 0;
	virtual void SetActive(bool bNewActive) = 0;
};

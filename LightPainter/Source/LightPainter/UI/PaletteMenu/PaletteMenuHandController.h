// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "HandControllerBase.h"

#include "WidgetComponent.h"

#include "PaletteMenuHandController.generated.h"

/**
 * 
 */
UCLASS()
class LIGHTPAINTER_API APaletteMenuHandController : public AHandControllerBase
{
	GENERATED_BODY()

public:
	APaletteMenuHandController();

private:

	// Components
	UPROPERTY(VisibleAnywhere)
	UWidgetComponent* PaletteMenu;
	
	
};

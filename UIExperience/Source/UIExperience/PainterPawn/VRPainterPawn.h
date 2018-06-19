// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "VRPawnBase.h"

#include "PaintBrushHandController.h"

#include "VRPainterPawn.generated.h"

/**
 * 
 */
UCLASS()
class UIEXPERIENCE_API AVRPainterPawn : public AVRPawnBase
{
	GENERATED_BODY()
public:

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

protected:
	void BeginPlay();

};

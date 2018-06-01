// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "VRPawn.h"

#include "PaintBrushHandController.h"

#include "VRPainterPawn.generated.h"

/**
 * 
 */
UCLASS()
class UIEXPERIENCE_API AVRPainterPawn : public AVRPawn
{
	GENERATED_BODY()
public:

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

protected:
	void BeginPlay();

private:
	void Save();
	void Load();

	//state
	FString UniquePaintingIdentifier = "";
};

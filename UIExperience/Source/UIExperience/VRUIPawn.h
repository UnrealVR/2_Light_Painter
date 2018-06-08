// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "VRPawn.h"
#include "VRUIPawn.generated.h"

/**
 * 
 */
UCLASS()
class UIEXPERIENCE_API AVRUIPawn : public AVRPawn
{
	GENERATED_BODY()

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
};

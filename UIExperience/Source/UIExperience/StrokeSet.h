// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "StrokeSet.generated.h"

USTRUCT()
struct FStrokeDataColor
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere)
	FText Name;

	UPROPERTY(EditAnywhere)
	class UMaterialInterface* Material;
};

/**
 * 
 */
UCLASS()
class UIEXPERIENCE_API UStrokeSet : public UDataAsset
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere)
	TArray<FStrokeDataColor> Colors;
	
};
